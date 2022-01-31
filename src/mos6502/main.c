/*-------------------------------------------------------------------------
  main.c - m6502 specific general function

  Copyright (C) 2003, Erik Petrich

  Hacked for the MOS6502:
  Copyright (C) 2020, Steven Hugg  hugg@fasterlight.com
  Copyright (C) 2021, Gabriele Gorla


  This program is free software; you can redistribute it and/or modify it
  under the terms of the GNU General Public License as published by the
  Free Software Foundation; either version 2, or (at your option) any
  later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
-------------------------------------------------------------------------*/
/*
    Note that mlh prepended _m6502_ on the static functions.  Makes
    it easier to set a breakpoint using the debugger.
*/
#include "common.h"
#include "m6502.h"
#include "main.h"
#include "ralloc.h"
#include "gen.h"
#include "dbuf_string.h"

extern char * iComments2;
extern DEBUGFILE dwarf2DebugFile;
extern int dwarf2FinalizeFile(FILE *);

#define OPTION_SMALL_MODEL          "--model-small"
#define OPTION_LARGE_MODEL          "--model-large"
//#define OPTION_CODE_SEG        "--codeseg"
//#define OPTION_CONST_SEG       "--constseg"
//#define OPTION_DATA_SEG        "--dataseg"
#define OPTION_NO_STD_CRT0     "--no-std-crt0"

static char _m6502_defaultRules[] =
{
#include "peeph.rul"
};

static char _m65c02_defaultRules[] =
{
#include "peeph.rul"
};

MOS6502_OPTS mos6502_opts;

static OPTION _mos6502_options[] =
  {
    {0, OPTION_SMALL_MODEL, NULL, "8-bit address space for data"},
    {0, OPTION_LARGE_MODEL, NULL, "16-bit address space for data (default)"},
    //    {0, OPTION_CODE_SEG,        &options.code_seg, "<name> use this name for the code segment", CLAT_STRING},
    //    {0, OPTION_CONST_SEG,       &options.const_seg, "<name> use this name for the const segment", CLAT_STRING},
    //    {0, OPTION_DATA_SEG,        &options.data_seg, "<name> use this name for the data segment", CLAT_STRING},
    {0, OPTION_NO_STD_CRT0,     &options.no_std_crt0, "Do not link default crt0.rel"},
    {0, NULL }
  };

/* list of key words used by m6502 */
static char *_keywords[] = {
  "at",
  "code",
  "critical",
  "data",
  "far",
  //"idata",
  "interrupt",
  "near",
  //"pdata",
  "reentrant",
  //"using",
  "xdata",
  "_data",
  "_code",
  "_generic",
  "_near",
  "_xdata",
  //"_pdata",
  //"_idata",
  "_naked",
  "_overlay",
  NULL
};


void m6502_assignRegisters (ebbIndex *);

static int regParmFlg;      /* determine if we can register a parameter */
static struct sym_link *regParmFuncType;

static void
_m6502_init (void)
{
  mos6502_opts.sub = SUB_MOS6502;
  asm_addTree (&asm_asxxxx_mapping);
}

static void
_m65c02_init (void)
{
  mos6502_opts.sub = SUB_MOS65C02;
  asm_addTree (&asm_asxxxx_mapping);
}

static void
_m6502_reset_regparm (struct sym_link *funcType)
{
  regParmFlg = 0;
  regParmFuncType = funcType;
}

static int
_m6502_regparm (sym_link * l, bool reentrant)
{
  if (IFFUNC_HASVARARGS (regParmFuncType))
    return 0;

  int size = getSize(l);

  /* If they fit completely, the first two bytes of parameters can go */
  /* into A and X, otherwise, they go on the stack. Examples:         */
  /*   foo(char p1)                    A <- p1                        */
  /*   foo(char p1, char p2)           A <- p1, X <- p2               */
  /*   foo(char p1, char p2, char p3)  A <- p1, X <- p2, stack <- p3  */
  /*   foo(int p1)                     XA <- p1                       */
  /*   foo(long p1)                    stack <- p1                    */
  /*   foo(char p1, int p2)            A <- p1, stack <- p2           */
  /*   foo(int p1, char p2)            XA <- p1, stack <- p2          */

  if (regParmFlg>=2)
    return 0;

  if ((regParmFlg+size)>2)
    {
      regParmFlg = 2;
      return 0;
    }

  regParmFlg += size;
  return 1+regParmFlg-size;
}

static bool
_m6502_parseOptions (int *pargc, char **argv, int *i)
{
  return false;
}

static void
_m6502_finaliseOptions (void)
{
  if (options.noXinitOpt)
    port->genXINIT = 0;

  if (options.model == MODEL_LARGE) {
      port->mem.default_local_map = xdata;
      port->mem.default_globl_map = xdata;
    }
  else
    {
      port->mem.default_local_map = data;
      port->mem.default_globl_map = data;
    }

  istack->ptrType = FPOINTER;
}

static void
_m6502_setDefaultOptions (void)
{
  options.code_loc = 0x200;
  options.data_loc = 0x20;	/* zero page */
  options.xdata_loc = 0x8000;   /* 0 means immediately following data */
  options.stack_loc = 0x1ff;
  options.out_fmt = 's';        /* use motorola S19 output */

  options.omitFramePtr = 1;     /* no frame pointer (we use SP */
                                /* offsets instead)            */
}

static const char *
_m6502_getRegName (const struct reg_info *reg)
{
  if (reg)
    return reg->name;
  return "err";
}

static void
_m6502_genAssemblerPreamble (FILE * of)
{
  symbol *mainExists=newSymbol("main", 0);
  mainExists->block=0;

  if ((mainExists=findSymWithLevel(SymbolTab, mainExists)))
    {
      // global variables in zero page
      fprintf (of, "\t.globl __TEMP\n");
      fprintf (of, "\t.globl __BASEPTR\n");
      
      fprintf (of, "\t.area %s\n",port->mem.data_name);
      fprintf (of, "__TEMP:\t.ds %d\n", NUM_TEMP_REGS);
      fprintf (of, "__BASEPTR:\t.ds 2\n");
    }
}

static void
_m6502_genAssemblerEnd (FILE * of)
{
  if (options.out_fmt == 'E' && options.debug)
    {
      dwarf2FinalizeFile (of);
    }
}

static void
_m6502_genExtraAreas (FILE * asmFile, bool mainExists)
{
    fprintf (asmFile, "%s", iComments2);
    fprintf (asmFile, "; extended address mode data\n");
    fprintf (asmFile, "%s", iComments2);
    dbuf_write_and_destroy (&xdata->oBuf, asmFile);
}


//#if 0
/* Generate interrupt vector table. */
static int
_m6502_genIVT (struct dbuf_s * oBuf, symbol ** interrupts, int maxInterrupts)
{
  int i;

  dbuf_printf (oBuf, "\t.area\tCODEIVT (ABS)\n");
  dbuf_printf (oBuf, "\t.org\t0x%04x\n",
    (0xfffe - 2 - (maxInterrupts * 2)));

  for (i=maxInterrupts;i>1;i--)
    {
      if (interrupts[i])
        dbuf_printf (oBuf, "\t.dw\t%s\n", interrupts[i]->rname);
      else
        dbuf_printf (oBuf, "\t.dw\t0xffff\n");
    }
  dbuf_printf (oBuf, "\t.dw\t%s", "__sdcc_gs_init_startup\n");
  if (maxInterrupts > 0)
    {
      if (interrupts[0])
        dbuf_printf (oBuf, "\t.dw\t%s\n", interrupts[0]->rname);
      else
        dbuf_printf (oBuf, "\t.dw\t0xffff\n");
    }

  return true;
}

/* Generate code to copy XINIT to XISEG */
static void _m6502_genXINIT (FILE * of) {
  fprintf (of, ";       _m6502_genXINIT() start\n");
  fprintf (of, ";       _m6502_genXINIT() end\n");
}

//#endif

/* Do CSE estimation */
static bool cseCostEstimation (iCode *ic, iCode *pdic)
{
    operand *result = IC_RESULT(ic);
    sym_link *result_type = operandType(result);

    /* if it is a pointer then return ok for now */
    if (IC_RESULT(ic) && IS_PTR(result_type)) return 1;

    if (ic->op == ADDRESS_OF)
      return 0;

    /* if bitwise | add & subtract then no since m6502 is pretty good at it
       so we will cse only if they are local (i.e. both ic & pdic belong to
       the same basic block */
    if (IS_BITWISE_OP(ic) || ic->op == '+' || ic->op == '-') {
        /* then if they are the same Basic block then ok */
        if (ic->eBBlockNum == pdic->eBBlockNum) return 1;
        else return 0;
    }

    /* for others it is cheaper to do the cse */
    return 1;
}

/* Indicate which extended bit operations this port supports */
static bool
hasExtBitOp (int op, int size)
{
  // TODO: doesn't seem to use RLC/RRC
  if (op == RRC
      || op == RLC
      //|| (op == SWAP && size <= 2)
      // TODO?
      //|| op == GETABIT
      //|| op == GETBYTE
      //|| op == GETWORD
     )
    return true;
  else
    return false;
}

/* Indicate the expense of an access to an output storage class */
static int
oclsExpense (struct memmap *oclass)
{
  if (IN_DIRSPACE (oclass))     /* direct addressing mode is fastest */
    return -2;
  if (IN_FARSPACE (oclass))     /* extended addressing mode is almost at fast */
    return -1;
  if (oclass == istack)         /* stack is the slowest */
    return 2;

  return 0; /* anything we missed */
}

/*----------------------------------------------------------------------*/
/* m6502_dwarfRegNum - return the DWARF register number for a register.  */
/*   These are defined for the M6502 in "Motorola 8- and 16-bit Embedded */
/*   Application Binary Interface (M8/16EABI)"                          */
/*----------------------------------------------------------------------*/
static int
m6502_dwarfRegNum (const struct reg_info *reg)
{
  switch (reg->rIdx)
    {
    case A_IDX: return 0;
    case Y_IDX: return 1;
    case X_IDX: return 2;
    case CND_IDX: return 17;
    case SP_IDX: return 15;
    }
  return -1;
}

static bool
_hasNativeMulFor (iCode *ic, sym_link *left, sym_link *right)
{
  return false;
}

typedef struct asmLineNode
  {
    int size;
  }
asmLineNode;

static asmLineNode *
newAsmLineNode (void)
{
  asmLineNode *aln;

  aln = Safe_alloc ( sizeof (asmLineNode));
  aln->size = 0;

  return aln;
}

/* These must be kept sorted by opcode name */
static m6502opcodedata m6502opcodeDataTable[] =
  {
    {".db",   M6502OP_INH, 0,     0 }, /* used by the code generator only in the jump table */
    {"adc",   M6502OP_REG, A_IDX, 0xc3 },
    {"and",   M6502OP_REG, A_IDX, 0x82 },
    {"asl",   M6502OP_RMW, 0,     0x83 },
    {"bbr",   M6502OP_BBR, 0,     0 }, // Rockwell and WDC only
    {"bbs",   M6502OP_BBR, 0,     0 }, // Rockwell and WDC only
    {"bcc",   M6502OP_BR,  0,     0 },
    {"bcs",   M6502OP_BR,  0,     0 },
    {"beq",   M6502OP_BR,  0,     0 },
    {"bit",   M6502OP_REG, 0,     0xc2 },
    {"bmi",   M6502OP_BR,  0,     0 },
    {"bne",   M6502OP_BR,  0,     0 },
    {"bpl",   M6502OP_BR,  0,     0 },
    {"brk",   M6502OP_INH, 0,     0 },
    {"bvc",   M6502OP_BR,  0,     0 },
    {"bvs",   M6502OP_BR,  0,     0 },
    {"bra",   M6502OP_BR,  0,     0 }, // 65C02 only
    {"clc",   M6502OP_INH, 0,     0x01 },
    {"cld",   M6502OP_INH, 0,     0x80 },
    {"cli",   M6502OP_INH, 0,     0x04 },
    {"clv",   M6502OP_INH, 0,     0x40 },
    {"cmp",   M6502OP_REG, 0,     0xc3 },
    {"cpx",   M6502OP_REG, 0,     0xc3 },
    {"cpy",   M6502OP_REG, 0,     0xc3 },
    {"dec",   M6502OP_RMW, 0,     0x82 },
    {"dex",   M6502OP_IDD, X_IDX, 0x82 },
    {"dey",   M6502OP_IDD, Y_IDX, 0x82 },
    {"eor",   M6502OP_REG, A_IDX, 0x82 },
    {"inc",   M6502OP_RMW, 0,     0x82 },
    {"inx",   M6502OP_IDI, X_IDX, 0x82 },
    {"iny",   M6502OP_IDI, Y_IDX, 0x82 },
    {"jmp",   M6502OP_JMP, 0,     0 },
    {"jsr",   M6502OP_JMP, 0,     0 },
    {"lda",   M6502OP_LD , A_IDX, 0x82 },
    {"ldx",   M6502OP_LD , X_IDX, 0x82 },
    {"ldy",   M6502OP_LD , Y_IDX, 0x82 },
    {"lsr",   M6502OP_RMW, 0,     0x83 },
    {"nop",   M6502OP_INH, 0,     0 },
    {"ora",   M6502OP_REG, A_IDX, 0x82 },
    {"pha",   M6502OP_SPH, 0,     0 },
    {"php",   M6502OP_SPH, 0,     0 },
    {"phy",   M6502OP_SPH, 0,     0 }, // 65C02 only
    {"phx",   M6502OP_SPH, 0,     0 }, // 65C02 only
    {"pla",   M6502OP_SPL, A_IDX, 0x82 },
    {"plp",   M6502OP_SPL, 0,     0xdf },
    {"ply",   M6502OP_SPL, Y_IDX, 0x82 }, // 65C02 only
    {"plx",   M6502OP_SPL, X_IDX, 0x82 }, // 65C02 only
    {"rmb",   M6502OP_REG, 0,     0 }, // Rockwell and WDC only
    {"rol",   M6502OP_RMW, 0,     0x83 },
    {"ror",   M6502OP_RMW, 0,     0x83 },
    {"rti",   M6502OP_INH, 0,     0xdf },
    {"rts",   M6502OP_INH, 0,     0 },
    {"sbc",   M6502OP_REG, A_IDX, 0xc3 },
    {"sec",   M6502OP_INH, 0,     0x01 },
    {"sed",   M6502OP_INH, 0,     0x08 },
    {"sei",   M6502OP_INH, 0,     0x04 },
    {"smb",   M6502OP_REG, 0,     0 }, // Rockwell and WDC only
    {"sta",   M6502OP_ST , 0,     0 },
    {"stp",   M6502OP_INH, 0,     0 }, // WDC only
    {"stx",   M6502OP_ST , 0,     0 },
    {"sty",   M6502OP_ST , 0,     0 },
    {"stz",   M6502OP_ST , 0,     0 }, // 65C02 only
    {"tax",   M6502OP_INH, X_IDX, 0x82 },
    {"tay",   M6502OP_INH, Y_IDX, 0x82 },
    {"trb",   M6502OP_REG, 0,     0 }, // 65C02 only
    {"tsb",   M6502OP_REG, 0,     0 }, // 65C02 only
    {"tsx",   M6502OP_INH, X_IDX, 0x82 },
    {"txa",   M6502OP_INH, A_IDX, 0x82 },
    {"txs",   M6502OP_INH, 0,     0 },
    {"tya",   M6502OP_INH, A_IDX, 0x82 },
    {"wai",   M6502OP_INH, 0,     0 }  // WDC only
  };

static int
m6502_opcodeCompare (const void *key, const void *member)
{
  return strcmp((const char *)key, ((m6502opcodedata *)member)->name);
}


const m6502opcodedata *m6502_getOpcodeData(const char *inst)
{
  
  return   bsearch (inst, m6502opcodeDataTable,
                    sizeof(m6502opcodeDataTable)/sizeof(m6502opcodedata),
                    sizeof(m6502opcodedata), m6502_opcodeCompare);
}

int
m6502_opcodeSize(const m6502opcodedata *opcode, const char *arg)
{
  switch (opcode->type)
    {
      case M6502OP_INH: /* Inherent addressing mode */
      case M6502OP_SPH:
      case M6502OP_SPL:
      case M6502OP_IDD:
      case M6502OP_IDI:
        return 1;
        
      case M6502OP_BR:  /* Branch (1 byte signed offset) */
        return 2;
        
      case M6502OP_BBR:  /* Branch on bit (1 byte signed offset) */
        return 3;

      case M6502OP_RMW: /* read/modify/write instructions */
        if (!strcmp(arg, "a"))  /* accumulator */
          return 1;
     	if (arg[0] == '*') /* Zero page */
    	  return 2;
        return 3;  /* absolute */
        
      case M6502OP_REG: /* standard instruction */
      case M6502OP_LD:
      case M6502OP_ST:
        if (arg[0] == '#') /* Immediate addressing mode */
	      return 2;
        if (arg[0] == '*') /* Zero page */
	      return 2;
        if (arg[0] == '[') /* indirect */
          return 2;
	return 3; /* Otherwise, must be extended addressing mode */
	    
      case M6502OP_JMP:
        return 3;

      default:
         werror (E_INTERNAL_ERROR, __FILE__, __LINE__, "unknown instruction type in m6502_opcodeSize");
         return 3;
    }
}

/*--------------------------------------------------------------------*/
/* Given an instruction and its first two operands, compute the       */
/* instruction size. There are a few cases where it's too complicated */
/* to distinguish between an 8-bit offset and 16-bit offset; in these */
/* cases we conservatively assume the 16-bit offset size.             */
/*--------------------------------------------------------------------*/
static int
m6502_instructionSize(const char *inst, const char *op1, const char *op2)
{
  const m6502opcodedata *opcode = m6502_getOpcodeData(inst);

  if (!opcode)
    return 999;

  //  printf("op: %s - %s - %s\n",inst,op1, op2);

  return m6502_opcodeSize(opcode, op1);
}


static asmLineNode *
m6502_asmLineNodeFromLineNode (lineNode *ln)
{
  asmLineNode *aln = newAsmLineNode();
  char *op, op1[256], op2[256];
  int opsize;
  const char *p;
  char inst[8];

  p = ln->line;

  while (*p && isspace(*p)) p++;
  for (op = inst, opsize=1; *p; p++)
    {
      if (isspace(*p) || *p == ';' || *p == ':' || *p == '=')
        break;
      else
        if (opsize < sizeof(inst))
          *op++ = tolower(*p), opsize++;
    }
  *op = '\0';

  if (*p == ':' || *p == '=')
    return aln;

  while (*p && isspace(*p)) p++;
  if (*p == '=')
    return aln;

  if(*p==';') {
    op1[0]=0;
    op2[0]=0;
    aln->size = m6502_instructionSize(inst, op1, op2);
    return aln;
  }

  for (op = op1, opsize=1; *p && *p != ',' && *p != ';'; p++)
    {
      if (!isspace(*p) && opsize < sizeof(op1))
        *op++ = tolower(*p), opsize++;
    }
  *op = '\0';

  if (*p == ',') p++;
  if (*p == ';') {
    op2[0]=0;
    aln->size = m6502_instructionSize(inst, op1, op2);
    return aln;
  }

  
  for (op = op2, opsize=1; *p && *p != ',' && *p != ';' ; p++)
    {
      if (!isspace(*p) && opsize < sizeof(op2))
        *op++ = tolower(*p), opsize++;
    }
  *op = '\0';

  aln->size = m6502_instructionSize(inst, op1, op2);

  return aln;
}

static int
m6502_getInstructionSize (lineNode *line)
{
  if (!line->aln)
    line->aln = (asmLineNodeBase *) m6502_asmLineNodeFromLineNode (line);

  return line->aln->size;
}

/** $1 is always the basename.
    $2 is always the output file.
    $3 varies
    $l is the list of extra options that should be there somewhere...
    MUST be terminated with a NULL.
*/
static const char *_linkCmd[] =
{
  "sdld6808", "-nf", "$1", NULL
};

/* $3 is replaced by assembler.debug_opts resp. port->assembler.plain_opts */
static const char *_asmCmd[] =
{
  "sdas6500", "$l", "$3", "$2", "$1.asm", NULL
};

static const char *const _crt[] = { "crt0.rel", NULL, };
static const char * const _libs_m6502[] = { "mos6502", NULL, };
static const char * const _libs_m65c02[] = { "mos65c02", NULL, };

/* Globals */
PORT mos6502_port =
{
  TARGET_ID_MOS6502,
  "mos6502",
  "MOS 6502",                       /* Target name */
  NULL,                         /* Processor name */
  {
    glue,
    false,                      /* Emit glue around main */
    MODEL_SMALL | MODEL_LARGE,
    MODEL_LARGE,
    NULL,                       /* model == target */
  },
  {
    _asmCmd,
    NULL,
    "-plosgffwy",               /* Options with debug */
    "-plosgffw",                /* Options without debug */
    0,
    ".asm",
    NULL                        /* no do_assemble function */
  },
  {                             /* Linker */
    _linkCmd,
    NULL,
    NULL,
    ".rel",                     /* object file extension */
    1,                          /* need linker script */
    _crt,                       /* crt */
    _libs_m6502,                 /* libs */
  },
  {                             /* Peephole optimizer */
    _m6502_defaultRules,
    m6502_getInstructionSize,
  },
  // TODO: banked func ptr?
  {
    /* Sizes: char, short, int, long, long long, near ptr, far ptr, gptr, func ptr, banked func ptr, bit, float */
    1, 2, 2, 4, 8, 2, 2, 2, 2, 0, 1, 4
  },
  /* tags for generic pointers */
  { 0x00, 0x00, 0x00, 0x00 },           /* far, near, xstack, code */
  {
    "XSEG",
    "STACK",
    "CSEG    (CODE)",
    "DSEG    (PAG)",
    NULL, /* idata */
    NULL, /* pdata */
    "XSEG",
    NULL, /* bit */
    "RSEG    (ABS)",
    "GSINIT  (CODE)",
    "OSEG    (PAG, OVR)",
    "GSFINAL (CODE)",
    "HOME    (CODE)",
    "XISEG",              // initialized xdata
    "XINIT   (CODE)",     // a code copy of xiseg
    "CONST   (CODE)",     // const_name - const data (code or not)
    "CABS    (ABS,CODE)", // cabs_name - const absolute data (code or not)
    "XABS    (ABS)",      // xabs_name - absolute xdata
    "IABS    (ABS)",      // iabs_name - absolute data
    NULL,                 // name of segment for initialized variables
    NULL,                 // name of segment for copies of initialized variables in code space
    NULL,
    NULL,
    1,
    1                     // No fancy alignments supported.
  },
  { _m6502_genExtraAreas,
    NULL },
  0,                      // ABI revision
  {
    -1,         /* direction (-1 = stack grows down) */
    0,          /* bank_overhead (switch between register banks) */
    4,          /* isr_overhead */
    2,          /* call_overhead */
    0,          /* reent_overhead */
    0,          /* banked_overhead (switch between code banks) */
    1           /* sp is offset by 1 from last item pushed */
  },
  {
    5, false // TODO: 5 max shift?
  },
  {
    m6502_emitDebuggerSymbol,
    {
      m6502_dwarfRegNum,
      NULL,
      NULL,
      4,                        /* addressSize */
      14,                       /* regNumRet */
      15,                       /* regNumSP */
      -1,                       /* regNumBP */
      1,                        /* offsetSP */
    },
  },
  {
    256,        /* maxCount */
    2,          /* sizeofElement */
    {8,16,32},  /* sizeofMatchJump[] */
    {8,16,32},  /* sizeofRangeCompare[] */
    5,          /* sizeofSubtract */
    10,         /* sizeofDispatch */
  },
  "_",
  _m6502_init,
  _m6502_parseOptions,
  _mos6502_options,
  NULL,
  _m6502_finaliseOptions,
  _m6502_setDefaultOptions,
  m6502_assignRegisters,
  _m6502_getRegName,
  0,
  NULL,
  _keywords,
  _m6502_genAssemblerPreamble,
  _m6502_genAssemblerEnd,        /* no genAssemblerEnd */
  _m6502_genIVT,
  _m6502_genXINIT,
  NULL,                         /* genInitStartup */
  _m6502_reset_regparm,
  _m6502_regparm,
  NULL,                         /* process_pragma */
  NULL,                         /* getMangledFunctionName */
  _hasNativeMulFor,             /* hasNativeMulFor */
  hasExtBitOp,                  /* hasExtBitOp */
  oclsExpense,                  /* oclsExpense */
  true,                         /* use_dw_for_init */
  true,                         /* little_endian */
  0,                            /* leave lt */
  0,                            /* leave gt */
  1,                            /* transform <= to ! > */
  1,                            /* transform >= to ! < */
  1,                            /* transform != to !(a == b) */
  0,                            /* leave == */
  false,                        /* No array initializer support. */
  cseCostEstimation,
  NULL,                         /* no builtin functions */
  GPOINTER,                     /* treat unqualified pointers as "generic" pointers */
  1,                            /* reset labelKey to 1 */
  1,                            /* globals & local statics allowed */
  3,                            /* Number of registers handled in the tree-decomposition-based register allocator in SDCCralloc.hpp */
  PORT_MAGIC
};

PORT mos65c02_port =
{
  TARGET_ID_MOS65C02,
  "mos65c02",
  "WDC 65C02",                        /* Target name */
  NULL,                         /* Processor name */
  {
    glue,
    false,                      /* Emit glue around main */
    MODEL_SMALL | MODEL_LARGE,
    MODEL_LARGE,
    NULL,                       /* model == target */
  },
  {
    _asmCmd,
    NULL,
    "-plosgffwy",               /* Options with debug */
    "-plosgffw",                /* Options without debug */
    0,
    ".asm",
    NULL                        /* no do_assemble function */
  },
  {                             /* Linker */
    _linkCmd,
    NULL,
    NULL,
    ".rel",
    1,
    NULL,                       /* crt */
    _libs_m65c02,                  /* libs */
  },
  {                             /* Peephole optimizer */
    _m65c02_defaultRules,
    m6502_getInstructionSize,
  },
  {
    /* Sizes: char, short, int, long, long long, near ptr, far ptr, gptr, func ptr, banked func ptr, bit, float */
    1, 2, 2, 4, 8, 2, 2, 2, 2, 0, 1, 4
  },
  /* tags for generic pointers */
  { 0x00, 0x00, 0x00, 0x00 },           /* far, near, xstack, code */
  {
    "XSEG",
    "STACK",
    "CSEG    (CODE)",
    "DSEG    (PAG)",
    NULL, /* idata */
    NULL, /* pdata */
    "XSEG",
    NULL, /* bit */
    "RSEG    (ABS)",
    "GSINIT  (CODE)",
    "OSEG    (PAG, OVR)",
    "GSFINAL (CODE)",
    "HOME    (CODE)",
    "XISEG",              // initialized xdata
    "XINIT   (CODE)",     // a code copy of xiseg
    "CONST   (CODE)",     // const_name - const data (code or not)
    "CABS    (ABS,CODE)", // cabs_name - const absolute data (code or not)
    "XABS    (ABS)",      // xabs_name - absolute xdata
    "IABS    (ABS)",      // iabs_name - absolute data
    NULL,                 // name of segment for initialized variables
    NULL,                 // name of segment for copies of initialized variables in code space
    NULL,
    NULL,
    1,                    /* CODE  is read-only */
    1                     // No fancy alignments supported.
  },
  { _m6502_genExtraAreas,
    NULL },
  0,                      // ABI revision
  {
    -1,         /* direction (-1 = stack grows down) */
    0,          /* bank_overhead (switch between register banks) */
    4,          /* isr_overhead */
    2,          /* call_overhead */
    0,          /* reent_overhead */
    0,          /* banked_overhead (switch between code banks) */
    1           /* sp is offset by 1 from last item pushed */
  },
  {
    5, false
  },
  {
    m6502_emitDebuggerSymbol,
    {
      m6502_dwarfRegNum,
      NULL,
      NULL,
      4,                        /* addressSize */
      14,                       /* regNumRet */
      15,                       /* regNumSP */
      -1,                       /* regNumBP */
      1,                        /* offsetSP */
    },
  },
  {
    256,        /* maxCount */
    2,          /* sizeofElement */
    {8,16,32},  /* sizeofMatchJump[] */
    {8,16,32},  /* sizeofRangeCompare[] */
    5,          /* sizeofSubtract */
    10,         /* sizeofDispatch */
  },
  "_",
  _m65c02_init,
  _m6502_parseOptions,
  _mos6502_options,
  NULL,
  _m6502_finaliseOptions,
  _m6502_setDefaultOptions,
  m6502_assignRegisters,
  _m6502_getRegName,
  0,
  NULL,
  _keywords,
  _m6502_genAssemblerPreamble,
  _m6502_genAssemblerEnd,        /* no genAssemblerEnd */
  _m6502_genIVT,
  _m6502_genXINIT,
  NULL,                         /* genInitStartup */
  _m6502_reset_regparm,
  _m6502_regparm,
  NULL,                         /* process_pragma */
  NULL,                         /* getMangledFunctionName */
  _hasNativeMulFor,             /* hasNativeMulFor */
  hasExtBitOp,                  /* hasExtBitOp */
  oclsExpense,                  /* oclsExpense */
  true,                         /* use_dw_for_init */
  true,                         /* little_endian */
  0,                            /* leave lt */
  0,                            /* leave gt */
  1,                            /* transform <= to ! > */
  1,                            /* transform >= to ! < */
  1,                            /* transform != to !(a == b) */
  0,                            /* leave == */
  false,                        /* No array initializer support. */
  cseCostEstimation,
  NULL,                         /* no builtin functions */
  GPOINTER,                     /* treat unqualified pointers as "generic" pointers */
  1,                            /* reset labelKey to 1 */
  1,                            /* globals & local statics allowed */
  3,                            /* Number of registers handled in the tree-decomposition-based register allocator in SDCCralloc.hpp */
  PORT_MAGIC
};

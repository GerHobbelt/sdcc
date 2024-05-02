/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 27 "src/SDCC.y"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "SDCCglobl.h"
#include "SDCCattr.h"
#include "SDCCsymt.h"
#include "SDCChasht.h"
#include "SDCCval.h"
#include "SDCCmem.h"
#include "SDCCast.h"
#include "port.h"
#include "newalloc.h"
#include "SDCCerr.h"
#include "SDCCutil.h"
#include "SDCCbtree.h"
#include "SDCCopt.h"
#include "dbuf_string.h"

extern int yyerror (char *);
extern FILE     *yyin;
long NestLevel = 0;     /* current NestLevel       */
int stackPtr  = 1;      /* stack pointer           */
int xstackPtr = 0;      /* xstack pointer          */
int reentrant = 0;
int blockNo   = 0;      /* sequential block number  */
int currBlockno=0;
int inCriticalFunction = 0;
int inCriticalBlock = 0;
int seqPointNo= 1;      /* sequence point number */
int ignoreTypedefType=0;
extern int yylex();
int yyparse(void);
extern int noLineno;
char lbuff[1024];       /* local buffer */
char function_name[256] = {0};

/* break & continue stacks */
STACK_DCL(continueStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(breakStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(forStack  ,symbol *,MAX_NEST_LEVEL)
STACK_DCL(swStk   ,ast   *,MAX_NEST_LEVEL)
STACK_DCL(blockNum,int,MAX_NEST_LEVEL*3)

value *cenum = NULL;        /* current enumeration  type chain*/
bool uselessDecl = true;

#define YYDEBUG 1


#line 122 "src/SDCCy.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "SDCCy.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_TYPE_NAME = 4,                  /* TYPE_NAME  */
  YYSYMBOL_ADDRSPACE_NAME = 5,             /* ADDRSPACE_NAME  */
  YYSYMBOL_CONSTANT = 6,                   /* CONSTANT  */
  YYSYMBOL_SIZEOF = 7,                     /* SIZEOF  */
  YYSYMBOL_OFFSETOF = 8,                   /* OFFSETOF  */
  YYSYMBOL_PTR_OP = 9,                     /* PTR_OP  */
  YYSYMBOL_INC_OP = 10,                    /* INC_OP  */
  YYSYMBOL_DEC_OP = 11,                    /* DEC_OP  */
  YYSYMBOL_LEFT_OP = 12,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 13,                  /* RIGHT_OP  */
  YYSYMBOL_LE_OP = 14,                     /* LE_OP  */
  YYSYMBOL_GE_OP = 15,                     /* GE_OP  */
  YYSYMBOL_EQ_OP = 16,                     /* EQ_OP  */
  YYSYMBOL_NE_OP = 17,                     /* NE_OP  */
  YYSYMBOL_AND_OP = 18,                    /* AND_OP  */
  YYSYMBOL_OR_OP = 19,                     /* OR_OP  */
  YYSYMBOL_ATTR_START = 20,                /* ATTR_START  */
  YYSYMBOL_TOK_SEP = 21,                   /* TOK_SEP  */
  YYSYMBOL_MUL_ASSIGN = 22,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 23,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 24,                /* MOD_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 25,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 26,                /* SUB_ASSIGN  */
  YYSYMBOL_LEFT_ASSIGN = 27,               /* LEFT_ASSIGN  */
  YYSYMBOL_RIGHT_ASSIGN = 28,              /* RIGHT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 29,                /* AND_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 30,                /* XOR_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 31,                 /* OR_ASSIGN  */
  YYSYMBOL_TYPEDEF = 32,                   /* TYPEDEF  */
  YYSYMBOL_EXTERN = 33,                    /* EXTERN  */
  YYSYMBOL_STATIC = 34,                    /* STATIC  */
  YYSYMBOL_AUTO = 35,                      /* AUTO  */
  YYSYMBOL_REGISTER = 36,                  /* REGISTER  */
  YYSYMBOL_CONSTEXPR = 37,                 /* CONSTEXPR  */
  YYSYMBOL_CODE = 38,                      /* CODE  */
  YYSYMBOL_EEPROM = 39,                    /* EEPROM  */
  YYSYMBOL_INTERRUPT = 40,                 /* INTERRUPT  */
  YYSYMBOL_SFR = 41,                       /* SFR  */
  YYSYMBOL_SFR16 = 42,                     /* SFR16  */
  YYSYMBOL_SFR32 = 43,                     /* SFR32  */
  YYSYMBOL_ADDRESSMOD = 44,                /* ADDRESSMOD  */
  YYSYMBOL_AT = 45,                        /* AT  */
  YYSYMBOL_SBIT = 46,                      /* SBIT  */
  YYSYMBOL_REENTRANT = 47,                 /* REENTRANT  */
  YYSYMBOL_USING = 48,                     /* USING  */
  YYSYMBOL_XDATA = 49,                     /* XDATA  */
  YYSYMBOL_DATA = 50,                      /* DATA  */
  YYSYMBOL_IDATA = 51,                     /* IDATA  */
  YYSYMBOL_PDATA = 52,                     /* PDATA  */
  YYSYMBOL_ELLIPSIS = 53,                  /* ELLIPSIS  */
  YYSYMBOL_CRITICAL = 54,                  /* CRITICAL  */
  YYSYMBOL_NONBANKED = 55,                 /* NONBANKED  */
  YYSYMBOL_BANKED = 56,                    /* BANKED  */
  YYSYMBOL_SHADOWREGS = 57,                /* SHADOWREGS  */
  YYSYMBOL_SD_WPARAM = 58,                 /* SD_WPARAM  */
  YYSYMBOL_SD_BOOL = 59,                   /* SD_BOOL  */
  YYSYMBOL_SD_CHAR = 60,                   /* SD_CHAR  */
  YYSYMBOL_SD_SHORT = 61,                  /* SD_SHORT  */
  YYSYMBOL_SD_INT = 62,                    /* SD_INT  */
  YYSYMBOL_SD_LONG = 63,                   /* SD_LONG  */
  YYSYMBOL_SIGNED = 64,                    /* SIGNED  */
  YYSYMBOL_UNSIGNED = 65,                  /* UNSIGNED  */
  YYSYMBOL_SD_FLOAT = 66,                  /* SD_FLOAT  */
  YYSYMBOL_DOUBLE = 67,                    /* DOUBLE  */
  YYSYMBOL_FIXED16X16 = 68,                /* FIXED16X16  */
  YYSYMBOL_SD_CONST = 69,                  /* SD_CONST  */
  YYSYMBOL_VOLATILE = 70,                  /* VOLATILE  */
  YYSYMBOL_SD_VOID = 71,                   /* SD_VOID  */
  YYSYMBOL_BIT = 72,                       /* BIT  */
  YYSYMBOL_COMPLEX = 73,                   /* COMPLEX  */
  YYSYMBOL_IMAGINARY = 74,                 /* IMAGINARY  */
  YYSYMBOL_STRUCT = 75,                    /* STRUCT  */
  YYSYMBOL_UNION = 76,                     /* UNION  */
  YYSYMBOL_ENUM = 77,                      /* ENUM  */
  YYSYMBOL_RANGE = 78,                     /* RANGE  */
  YYSYMBOL_SD_FAR = 79,                    /* SD_FAR  */
  YYSYMBOL_CASE = 80,                      /* CASE  */
  YYSYMBOL_DEFAULT = 81,                   /* DEFAULT  */
  YYSYMBOL_IF = 82,                        /* IF  */
  YYSYMBOL_ELSE = 83,                      /* ELSE  */
  YYSYMBOL_SWITCH = 84,                    /* SWITCH  */
  YYSYMBOL_WHILE = 85,                     /* WHILE  */
  YYSYMBOL_DO = 86,                        /* DO  */
  YYSYMBOL_FOR = 87,                       /* FOR  */
  YYSYMBOL_GOTO = 88,                      /* GOTO  */
  YYSYMBOL_CONTINUE = 89,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 90,                     /* BREAK  */
  YYSYMBOL_RETURN = 91,                    /* RETURN  */
  YYSYMBOL_NAKED = 92,                     /* NAKED  */
  YYSYMBOL_JAVANATIVE = 93,                /* JAVANATIVE  */
  YYSYMBOL_OVERLAY = 94,                   /* OVERLAY  */
  YYSYMBOL_TRAP = 95,                      /* TRAP  */
  YYSYMBOL_STRING_LITERAL = 96,            /* STRING_LITERAL  */
  YYSYMBOL_INLINEASM = 97,                 /* INLINEASM  */
  YYSYMBOL_FUNC = 98,                      /* FUNC  */
  YYSYMBOL_IFX = 99,                       /* IFX  */
  YYSYMBOL_ADDRESS_OF = 100,               /* ADDRESS_OF  */
  YYSYMBOL_GET_VALUE_AT_ADDRESS = 101,     /* GET_VALUE_AT_ADDRESS  */
  YYSYMBOL_SET_VALUE_AT_ADDRESS = 102,     /* SET_VALUE_AT_ADDRESS  */
  YYSYMBOL_SPIL = 103,                     /* SPIL  */
  YYSYMBOL_UNSPIL = 104,                   /* UNSPIL  */
  YYSYMBOL_GETABIT = 105,                  /* GETABIT  */
  YYSYMBOL_GETBYTE = 106,                  /* GETBYTE  */
  YYSYMBOL_GETWORD = 107,                  /* GETWORD  */
  YYSYMBOL_BITWISEAND = 108,               /* BITWISEAND  */
  YYSYMBOL_UNARYMINUS = 109,               /* UNARYMINUS  */
  YYSYMBOL_IPUSH = 110,                    /* IPUSH  */
  YYSYMBOL_IPUSH_VALUE_AT_ADDRESS = 111,   /* IPUSH_VALUE_AT_ADDRESS  */
  YYSYMBOL_IPOP = 112,                     /* IPOP  */
  YYSYMBOL_PCALL = 113,                    /* PCALL  */
  YYSYMBOL_ENDFUNCTION = 114,              /* ENDFUNCTION  */
  YYSYMBOL_JUMPTABLE = 115,                /* JUMPTABLE  */
  YYSYMBOL_ROT = 116,                      /* ROT  */
  YYSYMBOL_CAST = 117,                     /* CAST  */
  YYSYMBOL_CALL = 118,                     /* CALL  */
  YYSYMBOL_PARAM = 119,                    /* PARAM  */
  YYSYMBOL_NULLOP = 120,                   /* NULLOP  */
  YYSYMBOL_BLOCK = 121,                    /* BLOCK  */
  YYSYMBOL_LABEL = 122,                    /* LABEL  */
  YYSYMBOL_RECEIVE = 123,                  /* RECEIVE  */
  YYSYMBOL_SEND = 124,                     /* SEND  */
  YYSYMBOL_ARRAYINIT = 125,                /* ARRAYINIT  */
  YYSYMBOL_DUMMY_READ_VOLATILE = 126,      /* DUMMY_READ_VOLATILE  */
  YYSYMBOL_ENDCRITICAL = 127,              /* ENDCRITICAL  */
  YYSYMBOL_INLINE = 128,                   /* INLINE  */
  YYSYMBOL_RESTRICT = 129,                 /* RESTRICT  */
  YYSYMBOL_SMALLC = 130,                   /* SMALLC  */
  YYSYMBOL_RAISONANCE = 131,               /* RAISONANCE  */
  YYSYMBOL_IAR = 132,                      /* IAR  */
  YYSYMBOL_COSMIC = 133,                   /* COSMIC  */
  YYSYMBOL_SDCCCALL = 134,                 /* SDCCCALL  */
  YYSYMBOL_PRESERVES_REGS = 135,           /* PRESERVES_REGS  */
  YYSYMBOL_Z88DK_FASTCALL = 136,           /* Z88DK_FASTCALL  */
  YYSYMBOL_Z88DK_CALLEE = 137,             /* Z88DK_CALLEE  */
  YYSYMBOL_Z88DK_SHORTCALL = 138,          /* Z88DK_SHORTCALL  */
  YYSYMBOL_Z88DK_PARAMS_OFFSET = 139,      /* Z88DK_PARAMS_OFFSET  */
  YYSYMBOL_ALIGNAS = 140,                  /* ALIGNAS  */
  YYSYMBOL_ALIGNOF = 141,                  /* ALIGNOF  */
  YYSYMBOL_ATOMIC = 142,                   /* ATOMIC  */
  YYSYMBOL_GENERIC = 143,                  /* GENERIC  */
  YYSYMBOL_NORETURN = 144,                 /* NORETURN  */
  YYSYMBOL_STATIC_ASSERT = 145,            /* STATIC_ASSERT  */
  YYSYMBOL_THREAD_LOCAL = 146,             /* THREAD_LOCAL  */
  YYSYMBOL_TOKEN_FALSE = 147,              /* TOKEN_FALSE  */
  YYSYMBOL_TOKEN_TRUE = 148,               /* TOKEN_TRUE  */
  YYSYMBOL_NULLPTR = 149,                  /* NULLPTR  */
  YYSYMBOL_TYPEOF = 150,                   /* TYPEOF  */
  YYSYMBOL_TYPEOF_UNQUAL = 151,            /* TYPEOF_UNQUAL  */
  YYSYMBOL_SD_BITINT = 152,                /* SD_BITINT  */
  YYSYMBOL_DECIMAL32 = 153,                /* DECIMAL32  */
  YYSYMBOL_DECIMAL64 = 154,                /* DECIMAL64  */
  YYSYMBOL_DECIMAL128 = 155,               /* DECIMAL128  */
  YYSYMBOL_ASM = 156,                      /* ASM  */
  YYSYMBOL_GENERIC_ASSOC_LIST = 157,       /* GENERIC_ASSOC_LIST  */
  YYSYMBOL_GENERIC_ASSOCIATION = 158,      /* GENERIC_ASSOCIATION  */
  YYSYMBOL_159_ = 159,                     /* '('  */
  YYSYMBOL_160_ = 160,                     /* ')'  */
  YYSYMBOL_161_ = 161,                     /* ','  */
  YYSYMBOL_162_ = 162,                     /* ':'  */
  YYSYMBOL_163_ = 163,                     /* '['  */
  YYSYMBOL_164_ = 164,                     /* ']'  */
  YYSYMBOL_165_ = 165,                     /* '.'  */
  YYSYMBOL_166_ = 166,                     /* '{'  */
  YYSYMBOL_167_ = 167,                     /* '}'  */
  YYSYMBOL_168_ = 168,                     /* '&'  */
  YYSYMBOL_169_ = 169,                     /* '*'  */
  YYSYMBOL_170_ = 170,                     /* '+'  */
  YYSYMBOL_171_ = 171,                     /* '-'  */
  YYSYMBOL_172_ = 172,                     /* '~'  */
  YYSYMBOL_173_ = 173,                     /* '!'  */
  YYSYMBOL_174_ = 174,                     /* '/'  */
  YYSYMBOL_175_ = 175,                     /* '%'  */
  YYSYMBOL_176_ = 176,                     /* '<'  */
  YYSYMBOL_177_ = 177,                     /* '>'  */
  YYSYMBOL_178_ = 178,                     /* '^'  */
  YYSYMBOL_179_ = 179,                     /* '|'  */
  YYSYMBOL_180_ = 180,                     /* '?'  */
  YYSYMBOL_181_ = 181,                     /* '='  */
  YYSYMBOL_182_ = 182,                     /* ';'  */
  YYSYMBOL_YYACCEPT = 183,                 /* $accept  */
  YYSYMBOL_primary_expression = 184,       /* primary_expression  */
  YYSYMBOL_predefined_constant = 185,      /* predefined_constant  */
  YYSYMBOL_generic_selection = 186,        /* generic_selection  */
  YYSYMBOL_generic_assoc_list = 187,       /* generic_assoc_list  */
  YYSYMBOL_generic_association = 188,      /* generic_association  */
  YYSYMBOL_postfix_expression = 189,       /* postfix_expression  */
  YYSYMBOL_190_1 = 190,                    /* $@1  */
  YYSYMBOL_191_2 = 191,                    /* $@2  */
  YYSYMBOL_argument_expr_list = 192,       /* argument_expr_list  */
  YYSYMBOL_unary_expression = 193,         /* unary_expression  */
  YYSYMBOL_unary_operator = 194,           /* unary_operator  */
  YYSYMBOL_cast_expression = 195,          /* cast_expression  */
  YYSYMBOL_multiplicative_expression = 196, /* multiplicative_expression  */
  YYSYMBOL_additive_expression = 197,      /* additive_expression  */
  YYSYMBOL_shift_expression = 198,         /* shift_expression  */
  YYSYMBOL_relational_expression = 199,    /* relational_expression  */
  YYSYMBOL_equality_expression = 200,      /* equality_expression  */
  YYSYMBOL_and_expression = 201,           /* and_expression  */
  YYSYMBOL_exclusive_or_expression = 202,  /* exclusive_or_expression  */
  YYSYMBOL_inclusive_or_expression = 203,  /* inclusive_or_expression  */
  YYSYMBOL_logical_and_expr = 204,         /* logical_and_expr  */
  YYSYMBOL_205_3 = 205,                    /* $@3  */
  YYSYMBOL_logical_or_expr = 206,          /* logical_or_expr  */
  YYSYMBOL_207_4 = 207,                    /* $@4  */
  YYSYMBOL_conditional_expr = 208,         /* conditional_expr  */
  YYSYMBOL_209_5 = 209,                    /* $@5  */
  YYSYMBOL_assignment_expr = 210,          /* assignment_expr  */
  YYSYMBOL_assignment_operator = 211,      /* assignment_operator  */
  YYSYMBOL_expression = 212,               /* expression  */
  YYSYMBOL_213_6 = 213,                    /* $@6  */
  YYSYMBOL_expression_opt = 214,           /* expression_opt  */
  YYSYMBOL_constant_expr = 215,            /* constant_expr  */
  YYSYMBOL_declaration = 216,              /* declaration  */
  YYSYMBOL_declaration_specifiers = 217,   /* declaration_specifiers  */
  YYSYMBOL_declaration_specifiers_ = 218,  /* declaration_specifiers_  */
  YYSYMBOL_init_declarator_list = 219,     /* init_declarator_list  */
  YYSYMBOL_init_declarator = 220,          /* init_declarator  */
  YYSYMBOL_attribute_declaration = 221,    /* attribute_declaration  */
  YYSYMBOL_storage_class_specifier = 222,  /* storage_class_specifier  */
  YYSYMBOL_type_specifier = 223,           /* type_specifier  */
  YYSYMBOL_typeof_specifier = 224,         /* typeof_specifier  */
  YYSYMBOL_struct_or_union_specifier = 225, /* struct_or_union_specifier  */
  YYSYMBOL_226_7 = 226,                    /* $@7  */
  YYSYMBOL_struct_or_union = 227,          /* struct_or_union  */
  YYSYMBOL_member_declaration_list = 228,  /* member_declaration_list  */
  YYSYMBOL_member_declaration = 229,       /* member_declaration  */
  YYSYMBOL_type_specifier_qualifier = 230, /* type_specifier_qualifier  */
  YYSYMBOL_member_declarator_list = 231,   /* member_declarator_list  */
  YYSYMBOL_member_declarator = 232,        /* member_declarator  */
  YYSYMBOL_enum_specifier = 233,           /* enum_specifier  */
  YYSYMBOL_enum_comma_opt = 234,           /* enum_comma_opt  */
  YYSYMBOL_enumerator_list = 235,          /* enumerator_list  */
  YYSYMBOL_enumerator = 236,               /* enumerator  */
  YYSYMBOL_type_qualifier = 237,           /* type_qualifier  */
  YYSYMBOL_function_specifier = 238,       /* function_specifier  */
  YYSYMBOL_alignment_specifier = 239,      /* alignment_specifier  */
  YYSYMBOL_declarator = 240,               /* declarator  */
  YYSYMBOL_direct_declarator = 241,        /* direct_declarator  */
  YYSYMBOL_declarator2 = 242,              /* declarator2  */
  YYSYMBOL_array_declarator = 243,         /* array_declarator  */
  YYSYMBOL_declarator2_function_attributes = 244, /* declarator2_function_attributes  */
  YYSYMBOL_function_declarator = 245,      /* function_declarator  */
  YYSYMBOL_246_8 = 246,                    /* $@8  */
  YYSYMBOL_pointer = 247,                  /* pointer  */
  YYSYMBOL_unqualified_pointer = 248,      /* unqualified_pointer  */
  YYSYMBOL_type_qualifier_list = 249,      /* type_qualifier_list  */
  YYSYMBOL_type_qualifier_list_opt = 250,  /* type_qualifier_list_opt  */
  YYSYMBOL_parameter_type_list = 251,      /* parameter_type_list  */
  YYSYMBOL_parameter_list = 252,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 253,    /* parameter_declaration  */
  YYSYMBOL_abstract_declarator = 254,      /* abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator = 255, /* direct_abstract_declarator  */
  YYSYMBOL_direct_abstract_declarator_opt = 256, /* direct_abstract_declarator_opt  */
  YYSYMBOL_array_abstract_declarator = 257, /* array_abstract_declarator  */
  YYSYMBOL_function_abstract_declarator = 258, /* function_abstract_declarator  */
  YYSYMBOL_259_9 = 259,                    /* $@9  */
  YYSYMBOL_initializer = 260,              /* initializer  */
  YYSYMBOL_initializer_list = 261,         /* initializer_list  */
  YYSYMBOL_designation_opt = 262,          /* designation_opt  */
  YYSYMBOL_designation = 263,              /* designation  */
  YYSYMBOL_designator_list = 264,          /* designator_list  */
  YYSYMBOL_designator = 265,               /* designator  */
  YYSYMBOL_static_assert_declaration = 266, /* static_assert_declaration  */
  YYSYMBOL_attribute_specifier_sequence = 267, /* attribute_specifier_sequence  */
  YYSYMBOL_attribute_specifier_sequence_opt = 268, /* attribute_specifier_sequence_opt  */
  YYSYMBOL_attribute_specifier = 269,      /* attribute_specifier  */
  YYSYMBOL_attribute_list = 270,           /* attribute_list  */
  YYSYMBOL_attribute = 271,                /* attribute  */
  YYSYMBOL_attribute_opt = 272,            /* attribute_opt  */
  YYSYMBOL_attribute_token = 273,          /* attribute_token  */
  YYSYMBOL_attribute_argument_clause = 274, /* attribute_argument_clause  */
  YYSYMBOL_balanced_token_sequence = 275,  /* balanced_token_sequence  */
  YYSYMBOL_balanced_token = 276,           /* balanced_token  */
  YYSYMBOL_statement = 277,                /* statement  */
  YYSYMBOL_unlabeled_statement = 278,      /* unlabeled_statement  */
  YYSYMBOL_primary_block = 279,            /* primary_block  */
  YYSYMBOL_secondary_block = 280,          /* secondary_block  */
  YYSYMBOL_labeled_statement = 281,        /* labeled_statement  */
  YYSYMBOL_label = 282,                    /* label  */
  YYSYMBOL_283_10 = 283,                   /* @10  */
  YYSYMBOL_start_block = 284,              /* start_block  */
  YYSYMBOL_end_block = 285,                /* end_block  */
  YYSYMBOL_compound_statement = 286,       /* compound_statement  */
  YYSYMBOL_block_item_list = 287,          /* block_item_list  */
  YYSYMBOL_expression_statement = 288,     /* expression_statement  */
  YYSYMBOL_else_statement = 289,           /* else_statement  */
  YYSYMBOL_selection_statement = 290,      /* selection_statement  */
  YYSYMBOL_291_11 = 291,                   /* $@11  */
  YYSYMBOL_292_12 = 292,                   /* @12  */
  YYSYMBOL_iteration_statement = 293,      /* iteration_statement  */
  YYSYMBOL_294_13 = 294,                   /* $@13  */
  YYSYMBOL_295_14 = 295,                   /* $@14  */
  YYSYMBOL_jump_statement = 296,           /* jump_statement  */
  YYSYMBOL_translation_unit = 297,         /* translation_unit  */
  YYSYMBOL_external_declaration = 298,     /* external_declaration  */
  YYSYMBOL_function_definition = 299,      /* function_definition  */
  YYSYMBOL_300_15 = 300,                   /* $@15  */
  YYSYMBOL_301_16 = 301,                   /* $@16  */
  YYSYMBOL_function_body = 302,            /* function_body  */
  YYSYMBOL_file = 303,                     /* file  */
  YYSYMBOL_function_attributes = 304,      /* function_attributes  */
  YYSYMBOL_function_attribute = 305,       /* function_attribute  */
  YYSYMBOL_offsetof_member_designator = 306, /* offsetof_member_designator  */
  YYSYMBOL_307_17 = 307,                   /* $@17  */
  YYSYMBOL_string_literal_val = 308,       /* string_literal_val  */
  YYSYMBOL_Interrupt_storage = 309,        /* Interrupt_storage  */
  YYSYMBOL_sfr_reg_bit = 310,              /* sfr_reg_bit  */
  YYSYMBOL_sfr_attributes = 311,           /* sfr_attributes  */
  YYSYMBOL_opt_stag = 312,                 /* opt_stag  */
  YYSYMBOL_stag = 313,                     /* stag  */
  YYSYMBOL_opt_assign_expr = 314,          /* opt_assign_expr  */
  YYSYMBOL_specifier_qualifier_list = 315, /* specifier_qualifier_list  */
  YYSYMBOL_type_specifier_list_ = 316,     /* type_specifier_list_  */
  YYSYMBOL_identifier_list = 317,          /* identifier_list  */
  YYSYMBOL_type_name = 318,                /* type_name  */
  YYSYMBOL_critical = 319,                 /* critical  */
  YYSYMBOL_critical_statement = 320,       /* critical_statement  */
  YYSYMBOL_statements_and_implicit = 321,  /* statements_and_implicit  */
  YYSYMBOL_declaration_after_statement = 322, /* declaration_after_statement  */
  YYSYMBOL_323_18 = 323,                   /* $@18  */
  YYSYMBOL_implicit_block = 324,           /* implicit_block  */
  YYSYMBOL_declaration_list = 325,         /* declaration_list  */
  YYSYMBOL_kr_declaration = 326,           /* kr_declaration  */
  YYSYMBOL_kr_declaration_list = 327,      /* kr_declaration_list  */
  YYSYMBOL_statement_list = 328,           /* statement_list  */
  YYSYMBOL_while = 329,                    /* while  */
  YYSYMBOL_do = 330,                       /* do  */
  YYSYMBOL_for = 331,                      /* for  */
  YYSYMBOL_asm_string_literal = 332,       /* asm_string_literal  */
  YYSYMBOL_asm_statement = 333,            /* asm_statement  */
  YYSYMBOL_addressmod = 334,               /* addressmod  */
  YYSYMBOL_identifier = 335                /* identifier  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  154
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   2960

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  183
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  153
/* YYNRULES -- Number of rules.  */
#define YYNRULES  408
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  658

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   413


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   173,     2,     2,     2,   175,   168,     2,
     159,   160,   169,   170,   161,   171,   165,   174,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   162,   182,
     176,   181,   177,   180,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   163,     2,   164,   178,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   166,   179,   167,   172,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   174,   174,   175,   176,   177,   178,   179,   183,   184,
     185,   189,   193,   194,   198,   199,   203,   204,   205,   207,
     211,   211,   218,   218,   225,   227,   229,   237,   245,   258,
     259,   263,   264,   265,   266,   275,   276,   277,   278,   279,
     283,   284,   285,   286,   287,   288,   292,   293,   297,   298,
     299,   300,   304,   305,   306,   310,   311,   312,   316,   317,
     318,   319,   320,   324,   325,   326,   330,   331,   335,   336,
     340,   341,   345,   346,   346,   351,   352,   352,   357,   358,
     358,   366,   367,   412,   413,   414,   415,   416,   417,   418,
     419,   420,   421,   422,   426,   427,   427,   431,   432,   436,
     442,   466,   508,   512,   518,   521,   522,   527,   528,   533,
     534,   542,   543,   547,   548,   552,   556,   560,   564,   568,
     573,   577,   581,   588,   593,   598,   603,   608,   613,   618,
     623,   628,   633,   639,   644,   648,   652,   656,   660,   664,
     669,   675,   684,   688,   693,   701,   708,   717,   720,   725,
     730,   741,   755,   754,   865,   895,   896,   900,   901,   914,
     939,   940,   941,   945,   946,   954,   955,   965,   979,   983,
     988,  1012,  1029,  1032,  1040,  1041,  1049,  1077,  1081,  1085,
    1089,  1093,  1097,  1101,  1105,  1109,  1113,  1117,  1124,  1128,
    1135,  1141,  1156,  1157,  1165,  1166,  1167,  1168,  1172,  1173,
    1174,  1178,  1203,  1227,  1252,  1278,  1279,  1311,  1324,  1323,
    1366,  1377,  1378,  1388,  1401,  1421,  1427,  1467,  1475,  1476,
    1484,  1487,  1494,  1495,  1499,  1500,  1508,  1525,  1535,  1536,
    1537,  1544,  1545,  1546,  1550,  1551,  1555,  1562,  1574,  1575,
    1587,  1589,  1588,  1619,  1620,  1628,  1629,  1633,  1634,  1643,
    1644,  1648,  1652,  1653,  1657,  1679,  1683,  1691,  1704,  1711,
    1719,  1722,  1729,  1738,  1742,  1755,  1759,  1767,  1770,  1777,
    1783,  1796,  1797,  1801,  1802,  1806,  1807,  1808,  1814,  1815,
    1820,  1821,  1825,  1829,  1830,  1834,  1838,  1842,  1849,  1856,
    1869,  1874,  1881,  1881,  1891,  1902,  1911,  1912,  1920,  1921,
    1922,  1926,  1927,  1931,  1932,  1937,  1937,  1945,  1945,  1971,
    1971,  1980,  1990,  2016,  2015,  2056,  2066,  2079,  2089,  2098,
    2112,  2113,  2117,  2121,  2142,  2150,  2149,  2169,  2168,  2199,
    2200,  2211,  2214,  2221,  2222,  2226,  2230,  2233,  2236,  2239,
    2242,  2245,  2251,  2254,  2257,  2263,  2269,  2275,  2278,  2281,
    2284,  2287,  2291,  2294,  2297,  2306,  2330,  2348,  2349,  2349,
    2356,  2363,  2390,  2394,  2395,  2410,  2418,  2422,  2430,  2441,
    2452,  2464,  2465,  2476,  2495,  2513,  2526,  2529,  2531,  2539,
    2540,  2548,  2556,  2582,  2593,  2602,  2603,  2612,  2612,  2623,
    2631,  2642,  2658,  2692,  2730,  2742,  2768,  2769,  2770,  2771,
    2774,  2788,  2803,  2828,  2832,  2842,  2855,  2866,  2884
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "TYPE_NAME", "ADDRSPACE_NAME", "CONSTANT", "SIZEOF", "OFFSETOF",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "ATTR_START", "TOK_SEP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CONSTEXPR", "CODE",
  "EEPROM", "INTERRUPT", "SFR", "SFR16", "SFR32", "ADDRESSMOD", "AT",
  "SBIT", "REENTRANT", "USING", "XDATA", "DATA", "IDATA", "PDATA",
  "ELLIPSIS", "CRITICAL", "NONBANKED", "BANKED", "SHADOWREGS", "SD_WPARAM",
  "SD_BOOL", "SD_CHAR", "SD_SHORT", "SD_INT", "SD_LONG", "SIGNED",
  "UNSIGNED", "SD_FLOAT", "DOUBLE", "FIXED16X16", "SD_CONST", "VOLATILE",
  "SD_VOID", "BIT", "COMPLEX", "IMAGINARY", "STRUCT", "UNION", "ENUM",
  "RANGE", "SD_FAR", "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE",
  "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN", "NAKED",
  "JAVANATIVE", "OVERLAY", "TRAP", "STRING_LITERAL", "INLINEASM", "FUNC",
  "IFX", "ADDRESS_OF", "GET_VALUE_AT_ADDRESS", "SET_VALUE_AT_ADDRESS",
  "SPIL", "UNSPIL", "GETABIT", "GETBYTE", "GETWORD", "BITWISEAND",
  "UNARYMINUS", "IPUSH", "IPUSH_VALUE_AT_ADDRESS", "IPOP", "PCALL",
  "ENDFUNCTION", "JUMPTABLE", "ROT", "CAST", "CALL", "PARAM", "NULLOP",
  "BLOCK", "LABEL", "RECEIVE", "SEND", "ARRAYINIT", "DUMMY_READ_VOLATILE",
  "ENDCRITICAL", "INLINE", "RESTRICT", "SMALLC", "RAISONANCE", "IAR",
  "COSMIC", "SDCCCALL", "PRESERVES_REGS", "Z88DK_FASTCALL", "Z88DK_CALLEE",
  "Z88DK_SHORTCALL", "Z88DK_PARAMS_OFFSET", "ALIGNAS", "ALIGNOF", "ATOMIC",
  "GENERIC", "NORETURN", "STATIC_ASSERT", "THREAD_LOCAL", "TOKEN_FALSE",
  "TOKEN_TRUE", "NULLPTR", "TYPEOF", "TYPEOF_UNQUAL", "SD_BITINT",
  "DECIMAL32", "DECIMAL64", "DECIMAL128", "ASM", "GENERIC_ASSOC_LIST",
  "GENERIC_ASSOCIATION", "'('", "')'", "','", "':'", "'['", "']'", "'.'",
  "'{'", "'}'", "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'",
  "'<'", "'>'", "'^'", "'|'", "'?'", "'='", "';'", "$accept",
  "primary_expression", "predefined_constant", "generic_selection",
  "generic_assoc_list", "generic_association", "postfix_expression", "$@1",
  "$@2", "argument_expr_list", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expr", "$@3", "logical_or_expr", "$@4", "conditional_expr",
  "$@5", "assignment_expr", "assignment_operator", "expression", "$@6",
  "expression_opt", "constant_expr", "declaration",
  "declaration_specifiers", "declaration_specifiers_",
  "init_declarator_list", "init_declarator", "attribute_declaration",
  "storage_class_specifier", "type_specifier", "typeof_specifier",
  "struct_or_union_specifier", "$@7", "struct_or_union",
  "member_declaration_list", "member_declaration",
  "type_specifier_qualifier", "member_declarator_list",
  "member_declarator", "enum_specifier", "enum_comma_opt",
  "enumerator_list", "enumerator", "type_qualifier", "function_specifier",
  "alignment_specifier", "declarator", "direct_declarator", "declarator2",
  "array_declarator", "declarator2_function_attributes",
  "function_declarator", "$@8", "pointer", "unqualified_pointer",
  "type_qualifier_list", "type_qualifier_list_opt", "parameter_type_list",
  "parameter_list", "parameter_declaration", "abstract_declarator",
  "direct_abstract_declarator", "direct_abstract_declarator_opt",
  "array_abstract_declarator", "function_abstract_declarator", "$@9",
  "initializer", "initializer_list", "designation_opt", "designation",
  "designator_list", "designator", "static_assert_declaration",
  "attribute_specifier_sequence", "attribute_specifier_sequence_opt",
  "attribute_specifier", "attribute_list", "attribute", "attribute_opt",
  "attribute_token", "attribute_argument_clause",
  "balanced_token_sequence", "balanced_token", "statement",
  "unlabeled_statement", "primary_block", "secondary_block",
  "labeled_statement", "label", "@10", "start_block", "end_block",
  "compound_statement", "block_item_list", "expression_statement",
  "else_statement", "selection_statement", "$@11", "@12",
  "iteration_statement", "$@13", "$@14", "jump_statement",
  "translation_unit", "external_declaration", "function_definition",
  "$@15", "$@16", "function_body", "file", "function_attributes",
  "function_attribute", "offsetof_member_designator", "$@17",
  "string_literal_val", "Interrupt_storage", "sfr_reg_bit",
  "sfr_attributes", "opt_stag", "stag", "opt_assign_expr",
  "specifier_qualifier_list", "type_specifier_list_", "identifier_list",
  "type_name", "critical", "critical_statement", "statements_and_implicit",
  "declaration_after_statement", "$@18", "implicit_block",
  "declaration_list", "kr_declaration", "kr_declaration_list",
  "statement_list", "while", "do", "for", "asm_string_literal",
  "asm_statement", "addressmod", "identifier", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-581)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-391)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    2091,  -581,  -581,  -581,    33,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,  -581,    20,  -581,  -581,    33,    59,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,     7,  -581,  -581,   -98,  -581,  -581,   -61,  -581,   -47,
     -39,     6,  -581,  -581,  -581,    54,  -581,  -581,    18,  -581,
    -581,  2687,  -581,  -581,  -581,    66,  2687,  -581,  -581,  2687,
    -581,  -581,    17,    36,    49,    66,  2766,    43,   428,  -581,
      11,  -581,  2091,  -581,  -581,   162,  -581,  -581,  -581,    58,
     -60,  -581,  -581,    44,   199,  -581,    45,  -581,  1850,    33,
      74,  1528,  1850,  1528,  1528,  1850,    89,  -581,  -101,  -581,
     -93,  -581,    66,    33,  -581,  -581,  2319,   611,    12,  -581,
    -581,    95,  -581,    97,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,  -581,   107,   112,  -581,
    -581,   123,   126,  2766,  -581,  -581,    17,   161,  -581,  -581,
     997,  -581,  -581,  -581,  -581,  -581,    33,   109,    39,  -581,
      33,    33,   142,  -581,  1909,   173,  1944,  1944,  -581,  -581,
     177,   179,   184,  -581,  -581,  -581,  1528,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,   252,  -581,  1850,  -581,
    -102,    61,   293,    48,   299,   192,   185,   190,   353,    21,
    -581,   214,  -581,  -581,   218,  -581,    66,    33,   221,    -6,
     229,   166,   103,  -581,  -581,   169,   233,   180,   237,   240,
     243,    54,  -581,  1543,  2319,  -581,   238,  -581,  -581,    54,
     633,  -581,  -581,  -581,  2319,  1259,  1147,  1607,  -581,  2687,
     188,  -581,  1850,  1850,  1850,    33,  1850,  1850,  -581,  1850,
     248,  -581,  -581,  -581,  -581,  -581,  -581,  -581,   148,  -581,
    -581,  -581,   230,  -581,  1528,  -581,  2687,  1528,  -581,  -581,
    1944,  2687,  1850,   191,   253,  -581,  -581,  -581,  1642,  1850,
    -581,  -581,  1850,  1850,  1850,  1850,  1850,  1850,  1850,  1850,
    1850,  1850,  1850,  1850,  1850,  1850,  1850,  1850,  -581,  -581,
    -581,  -581,    33,   247,   241,   218,  -581,  2270,    46,  -581,
     113,   255,  -581,  -581,  -581,   234,   327,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,  -581,  -581,  1850,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,   245,   114,  -581,  -581,
    -581,   261,   -66,  -581,   246,   272,  -581,   271,   254,  -581,
      18,  1122,   426,  -581,  -581,  -581,   267,  -581,  1086,  -581,
    -581,   806,   909,  -581,   273,  -581,  -581,  1259,  1850,  1850,
    -581,   277,    47,   283,   284,  -581,  -581,  -581,    33,   286,
     287,   288,   193,   291,   294,   297,  1850,  -581,  -581,  -581,
     298,   292,   301,   302,   304,   307,  -581,  1721,    33,  -581,
     305,   309,    -9,    33,  -581,  -581,  -581,  -102,  -102,    61,
      61,   293,   293,   293,   293,    48,    48,   299,   192,   185,
    1850,  1850,  1850,  -581,  -581,  1850,  -581,   295,  -581,   315,
     322,   113,   323,  1736,  -581,   324,  -581,  1850,  1850,    33,
    -581,   -77,  1543,  -581,    78,  -581,    66,  -581,  -581,   348,
    -581,   -46,  1850,  -581,   333,   334,  -581,  -581,  -581,    33,
     312,   314,  1184,  -581,  -581,  -581,  -581,  -581,   340,  1086,
     341,  -581,  1815,  -581,  -581,  -581,  1086,  -581,  -581,  -581,
    -581,  1006,  2462,  -581,  -581,   337,   354,  -581,  2141,  -581,
      63,  -581,  2511,  -581,  -581,  -581,  -581,  -581,  1850,  -581,
    -581,   326,   338,    33,   338,  1944,  -581,  2637,   146,  -581,
    -581,  -581,  1850,  -581,  -581,   190,   353,   194,  -581,  -581,
    -581,  -581,  -581,  2687,  -581,   355,   339,  -581,   356,  -581,
     158,  -581,  -581,  -581,  -581,    -1,  -581,  2805,  -581,   362,
    -581,   361,   363,  1850,  1850,   342,  -581,  -581,  -581,   -44,
    1850,  -581,   442,  1357,  -581,  -581,  2462,  -581,  -581,  -581,
    -581,   368,  -581,   105,  -581,   369,   371,   216,  -581,   372,
    -581,    67,  -581,  1850,   370,  -581,  -581,  -581,  -581,  1543,
    -581,  -581,  -581,    35,  2805,   357,  -581,  -581,   225,   227,
    -581,  -581,   231,   376,   359,  1850,  -581,  -581,  1850,  -581,
    -581,  1850,  -581,  2637,  1850,   170,  -581,  -581,  -581,  -581,
    1850,   -15,  -581,   374,  -581,  -581,  -581,  -581,  -581,  1850,
    1850,   364,   119,    33,  -581,  -581,  -581,  -581,  -581,    35,
    -581,  1850,  1086,  1086,  1086,   235,   365,  1850,  -581,  -581,
    -581,  -581,   454,  -581,  -581,   366,  1850,   383,  1086,  -581,
    -581,   384,  -581,  -581,  1086,  1086,  -581,  -581
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
     331,   408,   141,   181,   267,   116,   117,   118,   120,   121,
     122,   183,   184,   367,   369,   370,     0,     0,   365,   182,
     185,   186,   187,   133,   124,   125,   126,   127,   130,   131,
     128,   129,   143,   177,   179,   123,   144,   134,   135,   155,
     156,     0,   188,   178,     0,   180,   189,     0,   119,     0,
       0,     0,   136,   137,   138,     0,   217,   323,     0,   104,
     103,   105,   160,   142,   139,   260,   107,   140,   161,   109,
     162,   325,   192,     0,   260,   260,   205,     0,   211,   102,
       0,   259,   332,   320,   322,     0,   147,   366,   324,   260,
       0,   268,   263,   265,   269,   368,     0,   145,     0,     0,
     171,     0,     0,     0,     0,     0,     0,   100,     0,   111,
     327,   106,   261,   372,   108,   110,     0,   220,   208,   196,
     197,   363,   336,     0,   337,   341,   344,   342,   343,   338,
     339,   340,   346,   347,   348,   349,   350,     0,     0,   352,
     353,     0,     0,   206,   333,   345,   193,     0,   218,   215,
     213,   115,   258,   321,     1,   194,   267,     0,     0,   266,
       0,     0,     0,     3,     0,     0,     0,     0,   362,   361,
       0,     0,     0,     8,     9,    10,     0,    40,    41,    42,
      43,    44,    45,    16,     7,     6,    31,    46,     0,    48,
      52,    55,    58,    63,    66,    68,    70,    72,    75,    78,
      99,     0,     4,     2,   172,   174,   260,     0,     0,   381,
       0,     0,    46,    81,    94,     0,     0,     0,     0,     0,
     195,     0,   101,     0,     0,   152,   154,   373,   294,     0,
     260,   329,   326,   394,     0,   220,   221,     0,   207,     0,
       0,   379,     0,     0,     0,     0,     0,     0,   334,     0,
       0,   219,   216,   264,   262,   277,   276,   271,     0,   273,
     275,   270,     0,   406,     0,    35,     0,     0,    32,    33,
       0,     0,     0,     0,     0,    22,    24,    25,     0,     0,
      20,    34,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    73,    76,
      79,   146,   173,     0,   375,   172,   191,   234,   228,   382,
     229,     0,   232,   233,   190,     0,     0,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    83,     0,   148,
      95,   149,   150,   151,   132,   112,   113,   249,   243,   114,
     328,     0,     0,   383,     0,     0,   295,    98,     0,   391,
       0,   261,     0,   396,   397,   296,     0,   280,   260,   283,
     298,   260,   387,   284,     2,   330,   395,   221,     0,     0,
     201,     0,   381,     0,   222,   224,   227,   210,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   272,   274,   407,
       0,     0,     0,     0,     0,     0,     5,     0,     0,    18,
       0,    29,     0,     0,    49,    50,    51,    53,    54,    56,
      57,    61,    62,    59,    60,    64,    65,    67,    69,    71,
       0,     0,     0,   175,   169,     0,   176,     0,   238,     0,
       0,   230,   241,     0,   257,     0,    82,     0,     0,     0,
     244,     0,     0,   250,     0,   252,   260,   393,   405,     0,
     301,     0,     0,   292,     0,     0,   400,   401,   402,     0,
       0,     0,     0,   281,   285,   286,   287,   282,     0,   260,
       0,   297,   261,   384,   279,   278,   260,   392,   300,   398,
     399,   260,     0,   386,   290,     0,     0,   202,   234,   226,
     228,   209,     0,   380,   364,   335,   351,   356,     0,   354,
     212,     0,    36,     0,     0,     0,    37,     0,   249,    47,
      23,    19,     0,    17,    21,    74,    77,     0,   374,   170,
     240,   231,   239,     0,   236,     0,     0,    96,     0,   255,
     249,   245,   247,   251,   253,   260,   157,     0,   403,     0,
     302,     0,     0,     0,     0,     0,   316,   317,   318,     0,
       0,   288,     0,    97,   289,   389,   388,   203,   204,   223,
     225,     0,   214,     0,   357,     0,     0,     0,    12,     0,
      28,     0,    30,     0,     0,   237,   256,   254,   246,     0,
     153,   158,   377,   168,   376,     0,   291,   293,     0,     0,
     315,   319,     0,     0,     0,    97,   355,    38,     0,   358,
      39,     0,    11,     0,     0,   249,    26,    80,   242,   248,
       0,     0,   163,   165,   378,   404,   305,   307,   309,     0,
      97,     0,     0,     0,    15,    13,    14,    27,   166,   168,
     159,     0,   260,   260,   260,     0,     0,    97,   360,   359,
     164,   167,   304,   308,   310,     0,    97,     0,   260,   306,
     311,     0,   313,   303,   260,   260,   312,   314
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -581,  -581,  -581,  -581,  -581,   -54,  -581,  -581,  -581,    38,
       4,  -581,  -161,   120,   121,    55,   127,   250,   257,   258,
     134,   139,  -581,  -581,  -581,   -68,  -581,  -130,  -581,   -12,
    -581,  -278,   -58,  -222,     3,    42,   335,   344,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,  -581,    27,  -513,  -581,   -62,
    -581,   263,   367,   264,   -53,  -581,  -581,     1,   -71,  -581,
    -581,  -581,  -581,  -581,   -50,  -581,   -95,   336,  -219,  -581,
      77,  -298,  -294,  -581,  -581,  -581,  -581,  -410,    64,  -495,
    -581,  -581,   131,  -581,     5,   -63,   -73,  -581,  -581,   420,
    -581,  -581,  -581,   320,  -329,  -217,  -581,  -580,  -581,  -212,
    -581,  -581,   223,  -211,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,  -581,   498,  -581,  -581,  -581,   358,
    -581,  -581,   438,  -581,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,  -581,  -581,   343,   -52,  -581,  -581,  -344,  -581,
    -581,  -581,   108,   351,  -581,  -581,  -581,  -581,  -581,  -581,
    -581,  -581,     0
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,   183,   184,   185,   567,   568,   186,   403,   398,   400,
     212,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   420,   199,   421,   213,   422,   214,   328,   347,
     437,   348,   201,    57,   209,    59,   108,   109,    60,    61,
      62,    63,    64,   341,    65,   535,   536,    66,   611,   612,
      67,   303,   204,   205,    68,    69,    70,   336,    72,    73,
      74,    75,    76,   239,    77,    78,   150,   237,   429,   374,
     375,   309,   310,   311,   312,   313,   523,   339,   441,   442,
     443,   444,   445,    79,   472,   352,    81,    90,    91,    92,
      93,   159,   258,   259,   551,   474,   463,   552,   475,   476,
     542,   230,   355,   231,   356,   357,   649,   465,   632,   633,
     466,   634,   655,   467,    82,    83,    84,   116,   224,   232,
      85,   143,   144,   563,   623,   202,   145,    86,    87,   225,
     226,   426,   583,   584,   240,   376,   358,   359,   360,   481,
     482,   483,   361,   233,   234,   362,   468,   469,   470,   539,
     363,    88,   203
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      89,    71,   113,    58,    94,    80,   146,   152,   349,   430,
       1,   119,   120,   353,   431,     1,    96,   478,   354,     4,
     373,     1,   236,   365,   582,   148,   155,   281,   149,   473,
     200,     4,   532,   200,   200,   579,     1,   200,     1,   152,
     299,   100,     1,   208,   211,   255,     1,   219,     1,   210,
       1,   216,   218,   643,   644,    89,   106,     1,    89,   110,
     221,   101,   289,   290,   148,    97,     1,   282,  -113,     4,
     112,   614,   283,   284,   656,   657,    95,    89,     4,   112,
     112,   222,    89,    71,   530,    58,     4,    80,   223,  -113,
     531,   215,   217,   338,   112,   221,   162,   251,   102,   206,
     252,   156,   187,   111,   157,   187,   187,   371,   114,   187,
     579,   115,   103,   227,   161,   330,   447,   330,   241,   229,
     104,   404,   405,   406,   274,   317,   318,   319,   320,   321,
     322,   323,   324,   325,   326,   256,   540,   555,   591,   477,
     367,   464,   395,   304,   353,   479,   629,   554,   401,   354,
     480,     1,   330,   307,   255,   513,    94,  -234,   260,   308,
     261,   262,   154,    56,   273,   105,   580,   630,   265,   609,
     268,   269,   238,    99,   200,   200,   200,    55,   200,   200,
     117,   200,   148,   251,   379,   380,   381,    56,   383,   384,
     430,   385,   187,   151,    55,   118,   431,   610,   436,   257,
     107,   300,    55,   158,    56,   307,   488,   206,  -200,  -234,
    -234,   112,   390,    55,   391,   392,    56,  -198,    98,   394,
     160,    89,   488,    56,   291,   292,  -234,   229,   605,    89,
     364,   285,   286,   350,   606,   351,   509,   229,   485,   486,
     207,   438,   372,   439,   256,   241,   187,   187,   187,   220,
     187,   187,   273,   187,   242,   273,   243,   308,   260,   533,
     349,   275,   276,   277,   353,   597,   244,   402,   598,   354,
     599,   245,   432,   254,   393,   594,  -235,   438,   152,   439,
     330,   440,   246,   638,   327,   247,   187,   187,   187,   187,
     187,   187,   187,   187,   187,   187,   187,   187,   187,   187,
     187,   187,   206,   642,   574,   287,   288,   527,   387,   438,
     372,   439,   338,   570,   251,   293,   294,   621,   200,   653,
     249,   438,   490,   439,   263,   578,   315,   316,   501,   329,
     330,   595,   266,   438,   477,   439,   270,   627,   271,   451,
     332,   330,   636,   272,   411,   412,   413,   414,   377,   378,
      89,   396,   330,   497,   378,   330,   573,   200,   364,   647,
     295,   364,   364,   296,   350,   200,   351,   518,   651,   297,
     200,   298,    89,   489,   301,   525,   602,   603,   493,   302,
     528,   306,   401,   537,   200,   616,   330,   617,   330,   314,
     187,   618,   330,   331,   541,   645,   330,   333,   510,   152,
     334,   187,  -199,   514,  -371,   407,   408,   386,   409,   410,
     517,   278,   389,   397,   424,   279,   434,   280,   433,   146,
     415,   416,   425,   435,   187,   187,   223,   446,   448,   187,
     200,   449,   330,     3,   346,   484,   450,   187,   490,   529,
     561,   487,   187,   491,   538,   492,   494,   495,   496,   338,
     549,   112,   498,   503,   499,   569,   187,   500,   502,   545,
     451,   504,   519,   505,   506,   511,    11,    12,   507,   364,
     512,   624,   537,   147,   626,   520,   364,    19,    20,    21,
      22,   364,   521,   522,   526,   350,   562,    80,    89,   106,
      89,   372,   543,   544,   546,   372,   547,    33,    34,   550,
     553,   557,   187,   564,   508,   607,   452,   453,   454,   565,
     455,   456,   457,   458,   459,   460,   461,   462,   558,   575,
     577,   576,   585,   586,   590,   587,   372,   593,   596,   600,
     608,   588,   589,   601,   604,   619,   631,   648,   592,   615,
     112,   620,   200,   652,   654,   417,   637,   646,   650,   625,
     572,   569,   628,   418,   515,   419,   350,    43,    80,   350,
     516,    80,   581,   200,   342,   335,   423,   640,   427,   560,
      45,   368,   571,   641,   305,   534,   253,   187,   388,   471,
     153,   248,   340,    89,   613,   366,   622,     0,   382,     0,
     556,     0,   228,     0,     0,     0,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   635,     0,     0,
       0,     0,     0,     0,   187,     0,     3,     0,     0,     0,
       0,     0,     0,   639,     0,     0,     0,     0,     0,    89,
     613,     0,   364,   364,   364,   187,     1,     2,     3,   163,
     164,   165,     0,   166,   167,   235,     0,     0,   364,    11,
      12,     0,     0,     4,   364,   364,     0,     0,     0,     0,
      19,    20,    21,    22,     0,     5,     6,     7,     8,     9,
      10,    11,    12,     0,    13,    14,    15,     0,    17,    18,
      33,    34,    19,    20,    21,    22,     0,   343,     0,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
     344,   169,     0,     0,     0,     0,     0,     0,     0,     0,
      43,     0,     0,     0,     0,     0,     0,     0,     0,   170,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,    42,    43,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    44,   171,    45,   172,    46,    47,    48,
     173,   174,   175,    49,    50,    51,    52,    53,    54,   345,
       0,     0,   176,     0,     0,     0,     0,     0,     0,     0,
     346,   177,   178,   179,   180,   181,   182,     0,     0,     1,
       2,     3,   163,   164,   165,   -97,   166,   167,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     5,     6,
       7,     8,     9,    10,    11,    12,     0,    13,    14,    15,
       0,    17,    18,     0,     0,    19,    20,    21,    22,     0,
     343,     0,     0,     0,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   168,   344,   169,     0,     0,     0,     0,     0,
       0,     0,     1,     0,     0,   163,   164,   165,     0,   166,
     167,     0,   170,     0,     0,     0,     0,     0,     0,     4,
       0,     0,     0,     0,    42,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,   171,    45,   172,
      46,    47,    48,   173,   174,   175,    49,    50,    51,    52,
      53,    54,   345,   343,     0,   176,     0,     0,     0,     0,
       0,     0,     0,  -299,   177,   178,   179,   180,   181,   182,
       0,     0,     0,     0,     0,     0,     0,     0,   -97,  -260,
    -260,  -260,     0,  -260,  -260,  -260,  -260,  -260,  -260,  -260,
    -260,     0,     3,     0,     0,   168,   344,   169,     0,     1,
       0,     0,   163,   164,   165,     0,   166,   167,     0,     0,
       0,     0,     0,     0,     0,   170,     4,     0,     0,     0,
       0,     0,     0,     0,     0,    11,    12,     0,     0,     0,
       0,     0,   250,     0,     0,     0,    19,    20,    21,    22,
     171,     0,   172,     0,     0,     0,   173,   174,   175,     0,
     343,     0,     0,     0,     0,   345,    33,    34,   176,     0,
       0,     0,     0,     0,     0,  -260,  -385,   177,   178,   179,
     180,   181,   182,     0,     0,     0,     0,     0,     0,     1,
       0,   -97,   163,   164,   165,     0,   166,   167,     0,     0,
       0,     0,   168,   344,   169,     0,     4,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,     0,     0,     1,    43,     0,   163,   164,
     165,     0,   166,   167,     0,     0,     0,     0,     0,    45,
     343,     0,     4,     0,     0,     0,     0,   171,     0,   172,
       0,     0,     3,   173,   174,   175,     0,     0,     0,     0,
       0,     0,   345,     0,     0,   176,    56,     0,     0,     0,
       0,     0,     0,  -390,   177,   178,   179,   180,   181,   182,
       0,   369,   168,   344,   169,    11,    12,     1,   -97,     0,
     163,   164,   165,     0,   166,   167,    19,    20,    21,    22,
       0,     0,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,    34,   168,     0,
     169,     0,     0,     0,     0,     0,     0,   171,     0,   172,
       0,     0,     0,   173,   174,   175,     0,     0,   170,     0,
       0,     0,   345,     0,     0,   176,     0,     0,     0,     0,
       0,     0,     0,     0,   177,   178,   179,   180,   181,   182,
       0,     0,     0,   171,     3,   172,     0,     0,   -97,   173,
     174,   175,     0,     0,     0,     0,    43,     0,     0,     0,
     168,   176,   169,     0,     0,     0,     0,     0,     0,    45,
     177,   178,   179,   180,   181,   182,     0,    11,    12,     0,
     170,     0,     0,     0,   151,     0,     0,     0,    19,    20,
      21,    22,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   171,     0,   172,    33,    34,
       0,   173,   174,   175,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   176,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   178,   179,   180,   181,   182,     0,     0,
       1,     2,     3,   163,   164,   165,   548,   166,   167,     0,
       0,     0,     0,     0,     0,     0,     0,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    43,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,    14,
      15,    45,    17,    18,     0,     0,    19,    20,    21,    22,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   168,     0,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   170,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,   171,    45,
     172,    46,    47,    48,   173,   174,   175,    49,    50,    51,
      52,    53,    54,     0,     0,     0,   176,     0,     0,     0,
       0,     0,     0,     0,     0,   177,   178,   179,   180,   181,
     182,     1,     2,     3,   163,   164,   165,     0,   166,   167,
       0,     0,     0,     0,     0,     0,     1,     0,     0,   163,
     164,   165,     0,   166,   167,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,    10,    11,    12,     0,    13,
      14,    15,     0,    17,    18,     0,     0,    19,    20,    21,
      22,     0,     0,     0,     0,     0,     0,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,     0,
       1,     0,     0,   163,   164,   165,     0,   166,   167,     0,
       0,     0,     0,     0,   168,     0,   169,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   168,
       0,   169,     0,     0,   170,     1,     0,     0,   163,   164,
     165,     0,   166,   167,     0,     0,    42,    43,     0,   170,
       0,     0,     0,     0,     0,     0,     0,     0,    44,   171,
      45,   172,    46,     0,    48,   173,   174,   175,    49,    50,
      51,    52,    53,    54,   171,     0,   172,   176,     0,     0,
     173,   174,   175,     0,     0,     0,   177,   178,   179,   180,
     181,   182,   176,   168,     0,   169,     0,     0,     0,   337,
       0,   177,   178,   179,   180,   181,   182,     0,     0,     0,
       0,     0,     0,   170,     1,     0,     0,   163,   164,   165,
       0,   166,   167,     0,     0,     0,     0,     0,   168,     1,
     169,     0,   163,   164,   165,     0,   166,   167,   171,     0,
     172,     0,     0,     0,   173,   174,   175,     0,   170,     0,
       0,     0,     0,     0,     0,     0,   176,     0,     0,     0,
       0,   370,     0,     0,     0,   177,   178,   179,   180,   181,
     182,     0,     0,   171,     0,   172,     0,     0,     0,   173,
     174,   175,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,   399,     0,     0,     0,     0,     0,     0,     0,
     177,   178,   179,   180,   181,   182,     0,   168,     1,   169,
       0,   163,   164,   165,     0,   166,   167,     0,     0,     0,
       0,     0,   168,     0,   169,     4,     0,   170,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   170,     1,     0,     0,   163,   164,   165,     0,
     166,   167,   171,     0,   172,     0,     0,     0,   173,   174,
     175,     0,     0,     0,     0,     0,     0,   171,     0,   172,
     176,     0,     0,   173,   174,   175,     0,   508,     0,   177,
     178,   179,   180,   181,   182,   176,     0,     0,     0,     0,
     524,     0,     0,     0,   177,   178,   179,   180,   181,   182,
       0,   168,     1,   169,     0,   163,   164,   165,     0,   166,
     167,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   168,     1,   169,     0,
     163,   164,   165,     0,   166,   167,   171,     0,   172,     0,
       0,     0,   173,   174,   175,     0,   170,     0,     0,     0,
       0,     0,     0,     0,   176,     0,     0,     0,     0,     0,
       0,     0,     0,   177,   178,   179,   180,   181,   182,     0,
       0,   171,     0,   172,     0,     0,     0,   173,   174,   175,
       0,     0,     0,     0,     0,   168,     0,   169,     0,   176,
       0,     0,     0,     0,     0,     0,     0,     0,   177,   178,
     179,   180,   181,   182,     0,   170,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     168,     0,   169,     0,     0,     0,     0,     0,     0,     0,
     171,     0,   172,     0,     0,     0,   173,   174,   175,     0,
     170,     0,     0,     0,     0,     0,     0,     0,   264,     0,
       0,     0,     0,     0,     0,     0,     0,   177,   178,   179,
     180,   181,   182,     0,     0,   171,     0,   172,     0,     0,
       0,   173,   174,   175,     1,     2,     3,     0,     0,     0,
       0,     0,     0,   267,     0,     0,     0,     0,     0,     0,
       0,     4,   177,   178,   179,   180,   181,   182,     0,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,    14,    15,    16,    17,    18,     0,     0,
      19,    20,    21,    22,     1,     2,     3,     0,     0,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,    14,    15,     0,    17,    18,     0,     0,
      19,    20,    21,    22,     0,     0,     0,     0,     0,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    44,     0,    45,     0,    46,    47,    48,     0,     0,
       0,    49,    50,    51,    52,    53,    54,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      43,     0,     0,     0,     2,     3,     0,     0,     0,     0,
       0,    44,     0,    45,     0,    46,     0,    48,     0,     0,
       0,    49,    50,    51,    52,    53,    54,     0,     0,     0,
     488,   428,     5,     6,     7,     8,     9,    10,    11,    12,
      56,    13,    14,    15,     0,    17,    18,     0,     0,    19,
      20,    21,    22,     2,     3,     0,     0,     0,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,     5,     6,     7,     8,     9,    10,    11,    12,     0,
      13,    14,    15,     0,    17,    18,     0,     0,    19,    20,
      21,    22,     0,     0,     0,     0,     0,     0,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,     0,    42,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,    45,     0,    46,     0,    48,     0,     0,     0,
      49,    50,    51,    52,    53,    54,     0,     0,     0,   307,
     428,     0,     0,     0,     0,     0,     0,     0,     0,    56,
       0,     0,     0,     0,     0,     0,     0,    42,    43,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    44,
       0,    45,     0,    46,     0,    48,     2,     3,     0,    49,
      50,    51,    52,    53,    54,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     0,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,     8,     9,    10,
      11,    12,     0,    13,    14,    15,     0,    17,    18,     0,
       0,    19,    20,    21,    22,     2,     3,     0,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,    14,    15,     0,    17,    18,     0,     0,
      19,    20,    21,    22,   559,     0,     0,     0,     0,     0,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,     0,
      42,    43,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,    45,     0,    46,    47,    48,     0,
       0,     0,    49,    50,    51,    52,    53,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      43,     2,     3,     0,     0,     0,     0,     0,     0,     0,
       0,    44,     0,    45,     0,    46,     0,    48,     0,     0,
       0,    49,    50,    51,    52,    53,    54,     0,     0,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,    14,
      15,     0,    17,    18,     0,     0,    19,    20,    21,    22,
       0,     2,     3,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,     0,     0,     0,   566,     5,
       6,     7,     8,     9,    10,    11,    12,     0,    13,    14,
      15,     0,    17,    18,     0,     0,    19,    20,    21,    22,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,    45,
       0,    46,     0,    48,     0,     0,     0,    49,    50,    51,
      52,    53,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   121,     0,     0,     2,
       3,     0,     0,   122,   123,    42,    43,     0,     0,     0,
     124,   125,   126,   127,   128,     0,     0,    44,     0,    45,
       0,    46,     0,    48,     0,     0,     0,    49,    50,    51,
      52,    53,    54,    11,    12,     0,    13,    14,    15,     0,
      17,    18,     0,     0,    19,    20,    21,    22,   129,   130,
     131,   132,     0,     0,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    43,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,    45,     0,     0,
       0,     0,     0,     0,     0,    49,    50,    51,    52,    53,
      54
};

static const yytype_int16 yycheck[] =
{
       0,     0,    65,     0,     4,     0,    77,    80,   230,   307,
       3,    74,    75,   230,   308,     3,    16,   361,   230,    20,
     239,     3,   117,   234,   537,    78,    89,   188,    78,   358,
      98,    20,   442,   101,   102,   530,     3,   105,     3,   112,
      19,    41,     3,   101,   102,     6,     3,   105,     3,   101,
       3,   103,   104,   633,   634,    55,    55,     3,    58,    58,
     161,   159,    14,    15,   117,     6,     3,   169,   161,    20,
      65,   584,   174,   175,   654,   655,    56,    77,    20,    74,
      75,   182,    82,    82,   161,    82,    20,    82,   181,   182,
     167,   103,   104,   223,    89,   161,    96,   150,   159,    99,
     150,   161,    98,    61,   164,   101,   102,   237,    66,   105,
     605,    69,   159,   113,    69,   161,   182,   161,   118,   116,
     159,   282,   283,   284,   176,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    96,   182,   481,   182,   361,
     235,   352,   272,   206,   361,   362,   161,   476,   278,   361,
     362,     3,   161,   159,     6,   164,   156,   163,   158,   209,
     160,   161,     0,   169,   176,   159,   167,   182,   164,   579,
     166,   167,   160,   166,   242,   243,   244,   159,   246,   247,
     163,   249,   235,   236,   242,   243,   244,   169,   246,   247,
     488,   249,   188,   182,   159,   159,   490,   162,   328,   160,
     182,   180,   159,   159,   169,   159,   159,   207,   159,   163,
     163,   206,   264,   159,   266,   267,   169,   159,   159,   271,
      21,   221,   159,   169,   176,   177,   163,   224,   161,   229,
     230,   170,   171,   230,   167,   230,   397,   234,   368,   369,
     166,   163,   239,   165,    96,   245,   242,   243,   244,   160,
     246,   247,   264,   249,   159,   267,   159,   307,   258,   181,
     482,     9,    10,    11,   481,   160,   159,   279,   163,   481,
     165,   159,   159,   164,   270,   553,   163,   163,   351,   165,
     161,   167,   159,   164,   181,   159,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   302,   632,   523,    12,    13,   437,   160,   163,
     307,   165,   442,   167,   367,    16,    17,   595,   386,   648,
     159,   163,   372,   165,   182,   167,   160,   161,   386,   160,
     161,   553,   159,   163,   556,   165,   159,   167,   159,   351,
     160,   161,   620,   159,   289,   290,   291,   292,   160,   161,
     350,   160,   161,   160,   161,   161,   162,   425,   358,   637,
     168,   361,   362,   178,   361,   433,   361,   425,   646,   179,
     438,    18,   372,   372,   160,   433,   160,   161,   378,   161,
     438,   160,   512,   446,   452,   160,   161,   160,   161,   160,
     386,   160,   161,   160,   452,   160,   161,   160,   398,   472,
     160,   397,   159,   403,   166,   285,   286,   159,   287,   288,
     422,   159,   182,   160,   167,   163,   182,   165,   163,   490,
     293,   294,   181,    96,   420,   421,   181,   166,   182,   425,
     498,   159,   161,     5,   167,   162,   182,   433,   488,   439,
     498,   164,   438,   160,    96,   161,   160,   160,   160,   579,
     462,   446,   161,   161,   160,   507,   452,   160,   160,   459,
     472,   160,   167,   161,   160,   160,    38,    39,   161,   469,
     161,   601,   535,    45,   604,   160,   476,    49,    50,    51,
      52,   481,   160,   160,   160,   482,   160,   482,   488,   488,
     490,   488,   159,   159,   182,   492,   182,    69,    70,   159,
     159,   164,   498,   503,   166,   573,    80,    81,    82,   505,
      84,    85,    86,    87,    88,    89,    90,    91,   164,   164,
     164,   182,   160,   162,   182,   162,   523,    85,   160,   160,
     160,   543,   544,   162,   162,   159,   162,    83,   550,   182,
     535,   182,   610,   160,   160,   295,   182,   182,   182,   603,
     512,   603,   610,   296,   420,   297,   553,   129,   553,   556,
     421,   556,   535,   631,   229,   221,   302,   629,   305,   492,
     142,   235,   508,   631,   207,   444,   156,   573,   258,   356,
      82,   143,   224,   583,   583,   234,   598,    -1,   245,    -1,
     482,    -1,   166,    -1,    -1,    -1,    -1,   169,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   619,    -1,    -1,
      -1,    -1,    -1,    -1,   610,    -1,     5,    -1,    -1,    -1,
      -1,    -1,    -1,   623,    -1,    -1,    -1,    -1,    -1,   629,
     629,    -1,   632,   633,   634,   631,     3,     4,     5,     6,
       7,     8,    -1,    10,    11,    34,    -1,    -1,   648,    38,
      39,    -1,    -1,    20,   654,   655,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    41,    42,    43,    -1,    45,    46,
      69,    70,    49,    50,    51,    52,    -1,    54,    -1,    -1,
      -1,    -1,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      97,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   116,
      -1,    -1,    -1,   142,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
      -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     167,   168,   169,   170,   171,   172,   173,    -1,    -1,     3,
       4,     5,     6,     7,     8,   182,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    41,    42,    43,
      -1,    45,    46,    -1,    -1,    49,    50,    51,    52,    -1,
      54,    -1,    -1,    -1,    -1,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    96,    97,    98,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,    -1,    -1,     6,     7,     8,    -1,    10,
      11,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,    54,    -1,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   182,    80,
      81,    82,    -1,    84,    85,    86,    87,    88,    89,    90,
      91,    -1,     5,    -1,    -1,    96,    97,    98,    -1,     3,
      -1,    -1,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   116,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    49,    50,    51,    52,
     141,    -1,   143,    -1,    -1,    -1,   147,   148,   149,    -1,
      54,    -1,    -1,    -1,    -1,   156,    69,    70,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,   169,   170,
     171,   172,   173,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,   182,     6,     7,     8,    -1,    10,    11,    -1,    -1,
      -1,    -1,    96,    97,    98,    -1,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,    -1,    -1,     3,   129,    -1,     6,     7,
       8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,   142,
      54,    -1,    20,    -1,    -1,    -1,    -1,   141,    -1,   143,
      -1,    -1,     5,   147,   148,   149,    -1,    -1,    -1,    -1,
      -1,    -1,   156,    -1,    -1,   159,   169,    -1,    -1,    -1,
      -1,    -1,    -1,   167,   168,   169,   170,   171,   172,   173,
      -1,    34,    96,    97,    98,    38,    39,     3,   182,    -1,
       6,     7,     8,    -1,    10,    11,    49,    50,    51,    52,
      -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    96,    -1,
      98,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,   143,
      -1,    -1,    -1,   147,   148,   149,    -1,    -1,   116,    -1,
      -1,    -1,   156,    -1,    -1,   159,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
      -1,    -1,    -1,   141,     5,   143,    -1,    -1,   182,   147,
     148,   149,    -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,
      96,   159,    98,    -1,    -1,    -1,    -1,    -1,    -1,   142,
     168,   169,   170,   171,   172,   173,    -1,    38,    39,    -1,
     116,    -1,    -1,    -1,   182,    -1,    -1,    -1,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   141,    -1,   143,    69,    70,
      -1,   147,   148,   149,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   168,   169,   170,   171,   172,   173,    -1,    -1,
       3,     4,     5,     6,     7,     8,   182,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   129,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,   142,    45,    46,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   128,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    -1,     6,
       7,     8,    -1,    10,    11,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    41,
      42,    43,    -1,    45,    46,    -1,    -1,    49,    50,    51,
      52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    -1,    -1,    -1,    -1,
       3,    -1,    -1,     6,     7,     8,    -1,    10,    11,    -1,
      -1,    -1,    -1,    -1,    96,    -1,    98,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    96,
      -1,    98,    -1,    -1,   116,     3,    -1,    -1,     6,     7,
       8,    -1,    10,    11,    -1,    -1,   128,   129,    -1,   116,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,   141,
     142,   143,   144,    -1,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   141,    -1,   143,   159,    -1,    -1,
     147,   148,   149,    -1,    -1,    -1,   168,   169,   170,   171,
     172,   173,   159,    96,    -1,    98,    -1,    -1,    -1,   166,
      -1,   168,   169,   170,   171,   172,   173,    -1,    -1,    -1,
      -1,    -1,    -1,   116,     3,    -1,    -1,     6,     7,     8,
      -1,    10,    11,    -1,    -1,    -1,    -1,    -1,    96,     3,
      98,    -1,     6,     7,     8,    -1,    10,    11,   141,    -1,
     143,    -1,    -1,    -1,   147,   148,   149,    -1,   116,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,   164,    -1,    -1,    -1,   168,   169,   170,   171,   172,
     173,    -1,    -1,   141,    -1,   143,    -1,    -1,    -1,   147,
     148,   149,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   159,   160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     168,   169,   170,   171,   172,   173,    -1,    96,     3,    98,
      -1,     6,     7,     8,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    96,    -1,    98,    20,    -1,   116,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   116,     3,    -1,    -1,     6,     7,     8,    -1,
      10,    11,   141,    -1,   143,    -1,    -1,    -1,   147,   148,
     149,    -1,    -1,    -1,    -1,    -1,    -1,   141,    -1,   143,
     159,    -1,    -1,   147,   148,   149,    -1,   166,    -1,   168,
     169,   170,   171,   172,   173,   159,    -1,    -1,    -1,    -1,
     164,    -1,    -1,    -1,   168,   169,   170,   171,   172,   173,
      -1,    96,     3,    98,    -1,     6,     7,     8,    -1,    10,
      11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    96,     3,    98,    -1,
       6,     7,     8,    -1,    10,    11,   141,    -1,   143,    -1,
      -1,    -1,   147,   148,   149,    -1,   116,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   168,   169,   170,   171,   172,   173,    -1,
      -1,   141,    -1,   143,    -1,    -1,    -1,   147,   148,   149,
      -1,    -1,    -1,    -1,    -1,    96,    -1,    98,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,
     170,   171,   172,   173,    -1,   116,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      96,    -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     141,    -1,   143,    -1,    -1,    -1,   147,   148,   149,    -1,
     116,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   168,   169,   170,
     171,   172,   173,    -1,    -1,   141,    -1,   143,    -1,    -1,
      -1,   147,   148,   149,     3,     4,     5,    -1,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,   168,   169,   170,   171,   172,   173,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    44,    45,    46,    -1,    -1,
      49,    50,    51,    52,     3,     4,     5,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    -1,    45,    46,    -1,    -1,
      49,    50,    51,    52,    -1,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,   128,
     129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   140,    -1,   142,    -1,   144,   145,   146,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
     159,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     169,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,    -1,    -1,    -1,     4,     5,    -1,    -1,    -1,    -1,
      -1,   140,    -1,   142,    -1,   144,    -1,   146,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   155,    -1,    -1,    -1,
     159,   160,    32,    33,    34,    35,    36,    37,    38,    39,
     169,    41,    42,    43,    -1,    45,    46,    -1,    -1,    49,
      50,    51,    52,     4,     5,    -1,    -1,    -1,    -1,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      41,    42,    43,    -1,    45,    46,    -1,    -1,    49,    50,
      51,    52,    -1,    -1,    -1,    -1,    -1,    -1,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    -1,   128,   129,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     140,    -1,   142,    -1,   144,    -1,   146,    -1,    -1,    -1,
     150,   151,   152,   153,   154,   155,    -1,    -1,    -1,   159,
     160,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   169,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,
      -1,   142,    -1,   144,    -1,   146,     4,     5,    -1,   150,
     151,   152,   153,   154,   155,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    -1,    -1,   166,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    41,    42,    43,    -1,    45,    46,    -1,
      -1,    49,    50,    51,    52,     4,     5,    -1,    -1,    -1,
      -1,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    41,    42,    43,    -1,    45,    46,    -1,    -1,
      49,    50,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    -1,
     128,   129,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   140,    -1,   142,    -1,   144,   145,   146,    -1,
      -1,    -1,   150,   151,   152,   153,   154,   155,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   128,
     129,     4,     5,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   140,    -1,   142,    -1,   144,    -1,   146,    -1,    -1,
      -1,   150,   151,   152,   153,   154,   155,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    -1,    45,    46,    -1,    -1,    49,    50,    51,    52,
      -1,     4,     5,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    -1,    -1,    -1,    81,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    41,    42,
      43,    -1,    45,    46,    -1,    -1,    49,    50,    51,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,   128,   129,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   140,    -1,   142,
      -1,   144,    -1,   146,    -1,    -1,    -1,   150,   151,   152,
     153,   154,   155,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,     4,
       5,    -1,    -1,    47,    48,   128,   129,    -1,    -1,    -1,
      54,    55,    56,    57,    58,    -1,    -1,   140,    -1,   142,
      -1,   144,    -1,   146,    -1,    -1,    -1,   150,   151,   152,
     153,   154,   155,    38,    39,    -1,    41,    42,    43,    -1,
      45,    46,    -1,    -1,    49,    50,    51,    52,    92,    93,
      94,    95,    -1,    -1,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   129,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   140,    -1,   142,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   150,   151,   152,   153,   154,
     155
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,     4,     5,    20,    32,    33,    34,    35,    36,
      37,    38,    39,    41,    42,    43,    44,    45,    46,    49,
      50,    51,    52,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,   128,   129,   140,   142,   144,   145,   146,   150,
     151,   152,   153,   154,   155,   159,   169,   216,   217,   218,
     221,   222,   223,   224,   225,   227,   230,   233,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   247,   248,   266,
     267,   269,   297,   298,   299,   303,   310,   311,   334,   335,
     270,   271,   272,   273,   335,    56,   335,     6,   159,   166,
     335,   159,   159,   159,   159,   159,   240,   182,   219,   220,
     240,   218,   267,   268,   218,   218,   300,   163,   159,   268,
     268,    40,    47,    48,    54,    55,    56,    57,    58,    92,
      93,    94,    95,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   304,   305,   309,   241,    45,   237,   247,
     249,   182,   269,   298,     0,   268,   161,   164,   159,   274,
      21,    69,   335,     6,     7,     8,    10,    11,    96,    98,
     116,   141,   143,   147,   148,   149,   159,   168,   169,   170,
     171,   172,   173,   184,   185,   186,   189,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   206,
     208,   215,   308,   335,   235,   236,   335,   166,   215,   217,
     318,   215,   193,   208,   210,   212,   318,   212,   318,   215,
     160,   161,   182,   181,   301,   312,   313,   335,   166,   217,
     284,   286,   302,   326,   327,    34,   249,   250,   160,   246,
     317,   335,   159,   159,   159,   159,   159,   159,   305,   159,
      45,   237,   247,   272,   164,     6,    96,   160,   275,   276,
     335,   335,   335,   182,   159,   193,   159,   159,   193,   193,
     159,   159,   159,   212,   318,     9,    10,    11,   159,   163,
     165,   195,   169,   174,   175,   170,   171,    12,    13,    14,
      15,   176,   177,    16,    17,   168,   178,   179,    18,    19,
     180,   160,   161,   234,   268,   235,   160,   159,   247,   254,
     255,   256,   257,   258,   160,   160,   161,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,   181,   211,   160,
     161,   160,   160,   160,   160,   220,   240,   166,   210,   260,
     302,   226,   219,    54,    97,   156,   167,   212,   214,   216,
     217,   267,   268,   278,   282,   285,   287,   288,   319,   320,
     321,   325,   328,   333,   335,   286,   326,   249,   250,    34,
     164,   210,   217,   251,   252,   253,   318,   160,   161,   215,
     215,   215,   317,   215,   215,   215,   159,   160,   276,   182,
     318,   318,   318,   193,   318,   210,   160,   160,   191,   160,
     192,   210,   212,   190,   195,   195,   195,   196,   196,   197,
     197,   198,   198,   198,   198,   199,   199,   200,   201,   202,
     205,   207,   209,   236,   167,   181,   314,   234,   160,   251,
     254,   255,   159,   163,   182,    96,   210,   213,   163,   165,
     167,   261,   262,   263,   264,   265,   166,   182,   182,   159,
     182,   212,    80,    81,    82,    84,    85,    86,    87,    88,
      89,    90,    91,   279,   286,   290,   293,   296,   329,   330,
     331,   285,   267,   277,   278,   281,   282,   216,   321,   278,
     282,   322,   323,   324,   162,   210,   210,   164,   159,   240,
     247,   160,   161,   335,   160,   160,   160,   160,   161,   160,
     160,   215,   160,   161,   160,   161,   160,   161,   166,   195,
     335,   160,   161,   164,   335,   203,   204,   212,   215,   167,
     160,   160,   160,   259,   164,   215,   160,   210,   215,   335,
     161,   167,   260,   181,   265,   228,   229,   268,    96,   332,
     182,   215,   283,   159,   159,   335,   182,   182,   182,   212,
     159,   277,   280,   159,   277,   321,   325,   164,   164,    53,
     253,   215,   160,   306,   335,   193,    81,   187,   188,   318,
     167,   261,   192,   162,   251,   164,   182,   164,   167,   262,
     167,   229,   230,   315,   316,   160,   162,   162,   212,   212,
     182,   182,   212,    85,   214,   216,   160,   160,   163,   165,
     160,   162,   160,   161,   162,   161,   167,   208,   160,   260,
     162,   231,   232,   240,   230,   182,   160,   160,   160,   159,
     182,   214,   212,   307,   210,   188,   210,   167,   215,   161,
     182,   162,   291,   292,   294,   212,   214,   182,   164,   335,
     232,   215,   277,   280,   280,   160,   182,   214,    83,   289,
     182,   214,   160,   277,   160,   295,   280,   280
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   183,   184,   184,   184,   184,   184,   184,   185,   185,
     185,   186,   187,   187,   188,   188,   189,   189,   189,   189,
     190,   189,   191,   189,   189,   189,   189,   189,   189,   192,
     192,   193,   193,   193,   193,   193,   193,   193,   193,   193,
     194,   194,   194,   194,   194,   194,   195,   195,   196,   196,
     196,   196,   197,   197,   197,   198,   198,   198,   199,   199,
     199,   199,   199,   200,   200,   200,   201,   201,   202,   202,
     203,   203,   204,   205,   204,   206,   207,   206,   208,   209,
     208,   210,   210,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   212,   213,   212,   214,   214,   215,
     216,   216,   216,   216,   217,   218,   218,   218,   218,   218,
     218,   219,   219,   220,   220,   221,   222,   222,   222,   222,
     222,   222,   222,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   223,   223,
     223,   223,   223,   223,   223,   223,   223,   223,   224,   224,
     224,   224,   226,   225,   225,   227,   227,   228,   228,   229,
     230,   230,   230,   231,   231,   232,   232,   232,   232,   233,
     233,   233,   234,   234,   235,   235,   236,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   238,   238,
     239,   239,   240,   240,   241,   241,   241,   241,   242,   242,
     242,   243,   243,   243,   243,   244,   244,   245,   246,   245,
     245,   247,   247,   247,   247,   247,   247,   248,   249,   249,
     250,   250,   251,   251,   252,   252,   253,   253,   254,   254,
     254,   255,   255,   255,   256,   256,   257,   257,   258,   258,
     258,   259,   258,   260,   260,   260,   260,   261,   261,   262,
     262,   263,   264,   264,   265,   265,   266,   266,   267,   267,
     268,   268,   269,   270,   270,   271,   271,   272,   272,   273,
     273,   274,   274,   275,   275,   276,   276,   276,   277,   277,
     278,   278,   278,   278,   278,   279,   279,   279,   280,   281,
     282,   282,   283,   282,   284,   285,   286,   286,   287,   287,
     287,   288,   288,   289,   289,   291,   290,   292,   290,   294,
     293,   293,   293,   295,   293,   296,   296,   296,   296,   296,
     297,   297,   298,   298,   298,   300,   299,   301,   299,   302,
     302,   303,   303,   304,   304,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   306,   307,   306,
     306,   308,   308,   309,   309,   310,   310,   311,   311,   311,
     311,   312,   312,   313,   314,   314,   315,   316,   316,   317,
     317,   318,   318,   319,   320,   321,   321,   323,   322,   324,
     324,   325,   325,   326,   327,   327,   328,   328,   328,   328,
     329,   330,   331,   332,   333,   333,   334,   334,   335
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     6,     1,     3,     3,     3,     1,     4,     3,     4,
       0,     4,     0,     4,     2,     2,     6,     7,     5,     1,
       3,     1,     2,     2,     2,     2,     4,     4,     6,     6,
       1,     1,     1,     1,     1,     1,     1,     4,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     0,     4,     1,     0,     4,     1,     0,
       6,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     4,     0,     1,     1,
       2,     3,     1,     1,     1,     1,     2,     1,     2,     1,
       2,     1,     3,     1,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     4,     1,     4,     4,
       4,     4,     0,     7,     3,     1,     1,     1,     2,     4,
       1,     1,     1,     1,     3,     1,     2,     3,     0,     5,
       6,     2,     0,     1,     1,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     1,     2,     2,     3,     2,     2,     1,     3,
       1,     4,     5,     6,     6,     1,     2,     3,     0,     5,
       4,     1,     5,     2,     6,     2,     3,     1,     1,     2,
       0,     1,     1,     3,     1,     3,     2,     1,     1,     1,
       2,     3,     1,     1,     0,     1,     3,     4,     2,     3,
       3,     0,     5,     1,     2,     3,     4,     2,     4,     0,
       1,     2,     1,     2,     3,     2,     7,     5,     2,     1,
       0,     1,     4,     1,     3,     1,     2,     0,     1,     1,
       3,     2,     3,     1,     2,     1,     1,     1,     1,     1,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     2,
       2,     4,     0,     4,     1,     1,     2,     3,     1,     1,
       2,     2,     3,     2,     0,     0,     7,     0,     6,     0,
       6,     7,     9,     0,     9,     3,     2,     2,     2,     3,
       1,     2,     1,     1,     1,     0,     3,     0,     4,     1,
       2,     0,     1,     1,     2,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     1,     1,     4,     6,     4,     1,     0,     4,
       4,     1,     1,     1,     4,     1,     1,     1,     2,     1,
       1,     1,     0,     1,     2,     0,     1,     1,     2,     1,
       3,     1,     2,     1,     2,     1,     2,     0,     2,     2,
       1,     1,     2,     3,     1,     2,     1,     1,     2,     2,
       1,     1,     1,     1,     5,     2,     4,     5,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* primary_expression: identifier  */
#line 174 "src/SDCC.y"
                     { (yyval.asts) = newAst_VALUE (symbolVal ((yyvsp[0].sym))); }
#line 2457 "src/SDCCy.c"
    break;

  case 3: /* primary_expression: CONSTANT  */
#line 175 "src/SDCC.y"
                     { (yyval.asts) = newAst_VALUE ((yyvsp[0].val)); }
#line 2463 "src/SDCCy.c"
    break;

  case 5: /* primary_expression: '(' expression ')'  */
#line 177 "src/SDCC.y"
                           { (yyval.asts) = (yyvsp[-1].asts); }
#line 2469 "src/SDCCy.c"
    break;

  case 8: /* predefined_constant: TOKEN_FALSE  */
#line 183 "src/SDCC.y"
                 { (yyval.asts) = newAst_VALUE (constBoolVal (false, true)); }
#line 2475 "src/SDCCy.c"
    break;

  case 9: /* predefined_constant: TOKEN_TRUE  */
#line 184 "src/SDCC.y"
                 { (yyval.asts) = newAst_VALUE (constBoolVal (true, true)); }
#line 2481 "src/SDCCy.c"
    break;

  case 10: /* predefined_constant: NULLPTR  */
#line 185 "src/SDCC.y"
                 { (yyval.asts) = newAst_VALUE (constNullptrVal ()); }
#line 2487 "src/SDCCy.c"
    break;

  case 11: /* generic_selection: GENERIC '(' assignment_expr ',' generic_assoc_list ')'  */
#line 189 "src/SDCC.y"
                                                            { (yyval.asts) = newNode (GENERIC, (yyvsp[-3].asts), (yyvsp[-1].asts)); }
#line 2493 "src/SDCCy.c"
    break;

  case 12: /* generic_assoc_list: generic_association  */
#line 193 "src/SDCC.y"
                         { (yyval.asts) = newNode  (GENERIC_ASSOC_LIST, NULL, (yyvsp[0].asts)); }
#line 2499 "src/SDCCy.c"
    break;

  case 13: /* generic_assoc_list: generic_assoc_list ',' generic_association  */
#line 194 "src/SDCC.y"
                                                { (yyval.asts) = newNode  (GENERIC_ASSOC_LIST, (yyvsp[-2].asts), (yyvsp[0].asts)); }
#line 2505 "src/SDCCy.c"
    break;

  case 14: /* generic_association: type_name ':' assignment_expr  */
#line 198 "src/SDCC.y"
                                   { (yyval.asts) = newNode  (GENERIC_ASSOCIATION, newAst_LINK((yyvsp[-2].lnk)), (yyvsp[0].asts)); }
#line 2511 "src/SDCCy.c"
    break;

  case 15: /* generic_association: DEFAULT ':' assignment_expr  */
#line 199 "src/SDCC.y"
                                 { (yyval.asts) = newNode  (GENERIC_ASSOCIATION,NULL,(yyvsp[0].asts)); }
#line 2517 "src/SDCCy.c"
    break;

  case 17: /* postfix_expression: postfix_expression '[' expression ']'  */
#line 204 "src/SDCC.y"
                                                    { (yyval.asts) = newNode  ('[', (yyvsp[-3].asts), (yyvsp[-1].asts)); }
#line 2523 "src/SDCCy.c"
    break;

  case 18: /* postfix_expression: postfix_expression '(' ')'  */
#line 205 "src/SDCC.y"
                                              { (yyval.asts) = newNode  (CALL,(yyvsp[-2].asts),NULL);
                                          (yyval.asts)->left->funcName = 1;}
#line 2530 "src/SDCCy.c"
    break;

  case 19: /* postfix_expression: postfix_expression '(' argument_expr_list ')'  */
#line 208 "src/SDCC.y"
          {
            (yyval.asts) = newNode  (CALL,(yyvsp[-3].asts),(yyvsp[-1].asts)); (yyval.asts)->left->funcName = 1;
          }
#line 2538 "src/SDCCy.c"
    break;

  case 20: /* $@1: %empty  */
#line 211 "src/SDCC.y"
                            { ignoreTypedefType = 1; }
#line 2544 "src/SDCCy.c"
    break;

  case 21: /* postfix_expression: postfix_expression '.' $@1 identifier  */
#line 212 "src/SDCC.y"
                      {
                        ignoreTypedefType = 0;
                        (yyvsp[0].sym) = newSymbol((yyvsp[0].sym)->name,NestLevel);
                        (yyvsp[0].sym)->implicit = 1;
                        (yyval.asts) = newNode(PTR_OP,newNode('&',(yyvsp[-3].asts),NULL),newAst_VALUE(symbolVal((yyvsp[0].sym))));
                      }
#line 2555 "src/SDCCy.c"
    break;

  case 22: /* $@2: %empty  */
#line 218 "src/SDCC.y"
                               { ignoreTypedefType = 1; }
#line 2561 "src/SDCCy.c"
    break;

  case 23: /* postfix_expression: postfix_expression PTR_OP $@2 identifier  */
#line 219 "src/SDCC.y"
                      {
                        ignoreTypedefType = 0;
                        (yyvsp[0].sym) = newSymbol((yyvsp[0].sym)->name,NestLevel);
                        (yyvsp[0].sym)->implicit = 1;
                        (yyval.asts) = newNode(PTR_OP,(yyvsp[-3].asts),newAst_VALUE(symbolVal((yyvsp[0].sym))));
                      }
#line 2572 "src/SDCCy.c"
    break;

  case 24: /* postfix_expression: postfix_expression INC_OP  */
#line 226 "src/SDCC.y"
                      { (yyval.asts) = newNode(INC_OP,(yyvsp[-1].asts),NULL);}
#line 2578 "src/SDCCy.c"
    break;

  case 25: /* postfix_expression: postfix_expression DEC_OP  */
#line 228 "src/SDCC.y"
                      { (yyval.asts) = newNode(DEC_OP,(yyvsp[-1].asts),NULL); }
#line 2584 "src/SDCCy.c"
    break;

  case 26: /* postfix_expression: '(' type_name ')' '{' initializer_list '}'  */
#line 230 "src/SDCC.y"
                      {
                        /* if (!options.std_c99) */
                          werror(E_COMPOUND_LITERALS_C99);

                        /* TODO: implement compound literals (C99) */
                        (yyval.asts) = newAst_VALUE (valueFromLit (0));
                      }
#line 2596 "src/SDCCy.c"
    break;

  case 27: /* postfix_expression: '(' type_name ')' '{' initializer_list ',' '}'  */
#line 238 "src/SDCC.y"
     {
       // if (!options.std_c99)
         werror(E_COMPOUND_LITERALS_C99);

       // TODO: implement compound literals (C99)
       (yyval.asts) = newAst_VALUE (valueFromLit (0));
     }
#line 2608 "src/SDCCy.c"
    break;

  case 28: /* postfix_expression: '(' type_name ')' '{' '}'  */
#line 246 "src/SDCC.y"
     {
       if (!options.std_c23)
         werror(W_EMPTY_INIT_C23);
       // if (!options.std_c99)
         werror(E_COMPOUND_LITERALS_C99);

       // TODO: implement compound literals (C99)
       (yyval.asts) = newAst_VALUE (valueFromLit (0));
     }
#line 2622 "src/SDCCy.c"
    break;

  case 30: /* argument_expr_list: assignment_expr ',' argument_expr_list  */
#line 259 "src/SDCC.y"
                                            { (yyval.asts) = newNode(PARAM,(yyvsp[-2].asts),(yyvsp[0].asts)); }
#line 2628 "src/SDCCy.c"
    break;

  case 32: /* unary_expression: INC_OP unary_expression  */
#line 264 "src/SDCC.y"
                                    { (yyval.asts) = newNode (INC_OP, NULL, (yyvsp[0].asts)); }
#line 2634 "src/SDCCy.c"
    break;

  case 33: /* unary_expression: DEC_OP unary_expression  */
#line 265 "src/SDCC.y"
                                    { (yyval.asts) = newNode (DEC_OP, NULL, (yyvsp[0].asts)); }
#line 2640 "src/SDCCy.c"
    break;

  case 34: /* unary_expression: unary_operator cast_expression  */
#line 267 "src/SDCC.y"
       {
         if ((yyvsp[-1].yyint) == '&' && IS_AST_OP ((yyvsp[0].asts)) && (yyvsp[0].asts)->opval.op == '*' && (yyvsp[0].asts)->right == NULL)
           (yyval.asts) = (yyvsp[0].asts)->left;
         else if ((yyvsp[-1].yyint) == '*' && IS_AST_OP ((yyvsp[0].asts)) && (yyvsp[0].asts)->opval.op == '&' && (yyvsp[0].asts)->right == NULL)
           (yyval.asts) = (yyvsp[0].asts)->left;
         else
           (yyval.asts) = newNode ((yyvsp[-1].yyint), (yyvsp[0].asts), NULL);
       }
#line 2653 "src/SDCCy.c"
    break;

  case 35: /* unary_expression: SIZEOF unary_expression  */
#line 275 "src/SDCC.y"
                                    { (yyval.asts) = newNode (SIZEOF, NULL, (yyvsp[0].asts)); }
#line 2659 "src/SDCCy.c"
    break;

  case 36: /* unary_expression: SIZEOF '(' type_name ')'  */
#line 276 "src/SDCC.y"
                                    { (yyval.asts) = newAst_VALUE (sizeofOp ((yyvsp[-1].lnk))); }
#line 2665 "src/SDCCy.c"
    break;

  case 37: /* unary_expression: ALIGNOF '(' type_name ')'  */
#line 277 "src/SDCC.y"
                                    { (yyval.asts) = newAst_VALUE (alignofOp ((yyvsp[-1].lnk))); }
#line 2671 "src/SDCCy.c"
    break;

  case 38: /* unary_expression: OFFSETOF '(' type_name ',' offsetof_member_designator ')'  */
#line 278 "src/SDCC.y"
                                                               { (yyval.asts) = offsetofOp((yyvsp[-3].lnk), (yyvsp[-1].asts)); }
#line 2677 "src/SDCCy.c"
    break;

  case 39: /* unary_expression: ROT '(' unary_expression ',' unary_expression ')'  */
#line 279 "src/SDCC.y"
                                                               { (yyval.asts) = newNode (ROT, (yyvsp[-3].asts), (yyvsp[-1].asts)); }
#line 2683 "src/SDCCy.c"
    break;

  case 40: /* unary_operator: '&'  */
#line 283 "src/SDCC.y"
            { (yyval.yyint) = '&';}
#line 2689 "src/SDCCy.c"
    break;

  case 41: /* unary_operator: '*'  */
#line 284 "src/SDCC.y"
            { (yyval.yyint) = '*';}
#line 2695 "src/SDCCy.c"
    break;

  case 42: /* unary_operator: '+'  */
#line 285 "src/SDCC.y"
            { (yyval.yyint) = '+';}
#line 2701 "src/SDCCy.c"
    break;

  case 43: /* unary_operator: '-'  */
#line 286 "src/SDCC.y"
            { (yyval.yyint) = '-';}
#line 2707 "src/SDCCy.c"
    break;

  case 44: /* unary_operator: '~'  */
#line 287 "src/SDCC.y"
            { (yyval.yyint) = '~';}
#line 2713 "src/SDCCy.c"
    break;

  case 45: /* unary_operator: '!'  */
#line 288 "src/SDCC.y"
            { (yyval.yyint) = '!';}
#line 2719 "src/SDCCy.c"
    break;

  case 47: /* cast_expression: '(' type_name ')' cast_expression  */
#line 293 "src/SDCC.y"
                                       { (yyval.asts) = newNode(CAST,newAst_LINK((yyvsp[-2].lnk)),(yyvsp[0].asts)); }
#line 2725 "src/SDCCy.c"
    break;

  case 49: /* multiplicative_expression: multiplicative_expression '*' cast_expression  */
#line 298 "src/SDCC.y"
                                                   { (yyval.asts) = newNode('*',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2731 "src/SDCCy.c"
    break;

  case 50: /* multiplicative_expression: multiplicative_expression '/' cast_expression  */
#line 299 "src/SDCC.y"
                                                   { (yyval.asts) = newNode('/',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2737 "src/SDCCy.c"
    break;

  case 51: /* multiplicative_expression: multiplicative_expression '%' cast_expression  */
#line 300 "src/SDCC.y"
                                                   { (yyval.asts) = newNode('%',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2743 "src/SDCCy.c"
    break;

  case 53: /* additive_expression: additive_expression '+' multiplicative_expression  */
#line 305 "src/SDCC.y"
                                                       { (yyval.asts)=newNode('+',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2749 "src/SDCCy.c"
    break;

  case 54: /* additive_expression: additive_expression '-' multiplicative_expression  */
#line 306 "src/SDCC.y"
                                                       { (yyval.asts)=newNode('-',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2755 "src/SDCCy.c"
    break;

  case 56: /* shift_expression: shift_expression LEFT_OP additive_expression  */
#line 311 "src/SDCC.y"
                                                   { (yyval.asts) = newNode(LEFT_OP,(yyvsp[-2].asts),(yyvsp[0].asts)); }
#line 2761 "src/SDCCy.c"
    break;

  case 57: /* shift_expression: shift_expression RIGHT_OP additive_expression  */
#line 312 "src/SDCC.y"
                                                   { (yyval.asts) = newNode(RIGHT_OP,(yyvsp[-2].asts),(yyvsp[0].asts)); }
#line 2767 "src/SDCCy.c"
    break;

  case 59: /* relational_expression: relational_expression '<' shift_expression  */
#line 317 "src/SDCC.y"
                                                  { (yyval.asts) = newNode('<',  (yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2773 "src/SDCCy.c"
    break;

  case 60: /* relational_expression: relational_expression '>' shift_expression  */
#line 318 "src/SDCC.y"
                                                  { (yyval.asts) = newNode('>',  (yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2779 "src/SDCCy.c"
    break;

  case 61: /* relational_expression: relational_expression LE_OP shift_expression  */
#line 319 "src/SDCC.y"
                                                  { (yyval.asts) = newNode(LE_OP,(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2785 "src/SDCCy.c"
    break;

  case 62: /* relational_expression: relational_expression GE_OP shift_expression  */
#line 320 "src/SDCC.y"
                                                  { (yyval.asts) = newNode(GE_OP,(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2791 "src/SDCCy.c"
    break;

  case 64: /* equality_expression: equality_expression EQ_OP relational_expression  */
#line 325 "src/SDCC.y"
                                                     { (yyval.asts) = newNode(EQ_OP,(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2797 "src/SDCCy.c"
    break;

  case 65: /* equality_expression: equality_expression NE_OP relational_expression  */
#line 326 "src/SDCC.y"
                                                     { (yyval.asts) = newNode(NE_OP,(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2803 "src/SDCCy.c"
    break;

  case 67: /* and_expression: and_expression '&' equality_expression  */
#line 331 "src/SDCC.y"
                                             { (yyval.asts) = newNode('&',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2809 "src/SDCCy.c"
    break;

  case 69: /* exclusive_or_expression: exclusive_or_expression '^' and_expression  */
#line 336 "src/SDCC.y"
                                                { (yyval.asts) = newNode('^',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2815 "src/SDCCy.c"
    break;

  case 71: /* inclusive_or_expression: inclusive_or_expression '|' exclusive_or_expression  */
#line 341 "src/SDCC.y"
                                                         { (yyval.asts) = newNode('|',(yyvsp[-2].asts),(yyvsp[0].asts));}
#line 2821 "src/SDCCy.c"
    break;

  case 73: /* $@3: %empty  */
#line 346 "src/SDCC.y"
                             { seqPointNo++;}
#line 2827 "src/SDCCy.c"
    break;

  case 74: /* logical_and_expr: logical_and_expr AND_OP $@3 inclusive_or_expression  */
#line 347 "src/SDCC.y"
                                 { (yyval.asts) = newNode(AND_OP,(yyvsp[-3].asts),(yyvsp[0].asts));}
#line 2833 "src/SDCCy.c"
    break;

  case 76: /* $@4: %empty  */
#line 352 "src/SDCC.y"
                           { seqPointNo++;}
#line 2839 "src/SDCCy.c"
    break;

  case 77: /* logical_or_expr: logical_or_expr OR_OP $@4 logical_and_expr  */
#line 353 "src/SDCC.y"
                                 { (yyval.asts) = newNode(OR_OP,(yyvsp[-3].asts),(yyvsp[0].asts)); }
#line 2845 "src/SDCCy.c"
    break;

  case 79: /* $@5: %empty  */
#line 358 "src/SDCC.y"
                         { seqPointNo++;}
#line 2851 "src/SDCCy.c"
    break;

  case 80: /* conditional_expr: logical_or_expr '?' $@5 expression ':' conditional_expr  */
#line 359 "src/SDCC.y"
                     {
                        (yyval.asts) = newNode(':',(yyvsp[-2].asts),(yyvsp[0].asts));
                        (yyval.asts) = newNode('?',(yyvsp[-5].asts),(yyval.asts));
                     }
#line 2860 "src/SDCCy.c"
    break;

  case 82: /* assignment_expr: unary_expression assignment_operator assignment_expr  */
#line 368 "src/SDCC.y"
                     {

                             switch ((yyvsp[-1].yyint)) {
                             case '=':
                                     (yyval.asts) = newNode((yyvsp[-1].yyint),(yyvsp[-2].asts),(yyvsp[0].asts));
                                     break;
                             case MUL_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '*', (yyvsp[0].asts));
                                     break;
                             case DIV_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '/', (yyvsp[0].asts));
                                     break;
                             case MOD_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '%', (yyvsp[0].asts));
                                     break;
                             case ADD_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '+', (yyvsp[0].asts));
                                     break;
                             case SUB_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '-', (yyvsp[0].asts));
                                     break;
                             case LEFT_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), LEFT_OP, (yyvsp[0].asts));
                                     break;
                             case RIGHT_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), RIGHT_OP, (yyvsp[0].asts));
                                     break;
                             case AND_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '&', (yyvsp[0].asts));
                                     break;
                             case XOR_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '^', (yyvsp[0].asts));
                                     break;
                             case OR_ASSIGN:
                                     (yyval.asts) = createRMW((yyvsp[-2].asts), '|', (yyvsp[0].asts));
                                     break;
                             default :
                                     (yyval.asts) = NULL;
                             }

                     }
#line 2906 "src/SDCCy.c"
    break;

  case 83: /* assignment_operator: '='  */
#line 412 "src/SDCC.y"
                     { (yyval.yyint) = '=';}
#line 2912 "src/SDCCy.c"
    break;

  case 95: /* $@6: %empty  */
#line 427 "src/SDCC.y"
                    { seqPointNo++;}
#line 2918 "src/SDCCy.c"
    break;

  case 96: /* expression: expression ',' $@6 assignment_expr  */
#line 427 "src/SDCC.y"
                                                     { (yyval.asts) = newNode(',',(yyvsp[-3].asts),(yyvsp[0].asts));}
#line 2924 "src/SDCCy.c"
    break;

  case 97: /* expression_opt: %empty  */
#line 431 "src/SDCC.y"
                     { (yyval.asts) = NULL; seqPointNo++; }
#line 2930 "src/SDCCy.c"
    break;

  case 98: /* expression_opt: expression  */
#line 432 "src/SDCC.y"
                     { (yyval.asts) = (yyvsp[0].asts); seqPointNo++; }
#line 2936 "src/SDCCy.c"
    break;

  case 100: /* declaration: declaration_specifiers ';'  */
#line 443 "src/SDCC.y"
      {
         /* Special case: if incomplete struct/union declared without name, */
         /* make sure an incomplete type for it exists in the current scope */
         if (IS_STRUCT((yyvsp[-1].lnk)))
           {
             structdef *sdef = SPEC_STRUCT((yyvsp[-1].lnk));
             structdef *osdef;
             osdef = findSymWithBlock (StructTab, sdef->tagsym, currBlockno, NestLevel);
             if (osdef && osdef->block != currBlockno)
               {
                 sdef = newStruct(osdef->tagsym->name);
                 sdef->level = NestLevel;
                 sdef->block = currBlockno;
                 sdef->tagsym = newSymbol (osdef->tagsym->name, NestLevel);
                 addSym (StructTab, sdef, sdef->tag, sdef->level, currBlockno, 0);
                 uselessDecl = false;
               }
           }
         if (uselessDecl)
           werror(W_USELESS_DECL);
         uselessDecl = true;
         (yyval.sym) = NULL;
      }
#line 2964 "src/SDCCy.c"
    break;

  case 101: /* declaration: declaration_specifiers init_declarator_list ';'  */
#line 467 "src/SDCC.y"
      {
         /* add the specifier list to the id */
         symbol *sym , *sym1;

         bool autocandidate = options.std_c23 && IS_SPEC ((yyvsp[-2].lnk)) && SPEC_SCLS((yyvsp[-2].lnk)) == S_AUTO;

         for (sym1 = sym = reverseSyms((yyvsp[-1].sym));sym != NULL;sym = sym->next) {
             sym_link *lnk = copyLinkChain((yyvsp[-2].lnk));
             sym_link *l0 = NULL, *l1 = NULL, *l2 = NULL;
             /* check illegal declaration */
             for (l0 = sym->type; l0 != NULL; l0 = l0->next)
               if (IS_PTR (l0))
                 break;
             /* check if creating instances of structs with flexible arrays */
             for (l1 = lnk; l1 != NULL; l1 = l1->next)
               if (IS_STRUCT (l1) && SPEC_STRUCT (l1)->b_flexArrayMember)
                 break;
             if (!options.std_c99 && l0 == NULL && l1 != NULL && SPEC_EXTR((yyvsp[-2].lnk)) != 1)
               werror (W_FLEXARRAY_INSTRUCT, sym->name);
             /* check if creating instances of function type */
             for (l1 = lnk; l1 != NULL; l1 = l1->next)
               if (IS_FUNC (l1))
                 break;
             for (l2 = lnk; l2 != NULL; l2 = l2->next)
               if (IS_PTR (l2))
                 break;
             if (l0 == NULL && l2 == NULL && l1 != NULL)
               werrorfl(sym->fileDef, sym->lineDef, E_TYPE_IS_FUNCTION, sym->name);
             if (autocandidate && !sym->type && sym->ival && sym->ival->type == INIT_NODE) // C23 auto type inference
               {
                 sym->type = sym->etype = typeofOp (sym->ival->init.node);
                 SPEC_SCLS (lnk) = 0;
               }
             /* do the pointer stuff */
             pointerTypes(sym->type,lnk);
             addDecl (sym,0,lnk);
         }

         uselessDecl = true;
         (yyval.sym) = sym1;
      }
#line 3010 "src/SDCCy.c"
    break;

  case 102: /* declaration: static_assert_declaration  */
#line 509 "src/SDCC.y"
      {
         (yyval.sym) = NULL;
      }
#line 3018 "src/SDCCy.c"
    break;

  case 103: /* declaration: attribute_declaration  */
#line 513 "src/SDCC.y"
      {
         (yyval.sym) = NULL;
      }
#line 3026 "src/SDCCy.c"
    break;

  case 104: /* declaration_specifiers: declaration_specifiers_  */
#line 518 "src/SDCC.y"
                                                 { (yyval.lnk) = finalizeSpec((yyvsp[0].lnk)); }
#line 3032 "src/SDCCy.c"
    break;

  case 105: /* declaration_specifiers_: storage_class_specifier  */
#line 521 "src/SDCC.y"
                                                     { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3038 "src/SDCCy.c"
    break;

  case 106: /* declaration_specifiers_: storage_class_specifier declaration_specifiers_  */
#line 522 "src/SDCC.y"
                                                     {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[-1].lnk), (yyvsp[0].lnk), "storage_class_specifier declaration_specifiers - skipped");
   }
#line 3048 "src/SDCCy.c"
    break;

  case 107: /* declaration_specifiers_: type_specifier_qualifier  */
#line 527 "src/SDCC.y"
                                                    { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3054 "src/SDCCy.c"
    break;

  case 108: /* declaration_specifiers_: type_specifier_qualifier declaration_specifiers_  */
#line 528 "src/SDCC.y"
                                                      {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[-1].lnk), (yyvsp[0].lnk), "type_specifier_qualifier declaration_specifiers - skipped");
   }
#line 3064 "src/SDCCy.c"
    break;

  case 109: /* declaration_specifiers_: function_specifier  */
#line 533 "src/SDCC.y"
                                                    { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3070 "src/SDCCy.c"
    break;

  case 110: /* declaration_specifiers_: function_specifier declaration_specifiers_  */
#line 534 "src/SDCC.y"
                                                    {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[-1].lnk), (yyvsp[0].lnk), "function_specifier declaration_specifiers - skipped");
   }
#line 3080 "src/SDCCy.c"
    break;

  case 112: /* init_declarator_list: init_declarator_list ',' init_declarator  */
#line 543 "src/SDCC.y"
                                                   { (yyvsp[0].sym)->next = (yyvsp[-2].sym); (yyval.sym) = (yyvsp[0].sym);}
#line 3086 "src/SDCCy.c"
    break;

  case 113: /* init_declarator: declarator  */
#line 547 "src/SDCC.y"
                                 { (yyvsp[0].sym)->ival = NULL; }
#line 3092 "src/SDCCy.c"
    break;

  case 114: /* init_declarator: declarator '=' initializer  */
#line 548 "src/SDCC.y"
                                 { (yyvsp[-2].sym)->ival = (yyvsp[0].ilist); seqPointNo++; }
#line 3098 "src/SDCCy.c"
    break;

  case 116: /* storage_class_specifier: TYPEDEF  */
#line 556 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_TYPEDEF((yyval.lnk)) = 1;
               }
#line 3107 "src/SDCCy.c"
    break;

  case 117: /* storage_class_specifier: EXTERN  */
#line 560 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink(SPECIFIER);
                  SPEC_EXTR((yyval.lnk)) = 1;
               }
#line 3116 "src/SDCCy.c"
    break;

  case 118: /* storage_class_specifier: STATIC  */
#line 564 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_STAT((yyval.lnk)) = 1;
               }
#line 3125 "src/SDCCy.c"
    break;

  case 119: /* storage_class_specifier: THREAD_LOCAL  */
#line 569 "src/SDCC.y"
               {
                  (yyval.lnk) = 0;
                  werror(E_THREAD_LOCAL);
               }
#line 3134 "src/SDCCy.c"
    break;

  case 120: /* storage_class_specifier: AUTO  */
#line 573 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_AUTO;
               }
#line 3143 "src/SDCCy.c"
    break;

  case 121: /* storage_class_specifier: REGISTER  */
#line 577 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_REGISTER;
               }
#line 3152 "src/SDCCy.c"
    break;

  case 122: /* storage_class_specifier: CONSTEXPR  */
#line 581 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  werror (E_CONSTEXPR);
               }
#line 3161 "src/SDCCy.c"
    break;

  case 123: /* type_specifier: SD_VOID  */
#line 588 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_VOID;
                  ignoreTypedefType = 1;
               }
#line 3171 "src/SDCCy.c"
    break;

  case 124: /* type_specifier: SD_CHAR  */
#line 593 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_CHAR;
                  ignoreTypedefType = 1;
               }
#line 3181 "src/SDCCy.c"
    break;

  case 125: /* type_specifier: SD_SHORT  */
#line 598 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_SHORT((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
#line 3191 "src/SDCCy.c"
    break;

  case 126: /* type_specifier: SD_INT  */
#line 603 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_INT;
                  ignoreTypedefType = 1;
               }
#line 3201 "src/SDCCy.c"
    break;

  case 127: /* type_specifier: SD_LONG  */
#line 608 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_LONG((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
#line 3211 "src/SDCCy.c"
    break;

  case 128: /* type_specifier: SD_FLOAT  */
#line 613 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_FLOAT;
                  ignoreTypedefType = 1;
               }
#line 3221 "src/SDCCy.c"
    break;

  case 129: /* type_specifier: DOUBLE  */
#line 618 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_DOUBLE;
                  ignoreTypedefType = 1;
               }
#line 3231 "src/SDCCy.c"
    break;

  case 130: /* type_specifier: SIGNED  */
#line 623 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  (yyval.lnk)->select.s.b_signed = 1;
                  ignoreTypedefType = 1;
               }
#line 3241 "src/SDCCy.c"
    break;

  case 131: /* type_specifier: UNSIGNED  */
#line 628 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_USIGN((yyval.lnk)) = 1;
                  ignoreTypedefType = 1;
               }
#line 3251 "src/SDCCy.c"
    break;

  case 132: /* type_specifier: SD_BITINT '(' constant_expr ')'  */
#line 633 "src/SDCC.y"
                                      {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_BITINT;
                  SPEC_BITINTWIDTH((yyval.lnk)) = (unsigned int) ulFromVal(constExprValue((yyvsp[-1].asts), true));
                  ignoreTypedefType = 1;
               }
#line 3262 "src/SDCCy.c"
    break;

  case 133: /* type_specifier: SD_BOOL  */
#line 639 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_BOOL;
                  ignoreTypedefType = 1;
               }
#line 3272 "src/SDCCy.c"
    break;

  case 134: /* type_specifier: COMPLEX  */
#line 644 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  werror (E_COMPLEX_UNSUPPORTED);
               }
#line 3281 "src/SDCCy.c"
    break;

  case 135: /* type_specifier: IMAGINARY  */
#line 648 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  werror (E_COMPLEX_UNSUPPORTED);
               }
#line 3290 "src/SDCCy.c"
    break;

  case 136: /* type_specifier: DECIMAL32  */
#line 652 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  werror (E_DECIMAL_FLOAT_UNSUPPORTED);
               }
#line 3299 "src/SDCCy.c"
    break;

  case 137: /* type_specifier: DECIMAL64  */
#line 656 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  werror (E_DECIMAL_FLOAT_UNSUPPORTED);
               }
#line 3308 "src/SDCCy.c"
    break;

  case 138: /* type_specifier: DECIMAL128  */
#line 660 "src/SDCC.y"
                {
                  (yyval.lnk)=newLink(SPECIFIER);
                  werror (E_DECIMAL_FLOAT_UNSUPPORTED);
               }
#line 3317 "src/SDCCy.c"
    break;

  case 139: /* type_specifier: struct_or_union_specifier  */
#line 664 "src/SDCC.y"
                                {
                                   uselessDecl = false;
                                   (yyval.lnk) = (yyvsp[0].lnk);
                                   ignoreTypedefType = 1;
                                }
#line 3327 "src/SDCCy.c"
    break;

  case 140: /* type_specifier: enum_specifier  */
#line 669 "src/SDCC.y"
                        {
                           cenum = NULL;
                           uselessDecl = false;
                           ignoreTypedefType = 1;
                           (yyval.lnk) = (yyvsp[0].lnk);
                        }
#line 3338 "src/SDCCy.c"
    break;

  case 141: /* type_specifier: TYPE_NAME  */
#line 676 "src/SDCC.y"
         {
            symbol *sym;
            sym_link *p;
            sym = findSym(TypedefTab,NULL,(yyvsp[0].yychar));
            (yyval.lnk) = p = copyLinkChain(sym ? sym->type : NULL);
            SPEC_TYPEDEF(getSpec(p)) = 0;
            ignoreTypedefType = 1;
         }
#line 3351 "src/SDCCy.c"
    break;

  case 142: /* type_specifier: typeof_specifier  */
#line 685 "src/SDCC.y"
     {
       (yyval.lnk) = (yyvsp[0].lnk);
     }
#line 3359 "src/SDCCy.c"
    break;

  case 143: /* type_specifier: FIXED16X16  */
#line 688 "src/SDCC.y"
                {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_FIXED16X16;
                  ignoreTypedefType = 1;
               }
#line 3369 "src/SDCCy.c"
    break;

  case 144: /* type_specifier: BIT  */
#line 693 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_NOUN((yyval.lnk)) = V_BIT;
                  SPEC_SCLS((yyval.lnk)) = S_BIT;
                  SPEC_BLEN((yyval.lnk)) = 1;
                  SPEC_BSTR((yyval.lnk)) = 0;
                  ignoreTypedefType = 1;
               }
#line 3382 "src/SDCCy.c"
    break;

  case 145: /* type_specifier: AT CONSTANT  */
#line 701 "src/SDCC.y"
                 {
                  (yyval.lnk)=newLink(SPECIFIER);
                  /* add this to the storage class specifier  */
                  SPEC_ABSA((yyval.lnk)) = 1;   /* set the absolute addr flag */
                  /* now get the abs addr from value */
                  SPEC_ADDR((yyval.lnk)) = (unsigned int) ulFromVal(constExprValue(newAst_VALUE ((yyvsp[0].val)), true));
               }
#line 3394 "src/SDCCy.c"
    break;

  case 146: /* type_specifier: AT '(' constant_expr ')'  */
#line 708 "src/SDCC.y"
                              {
                  (yyval.lnk)=newLink(SPECIFIER);
                  /* add this to the storage class specifier  */
                  SPEC_ABSA((yyval.lnk)) = 1;   /* set the absolute addr flag */
                  /* now get the abs addr from value */
                  SPEC_ADDR((yyval.lnk)) = (unsigned int) ulFromVal(constExprValue((yyvsp[-1].asts), true));
               }
#line 3406 "src/SDCCy.c"
    break;

  case 148: /* typeof_specifier: TYPEOF '(' expression ')'  */
#line 721 "src/SDCC.y"
     {
       (yyval.lnk) = typeofOp ((yyvsp[-1].asts));
       wassert ((yyval.lnk));
     }
#line 3415 "src/SDCCy.c"
    break;

  case 149: /* typeof_specifier: TYPEOF '(' type_name ')'  */
#line 726 "src/SDCC.y"
     {
       checkTypeSanity ((yyvsp[-1].lnk), "(typeof)");
       (yyval.lnk) = (yyvsp[-1].lnk);
     }
#line 3424 "src/SDCCy.c"
    break;

  case 150: /* typeof_specifier: TYPEOF_UNQUAL '(' expression ')'  */
#line 731 "src/SDCC.y"
     {
       (yyval.lnk) = typeofOp ((yyvsp[-1].asts));
       wassert ((yyval.lnk));
       wassert (IS_SPEC ((yyval.lnk)));
       SPEC_CONST ((yyval.lnk)) = 0;
       SPEC_RESTRICT ((yyval.lnk)) = 0;
       SPEC_VOLATILE ((yyval.lnk)) = 0;
       SPEC_ATOMIC ((yyval.lnk)) = 0;
       SPEC_ADDRSPACE ((yyval.lnk)) = 0;
     }
#line 3439 "src/SDCCy.c"
    break;

  case 151: /* typeof_specifier: TYPEOF_UNQUAL '(' type_name ')'  */
#line 742 "src/SDCC.y"
     {
       checkTypeSanity ((yyvsp[-1].lnk), "(typeof_unqual)");
       (yyval.lnk) = (yyvsp[-1].lnk);
       wassert (IS_SPEC ((yyval.lnk)));
       SPEC_CONST ((yyval.lnk)) = 0;
       SPEC_RESTRICT ((yyval.lnk)) = 0;
       SPEC_VOLATILE ((yyval.lnk)) = 0;
       SPEC_ATOMIC ((yyval.lnk)) = 0;
       SPEC_ADDRSPACE ((yyval.lnk)) = 0;
     }
#line 3454 "src/SDCCy.c"
    break;

  case 152: /* $@7: %empty  */
#line 755 "src/SDCC.y"
        {
          structdef *sdef;

          if (!(yyvsp[0].sdef)->tagsym)
            {
              /* no tag given, so new struct def for current scope */
              addSym (StructTab, (yyvsp[0].sdef), (yyvsp[0].sdef)->tag, (yyvsp[0].sdef)->level, currBlockno, 0);
            }
          else
            {
              sdef = findSymWithBlock (StructTab, (yyvsp[0].sdef)->tagsym, currBlockno, NestLevel);
              if (sdef)
                {
                  /* Error if a complete type already defined in this scope */
                  if (sdef->block == currBlockno)
                    {
                      if (sdef->fields)
                        (yyvsp[0].sdef)->redefinition = true;
                      else // We are completing an incomplete type
                        (yyvsp[0].sdef) = sdef;
                    }
                  else
                    {
                      /* There is an existing struct def in an outer scope. */
                      /* Create new struct def for current scope */
                      addSym (StructTab, (yyvsp[0].sdef), (yyvsp[0].sdef)->tag, (yyvsp[0].sdef)->level, currBlockno, 0);
                    }
                }
              else
               {
                 /* There is no existing struct def at all. */
                 /* Create new struct def for current scope */
                 addSym (StructTab, (yyvsp[0].sdef), (yyvsp[0].sdef)->tag, (yyvsp[0].sdef)->level, currBlockno, 0);
               }
            }

          if (!(yyvsp[0].sdef)->type)
            {
              (yyvsp[0].sdef)->type = (yyvsp[-2].yyint);
            }
          else
            {
              if ((yyvsp[0].sdef)->type != (yyvsp[-2].yyint))
                  werror(E_BAD_TAG, (yyvsp[0].sdef)->tag, (yyvsp[-2].yyint)==STRUCT ? "struct" : "union");
            }
        }
#line 3505 "src/SDCCy.c"
    break;

  case 153: /* struct_or_union_specifier: struct_or_union attribute_specifier_sequence_opt opt_stag $@7 '{' member_declaration_list '}'  */
#line 802 "src/SDCC.y"
        {
          structdef *sdef;
          symbol *sym, *dsym;

          // check for errors in structure members
          for (sym=(yyvsp[-1].sym); sym; sym=sym->next)
            {
              if (IS_ABSOLUTE(sym->etype))
                {
                  werrorfl(sym->fileDef, sym->lineDef, E_NOT_ALLOWED, "'at'");
                  SPEC_ABSA(sym->etype) = 0;
                }
              if (IS_SPEC(sym->etype) && SPEC_SCLS(sym->etype))
                {
                  werrorfl(sym->fileDef, sym->lineDef, E_NOT_ALLOWED, "storage class");
                  printTypeChainRaw (sym->type, NULL);
                  SPEC_SCLS(sym->etype) = 0;
                }
              for (dsym=sym->next; dsym; dsym=dsym->next)
                {
                  if (*dsym->name && strcmp(sym->name, dsym->name)==0)
                    {
                      werrorfl(sym->fileDef, sym->lineDef, E_DUPLICATE_MEMBER,
                               (yyvsp[-6].yyint)==STRUCT ? "struct" : "union", sym->name);
                      werrorfl(dsym->fileDef, dsym->lineDef, E_PREVIOUS_DEF);
                    }
                }
            }

          /* Create a structdef   */
          (yyvsp[-4].sdef)->fields = reverseSyms((yyvsp[-1].sym));        /* link the fields */
          (yyvsp[-4].sdef)->size = compStructSize((yyvsp[-6].yyint), (yyvsp[-4].sdef));   /* update size of  */
          promoteAnonStructs ((yyvsp[-6].yyint), (yyvsp[-4].sdef));

          if ((yyvsp[-4].sdef)->redefinition) // Since C23, multiple definitions for struct / union are allowed, if they are compatible and have the same tags. The current standard draft N3047 allows redeclarations of unions to have a different order of the members. We don't. The rule in N3047 is now considered a mistake by many, and will hopefully be changed to the SDCC behaviour via a national body comment for the final version of the standard.
            {
              sdef = findSymWithBlock (StructTab, (yyvsp[-4].sdef)->tagsym, currBlockno, NestLevel);
              bool compatible = options.std_c23 && sdef->tagsym && (yyvsp[-4].sdef)->tagsym && !strcmp (sdef->tagsym->name, (yyvsp[-4].sdef)->tagsym->name);
              for (symbol *fieldsym1 = sdef->fields, *fieldsym2 = (yyvsp[-4].sdef)->fields; compatible; fieldsym1 = fieldsym1->next, fieldsym2 = fieldsym2->next)
                {
                  if (!fieldsym1 && !fieldsym2)
                    break;
                  if (!fieldsym1 || !fieldsym2)
                    compatible = false;
                  else if (strcmp (fieldsym1->name, fieldsym2->name))
                    compatible = false;
                  else if (compareType (fieldsym1->type, fieldsym2->type, true) <= 0)
                    compatible = false;
               }
              if (!compatible)
                {
                  werror(E_STRUCT_REDEF_INCOMPATIBLE, (yyvsp[-4].sdef)->tag);
                  werrorfl(sdef->tagsym->fileDef, sdef->tagsym->lineDef, E_PREVIOUS_DEF);
                }
            }
          else
            sdef = (yyvsp[-4].sdef);

          /* Create the specifier */
          (yyval.lnk) = newLink (SPECIFIER);
          SPEC_NOUN((yyval.lnk)) = V_STRUCT;
          SPEC_STRUCT((yyval.lnk))= sdef;
        }
#line 3573 "src/SDCCy.c"
    break;

  case 154: /* struct_or_union_specifier: struct_or_union attribute_specifier_sequence_opt stag  */
#line 866 "src/SDCC.y"
        {
          structdef *sdef;

          sdef = findSymWithBlock (StructTab, (yyvsp[0].sdef)->tagsym, currBlockno, NestLevel);

          if (sdef)
            (yyvsp[0].sdef) = sdef;
          else
            {
              /* new struct def for current scope */
              addSym (StructTab, (yyvsp[0].sdef), (yyvsp[0].sdef)->tag, (yyvsp[0].sdef)->level, currBlockno, 0);
            }
          (yyval.lnk) = newLink(SPECIFIER);
          SPEC_NOUN((yyval.lnk)) = V_STRUCT;
          SPEC_STRUCT((yyval.lnk)) = (yyvsp[0].sdef);

          if (!(yyvsp[0].sdef)->type)
            {
              (yyvsp[0].sdef)->type = (yyvsp[-2].yyint);
            }
          else
            {
              if ((yyvsp[0].sdef)->type != (yyvsp[-2].yyint))
                  werror(E_BAD_TAG, (yyvsp[0].sdef)->tag, (yyvsp[-2].yyint)==STRUCT ? "struct" : "union");
            }
        }
#line 3604 "src/SDCCy.c"
    break;

  case 155: /* struct_or_union: STRUCT  */
#line 895 "src/SDCC.y"
                     { (yyval.yyint) = STRUCT; ignoreTypedefType = 1; }
#line 3610 "src/SDCCy.c"
    break;

  case 156: /* struct_or_union: UNION  */
#line 896 "src/SDCC.y"
                     { (yyval.yyint) = UNION; ignoreTypedefType = 1; }
#line 3616 "src/SDCCy.c"
    break;

  case 158: /* member_declaration_list: member_declaration_list member_declaration  */
#line 902 "src/SDCC.y"
        {
          symbol *sym = (yyvsp[0].sym);

          /* go to the end of the chain */
          while (sym->next) sym = sym->next;
          sym->next = (yyvsp[-1].sym);

           (yyval.sym) = (yyvsp[0].sym);
        }
#line 3630 "src/SDCCy.c"
    break;

  case 159: /* member_declaration: attribute_specifier_sequence_opt specifier_qualifier_list member_declarator_list ';'  */
#line 915 "src/SDCC.y"
        {
          /* add this type to all the symbols */
          symbol *sym;
          for ( sym = (yyvsp[-1].sym); sym != NULL; sym = sym->next )
            {
              sym_link *btype = copyLinkChain((yyvsp[-2].lnk));

              pointerTypes(sym->type, btype);
              if (!sym->type)
                {
                  sym->type = btype;
                  sym->etype = getSpec(sym->type);
                }
              else
                  addDecl (sym, 0, btype);
              /* make sure the type is complete and sane */
              checkTypeSanity(sym->etype, sym->name);
            }
          ignoreTypedefType = 0;
          (yyval.sym) = (yyvsp[-1].sym);
        }
#line 3656 "src/SDCCy.c"
    break;

  case 160: /* type_specifier_qualifier: type_specifier  */
#line 939 "src/SDCC.y"
                         { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3662 "src/SDCCy.c"
    break;

  case 161: /* type_specifier_qualifier: type_qualifier  */
#line 940 "src/SDCC.y"
                         { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3668 "src/SDCCy.c"
    break;

  case 162: /* type_specifier_qualifier: alignment_specifier  */
#line 941 "src/SDCC.y"
                         { (yyval.lnk) = (yyvsp[0].lnk); }
#line 3674 "src/SDCCy.c"
    break;

  case 164: /* member_declarator_list: member_declarator_list ',' member_declarator  */
#line 947 "src/SDCC.y"
        {
          (yyvsp[0].sym)->next  = (yyvsp[-2].sym);
          (yyval.sym) = (yyvsp[0].sym);
        }
#line 3683 "src/SDCCy.c"
    break;

  case 166: /* member_declarator: ':' constant_expr  */
#line 956 "src/SDCC.y"
        {
          unsigned int bitsize;
          (yyval.sym) = newSymbol (genSymName(NestLevel), NestLevel);
          bitsize = (unsigned int) ulFromVal(constExprValue((yyvsp[0].asts), true));
          if (!bitsize)
              bitsize = BITVAR_PAD;
          (yyval.sym)->bitVar = bitsize;
          (yyval.sym)->bitUnnamed = 1;
        }
#line 3697 "src/SDCCy.c"
    break;

  case 167: /* member_declarator: declarator ':' constant_expr  */
#line 966 "src/SDCC.y"
        {
          unsigned int bitsize;
          bitsize = (unsigned int) ulFromVal(constExprValue((yyvsp[0].asts), true));

          if (!bitsize)
            {
              (yyval.sym) = newSymbol (genSymName(NestLevel), NestLevel);
              (yyval.sym)->bitVar = BITVAR_PAD;
              werror(W_BITFLD_NAMED);
            }
          else
              (yyvsp[-2].sym)->bitVar = bitsize;
        }
#line 3715 "src/SDCCy.c"
    break;

  case 168: /* member_declarator: %empty  */
#line 979 "src/SDCC.y"
     { (yyval.sym) = newSymbol ("", NestLevel); }
#line 3721 "src/SDCCy.c"
    break;

  case 169: /* enum_specifier: ENUM '{' enumerator_list enum_comma_opt '}'  */
#line 984 "src/SDCC.y"
        {
          (yyval.lnk) = newEnumType ((yyvsp[-2].sym));
          SPEC_SCLS(getSpec((yyval.lnk))) = 0;
        }
#line 3730 "src/SDCCy.c"
    break;

  case 170: /* enum_specifier: ENUM identifier '{' enumerator_list enum_comma_opt '}'  */
#line 989 "src/SDCC.y"
        {
          symbol *csym;
          sym_link *enumtype;

          enumtype = newEnumType ((yyvsp[-2].sym));
          SPEC_SCLS(getSpec(enumtype)) = 0;
          (yyvsp[-4].sym)->type = enumtype;

          csym = findSymWithLevel(enumTab, (yyvsp[-4].sym));
          if ((csym && csym->level == (yyvsp[-4].sym)->level))
            {
              if (!options.std_c23 || compareType (csym->type, (yyvsp[-4].sym)->type, true) <= 0)
                {
                  werrorfl((yyvsp[-4].sym)->fileDef, (yyvsp[-4].sym)->lineDef, E_DUPLICATE_TYPEDEF, csym->name);
                  werrorfl(csym->fileDef, csym->lineDef, E_PREVIOUS_DEF);
                }
            }

          /* add this to the enumerator table */
          if (!csym)
              addSym (enumTab, (yyvsp[-4].sym), (yyvsp[-4].sym)->name, (yyvsp[-4].sym)->level, (yyvsp[-4].sym)->block, 0);
          (yyval.lnk) = copyLinkChain(enumtype);
        }
#line 3758 "src/SDCCy.c"
    break;

  case 171: /* enum_specifier: ENUM identifier  */
#line 1013 "src/SDCC.y"
        {
          symbol *csym;

          /* check the enumerator table */
          if ((csym = findSymWithLevel(enumTab, (yyvsp[0].sym))))
              (yyval.lnk) = copyLinkChain(csym->type);
          else
            {
              (yyval.lnk) = newLink(SPECIFIER);
              SPEC_NOUN((yyval.lnk)) = V_INT;
            }
        }
#line 3775 "src/SDCCy.c"
    break;

  case 172: /* enum_comma_opt: %empty  */
#line 1029 "src/SDCC.y"
     {
       (yyval.lnk) = NULL;
     }
#line 3783 "src/SDCCy.c"
    break;

  case 173: /* enum_comma_opt: ','  */
#line 1033 "src/SDCC.y"
     {
       if (!options.std_c99)
         werror (E_ENUM_COMMA_C99);
       (yyval.lnk) = NULL;
     }
#line 3793 "src/SDCCy.c"
    break;

  case 175: /* enumerator_list: enumerator_list ',' enumerator  */
#line 1042 "src/SDCC.y"
        {
          (yyvsp[0].sym)->next = (yyvsp[-2].sym);
          (yyval.sym) = (yyvsp[0].sym);
        }
#line 3802 "src/SDCCy.c"
    break;

  case 176: /* enumerator: identifier attribute_specifier_sequence_opt opt_assign_expr  */
#line 1050 "src/SDCC.y"
        {
          symbol *sym;

          (yyvsp[-2].sym)->type = copyLinkChain ((yyvsp[0].val)->type);
          (yyvsp[-2].sym)->etype = getSpec ((yyvsp[-2].sym)->type);
          SPEC_ENUM ((yyvsp[-2].sym)->etype) = 1;
          (yyval.sym) = (yyvsp[-2].sym);

          // check if the symbol at the same level already exists
          if ((sym = findSymWithLevel (SymbolTab, (yyvsp[-2].sym))) && sym->level == (yyvsp[-2].sym)->level)
            {
              // C23 allows redefinitions of enumeration constants with the same value as part of a redeclaration of the same enumerated type.
              if (!options.std_c23 || ullFromVal (valFromType (sym->type)) != ullFromVal (valFromType ((yyvsp[-2].sym)->type)))
                {
                  werrorfl ((yyvsp[-2].sym)->fileDef, (yyvsp[-2].sym)->lineDef, E_DUPLICATE_MEMBER, "enum", (yyvsp[-2].sym)->name);
                  werrorfl (sym->fileDef, sym->lineDef, E_PREVIOUS_DEF);
                }
            }
          else
            {
              // do this now, so we can use it for the next enums in the list
              addSymChain (&(yyvsp[-2].sym));
            }
        }
#line 3831 "src/SDCCy.c"
    break;

  case 177: /* type_qualifier: SD_CONST  */
#line 1077 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_CONST((yyval.lnk)) = 1;
               }
#line 3840 "src/SDCCy.c"
    break;

  case 178: /* type_qualifier: RESTRICT  */
#line 1081 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_RESTRICT((yyval.lnk)) = 1;
               }
#line 3849 "src/SDCCy.c"
    break;

  case 179: /* type_qualifier: VOLATILE  */
#line 1085 "src/SDCC.y"
               {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_VOLATILE((yyval.lnk)) = 1;
               }
#line 3858 "src/SDCCy.c"
    break;

  case 180: /* type_qualifier: ATOMIC  */
#line 1089 "src/SDCC.y"
             {
                  (yyval.lnk)=newLink(SPECIFIER);
                  werror (E_ATOMIC_UNSUPPORTED);
               }
#line 3867 "src/SDCCy.c"
    break;

  case 181: /* type_qualifier: ADDRSPACE_NAME  */
#line 1093 "src/SDCC.y"
                    {
                  (yyval.lnk)=newLink(SPECIFIER);
                  SPEC_ADDRSPACE((yyval.lnk)) = findSym (AddrspaceTab, 0, (yyvsp[0].yychar));
               }
#line 3876 "src/SDCCy.c"
    break;

  case 182: /* type_qualifier: XDATA  */
#line 1097 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_XDATA;
               }
#line 3885 "src/SDCCy.c"
    break;

  case 183: /* type_qualifier: CODE  */
#line 1101 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_CODE;
               }
#line 3894 "src/SDCCy.c"
    break;

  case 184: /* type_qualifier: EEPROM  */
#line 1105 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_EEPROM;
               }
#line 3903 "src/SDCCy.c"
    break;

  case 185: /* type_qualifier: DATA  */
#line 1109 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_DATA;
               }
#line 3912 "src/SDCCy.c"
    break;

  case 186: /* type_qualifier: IDATA  */
#line 1113 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_IDATA;
               }
#line 3921 "src/SDCCy.c"
    break;

  case 187: /* type_qualifier: PDATA  */
#line 1117 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_SCLS((yyval.lnk)) = S_PDATA;
               }
#line 3930 "src/SDCCy.c"
    break;

  case 188: /* function_specifier: INLINE  */
#line 1124 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_INLINE((yyval.lnk)) = 1;
               }
#line 3939 "src/SDCCy.c"
    break;

  case 189: /* function_specifier: NORETURN  */
#line 1128 "src/SDCC.y"
               {
                  (yyval.lnk) = newLink (SPECIFIER);
                  SPEC_NORETURN((yyval.lnk)) = 1;
               }
#line 3948 "src/SDCCy.c"
    break;

  case 190: /* alignment_specifier: ALIGNAS '(' type_name ')'  */
#line 1136 "src/SDCC.y"
              {
                 checkTypeSanity ((yyvsp[-1].lnk), "(_Alignas)");
                 (yyval.lnk) = newLink (SPECIFIER);
                 SPEC_ALIGNAS((yyval.lnk)) = 1;
              }
#line 3958 "src/SDCCy.c"
    break;

  case 191: /* alignment_specifier: ALIGNAS '(' constant_expr ')'  */
#line 1142 "src/SDCC.y"
              {
                 value *val = constExprValue ((yyvsp[-1].asts), true);
                 (yyval.lnk) = newLink (SPECIFIER);
                 SPEC_ALIGNAS((yyval.lnk)) = 0;
                 if (!val)
                   werror (E_CONST_EXPECTED);
                 else if (ulFromVal (val) == 0 || isPowerOf2 (ulFromVal (val)) && ulFromVal (val) <= port->mem.maxextalign)
                   SPEC_ALIGNAS((yyval.lnk)) = ulFromVal(val);
                 else
                   werror (E_ALIGNAS, ulFromVal(val));
              }
#line 3974 "src/SDCCy.c"
    break;

  case 192: /* declarator: direct_declarator  */
#line 1156 "src/SDCC.y"
                                              { (yyval.sym) = (yyvsp[0].sym); }
#line 3980 "src/SDCCy.c"
    break;

  case 193: /* declarator: pointer direct_declarator  */
#line 1158 "src/SDCC.y"
         {
             addDecl ((yyvsp[0].sym),0,reverseLink((yyvsp[-1].lnk)));
             (yyval.sym) = (yyvsp[0].sym);
         }
#line 3989 "src/SDCCy.c"
    break;

  case 195: /* direct_declarator: '(' declarator ')'  */
#line 1166 "src/SDCC.y"
                            { (yyval.sym) = (yyvsp[-1].sym); }
#line 3995 "src/SDCCy.c"
    break;

  case 199: /* declarator2: '(' declarator ')'  */
#line 1173 "src/SDCC.y"
                            { (yyval.sym) = (yyvsp[-1].sym); }
#line 4001 "src/SDCCy.c"
    break;

  case 201: /* array_declarator: direct_declarator '[' type_qualifier_list_opt ']'  */
#line 1179 "src/SDCC.y"
     {
       sym_link *p, *n;

       p = newLink (DECLARATOR);
       DCL_TYPE(p) = ARRAY;
       DCL_ELEM(p) = 0;

       if ((yyvsp[-1].lnk))
         {
           if (!options.std_c99)
             werror (E_QUALIFIED_ARRAY_PARAM_C99);

           DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[-1].lnk));
           DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[-1].lnk));
           DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[-1].lnk));
           DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[-1].lnk));
           addDecl((yyvsp[-3].sym),0,p);
           n = newLink (SPECIFIER);
           SPEC_NEEDSPAR(n) = 1;
           addDecl((yyvsp[-3].sym),0,n);
         }
       else
         addDecl((yyvsp[-3].sym),0,p);
     }
#line 4030 "src/SDCCy.c"
    break;

  case 202: /* array_declarator: direct_declarator '[' type_qualifier_list_opt assignment_expr ']'  */
#line 1204 "src/SDCC.y"
     {
       sym_link *p, *n;

       p = newLink (DECLARATOR);
       DCL_TYPE(p) = ARRAY;
       DCL_ELEM_AST (p) = (yyvsp[-1].asts);

       if ((yyvsp[-2].lnk))
         {
           if (!options.std_c99)
             werror (E_QUALIFIED_ARRAY_PARAM_C99);
           DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[-2].lnk));
           DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[-2].lnk));
           DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[-2].lnk));
           DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[-2].lnk));
           addDecl((yyvsp[-4].sym), 0, p);
           n = newLink (SPECIFIER);
           SPEC_NEEDSPAR(n) = 1;
           addDecl((yyvsp[-4].sym),0,n);
         }
       else
         addDecl((yyvsp[-4].sym), 0, p);
     }
#line 4058 "src/SDCCy.c"
    break;

  case 203: /* array_declarator: direct_declarator '[' STATIC type_qualifier_list_opt assignment_expr ']'  */
#line 1228 "src/SDCC.y"
     {
       sym_link *p, *n;

       if (!options.std_c99)
         werror (E_STATIC_ARRAY_PARAM_C99);

       p = newLink (DECLARATOR);
       DCL_TYPE(p) = ARRAY;
       DCL_ELEM_AST (p) = (yyvsp[-1].asts);

       if ((yyvsp[-2].lnk))
         {
           if (!options.std_c99)
             werror (E_QUALIFIED_ARRAY_PARAM_C99);
           DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[-2].lnk));
           DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[-2].lnk));
           DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[-2].lnk));
           DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[-2].lnk));
         }
       addDecl((yyvsp[-5].sym), 0, p);
       n = newLink (SPECIFIER);
       SPEC_NEEDSPAR(n) = 1;
       addDecl((yyvsp[-5].sym),0,n);
     }
#line 4087 "src/SDCCy.c"
    break;

  case 204: /* array_declarator: direct_declarator '[' type_qualifier_list STATIC assignment_expr ']'  */
#line 1253 "src/SDCC.y"
     {
       sym_link *p, *n;

       if (!options.std_c99)
         {
           werror (E_QUALIFIED_ARRAY_PARAM_C99);
           werror (E_STATIC_ARRAY_PARAM_C99);
         }

       p = newLink (DECLARATOR);
       DCL_TYPE(p) = ARRAY;
       DCL_ELEM_AST (p) = (yyvsp[-1].asts);

       DCL_PTR_CONST(p) = SPEC_CONST ((yyvsp[-3].lnk));
       DCL_PTR_RESTRICT(p) = SPEC_RESTRICT ((yyvsp[-3].lnk));
       DCL_PTR_VOLATILE(p) = SPEC_VOLATILE ((yyvsp[-3].lnk));
       DCL_PTR_ADDRSPACE(p) = SPEC_ADDRSPACE ((yyvsp[-3].lnk));
       addDecl((yyvsp[-5].sym), 0, p);
       n = newLink (SPECIFIER);
       SPEC_NEEDSPAR(n) = 1;
       addDecl((yyvsp[-5].sym),0,n);
     }
#line 4114 "src/SDCCy.c"
    break;

  case 205: /* declarator2_function_attributes: function_declarator  */
#line 1278 "src/SDCC.y"
                                         { (yyval.sym) = (yyvsp[0].sym); }
#line 4120 "src/SDCCy.c"
    break;

  case 206: /* declarator2_function_attributes: function_declarator function_attributes  */
#line 1279 "src/SDCC.y"
                                              {
           // copy the functionAttributes (not the args and hasVargs !!)
           sym_link *funcType=(yyvsp[-1].sym)->type;

           while (funcType && !IS_FUNC(funcType))
             funcType = funcType->next;

           if (!funcType)
             werror (E_FUNC_ATTR);
           else
             {
               struct value *args = FUNC_ARGS(funcType);
               unsigned hasVargs = FUNC_HASVARARGS(funcType);
               bool noprototype = FUNC_NOPROTOTYPE(funcType);

               memcpy (&funcType->funcAttrs, &(yyvsp[0].lnk)->funcAttrs,
                   sizeof((yyvsp[0].lnk)->funcAttrs));

               FUNC_ARGS(funcType)=args;
               FUNC_HASVARARGS(funcType)=hasVargs;
               FUNC_NOPROTOTYPE(funcType)=noprototype;

               // just to be sure
               memset (&(yyvsp[0].lnk)->funcAttrs, 0,
                   sizeof((yyvsp[0].lnk)->funcAttrs));

               addDecl ((yyvsp[-1].sym),0,(yyvsp[0].lnk));
             }
   }
#line 4154 "src/SDCCy.c"
    break;

  case 207: /* function_declarator: declarator2 '(' ')'  */
#line 1312 "src/SDCC.y"
     {
       addDecl ((yyvsp[-2].sym), FUNCTION, NULL);

       // Up to C17, this was a function declarator without a prototype.
       if (!options.std_c23)
         {
           FUNC_NOPROTOTYPE((yyvsp[-2].sym)->type) = true;
           if (!options.lessPedantic)
             werror (W_FUNCDECL_WITH_NO_PROTOTYPE);
         }
     }
#line 4170 "src/SDCCy.c"
    break;

  case 208: /* $@8: %empty  */
#line 1324 "src/SDCC.y"
        {
          NestLevel += LEVEL_UNIT;
          STACK_PUSH(blockNum, currBlockno);
          btree_add_child(currBlockno, ++blockNo);
          currBlockno = blockNo;
          seqPointNo++; /* not a true sequence point, but helps resolve scope */
        }
#line 4182 "src/SDCCy.c"
    break;

  case 209: /* function_declarator: declarator2 '(' $@8 parameter_type_list ')'  */
#line 1332 "src/SDCC.y"
        {
          sym_link *funcType;

          bool is_fptr = IS_FUNC((yyvsp[-4].sym)->type); // Already a function, must be a function pointer.

          addDecl ((yyvsp[-4].sym), FUNCTION, NULL);
          funcType = (yyvsp[-4].sym)->type;

          // For a function pointer, the parameter list here is for the returned type.
          if (is_fptr)
            funcType = funcType->next;

          while (funcType && !IS_FUNC(funcType))
            funcType = funcType->next;

          wassert (funcType);

          FUNC_HASVARARGS(funcType) = IS_VARG((yyvsp[-1].val));
          FUNC_ARGS(funcType) = reverseVal((yyvsp[-1].val));

          FUNC_SDCCCALL(funcType) = -1;

          /* nest level was incremented to take care of the parms  */
          leaveBlockScope (currBlockno);
          NestLevel -= LEVEL_UNIT;
          currBlockno = STACK_POP(blockNum);
          seqPointNo++; /* not a true sequence point, but helps resolve scope */

          // if this was a pointer (to a function)
          if (!IS_FUNC((yyvsp[-4].sym)->type))
              cleanUpLevel(SymbolTab, NestLevel + LEVEL_UNIT);

          (yyval.sym) = (yyvsp[-4].sym);
        }
#line 4221 "src/SDCCy.c"
    break;

  case 210: /* function_declarator: declarator2 '(' identifier_list ')'  */
#line 1367 "src/SDCC.y"
        {
          werror(E_OLD_STYLE,(yyvsp[-3].sym)->name);
          
          addDecl ((yyvsp[-3].sym), FUNCTION, NULL);
          
          (yyval.sym) = (yyvsp[-3].sym);
        }
#line 4233 "src/SDCCy.c"
    break;

  case 211: /* pointer: unqualified_pointer  */
#line 1377 "src/SDCC.y"
                         { (yyval.lnk) = (yyvsp[0].lnk);}
#line 4239 "src/SDCCy.c"
    break;

  case 212: /* pointer: unqualified_pointer AT '(' constant_expr ')'  */
#line 1379 "src/SDCC.y"
         {
             sym_link *n = newLink(SPECIFIER);
             /* add this to the storage class specifier  */
             SPEC_ABSA(n) = 1;   /* set the absolute addr flag */
             /* now get the abs addr from value */
             SPEC_ADDR(n) = (unsigned int) ulFromVal(constExprValue((yyvsp[-1].asts),true));
             n->next = (yyvsp[-4].lnk);
             (yyval.lnk) = n;
         }
#line 4253 "src/SDCCy.c"
    break;

  case 213: /* pointer: unqualified_pointer type_qualifier_list  */
#line 1389 "src/SDCC.y"
         {
             (yyval.lnk) = (yyvsp[-1].lnk);
             if (IS_SPEC((yyvsp[0].lnk))) {
                 DCL_TSPEC((yyvsp[-1].lnk)) = (yyvsp[0].lnk);
                 DCL_PTR_CONST((yyvsp[-1].lnk)) = SPEC_CONST((yyvsp[0].lnk));
                 DCL_PTR_VOLATILE((yyvsp[-1].lnk)) = SPEC_VOLATILE((yyvsp[0].lnk));
                 DCL_PTR_RESTRICT((yyvsp[-1].lnk)) = SPEC_RESTRICT((yyvsp[0].lnk));
                 DCL_PTR_ADDRSPACE((yyvsp[-1].lnk)) = SPEC_ADDRSPACE((yyvsp[0].lnk));
             }
             else
                 werror (W_PTR_TYPE_INVALID);
         }
#line 4270 "src/SDCCy.c"
    break;

  case 214: /* pointer: unqualified_pointer type_qualifier_list AT '(' constant_expr ')'  */
#line 1402 "src/SDCC.y"
         {
             if (IS_SPEC((yyvsp[-4].lnk))) {
                 DCL_TSPEC((yyvsp[-5].lnk)) = (yyvsp[-4].lnk);
                 DCL_PTR_CONST((yyvsp[-5].lnk)) = SPEC_CONST((yyvsp[-4].lnk));
                 DCL_PTR_VOLATILE((yyvsp[-5].lnk)) = SPEC_VOLATILE((yyvsp[-4].lnk));
                 DCL_PTR_RESTRICT((yyvsp[-5].lnk)) = SPEC_RESTRICT((yyvsp[-4].lnk));
                 DCL_PTR_ADDRSPACE((yyvsp[-5].lnk)) = SPEC_ADDRSPACE((yyvsp[-4].lnk));
             }
             else
                 werror (W_PTR_TYPE_INVALID);

             sym_link *n = newLink(SPECIFIER);
             /* add this to the storage class specifier  */
             SPEC_ABSA(n) = 1;   /* set the absolute addr flag */
             /* now get the abs addr from value */
             SPEC_ADDR(n) = (unsigned int) ulFromVal(constExprValue((yyvsp[-1].asts),true));
             n->next = (yyvsp[-5].lnk);
             (yyval.lnk) = n;
         }
#line 4294 "src/SDCCy.c"
    break;

  case 215: /* pointer: unqualified_pointer pointer  */
#line 1422 "src/SDCC.y"
         {
             (yyval.lnk) = (yyvsp[-1].lnk);
             (yyval.lnk)->next = (yyvsp[0].lnk);
             DCL_TYPE((yyvsp[0].lnk))=port->unqualified_pointer;
         }
#line 4304 "src/SDCCy.c"
    break;

  case 216: /* pointer: unqualified_pointer type_qualifier_list pointer  */
#line 1428 "src/SDCC.y"
         {
             (yyval.lnk) = (yyvsp[-2].lnk);
             if (IS_SPEC((yyvsp[-1].lnk)) && DCL_TYPE((yyvsp[0].lnk)) == UPOINTER) {
                 DCL_PTR_CONST((yyvsp[-2].lnk)) = SPEC_CONST((yyvsp[-1].lnk));
                 DCL_PTR_VOLATILE((yyvsp[-2].lnk)) = SPEC_VOLATILE((yyvsp[-1].lnk));
                 DCL_PTR_RESTRICT((yyvsp[-2].lnk)) = SPEC_RESTRICT((yyvsp[-1].lnk));
                 DCL_PTR_ADDRSPACE((yyvsp[-2].lnk)) = SPEC_ADDRSPACE((yyvsp[-1].lnk));
                 switch (SPEC_SCLS((yyvsp[-1].lnk))) {
                 case S_XDATA:
                     DCL_TYPE((yyvsp[0].lnk)) = FPOINTER;
                     break;
                 case S_IDATA:
                     DCL_TYPE((yyvsp[0].lnk)) = IPOINTER;
                     break;
                 case S_PDATA:
                     DCL_TYPE((yyvsp[0].lnk)) = PPOINTER;
                     break;
                 case S_DATA:
                     DCL_TYPE((yyvsp[0].lnk)) = POINTER;
                     break;
                 case S_CODE:
                     DCL_TYPE((yyvsp[0].lnk)) = CPOINTER;
                     break;
                 case S_EEPROM:
                     DCL_TYPE((yyvsp[0].lnk)) = EEPPOINTER;
                     break;
                 default:
                   // this could be just "constant"
                   // werror(W_PTR_TYPE_INVALID);
                     ;
                 }
             }
             else
                 werror (W_PTR_TYPE_INVALID);
             (yyval.lnk)->next = (yyvsp[0].lnk);
         }
#line 4345 "src/SDCCy.c"
    break;

  case 217: /* unqualified_pointer: '*'  */
#line 1468 "src/SDCC.y"
      {
        (yyval.lnk) = newLink(DECLARATOR);
        DCL_TYPE((yyval.lnk))=UPOINTER;
      }
#line 4354 "src/SDCCy.c"
    break;

  case 219: /* type_qualifier_list: type_qualifier_list type_qualifier  */
#line 1477 "src/SDCC.y"
               {
                 (yyval.lnk) = mergeDeclSpec((yyvsp[-1].lnk), (yyvsp[0].lnk), "type_qualifier_list type_qualifier skipped");
               }
#line 4362 "src/SDCCy.c"
    break;

  case 220: /* type_qualifier_list_opt: %empty  */
#line 1484 "src/SDCC.y"
    {
      (yyval.lnk) = 0;
    }
#line 4370 "src/SDCCy.c"
    break;

  case 221: /* type_qualifier_list_opt: type_qualifier_list  */
#line 1488 "src/SDCC.y"
    {
      (yyval.lnk) = (yyvsp[0].lnk);
    }
#line 4378 "src/SDCCy.c"
    break;

  case 223: /* parameter_type_list: parameter_list ',' ELLIPSIS  */
#line 1495 "src/SDCC.y"
                                      { (yyvsp[-2].val)->vArgs = 1;}
#line 4384 "src/SDCCy.c"
    break;

  case 225: /* parameter_list: parameter_list ',' parameter_declaration  */
#line 1501 "src/SDCC.y"
         {
            (yyvsp[0].val)->next = (yyvsp[-2].val);
            (yyval.val) = (yyvsp[0].val);
         }
#line 4393 "src/SDCCy.c"
    break;

  case 226: /* parameter_declaration: declaration_specifiers declarator  */
#line 1509 "src/SDCC.y"
        {
          symbol *loop;

          if (IS_SPEC ((yyvsp[-1].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[-1].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, (yyvsp[0].sym)->name);
            }
          pointerTypes ((yyvsp[0].sym)->type, (yyvsp[-1].lnk));
          if (IS_SPEC ((yyvsp[0].sym)->etype))
            SPEC_NEEDSPAR((yyvsp[0].sym)->etype) = 0;
          addDecl ((yyvsp[0].sym), 0, (yyvsp[-1].lnk));
          for (loop = (yyvsp[0].sym); loop; loop->_isparm = 1, loop = loop->next)
            ;
          (yyval.val) = symbolVal ((yyvsp[0].sym));
          ignoreTypedefType = 0;
        }
#line 4414 "src/SDCCy.c"
    break;

  case 227: /* parameter_declaration: type_name  */
#line 1526 "src/SDCC.y"
        {
          (yyval.val) = newValue ();
          (yyval.val)->type = (yyvsp[0].lnk);
          (yyval.val)->etype = getSpec ((yyval.val)->type);
          ignoreTypedefType = 0;
         }
#line 4425 "src/SDCCy.c"
    break;

  case 228: /* abstract_declarator: pointer  */
#line 1535 "src/SDCC.y"
             { (yyval.lnk) = reverseLink((yyvsp[0].lnk)); }
#line 4431 "src/SDCCy.c"
    break;

  case 230: /* abstract_declarator: pointer direct_abstract_declarator  */
#line 1537 "src/SDCC.y"
                                          { (yyvsp[-1].lnk) = reverseLink((yyvsp[-1].lnk)); (yyvsp[0].lnk)->next = (yyvsp[-1].lnk); (yyval.lnk) = (yyvsp[0].lnk);
          if (IS_PTR((yyvsp[-1].lnk)) && IS_FUNC((yyvsp[0].lnk)))
            DCL_TYPE((yyvsp[-1].lnk)) = CPOINTER;
        }
#line 4440 "src/SDCCy.c"
    break;

  case 231: /* direct_abstract_declarator: '(' abstract_declarator ')'  */
#line 1544 "src/SDCC.y"
                                    { (yyval.lnk) = (yyvsp[-1].lnk); }
#line 4446 "src/SDCCy.c"
    break;

  case 234: /* direct_abstract_declarator_opt: %empty  */
#line 1550 "src/SDCC.y"
                                 { (yyval.lnk) = NULL; }
#line 4452 "src/SDCCy.c"
    break;

  case 236: /* array_abstract_declarator: direct_abstract_declarator_opt '[' ']'  */
#line 1555 "src/SDCC.y"
                                              {
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = 0;
                                       if((yyvsp[-2].lnk))
                                         (yyval.lnk)->next = (yyvsp[-2].lnk);
                                    }
#line 4464 "src/SDCCy.c"
    break;

  case 237: /* array_abstract_declarator: direct_abstract_declarator_opt '[' constant_expr ']'  */
#line 1563 "src/SDCC.y"
                                    {
                                       value *val;
                                       (yyval.lnk) = newLink (DECLARATOR);
                                       DCL_TYPE((yyval.lnk)) = ARRAY;
                                       DCL_ELEM((yyval.lnk)) = (int) ulFromVal(val = constExprValue((yyvsp[-1].asts), true));
                                       if((yyvsp[-3].lnk))
                                         (yyval.lnk)->next = (yyvsp[-3].lnk);
                                    }
#line 4477 "src/SDCCy.c"
    break;

  case 238: /* function_abstract_declarator: '(' ')'  */
#line 1574 "src/SDCC.y"
                                    { (yyval.lnk) = NULL;}
#line 4483 "src/SDCCy.c"
    break;

  case 239: /* function_abstract_declarator: direct_abstract_declarator '(' ')'  */
#line 1575 "src/SDCC.y"
                                        {
     // $1 must be a pointer to a function
     sym_link *p=newLink(DECLARATOR);
     DCL_TYPE(p) = FUNCTION;
     if (!(yyvsp[-2].lnk)) {
       // ((void (code *) ()) 0) ()
       (yyvsp[-2].lnk)=newLink(DECLARATOR);
       DCL_TYPE((yyvsp[-2].lnk))=CPOINTER;
       (yyval.lnk) = (yyvsp[-2].lnk);
     }
     (yyvsp[-2].lnk)->next=p;
   }
#line 4500 "src/SDCCy.c"
    break;

  case 240: /* function_abstract_declarator: '(' parameter_type_list ')'  */
#line 1587 "src/SDCC.y"
                                    { (yyval.lnk) = NULL;}
#line 4506 "src/SDCCy.c"
    break;

  case 241: /* $@9: %empty  */
#line 1589 "src/SDCC.y"
        {
          NestLevel += LEVEL_UNIT;
          STACK_PUSH(blockNum, currBlockno);
          btree_add_child(currBlockno, ++blockNo);
          currBlockno = blockNo;
        }
#line 4517 "src/SDCCy.c"
    break;

  case 242: /* function_abstract_declarator: direct_abstract_declarator '(' $@9 parameter_type_list ')'  */
#line 1596 "src/SDCC.y"
        {
          sym_link *p = newLink(DECLARATOR), *q;
          DCL_TYPE(p) = FUNCTION;

          FUNC_HASVARARGS(p) = IS_VARG((yyvsp[-1].val));
          FUNC_ARGS(p) = reverseVal((yyvsp[-1].val));

          /* nest level was incremented to take care of the parms  */
          NestLevel -= LEVEL_UNIT;
          currBlockno = STACK_POP(blockNum);
          if (!(yyvsp[-4].lnk))
            {
              /* ((void (code *) (void)) 0) () */
              (yyvsp[-4].lnk) = newLink(DECLARATOR);
              DCL_TYPE((yyvsp[-4].lnk)) = CPOINTER;
              (yyval.lnk) = (yyvsp[-4].lnk);
            }
          for (q = (yyvsp[-4].lnk); q && q->next; q = q->next);
          q->next = p;
        }
#line 4542 "src/SDCCy.c"
    break;

  case 243: /* initializer: assignment_expr  */
#line 1619 "src/SDCC.y"
                                    { (yyval.ilist) = newiList(INIT_NODE,(yyvsp[0].asts)); }
#line 4548 "src/SDCCy.c"
    break;

  case 244: /* initializer: '{' '}'  */
#line 1621 "src/SDCC.y"
     {
       if (!options.std_c23)
         werror(W_EMPTY_INIT_C23);
       // {} behaves mostly like {0}, so we emulate that, and use the isempty flag for the few cases where there is a difference.
       (yyval.ilist) = newiList(INIT_DEEP, revinit(newiList(INIT_NODE, newAst_VALUE(constIntVal("0")))));
       (yyval.ilist)->isempty = true;
     }
#line 4560 "src/SDCCy.c"
    break;

  case 245: /* initializer: '{' initializer_list '}'  */
#line 1628 "src/SDCC.y"
                                    { (yyval.ilist) = newiList(INIT_DEEP,revinit((yyvsp[-1].ilist))); }
#line 4566 "src/SDCCy.c"
    break;

  case 246: /* initializer: '{' initializer_list ',' '}'  */
#line 1629 "src/SDCC.y"
                                    { (yyval.ilist) = newiList(INIT_DEEP,revinit((yyvsp[-2].ilist))); }
#line 4572 "src/SDCCy.c"
    break;

  case 247: /* initializer_list: designation_opt initializer  */
#line 1633 "src/SDCC.y"
                                    { (yyvsp[0].ilist)->designation = (yyvsp[-1].dsgn); (yyval.ilist) = (yyvsp[0].ilist); }
#line 4578 "src/SDCCy.c"
    break;

  case 248: /* initializer_list: initializer_list ',' designation_opt initializer  */
#line 1635 "src/SDCC.y"
                                    {
                                       (yyvsp[0].ilist)->designation = (yyvsp[-1].dsgn);
                                       (yyvsp[0].ilist)->next = (yyvsp[-3].ilist);
                                       (yyval.ilist) = (yyvsp[0].ilist);
                                    }
#line 4588 "src/SDCCy.c"
    break;

  case 249: /* designation_opt: %empty  */
#line 1643 "src/SDCC.y"
                                 { (yyval.dsgn) = NULL; }
#line 4594 "src/SDCCy.c"
    break;

  case 251: /* designation: designator_list '='  */
#line 1648 "src/SDCC.y"
                                 { (yyval.dsgn) = revDesignation((yyvsp[-1].dsgn)); }
#line 4600 "src/SDCCy.c"
    break;

  case 253: /* designator_list: designator_list designator  */
#line 1653 "src/SDCC.y"
                                 { (yyvsp[0].dsgn)->next = (yyvsp[-1].dsgn); (yyval.dsgn) = (yyvsp[0].dsgn); }
#line 4606 "src/SDCCy.c"
    break;

  case 254: /* designator: '[' constant_expr ']'  */
#line 1658 "src/SDCC.y"
         {
            value *tval;
            int elemno;

            tval = constExprValue((yyvsp[-1].asts), true);
            /* if it is not a constant then Error  */
            if (!tval || (SPEC_SCLS(tval->etype) != S_LITERAL))
              {
                werror (E_CONST_EXPECTED);
                elemno = 0; /* arbitrary fixup */
              }
            else
              {
                if ((elemno = (int) ulFromVal(tval)) < 0)
                  {
                    werror (E_BAD_DESIGNATOR);
                    elemno = 0; /* arbitrary fixup */
                  }
              }
            (yyval.dsgn) = newDesignation(DESIGNATOR_ARRAY, &elemno);
         }
#line 4632 "src/SDCCy.c"
    break;

  case 255: /* designator: '.' identifier  */
#line 1679 "src/SDCC.y"
                                 { (yyval.dsgn) = newDesignation(DESIGNATOR_STRUCT,(yyvsp[0].sym)); }
#line 4638 "src/SDCCy.c"
    break;

  case 256: /* static_assert_declaration: STATIC_ASSERT '(' constant_expr ',' STRING_LITERAL ')' ';'  */
#line 1684 "src/SDCC.y"
                                    {
                                       value *val = constExprValue ((yyvsp[-4].asts), true);
                                       if (!val)
                                         werror (E_CONST_EXPECTED);
                                       else if (!ullFromVal(val))
                                         werror (W_STATIC_ASSERTION, (yyvsp[-2].yystr));
                                    }
#line 4650 "src/SDCCy.c"
    break;

  case 257: /* static_assert_declaration: STATIC_ASSERT '(' constant_expr ')' ';'  */
#line 1692 "src/SDCC.y"
                                    {
                                       value *val = constExprValue ((yyvsp[-2].asts), true);
                                       if (!options.std_c23)
                                         werror (E_STATIC_ASSERTION_C23);
                                       if (!val)
                                         werror (E_CONST_EXPECTED);
                                       else if (!ullFromVal(val))
                                         werror (W_STATIC_ASSERTION_2);
                                    }
#line 4664 "src/SDCCy.c"
    break;

  case 258: /* attribute_specifier_sequence: attribute_specifier_sequence attribute_specifier  */
#line 1705 "src/SDCC.y"
     {
       (yyval.attr) = (yyvsp[-1].attr);
       attribute *a;
       for (a = (yyval.attr); a->next; a = a->next);
       a->next = (yyvsp[0].attr);
     }
#line 4675 "src/SDCCy.c"
    break;

  case 259: /* attribute_specifier_sequence: attribute_specifier  */
#line 1712 "src/SDCC.y"
     {
       (yyval.attr) = (yyvsp[0].attr);
     }
#line 4683 "src/SDCCy.c"
    break;

  case 260: /* attribute_specifier_sequence_opt: %empty  */
#line 1719 "src/SDCC.y"
     {
       (yyval.attr) = 0;
     }
#line 4691 "src/SDCCy.c"
    break;

  case 261: /* attribute_specifier_sequence_opt: attribute_specifier_sequence  */
#line 1723 "src/SDCC.y"
     {
       (yyval.attr) = (yyvsp[0].attr);
     }
#line 4699 "src/SDCCy.c"
    break;

  case 262: /* attribute_specifier: ATTR_START attribute_list ']' ']'  */
#line 1730 "src/SDCC.y"
     {
       if (!options.std_c23)
         werror(E_ATTRIBUTE_C23);
       (yyval.attr) = (yyvsp[-2].attr);
     }
#line 4709 "src/SDCCy.c"
    break;

  case 263: /* attribute_list: attribute_opt  */
#line 1739 "src/SDCC.y"
     {
       (yyval.attr) = (yyvsp[0].attr);
     }
#line 4717 "src/SDCCy.c"
    break;

  case 264: /* attribute_list: attribute_list ',' attribute_opt  */
#line 1743 "src/SDCC.y"
     {
       (yyval.attr) = (yyvsp[-2].attr);
       if ((yyvsp[0].attr))
         {
           attribute *a;
           for (a = (yyval.attr); a->next; a = a->next);
           a->next = (yyvsp[0].attr);
         }
     }
#line 4731 "src/SDCCy.c"
    break;

  case 265: /* attribute: attribute_token  */
#line 1756 "src/SDCC.y"
   {
     (yyval.attr) = newAttribute ((yyvsp[0].sym), 0);
   }
#line 4739 "src/SDCCy.c"
    break;

  case 266: /* attribute: attribute_token attribute_argument_clause  */
#line 1760 "src/SDCC.y"
   {
     (yyval.attr) = newAttribute ((yyvsp[-1].sym), 0);
   }
#line 4747 "src/SDCCy.c"
    break;

  case 267: /* attribute_opt: %empty  */
#line 1767 "src/SDCC.y"
     {
       (yyval.attr) = 0;
     }
#line 4755 "src/SDCCy.c"
    break;

  case 268: /* attribute_opt: attribute  */
#line 1771 "src/SDCC.y"
     {
       (yyval.attr) = (yyvsp[0].attr);
     }
#line 4763 "src/SDCCy.c"
    break;

  case 269: /* attribute_token: identifier  */
#line 1778 "src/SDCC.y"
     {
       (yyval.sym) = (yyvsp[0].sym);
       (yyval.sym)->next = 0;
       werror (W_UNKNOWN_ATTRIBUTE, (yyvsp[0].sym)->name);
     }
#line 4773 "src/SDCCy.c"
    break;

  case 270: /* attribute_token: identifier TOK_SEP identifier  */
#line 1784 "src/SDCC.y"
     {
       (yyval.sym) = (yyvsp[-2].sym);
       (yyval.sym)->next = (yyvsp[0].sym);
       struct dbuf_s dbuf;
       dbuf_init (&dbuf, 64);
       dbuf_printf (&dbuf, "%s::%s", (yyvsp[-2].sym)->name, (yyvsp[0].sym)->name);
       werror (W_UNKNOWN_ATTRIBUTE, dbuf_c_str (&dbuf));
       dbuf_destroy (&dbuf);
     }
#line 4787 "src/SDCCy.c"
    break;

  case 281: /* unlabeled_statement: attribute_specifier_sequence_opt primary_block  */
#line 1822 "src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[0].asts);
     }
#line 4795 "src/SDCCy.c"
    break;

  case 282: /* unlabeled_statement: attribute_specifier_sequence_opt jump_statement  */
#line 1826 "src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[0].asts);
     }
#line 4803 "src/SDCCy.c"
    break;

  case 285: /* primary_block: compound_statement  */
#line 1835 "src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[0].asts);
     }
#line 4811 "src/SDCCy.c"
    break;

  case 286: /* primary_block: selection_statement  */
#line 1839 "src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[0].asts);
     }
#line 4819 "src/SDCCy.c"
    break;

  case 287: /* primary_block: iteration_statement  */
#line 1843 "src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[0].asts);
     }
#line 4827 "src/SDCCy.c"
    break;

  case 288: /* secondary_block: statement  */
#line 1850 "src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[0].asts);
     }
#line 4835 "src/SDCCy.c"
    break;

  case 289: /* labeled_statement: label statement  */
#line 1857 "src/SDCC.y"
     {
       if ((yyvsp[-1].asts))
         {
           (yyval.asts) = (yyvsp[-1].asts);
           (yyvsp[-1].asts)->right = (yyvsp[0].asts);
         }
       else
         (yyval.asts) = newNode (BLOCK, NULL, NULL);
     }
#line 4849 "src/SDCCy.c"
    break;

  case 290: /* label: identifier ':'  */
#line 1870 "src/SDCC.y"
     {
       (yyval.asts) = createLabel((yyvsp[-1].sym),NULL);
       (yyvsp[-1].sym)->isitmp = 0;
     }
#line 4858 "src/SDCCy.c"
    break;

  case 291: /* label: attribute_specifier_sequence_opt CASE constant_expr ':'  */
#line 1875 "src/SDCC.y"
     {
       if (STACK_EMPTY(swStk))
         (yyval.asts) = createCase(NULL,(yyvsp[-1].asts),NULL);
       else
         (yyval.asts) = createCase(STACK_PEEK(swStk),(yyvsp[-1].asts),NULL);
     }
#line 4869 "src/SDCCy.c"
    break;

  case 292: /* @10: %empty  */
#line 1881 "src/SDCC.y"
                                              { (yyval.asts) = newNode(DEFAULT,NULL,NULL); }
#line 4875 "src/SDCCy.c"
    break;

  case 293: /* label: attribute_specifier_sequence_opt DEFAULT @10 ':'  */
#line 1882 "src/SDCC.y"
     {
       if (STACK_EMPTY(swStk))
         (yyval.asts) = createDefault(NULL,(yyvsp[-1].asts),NULL);
       else
         (yyval.asts) = createDefault(STACK_PEEK(swStk),(yyvsp[-1].asts),NULL);
     }
#line 4886 "src/SDCCy.c"
    break;

  case 294: /* start_block: '{'  */
#line 1892 "src/SDCC.y"
        {
          NestLevel += LEVEL_UNIT;
          STACK_PUSH(blockNum, currBlockno);
          btree_add_child(currBlockno, ++blockNo);
          currBlockno = blockNo;
          ignoreTypedefType = 0;
        }
#line 4898 "src/SDCCy.c"
    break;

  case 295: /* end_block: '}'  */
#line 1903 "src/SDCC.y"
        {
          leaveBlockScope (currBlockno);
          NestLevel -= LEVEL_UNIT;
          currBlockno = STACK_POP(blockNum);
        }
#line 4908 "src/SDCCy.c"
    break;

  case 296: /* compound_statement: start_block end_block  */
#line 1911 "src/SDCC.y"
                                              { (yyval.asts) = createBlock(NULL, NULL); }
#line 4914 "src/SDCCy.c"
    break;

  case 297: /* compound_statement: start_block block_item_list end_block  */
#line 1913 "src/SDCC.y"
     {
       (yyval.asts) = (yyvsp[-1].asts);
       cleanUpLevel(StructTab, NestLevel + LEVEL_UNIT);
     }
#line 4923 "src/SDCCy.c"
    break;

  case 298: /* block_item_list: statements_and_implicit  */
#line 1920 "src/SDCC.y"
                                              { (yyval.asts) = createBlock(NULL, (yyvsp[0].asts)); }
#line 4929 "src/SDCCy.c"
    break;

  case 299: /* block_item_list: declaration_list  */
#line 1921 "src/SDCC.y"
                                              { (yyval.asts) = createBlock((yyvsp[0].sym), NULL); }
#line 4935 "src/SDCCy.c"
    break;

  case 300: /* block_item_list: declaration_list statements_and_implicit  */
#line 1922 "src/SDCC.y"
                                              { (yyval.asts) = createBlock((yyvsp[-1].sym), (yyvsp[0].asts)); }
#line 4941 "src/SDCCy.c"
    break;

  case 302: /* expression_statement: attribute_specifier_sequence expression ';'  */
#line 1927 "src/SDCC.y"
                                                           { (yyval.asts) = (yyvsp[-1].asts); seqPointNo++;}
#line 4947 "src/SDCCy.c"
    break;

  case 303: /* else_statement: ELSE statement  */
#line 1931 "src/SDCC.y"
                        { (yyval.asts) = (yyvsp[0].asts); }
#line 4953 "src/SDCCy.c"
    break;

  case 304: /* else_statement: %empty  */
#line 1932 "src/SDCC.y"
                        { (yyval.asts) = NULL; }
#line 4959 "src/SDCCy.c"
    break;

  case 305: /* $@11: %empty  */
#line 1937 "src/SDCC.y"
                           { seqPointNo++;}
#line 4965 "src/SDCCy.c"
    break;

  case 306: /* selection_statement: IF '(' expression ')' $@11 statement else_statement  */
#line 1938 "src/SDCC.y"
                           {
                              noLineno++;
                              (yyval.asts) = createIf ((yyvsp[-4].asts), (yyvsp[-1].asts), (yyvsp[0].asts) );
                              (yyval.asts)->lineno = (yyvsp[-4].asts)->lineno;
                              (yyval.asts)->filename = (yyvsp[-4].asts)->filename;
                              noLineno--;
                           }
#line 4977 "src/SDCCy.c"
    break;

  case 307: /* @12: %empty  */
#line 1945 "src/SDCC.y"
                                 {
                              ast *ex;
                              static   int swLabel = 0;

                              seqPointNo++;
                              /* create a node for expression  */
                              ex = newNode(SWITCH,(yyvsp[-1].asts),NULL);
                              STACK_PUSH(swStk,ex);   /* save it in the stack */
                              ex->values.switchVals.swNum = swLabel;

                              /* now create the label */
                              SNPRINTF(lbuff, sizeof(lbuff),
                                       "_swBrk_%d",swLabel++);
                              (yyval.sym)  =  newSymbol(lbuff,NestLevel);
                              /* put label in the break stack  */
                              STACK_PUSH(breakStack,(yyval.sym));
                           }
#line 4999 "src/SDCCy.c"
    break;

  case 308: /* selection_statement: SWITCH '(' expression ')' @12 secondary_block  */
#line 1962 "src/SDCC.y"
                           {
                              /* get back the switch form the stack  */
                              (yyval.asts) = STACK_POP(swStk);
                              (yyval.asts)->right = newNode (NULLOP,(yyvsp[0].asts),createLabel((yyvsp[-1].sym),NULL));
                              STACK_POP(breakStack);
                           }
#line 5010 "src/SDCCy.c"
    break;

  case 309: /* $@13: %empty  */
#line 1971 "src/SDCC.y"
                              { seqPointNo++;}
#line 5016 "src/SDCCy.c"
    break;

  case 310: /* iteration_statement: while '(' expression ')' $@13 secondary_block  */
#line 1972 "src/SDCC.y"
                         {
                           noLineno++;
                           (yyval.asts) = createWhile ( (yyvsp[-5].sym), STACK_POP(continueStack),
                                              STACK_POP(breakStack), (yyvsp[-3].asts), (yyvsp[0].asts) );
                           (yyval.asts)->lineno = (yyvsp[-5].sym)->lineDef;
                           (yyval.asts)->filename = (yyvsp[-5].sym)->fileDef;
                           noLineno--;
                         }
#line 5029 "src/SDCCy.c"
    break;

  case 311: /* iteration_statement: do secondary_block WHILE '(' expression ')' ';'  */
#line 1981 "src/SDCC.y"
                        {
                          seqPointNo++;
                          noLineno++;
                          (yyval.asts) = createDo ( (yyvsp[-6].sym) , STACK_POP(continueStack),
                                          STACK_POP(breakStack), (yyvsp[-2].asts), (yyvsp[-5].asts));
                          (yyval.asts)->lineno = (yyvsp[-6].sym)->lineDef;
                          (yyval.asts)->filename = (yyvsp[-6].sym)->fileDef;
                          noLineno--;
                        }
#line 5043 "src/SDCCy.c"
    break;

  case 312: /* iteration_statement: for '(' expression_opt ';' expression_opt ';' expression_opt ')' secondary_block  */
#line 1991 "src/SDCC.y"
                        {
                          noLineno++;

                          (yyval.asts) = newNode(FOR,(yyvsp[0].asts),NULL);
                          AST_FOR((yyval.asts),trueLabel) = (yyvsp[-8].sym);
                          AST_FOR((yyval.asts),continueLabel) =  STACK_POP(continueStack);
                          AST_FOR((yyval.asts),falseLabel) = STACK_POP(breakStack);
                          AST_FOR((yyval.asts),condLabel)  = STACK_POP(forStack);
                          AST_FOR((yyval.asts),initExpr)   = (yyvsp[-6].asts);
                          AST_FOR((yyval.asts),condExpr)   = (yyvsp[-4].asts);
                          AST_FOR((yyval.asts),loopExpr)   = (yyvsp[-2].asts);
                          
                          /* This continue label is not at the correct location, */
                          /* but we need to create it now for proper binding. The */
                          /* code that handles the FOR node will move it to the */
                          /* proper location inside the for loop. */
                          if (AST_FOR((yyval.asts),continueLabel)->isref)
                            (yyval.asts)->right = createLabel(AST_FOR((yyval.asts),continueLabel),NULL);
                          (yyval.asts) = newNode(NULLOP,(yyval.asts),createLabel(AST_FOR((yyval.asts),falseLabel),NULL));
                          noLineno--;

                          NestLevel -= LEVEL_UNIT;
                          currBlockno = STACK_POP(blockNum);
                        }
#line 5072 "src/SDCCy.c"
    break;

  case 313: /* $@14: %empty  */
#line 2016 "src/SDCC.y"
                        {
                          if (!options.std_c99)
                            werror (E_FOR_INITAL_DECLARATION_C99);

                          if ( (yyvsp[-4].sym) && IS_TYPEDEF((yyvsp[-4].sym)->etype))
                            allocVariables ((yyvsp[-4].sym));
                          ignoreTypedefType = 0;
                          addSymChain(&(yyvsp[-4].sym));
                        }
#line 5086 "src/SDCCy.c"
    break;

  case 314: /* iteration_statement: for '(' declaration expression_opt ';' expression_opt ')' $@14 secondary_block  */
#line 2026 "src/SDCC.y"
                        {

                          noLineno++;

                          (yyval.asts) = newNode(FOR,(yyvsp[0].asts),NULL);
                          AST_FOR((yyval.asts),trueLabel) = (yyvsp[-8].sym);
                          AST_FOR((yyval.asts),continueLabel) =  STACK_POP(continueStack);
                          AST_FOR((yyval.asts),falseLabel) = STACK_POP(breakStack);
                          AST_FOR((yyval.asts),condLabel)  = STACK_POP(forStack);
                          AST_FOR((yyval.asts),initExpr)   = 0;
                          AST_FOR((yyval.asts),condExpr)   = (yyvsp[-5].asts);
                          AST_FOR((yyval.asts),loopExpr)   = (yyvsp[-3].asts);

                          /* This continue label is not at the correct location, */
                          /* but we need to create it now for proper binding. The */
                          /* code that handles the FOR node will move it to the */
                          /* proper location inside the for loop. */
                          if (AST_FOR((yyval.asts),continueLabel)->isref)
                            (yyval.asts)->right = createLabel(AST_FOR((yyval.asts),continueLabel),NULL);
                          (yyval.asts) = createBlock((yyvsp[-6].sym), newNode(NULLOP,(yyval.asts),createLabel(AST_FOR((yyval.asts),falseLabel),NULL)));
                          cleanUpLevel(StructTab, NestLevel + LEVEL_UNIT);
                          noLineno--;

                          leaveBlockScope (currBlockno);
                          NestLevel -= LEVEL_UNIT;
                          currBlockno = STACK_POP(blockNum);
                        }
#line 5118 "src/SDCCy.c"
    break;

  case 315: /* jump_statement: GOTO identifier ';'  */
#line 2056 "src/SDCC.y"
                           {
                              if (inCriticalBlock) {
                                werror(E_INVALID_CRITICAL);
                                (yyval.asts) = NULL;
                              } else {
                                (yyvsp[-1].sym)->islbl = 1;
                                (yyval.asts) = newAst_VALUE(symbolVal((yyvsp[-1].sym)));
                                (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
                              }
                           }
#line 5133 "src/SDCCy.c"
    break;

  case 316: /* jump_statement: CONTINUE ';'  */
#line 2066 "src/SDCC.y"
                           {
       /* make sure continue is in context */
       if (STACK_EMPTY(continueStack) || STACK_PEEK(continueStack) == NULL) {
           werror(E_BREAK_CONTEXT);
           (yyval.asts) = NULL;
       }
       else {
           (yyval.asts) = newAst_VALUE(symbolVal(STACK_PEEK(continueStack)));
           (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
           /* mark the continue label as referenced */
           STACK_PEEK(continueStack)->isref = 1;
       }
   }
#line 5151 "src/SDCCy.c"
    break;

  case 317: /* jump_statement: BREAK ';'  */
#line 2079 "src/SDCC.y"
                           {
       if (STACK_EMPTY(breakStack) || STACK_PEEK(breakStack) == NULL) {
           werror(E_BREAK_CONTEXT);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newAst_VALUE(symbolVal(STACK_PEEK(breakStack)));
           (yyval.asts) = newNode(GOTO,(yyval.asts),NULL);
           STACK_PEEK(breakStack)->isref = 1;
       }
   }
#line 5166 "src/SDCCy.c"
    break;

  case 318: /* jump_statement: RETURN ';'  */
#line 2089 "src/SDCC.y"
                           {
       seqPointNo++;
       if (inCriticalBlock) {
           werror(E_INVALID_CRITICAL);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newNode(RETURN,NULL,NULL);
       }
   }
#line 5180 "src/SDCCy.c"
    break;

  case 319: /* jump_statement: RETURN expression ';'  */
#line 2098 "src/SDCC.y"
                                 {
       seqPointNo++;
       if (inCriticalBlock) {
           werror(E_INVALID_CRITICAL);
           (yyval.asts) = NULL;
       } else {
           (yyval.asts) = newNode(RETURN,NULL,(yyvsp[-1].asts));
       }
   }
#line 5194 "src/SDCCy.c"
    break;

  case 322: /* external_declaration: function_definition  */
#line 2118 "src/SDCC.y"
        {
          // blockNo = 0;
        }
#line 5202 "src/SDCCy.c"
    break;

  case 323: /* external_declaration: declaration  */
#line 2122 "src/SDCC.y"
        {
          ignoreTypedefType = 0;
          if ((yyvsp[0].sym) && (yyvsp[0].sym)->type && IS_FUNC((yyvsp[0].sym)->type))
            {
              /* The only legal storage classes for
               * a function prototype (declaration)
               * are extern and static. extern is the
               * default. Thus, if this function isn't
               * explicitly marked static, mark it
               * extern.
               */
              if ((yyvsp[0].sym)->etype && IS_SPEC((yyvsp[0].sym)->etype) && !SPEC_STAT((yyvsp[0].sym)->etype))
                {
                  SPEC_EXTR((yyvsp[0].sym)->etype) = 1;
                }
            }
          addSymChain (&(yyvsp[0].sym));
          allocVariables ((yyvsp[0].sym));
          cleanUpLevel (SymbolTab, 1);
        }
#line 5227 "src/SDCCy.c"
    break;

  case 324: /* external_declaration: addressmod  */
#line 2143 "src/SDCC.y"
        {
          /* These empty braces here are apparently required by some version of GNU bison on MS Windows. See bug #2858. */
        }
#line 5235 "src/SDCCy.c"
    break;

  case 325: /* $@15: %empty  */
#line 2150 "src/SDCC.y"
        {   /* function return type not specified, which is allowed in C90 (and means int), but disallowed in C99 and later */
            werror (W_RETURN_TYPE_OMITTED_INT);
            addDecl((yyvsp[0].sym),0,newIntLink());
            (yyvsp[0].sym) = createFunctionDecl((yyvsp[0].sym));
            if ((yyvsp[0].sym))
                {
                    if (FUNC_ISCRITICAL ((yyvsp[0].sym)->type))
                        inCriticalFunction = 1;
                    strncpyz (function_name, (yyvsp[0].sym)->name, sizeof (function_name) - 3);
                    memset (function_name + sizeof (function_name) - 4, 0x00, 4);
                }
        }
#line 5252 "src/SDCCy.c"
    break;

  case 326: /* function_definition: declarator $@15 function_body  */
#line 2163 "src/SDCC.y"
        {
            (yyval.asts) = createFunction((yyvsp[-2].sym),(yyvsp[0].asts));
            if ((yyvsp[-2].sym) && FUNC_ISCRITICAL ((yyvsp[-2].sym)->type))
                inCriticalFunction = 0;
        }
#line 5262 "src/SDCCy.c"
    break;

  case 327: /* $@16: %empty  */
#line 2169 "src/SDCC.y"
        {
            sym_link *p = copyLinkChain((yyvsp[-1].lnk));
            pointerTypes((yyvsp[0].sym)->type,p);
            addDecl((yyvsp[0].sym),0,p);
            (yyvsp[0].sym) = createFunctionDecl((yyvsp[0].sym));
            if ((yyvsp[0].sym))
                {
                    if (!strcmp ((yyvsp[0].sym)->name, "_sdcc_external_startup")) // The rename (and semantics change happened) in SDCC 4.2.10. Keep this warning for two major releases afterwards.
                        werror (W__SDCC_EXTERNAL_STARTUP_DEF);
                    if (FUNC_ISCRITICAL ((yyvsp[0].sym)->type))
                        inCriticalFunction = 1;
                    // warn for loss of calling convention for inlined functions.
                    if (FUNC_ISINLINE ((yyvsp[0].sym)->type) &&
                        ( FUNC_ISZ88DK_CALLEE ((yyvsp[0].sym)->type) || FUNC_ISZ88DK_FASTCALL ((yyvsp[0].sym)->type) ||
                          FUNC_BANKED ((yyvsp[0].sym)->type)         || FUNC_REGBANK ((yyvsp[0].sym)->type)          ||
                          FUNC_ISOVERLAY ((yyvsp[0].sym)->type)      || FUNC_ISISR ((yyvsp[0].sym)->type) ))
                        werror (W_INLINE_FUNCATTR, (yyvsp[0].sym)->name);
                    strncpyz (function_name, (yyvsp[0].sym)->name, sizeof (function_name) - 3);
                    memset (function_name + sizeof (function_name) - 4, 0x00, 4);
                }
        }
#line 5288 "src/SDCCy.c"
    break;

  case 328: /* function_definition: declaration_specifiers declarator $@16 function_body  */
#line 2191 "src/SDCC.y"
        {
            (yyval.asts) = createFunction((yyvsp[-2].sym),(yyvsp[0].asts));
            if ((yyvsp[-2].sym) && FUNC_ISCRITICAL ((yyvsp[-2].sym)->type))
                inCriticalFunction = 0;
        }
#line 5298 "src/SDCCy.c"
    break;

  case 330: /* function_body: kr_declaration_list compound_statement  */
#line 2201 "src/SDCC.y"
     {
       werror (E_OLD_STYLE, ((yyvsp[-1].sym) ? (yyvsp[-1].sym)->name: ""));
       exit (1);
     }
#line 5307 "src/SDCCy.c"
    break;

  case 331: /* file: %empty  */
#line 2211 "src/SDCC.y"
     {
       werror(W_EMPTY_TRANSLATION_UNIT);
     }
#line 5315 "src/SDCCy.c"
    break;

  case 334: /* function_attributes: function_attributes function_attribute  */
#line 2222 "src/SDCC.y"
                                            { (yyval.lnk) = mergeSpec((yyvsp[-1].lnk),(yyvsp[0].lnk),"function_attribute"); }
#line 5321 "src/SDCCy.c"
    break;

  case 335: /* function_attribute: USING '(' constant_expr ')'  */
#line 2226 "src/SDCC.y"
                                  {
                        (yyval.lnk) = newLink(SPECIFIER);
                        FUNC_REGBANK((yyval.lnk)) = (int) ulFromVal(constExprValue((yyvsp[-1].asts), true));
                     }
#line 5330 "src/SDCCy.c"
    break;

  case 336: /* function_attribute: REENTRANT  */
#line 2230 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISREENT((yyval.lnk))=1;
                     }
#line 5338 "src/SDCCy.c"
    break;

  case 337: /* function_attribute: CRITICAL  */
#line 2233 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISCRITICAL((yyval.lnk)) = 1;
                     }
#line 5346 "src/SDCCy.c"
    break;

  case 338: /* function_attribute: NAKED  */
#line 2236 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISNAKED((yyval.lnk))=1;
                     }
#line 5354 "src/SDCCy.c"
    break;

  case 339: /* function_attribute: JAVANATIVE  */
#line 2239 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISJAVANATIVE((yyval.lnk))=1;
                     }
#line 5362 "src/SDCCy.c"
    break;

  case 340: /* function_attribute: OVERLAY  */
#line 2242 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISOVERLAY((yyval.lnk))=1;
                     }
#line 5370 "src/SDCCy.c"
    break;

  case 341: /* function_attribute: NONBANKED  */
#line 2245 "src/SDCC.y"
                     {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_NONBANKED((yyval.lnk)) = 1;
                        if (FUNC_BANKED((yyval.lnk))) {
                            werror(W_BANKED_WITH_NONBANKED);
                        }
                     }
#line 5381 "src/SDCCy.c"
    break;

  case 342: /* function_attribute: SHADOWREGS  */
#line 2251 "src/SDCC.y"
                     {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISSHADOWREGS((yyval.lnk)) = 1;
                     }
#line 5389 "src/SDCCy.c"
    break;

  case 343: /* function_attribute: SD_WPARAM  */
#line 2254 "src/SDCC.y"
                     {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISWPARAM((yyval.lnk)) = 1;
                     }
#line 5397 "src/SDCCy.c"
    break;

  case 344: /* function_attribute: BANKED  */
#line 2257 "src/SDCC.y"
                     {(yyval.lnk) = newLink (SPECIFIER);
                        FUNC_BANKED((yyval.lnk)) = 1;
                        if (FUNC_NONBANKED((yyval.lnk))) {
                            werror(W_BANKED_WITH_NONBANKED);
                        }
                     }
#line 5408 "src/SDCCy.c"
    break;

  case 345: /* function_attribute: Interrupt_storage  */
#line 2264 "src/SDCC.y"
                     {
                        (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_INTNO((yyval.lnk)) = (yyvsp[0].yyint);
                        FUNC_ISISR((yyval.lnk)) = 1;
                     }
#line 5418 "src/SDCCy.c"
    break;

  case 346: /* function_attribute: TRAP  */
#line 2270 "src/SDCC.y"
                     {
                        (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_INTNO((yyval.lnk)) = INTNO_TRAP;
                        FUNC_ISISR((yyval.lnk)) = 1;
                     }
#line 5428 "src/SDCCy.c"
    break;

  case 347: /* function_attribute: SMALLC  */
#line 2275 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISSMALLC((yyval.lnk)) = 1;
                     }
#line 5436 "src/SDCCy.c"
    break;

  case 348: /* function_attribute: RAISONANCE  */
#line 2278 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISRAISONANCE((yyval.lnk)) = 1;
                     }
#line 5444 "src/SDCCy.c"
    break;

  case 349: /* function_attribute: IAR  */
#line 2281 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISIAR((yyval.lnk)) = 1;
                     }
#line 5452 "src/SDCCy.c"
    break;

  case 350: /* function_attribute: COSMIC  */
#line 2284 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISCOSMIC((yyval.lnk)) = 1;
                     }
#line 5460 "src/SDCCy.c"
    break;

  case 351: /* function_attribute: SDCCCALL '(' constant_expr ')'  */
#line 2288 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_SDCCCALL((yyval.lnk)) = ulFromVal(constExprValue ((yyvsp[-1].asts), true));
                     }
#line 5468 "src/SDCCy.c"
    break;

  case 352: /* function_attribute: Z88DK_FASTCALL  */
#line 2291 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISZ88DK_FASTCALL((yyval.lnk)) = 1;
                     }
#line 5476 "src/SDCCy.c"
    break;

  case 353: /* function_attribute: Z88DK_CALLEE  */
#line 2294 "src/SDCC.y"
                     {  (yyval.lnk) = newLink (SPECIFIER);
                        FUNC_ISZ88DK_CALLEE((yyval.lnk)) = 1;
                     }
#line 5484 "src/SDCCy.c"
    break;

  case 354: /* function_attribute: Z88DK_PARAMS_OFFSET '(' constant_expr ')'  */
#line 2298 "src/SDCC.y"
                     {
                        value *offset_v = constExprValue ((yyvsp[-1].asts), true);
                        int    offset = 0;
                        (yyval.lnk) = newLink(SPECIFIER);
                        if  ( offset_v ) 
                          offset = ulFromVal(offset_v);
                        (yyval.lnk)->funcAttrs.z88dk_params_offset = offset;
                     }
#line 5497 "src/SDCCy.c"
    break;

  case 355: /* function_attribute: Z88DK_SHORTCALL '(' constant_expr ',' constant_expr ')'  */
#line 2307 "src/SDCC.y"
                     {
                        value *rst_v = constExprValue ((yyvsp[-3].asts), true);
                        value *value_v = constExprValue ((yyvsp[-1].asts), true);
                        int rst = -1, value = -1;
                        (yyval.lnk) = newLink(SPECIFIER);

                        if  ( rst_v ) 
                          rst = ulFromVal(rst_v);
                        if  ( value_v ) 
                          value = ulFromVal(value_v);
          
                        if ( rst < 0 || rst > 56 || ( rst % 8 ) )
                          {
                            werror(E_SHORTCALL_INVALID_VALUE, "rst", rst);
                          }
                        if ( value < 0 || value > 0xfff )
                          {
                            werror(E_SHORTCALL_INVALID_VALUE, "value", value);
                          }
                        (yyval.lnk)->funcAttrs.z88dk_shortcall_rst = rst;
                        (yyval.lnk)->funcAttrs.z88dk_shortcall_val = value;
                        FUNC_ISZ88DK_SHORTCALL((yyval.lnk)) = 1;
                     }
#line 5525 "src/SDCCy.c"
    break;

  case 356: /* function_attribute: PRESERVES_REGS '(' identifier_list ')'  */
#line 2331 "src/SDCC.y"
                     {
                        const struct symbol *regsym;
                        (yyval.lnk) = newLink (SPECIFIER);

                        for(regsym = (yyvsp[-1].sym); regsym; regsym = regsym->next)
                          {
                            int regnum;

                            if (!port->getRegByName || ((regnum = port->getRegByName(regsym->name)) < 0))
                              werror (W_UNKNOWN_REG, regsym->name);
                            else
                              (yyval.lnk)->funcAttrs.preserved_regs[regnum] = true;
                          }
                     }
#line 5544 "src/SDCCy.c"
    break;

  case 357: /* offsetof_member_designator: identifier  */
#line 2348 "src/SDCC.y"
                     { (yyval.asts) = newAst_VALUE (symbolVal ((yyvsp[0].sym))); }
#line 5550 "src/SDCCy.c"
    break;

  case 358: /* $@17: %empty  */
#line 2349 "src/SDCC.y"
                                    { ignoreTypedefType = 1; }
#line 5556 "src/SDCCy.c"
    break;

  case 359: /* offsetof_member_designator: offsetof_member_designator '.' $@17 identifier  */
#line 2350 "src/SDCC.y"
                     {
                       ignoreTypedefType = 0;
                       (yyvsp[0].sym) = newSymbol ((yyvsp[0].sym)->name, NestLevel);
                       (yyvsp[0].sym)->implicit = 1;
                       (yyval.asts) = newNode ('.', (yyvsp[-3].asts), newAst_VALUE (symbolVal ((yyvsp[0].sym))));
                     }
#line 5567 "src/SDCCy.c"
    break;

  case 360: /* offsetof_member_designator: offsetof_member_designator '[' expression ']'  */
#line 2357 "src/SDCC.y"
                     {
                       (yyval.asts) = newNode ('[', (yyvsp[-3].asts), (yyvsp[-1].asts));
                     }
#line 5575 "src/SDCCy.c"
    break;

  case 361: /* string_literal_val: FUNC  */
#line 2364 "src/SDCC.y"
       {
         // essentially do $$ = newAst_VALUE (strVal("\"$function_name\""));

         value* val = newValue ();
         { // BUG: duplicate from strVal
           val->type = newLink (DECLARATOR);
           DCL_TYPE (val->type) = ARRAY;
           val->type->next = val->etype = newLink (SPECIFIER);
           SPEC_SCLS (val->etype) = S_LITERAL;
           SPEC_CONST (val->etype) = 1;
           SPEC_NOUN (val->etype) = V_CHAR;
           SPEC_USIGN (val->etype) = !options.signed_char;
           val->etype->select.s.b_implicit_sign = true;
         }

         int ll = 1 + strlen(function_name);
         char* s = (char*) Safe_alloc(ll*sizeof(char));
         if(ll > 1){
           s = strncpy(s, function_name, ll);
         }else{
           *s = 0;
         }
         SPEC_CVAL (val->etype).v_char = s;
         DCL_ELEM (val->type) = ll;
         (yyval.asts) = newAst_VALUE ( val );
       }
#line 5606 "src/SDCCy.c"
    break;

  case 362: /* string_literal_val: STRING_LITERAL  */
#line 2390 "src/SDCC.y"
                    { (yyval.asts) = newAst_VALUE (strVal ((yyvsp[0].yystr))); }
#line 5612 "src/SDCCy.c"
    break;

  case 363: /* Interrupt_storage: INTERRUPT  */
#line 2394 "src/SDCC.y"
               { (yyval.yyint) = INTNO_UNSPEC; }
#line 5618 "src/SDCCy.c"
    break;

  case 364: /* Interrupt_storage: INTERRUPT '(' constant_expr ')'  */
#line 2396 "src/SDCC.y"
        { 
          value *val = constExprValue((yyvsp[-1].asts), true);
          int intno = (int) ulFromVal(val);
          if (val && (intno >= 0) && (intno <= INTNO_MAX))
            (yyval.yyint) = intno;
          else
            {
              werror(E_INT_BAD_INTNO, intno);
              (yyval.yyint) = INTNO_UNSPEC;
            }
        }
#line 5634 "src/SDCCy.c"
    break;

  case 365: /* sfr_reg_bit: SBIT  */
#line 2410 "src/SDCC.y"
            {
               (yyval.lnk) = newLink(SPECIFIER);
               SPEC_NOUN((yyval.lnk)) = V_SBIT;
               SPEC_SCLS((yyval.lnk)) = S_SBIT;
               SPEC_BLEN((yyval.lnk)) = 1;
               SPEC_BSTR((yyval.lnk)) = 0;
               ignoreTypedefType = 1;
            }
#line 5647 "src/SDCCy.c"
    break;

  case 367: /* sfr_attributes: SFR  */
#line 2422 "src/SDCC.y"
            {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_CHAR;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
#line 5660 "src/SDCCy.c"
    break;

  case 368: /* sfr_attributes: SFR BANKED  */
#line 2430 "src/SDCC.y"
                {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 1;
               SPEC_NOUN((yyval.lnk))    = V_CHAR;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
#line 5673 "src/SDCCy.c"
    break;

  case 369: /* sfr_attributes: SFR16  */
#line 2441 "src/SDCC.y"
            {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_INT;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
#line 5686 "src/SDCCy.c"
    break;

  case 370: /* sfr_attributes: SFR32  */
#line 2452 "src/SDCC.y"
            {
               (yyval.lnk) = newLink(SPECIFIER);
               FUNC_REGBANK((yyval.lnk)) = 0;
               SPEC_NOUN((yyval.lnk))    = V_INT;
               SPEC_SCLS((yyval.lnk))    = S_SFR;
               SPEC_LONG((yyval.lnk))    = 1;
               SPEC_USIGN((yyval.lnk))   = 1;
               ignoreTypedefType = 1;
            }
#line 5700 "src/SDCCy.c"
    break;

  case 372: /* opt_stag: %empty  */
#line 2465 "src/SDCC.y"
        {  /* synthesize a name add to structtable */
          ignoreTypedefType = 0;
          (yyval.sdef) = newStruct(genSymName(NestLevel));
          (yyval.sdef)->level = NestLevel;
          (yyval.sdef)->block = currBlockno;
          (yyval.sdef)->tagsym = NULL;
          //addSym (StructTab, $$, $$->tag, $$->level, currBlockno, 0);
        }
#line 5713 "src/SDCCy.c"
    break;

  case 373: /* stag: identifier  */
#line 2477 "src/SDCC.y"
        {  /* add name to structure table */
          ignoreTypedefType = 0;
          (yyval.sdef) = newStruct((yyvsp[0].sym)->name);
          (yyval.sdef)->level = NestLevel;
          (yyval.sdef)->block = currBlockno;
          (yyval.sdef)->tagsym = (yyvsp[0].sym);
          //$$ = findSymWithBlock (StructTab, $1, currBlockno);
          //if (! $$ )
          //  {
          //    $$ = newStruct($1->name);
          //    $$->level = NestLevel;
          //    $$->tagsym = $1;
          //    //addSym (StructTab, $$, $$->tag, $$->level, currBlockno, 0);
          //  }
        }
#line 5733 "src/SDCCy.c"
    break;

  case 374: /* opt_assign_expr: '=' constant_expr  */
#line 2496 "src/SDCC.y"
        {
          value *val;

          val = constExprValue((yyvsp[0].asts), true);
          if (!val) // Not a constant expression
            {
              werror (E_CONST_EXPECTED);
              val = constIntVal("0");
            }
          else if (!IS_INT(val->type) && !IS_CHAR(val->type) && !IS_BOOL(val->type))
            {
              werror(E_ENUM_NON_INTEGER);
              SNPRINTF(lbuff, sizeof(lbuff), "%lld", (long long int) ullFromVal(val));
              val = constVal(lbuff);
            }
          (yyval.val) = cenum = val;
        }
#line 5755 "src/SDCCy.c"
    break;

  case 375: /* opt_assign_expr: %empty  */
#line 2513 "src/SDCC.y"
        {
          if (cenum)
            {
              SNPRINTF(lbuff, sizeof(lbuff), "%lld", (long long int) ullFromVal(cenum)+1);
              (yyval.val) = cenum = constVal(lbuff);
            }
          else
            {
              (yyval.val) = cenum = constCharVal(0);
            }
        }
#line 5771 "src/SDCCy.c"
    break;

  case 376: /* specifier_qualifier_list: type_specifier_list_  */
#line 2526 "src/SDCC.y"
                                                { (yyval.lnk) = finalizeSpec((yyvsp[0].lnk)); }
#line 5777 "src/SDCCy.c"
    break;

  case 378: /* type_specifier_list_: type_specifier_list_ type_specifier_qualifier  */
#line 2531 "src/SDCC.y"
                                                   {
     /* if the decl $2 is not a specifier */
     /* find the spec and replace it      */
     (yyval.lnk) = mergeDeclSpec((yyvsp[-1].lnk), (yyvsp[0].lnk), "type_specifier_list type_specifier skipped");
   }
#line 5787 "src/SDCCy.c"
    break;

  case 380: /* identifier_list: identifier_list ',' identifier  */
#line 2541 "src/SDCC.y"
         {
           (yyvsp[0].sym)->next = (yyvsp[-2].sym);
           (yyval.sym) = (yyvsp[0].sym);
         }
#line 5796 "src/SDCCy.c"
    break;

  case 381: /* type_name: declaration_specifiers  */
#line 2549 "src/SDCC.y"
        {
          if (IS_SPEC ((yyvsp[0].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[0].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, "type name");
            }
          (yyval.lnk) = (yyvsp[0].lnk); ignoreTypedefType = 0;
        }
#line 5808 "src/SDCCy.c"
    break;

  case 382: /* type_name: declaration_specifiers abstract_declarator  */
#line 2557 "src/SDCC.y"
        {
          /* go to the end of the list */
          sym_link *p;

          if (IS_SPEC ((yyvsp[-1].lnk)) && !IS_VALID_PARAMETER_STORAGE_CLASS_SPEC ((yyvsp[-1].lnk)))
            {
              werror (E_STORAGE_CLASS_FOR_PARAMETER, "type name");
            }
          pointerTypes ((yyvsp[0].lnk),(yyvsp[-1].lnk));
          for (p = (yyvsp[0].lnk); p && p->next; p = p->next)
            ;
          if (!p)
            {
              werror(E_SYNTAX_ERROR, yytext);
            }
          else
            {
              p->next = (yyvsp[-1].lnk);
            }
          (yyval.lnk) = (yyvsp[0].lnk);
          ignoreTypedefType = 0;
        }
#line 5835 "src/SDCCy.c"
    break;

  case 383: /* critical: CRITICAL  */
#line 2582 "src/SDCC.y"
                {
                   if (inCriticalFunction || inCriticalBlock)
                     werror(E_INVALID_CRITICAL);
                   inCriticalBlock = 1;
                   STACK_PUSH(continueStack,NULL);
                   STACK_PUSH(breakStack,NULL);
                   (yyval.sym) = NULL;
                }
#line 5848 "src/SDCCy.c"
    break;

  case 384: /* critical_statement: critical statement  */
#line 2593 "src/SDCC.y"
                         {
                   STACK_POP(breakStack);
                   STACK_POP(continueStack);
                   (yyval.asts) = newNode(CRITICAL,(yyvsp[0].asts),NULL);
                   inCriticalBlock = 0;
                }
#line 5859 "src/SDCCy.c"
    break;

  case 386: /* statements_and_implicit: statement_list implicit_block  */
#line 2604 "src/SDCC.y"
     {
       (yyval.asts) = newNode(NULLOP, (yyvsp[-1].asts), (yyvsp[0].asts));
       if (!options.std_c99)
         werror(E_DECL_AFTER_STATEMENT_C99);
     }
#line 5869 "src/SDCCy.c"
    break;

  case 387: /* $@18: %empty  */
#line 2612 "src/SDCC.y"
     {
       NestLevel += SUBLEVEL_UNIT;
       STACK_PUSH(blockNum, currBlockno);
       btree_add_child(currBlockno, ++blockNo);
       currBlockno = blockNo;
       ignoreTypedefType = 0;
     }
#line 5881 "src/SDCCy.c"
    break;

  case 388: /* declaration_after_statement: $@18 declaration_list  */
#line 2619 "src/SDCC.y"
                                              { (yyval.sym) = (yyvsp[0].sym); }
#line 5887 "src/SDCCy.c"
    break;

  case 389: /* implicit_block: declaration_after_statement statements_and_implicit  */
#line 2624 "src/SDCC.y"
     {
       leaveBlockScope (currBlockno);
       NestLevel -= SUBLEVEL_UNIT;
       currBlockno = STACK_POP(blockNum);
       (yyval.asts) = createBlock((yyvsp[-1].sym), (yyvsp[0].asts));
       cleanUpLevel(StructTab, NestLevel + SUBLEVEL_UNIT);
     }
#line 5899 "src/SDCCy.c"
    break;

  case 390: /* implicit_block: declaration_after_statement  */
#line 2632 "src/SDCC.y"
     {
       leaveBlockScope (currBlockno);
       NestLevel -= SUBLEVEL_UNIT;
       currBlockno = STACK_POP(blockNum);
       (yyval.asts) = createBlock((yyvsp[0].sym), NULL);
       cleanUpLevel(StructTab, NestLevel + SUBLEVEL_UNIT);
     }
#line 5911 "src/SDCCy.c"
    break;

  case 391: /* declaration_list: declaration  */
#line 2643 "src/SDCC.y"
     {
       /* if this is typedef declare it immediately */
       if ( (yyvsp[0].sym) && IS_TYPEDEF((yyvsp[0].sym)->etype)) {
         allocVariables ((yyvsp[0].sym));
         (yyval.sym) = NULL;
       }
       else
         (yyval.sym) = (yyvsp[0].sym);
       ignoreTypedefType = 0;/*printf("1 %s %d %d\n", $1->name, IS_ARRAY ($1->type), DCL_ARRAY_VLA ($1->type));
       if (IS_ARRAY ($1->type) && DCL_ARRAY_VLA ($1->type))
         werror (E_VLA_OBJECT);
       else*/
         addSymChain(&(yyvsp[0].sym));
     }
#line 5930 "src/SDCCy.c"
    break;

  case 392: /* declaration_list: declaration_list declaration  */
#line 2659 "src/SDCC.y"
     {
       symbol   *sym;

       /* if this is a typedef */
       if ((yyvsp[0].sym) && IS_TYPEDEF((yyvsp[0].sym)->etype)) {
         allocVariables ((yyvsp[0].sym));
         (yyval.sym) = (yyvsp[-1].sym);
       }
       else {
         /* get to the end of the previous decl */
         if ( (yyvsp[-1].sym) ) {
           (yyval.sym) = sym = (yyvsp[-1].sym);
           while (sym->next)
             sym = sym->next;
           sym->next = (yyvsp[0].sym);
         }
         else
           (yyval.sym) = (yyvsp[0].sym);
       }
       ignoreTypedefType = 0;/*printf("2 %s %d %d\n", $1->name, IS_ARRAY ($1->type), DCL_ARRAY_VLA ($1->type));
       if (IS_ARRAY ($2->type) && DCL_ARRAY_VLA ($2->type))
         werror (E_VLA_OBJECT);
       else*/
         addSymChain(&(yyvsp[0].sym));
     }
#line 5960 "src/SDCCy.c"
    break;

  case 393: /* kr_declaration: declaration_specifiers init_declarator_list ';'  */
#line 2693 "src/SDCC.y"
      {
         /* add the specifier list to the id */
         symbol *sym , *sym1;

         for (sym1 = sym = reverseSyms((yyvsp[-1].sym));sym != NULL;sym = sym->next) {
             sym_link *lnk = copyLinkChain((yyvsp[-2].lnk));
             sym_link *l0 = NULL, *l1 = NULL, *l2 = NULL;
             /* check illegal declaration */
             for (l0 = sym->type; l0 != NULL; l0 = l0->next)
               if (IS_PTR (l0))
                 break;
             /* check if creating instances of structs with flexible arrays */
             for (l1 = lnk; l1 != NULL; l1 = l1->next)
               if (IS_STRUCT (l1) && SPEC_STRUCT (l1)->b_flexArrayMember)
                 break;
             if (!options.std_c99 && l0 == NULL && l1 != NULL && SPEC_EXTR((yyvsp[-2].lnk)) != 1)
               werror (W_FLEXARRAY_INSTRUCT, sym->name);
             /* check if creating instances of function type */
             for (l1 = lnk; l1 != NULL; l1 = l1->next)
               if (IS_FUNC (l1))
                 break;
             for (l2 = lnk; l2 != NULL; l2 = l2->next)
               if (IS_PTR (l2))
                 break;
             if (l0 == NULL && l2 == NULL && l1 != NULL)
               werrorfl(sym->fileDef, sym->lineDef, E_TYPE_IS_FUNCTION, sym->name);
             /* do the pointer stuff */
             pointerTypes(sym->type,lnk);
             addDecl (sym,0,lnk);
         }

         uselessDecl = true;
         (yyval.sym) = sym1;
      }
#line 5999 "src/SDCCy.c"
    break;

  case 394: /* kr_declaration_list: kr_declaration  */
#line 2731 "src/SDCC.y"
     {
       /* if this is typedef declare it immediately */
       if ( (yyvsp[0].sym) && IS_TYPEDEF((yyvsp[0].sym)->etype)) {
         allocVariables ((yyvsp[0].sym));
         (yyval.sym) = NULL;
       }
       else
         (yyval.sym) = (yyvsp[0].sym);
       ignoreTypedefType = 0;
       addSymChain(&(yyvsp[0].sym));
     }
#line 6015 "src/SDCCy.c"
    break;

  case 395: /* kr_declaration_list: kr_declaration_list kr_declaration  */
#line 2743 "src/SDCC.y"
     {
       symbol   *sym;

       /* if this is a typedef */
       if ((yyvsp[0].sym) && IS_TYPEDEF((yyvsp[0].sym)->etype)) {
         allocVariables ((yyvsp[0].sym));
         (yyval.sym) = (yyvsp[-1].sym);
       }
       else {
         /* get to the end of the previous decl */
         if ( (yyvsp[-1].sym) ) {
           (yyval.sym) = sym = (yyvsp[-1].sym);
           while (sym->next)
             sym = sym->next;
           sym->next = (yyvsp[0].sym);
         }
         else
           (yyval.sym) = (yyvsp[0].sym);
       }
       ignoreTypedefType = 0;
       addSymChain(&(yyvsp[0].sym));
     }
#line 6042 "src/SDCCy.c"
    break;

  case 396: /* statement_list: unlabeled_statement  */
#line 2768 "src/SDCC.y"
                                        { (yyval.asts) = (yyvsp[0].asts); }
#line 6048 "src/SDCCy.c"
    break;

  case 397: /* statement_list: label  */
#line 2769 "src/SDCC.y"
                                        { (yyval.asts) = (yyvsp[0].asts); }
#line 6054 "src/SDCCy.c"
    break;

  case 398: /* statement_list: statement_list unlabeled_statement  */
#line 2770 "src/SDCC.y"
                                        { (yyval.asts) = newNode(NULLOP,(yyvsp[-1].asts),(yyvsp[0].asts));}
#line 6060 "src/SDCCy.c"
    break;

  case 399: /* statement_list: statement_list label  */
#line 2771 "src/SDCC.y"
                                        { (yyval.asts) = newNode(NULLOP,(yyvsp[-1].asts),(yyvsp[0].asts));}
#line 6066 "src/SDCCy.c"
    break;

  case 400: /* while: WHILE  */
#line 2774 "src/SDCC.y"
               {  /* create and push the continue , break & body labels */
                  static int Lblnum = 0;
                  /* continue */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilecontinue_%d",Lblnum);
                  STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
                  /* break */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilebreak_%d",Lblnum);
                  STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
                  /* body */
                  SNPRINTF (lbuff, sizeof(lbuff), "_whilebody_%d",Lblnum++);
                  (yyval.sym) = newSymbol(lbuff,NestLevel);
               }
#line 6083 "src/SDCCy.c"
    break;

  case 401: /* do: DO  */
#line 2788 "src/SDCC.y"
        {  /* create and push the continue , break & body Labels */
           static int Lblnum = 0;

           /* continue */
           SNPRINTF(lbuff, sizeof(lbuff), "_docontinue_%d",Lblnum);
           STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
           /* break */
           SNPRINTF(lbuff, sizeof(lbuff), "_dobreak_%d",Lblnum);
           STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
           /* do body */
           SNPRINTF(lbuff, sizeof(lbuff), "_dobody_%d",Lblnum++);
           (yyval.sym) = newSymbol (lbuff,NestLevel);
        }
#line 6101 "src/SDCCy.c"
    break;

  case 402: /* for: FOR  */
#line 2803 "src/SDCC.y"
          { /* create & push continue, break & body labels */
            static int Lblnum = 0;

           NestLevel += LEVEL_UNIT;
           STACK_PUSH(blockNum, currBlockno);
           btree_add_child(currBlockno, ++blockNo);
           currBlockno = blockNo;
           ignoreTypedefType = 0;

            /* continue */
            SNPRINTF(lbuff, sizeof(lbuff), "_forcontinue_%d",Lblnum);
            STACK_PUSH(continueStack,newSymbol(lbuff,NestLevel));
            /* break    */
            SNPRINTF(lbuff, sizeof(lbuff), "_forbreak_%d",Lblnum);
            STACK_PUSH(breakStack,newSymbol(lbuff,NestLevel));
            /* body */
            SNPRINTF(lbuff, sizeof(lbuff), "_forbody_%d",Lblnum);
            (yyval.sym) = newSymbol(lbuff,NestLevel);
            /* condition */
            SNPRINTF(lbuff, sizeof(lbuff), "_forcond_%d",Lblnum++);
            STACK_PUSH(forStack,newSymbol(lbuff,NestLevel));
          }
#line 6128 "src/SDCCy.c"
    break;

  case 404: /* asm_statement: ASM '(' asm_string_literal ')' ';'  */
#line 2833 "src/SDCC.y"
      {
        ast *ex;

        seqPointNo++;
        ex = newNode(INLINEASM, NULL, NULL);
        ex->values.inlineasm = strdup(copyStr ((yyvsp[-2].yystr), NULL));
        seqPointNo++;
        (yyval.asts) = ex;
     }
#line 6142 "src/SDCCy.c"
    break;

  case 405: /* asm_statement: INLINEASM ';'  */
#line 2843 "src/SDCC.y"
      {
        ast *ex;

        seqPointNo++;
        ex = newNode(INLINEASM, NULL, NULL);
        ex->values.inlineasm = strdup((yyvsp[-1].yystr));
        seqPointNo++;
        (yyval.asts) = ex;
      }
#line 6156 "src/SDCCy.c"
    break;

  case 406: /* addressmod: ADDRESSMOD identifier identifier ';'  */
#line 2855 "src/SDCC.y"
                                          {
     symbol *sym;
     if ((sym = findSymWithLevel (AddrspaceTab, (yyvsp[-1].sym))) && sym->level == (yyvsp[-1].sym)->level)
       werrorfl (sym->fileDef, sym->lineDef, E_PREVIOUS_DEF);
     if (!findSymWithLevel (SymbolTab, (yyvsp[-2].sym)))
       werror (E_ID_UNDEF, (yyvsp[-2].sym)->name);
     addSym (AddrspaceTab, (yyvsp[-1].sym), (yyvsp[-1].sym)->name, (yyvsp[-1].sym)->level, (yyvsp[-1].sym)->block, 0);
     sym = findSymWithLevel (AddrspaceTab, (yyvsp[-1].sym));
     sym->addressmod[0] = findSymWithLevel (SymbolTab, (yyvsp[-2].sym));
     sym->addressmod[1] = 0;
   }
#line 6172 "src/SDCCy.c"
    break;

  case 407: /* addressmod: ADDRESSMOD identifier SD_CONST identifier ';'  */
#line 2866 "src/SDCC.y"
                                                   {
     symbol *sym;
     sym_link *type;
     if ((sym = findSymWithLevel (AddrspaceTab, (yyvsp[-1].sym))) && sym->level == (yyvsp[-1].sym)->level)
       werrorfl (sym->fileDef, sym->lineDef, E_PREVIOUS_DEF);
     if (!findSymWithLevel (SymbolTab, (yyvsp[-3].sym)))
       werror (E_ID_UNDEF, (yyvsp[-3].sym)->name);
     addSym (AddrspaceTab, (yyvsp[-1].sym), (yyvsp[-1].sym)->name, (yyvsp[-1].sym)->level, (yyvsp[-1].sym)->block, 0);
     sym = findSymWithLevel (AddrspaceTab, (yyvsp[-1].sym));
     sym->addressmod[0] = findSymWithLevel (SymbolTab, (yyvsp[-3].sym));
     sym->addressmod[1] = 0;
     type = newLink (SPECIFIER);
     SPEC_CONST(type) = 1;
     sym->type = sym->etype = type;
   }
#line 6192 "src/SDCCy.c"
    break;

  case 408: /* identifier: IDENTIFIER  */
#line 2884 "src/SDCC.y"
                  { (yyval.sym) = newSymbol ((yyvsp[0].yychar), NestLevel); }
#line 6198 "src/SDCCy.c"
    break;


#line 6202 "src/SDCCy.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2886 "src/SDCC.y"


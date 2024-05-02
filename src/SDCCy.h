/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_SDCCY_H_INCLUDED
# define YY_YY_SRC_SDCCY_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFIER = 258,              /* IDENTIFIER  */
    TYPE_NAME = 259,               /* TYPE_NAME  */
    ADDRSPACE_NAME = 260,          /* ADDRSPACE_NAME  */
    CONSTANT = 261,                /* CONSTANT  */
    SIZEOF = 262,                  /* SIZEOF  */
    OFFSETOF = 263,                /* OFFSETOF  */
    PTR_OP = 264,                  /* PTR_OP  */
    INC_OP = 265,                  /* INC_OP  */
    DEC_OP = 266,                  /* DEC_OP  */
    LEFT_OP = 267,                 /* LEFT_OP  */
    RIGHT_OP = 268,                /* RIGHT_OP  */
    LE_OP = 269,                   /* LE_OP  */
    GE_OP = 270,                   /* GE_OP  */
    EQ_OP = 271,                   /* EQ_OP  */
    NE_OP = 272,                   /* NE_OP  */
    AND_OP = 273,                  /* AND_OP  */
    OR_OP = 274,                   /* OR_OP  */
    ATTR_START = 275,              /* ATTR_START  */
    TOK_SEP = 276,                 /* TOK_SEP  */
    MUL_ASSIGN = 277,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 278,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 279,              /* MOD_ASSIGN  */
    ADD_ASSIGN = 280,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 281,              /* SUB_ASSIGN  */
    LEFT_ASSIGN = 282,             /* LEFT_ASSIGN  */
    RIGHT_ASSIGN = 283,            /* RIGHT_ASSIGN  */
    AND_ASSIGN = 284,              /* AND_ASSIGN  */
    XOR_ASSIGN = 285,              /* XOR_ASSIGN  */
    OR_ASSIGN = 286,               /* OR_ASSIGN  */
    TYPEDEF = 287,                 /* TYPEDEF  */
    EXTERN = 288,                  /* EXTERN  */
    STATIC = 289,                  /* STATIC  */
    AUTO = 290,                    /* AUTO  */
    REGISTER = 291,                /* REGISTER  */
    CONSTEXPR = 292,               /* CONSTEXPR  */
    CODE = 293,                    /* CODE  */
    EEPROM = 294,                  /* EEPROM  */
    INTERRUPT = 295,               /* INTERRUPT  */
    SFR = 296,                     /* SFR  */
    SFR16 = 297,                   /* SFR16  */
    SFR32 = 298,                   /* SFR32  */
    ADDRESSMOD = 299,              /* ADDRESSMOD  */
    AT = 300,                      /* AT  */
    SBIT = 301,                    /* SBIT  */
    REENTRANT = 302,               /* REENTRANT  */
    USING = 303,                   /* USING  */
    XDATA = 304,                   /* XDATA  */
    DATA = 305,                    /* DATA  */
    IDATA = 306,                   /* IDATA  */
    PDATA = 307,                   /* PDATA  */
    ELLIPSIS = 308,                /* ELLIPSIS  */
    CRITICAL = 309,                /* CRITICAL  */
    NONBANKED = 310,               /* NONBANKED  */
    BANKED = 311,                  /* BANKED  */
    SHADOWREGS = 312,              /* SHADOWREGS  */
    SD_WPARAM = 313,               /* SD_WPARAM  */
    SD_BOOL = 314,                 /* SD_BOOL  */
    SD_CHAR = 315,                 /* SD_CHAR  */
    SD_SHORT = 316,                /* SD_SHORT  */
    SD_INT = 317,                  /* SD_INT  */
    SD_LONG = 318,                 /* SD_LONG  */
    SIGNED = 319,                  /* SIGNED  */
    UNSIGNED = 320,                /* UNSIGNED  */
    SD_FLOAT = 321,                /* SD_FLOAT  */
    DOUBLE = 322,                  /* DOUBLE  */
    FIXED16X16 = 323,              /* FIXED16X16  */
    SD_CONST = 324,                /* SD_CONST  */
    VOLATILE = 325,                /* VOLATILE  */
    SD_VOID = 326,                 /* SD_VOID  */
    BIT = 327,                     /* BIT  */
    COMPLEX = 328,                 /* COMPLEX  */
    IMAGINARY = 329,               /* IMAGINARY  */
    STRUCT = 330,                  /* STRUCT  */
    UNION = 331,                   /* UNION  */
    ENUM = 332,                    /* ENUM  */
    RANGE = 333,                   /* RANGE  */
    SD_FAR = 334,                  /* SD_FAR  */
    CASE = 335,                    /* CASE  */
    DEFAULT = 336,                 /* DEFAULT  */
    IF = 337,                      /* IF  */
    ELSE = 338,                    /* ELSE  */
    SWITCH = 339,                  /* SWITCH  */
    WHILE = 340,                   /* WHILE  */
    DO = 341,                      /* DO  */
    FOR = 342,                     /* FOR  */
    GOTO = 343,                    /* GOTO  */
    CONTINUE = 344,                /* CONTINUE  */
    BREAK = 345,                   /* BREAK  */
    RETURN = 346,                  /* RETURN  */
    NAKED = 347,                   /* NAKED  */
    JAVANATIVE = 348,              /* JAVANATIVE  */
    OVERLAY = 349,                 /* OVERLAY  */
    TRAP = 350,                    /* TRAP  */
    STRING_LITERAL = 351,          /* STRING_LITERAL  */
    INLINEASM = 352,               /* INLINEASM  */
    FUNC = 353,                    /* FUNC  */
    IFX = 354,                     /* IFX  */
    ADDRESS_OF = 355,              /* ADDRESS_OF  */
    GET_VALUE_AT_ADDRESS = 356,    /* GET_VALUE_AT_ADDRESS  */
    SET_VALUE_AT_ADDRESS = 357,    /* SET_VALUE_AT_ADDRESS  */
    SPIL = 358,                    /* SPIL  */
    UNSPIL = 359,                  /* UNSPIL  */
    GETABIT = 360,                 /* GETABIT  */
    GETBYTE = 361,                 /* GETBYTE  */
    GETWORD = 362,                 /* GETWORD  */
    BITWISEAND = 363,              /* BITWISEAND  */
    UNARYMINUS = 364,              /* UNARYMINUS  */
    IPUSH = 365,                   /* IPUSH  */
    IPUSH_VALUE_AT_ADDRESS = 366,  /* IPUSH_VALUE_AT_ADDRESS  */
    IPOP = 367,                    /* IPOP  */
    PCALL = 368,                   /* PCALL  */
    ENDFUNCTION = 369,             /* ENDFUNCTION  */
    JUMPTABLE = 370,               /* JUMPTABLE  */
    ROT = 371,                     /* ROT  */
    CAST = 372,                    /* CAST  */
    CALL = 373,                    /* CALL  */
    PARAM = 374,                   /* PARAM  */
    NULLOP = 375,                  /* NULLOP  */
    BLOCK = 376,                   /* BLOCK  */
    LABEL = 377,                   /* LABEL  */
    RECEIVE = 378,                 /* RECEIVE  */
    SEND = 379,                    /* SEND  */
    ARRAYINIT = 380,               /* ARRAYINIT  */
    DUMMY_READ_VOLATILE = 381,     /* DUMMY_READ_VOLATILE  */
    ENDCRITICAL = 382,             /* ENDCRITICAL  */
    INLINE = 383,                  /* INLINE  */
    RESTRICT = 384,                /* RESTRICT  */
    SMALLC = 385,                  /* SMALLC  */
    RAISONANCE = 386,              /* RAISONANCE  */
    IAR = 387,                     /* IAR  */
    COSMIC = 388,                  /* COSMIC  */
    SDCCCALL = 389,                /* SDCCCALL  */
    PRESERVES_REGS = 390,          /* PRESERVES_REGS  */
    Z88DK_FASTCALL = 391,          /* Z88DK_FASTCALL  */
    Z88DK_CALLEE = 392,            /* Z88DK_CALLEE  */
    Z88DK_SHORTCALL = 393,         /* Z88DK_SHORTCALL  */
    Z88DK_PARAMS_OFFSET = 394,     /* Z88DK_PARAMS_OFFSET  */
    ALIGNAS = 395,                 /* ALIGNAS  */
    ALIGNOF = 396,                 /* ALIGNOF  */
    ATOMIC = 397,                  /* ATOMIC  */
    GENERIC = 398,                 /* GENERIC  */
    NORETURN = 399,                /* NORETURN  */
    STATIC_ASSERT = 400,           /* STATIC_ASSERT  */
    THREAD_LOCAL = 401,            /* THREAD_LOCAL  */
    TOKEN_FALSE = 402,             /* TOKEN_FALSE  */
    TOKEN_TRUE = 403,              /* TOKEN_TRUE  */
    NULLPTR = 404,                 /* NULLPTR  */
    TYPEOF = 405,                  /* TYPEOF  */
    TYPEOF_UNQUAL = 406,           /* TYPEOF_UNQUAL  */
    SD_BITINT = 407,               /* SD_BITINT  */
    DECIMAL32 = 408,               /* DECIMAL32  */
    DECIMAL64 = 409,               /* DECIMAL64  */
    DECIMAL128 = 410,              /* DECIMAL128  */
    ASM = 411,                     /* ASM  */
    GENERIC_ASSOC_LIST = 412,      /* GENERIC_ASSOC_LIST  */
    GENERIC_ASSOCIATION = 413      /* GENERIC_ASSOCIATION  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 79 "src/SDCC.y"

    attribute  *attr;       /* attribute                              */
    symbol     *sym;        /* symbol table pointer                   */
    structdef  *sdef;       /* structure definition                   */
    char       yychar[SDCC_NAME_MAX+1];
    sym_link   *lnk;        /* declarator  or specifier               */
    int        yyint;       /* integer value returned                 */
    value      *val;        /* for integer constant                   */
    initList   *ilist;      /* initial list                           */
    designation*dsgn;       /* designator                             */
    const char *yystr;      /* pointer to dynamicaly allocated string */
    ast        *asts;       /* expression tree                        */

#line 236 "src/SDCCy.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_SDCCY_H_INCLUDED  */

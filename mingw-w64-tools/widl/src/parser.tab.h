/* A Bison parser, made by GNU Bison 3.7.3.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED
# define YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int parser_debug;
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
    aIDENTIFIER = 258,             /* aIDENTIFIER  */
    aPRAGMA = 259,                 /* aPRAGMA  */
    aKNOWNTYPE = 260,              /* aKNOWNTYPE  */
    aNAMESPACE = 261,              /* aNAMESPACE  */
    aNUM = 262,                    /* aNUM  */
    aHEXNUM = 263,                 /* aHEXNUM  */
    aDOUBLE = 264,                 /* aDOUBLE  */
    aSTRING = 265,                 /* aSTRING  */
    aWSTRING = 266,                /* aWSTRING  */
    aSQSTRING = 267,               /* aSQSTRING  */
    aUUID = 268,                   /* aUUID  */
    aEOF = 269,                    /* aEOF  */
    aACF = 270,                    /* aACF  */
    SHL = 271,                     /* SHL  */
    SHR = 272,                     /* SHR  */
    MEMBERPTR = 273,               /* MEMBERPTR  */
    EQUALITY = 274,                /* EQUALITY  */
    INEQUALITY = 275,              /* INEQUALITY  */
    GREATEREQUAL = 276,            /* GREATEREQUAL  */
    LESSEQUAL = 277,               /* LESSEQUAL  */
    LOGICALOR = 278,               /* LOGICALOR  */
    LOGICALAND = 279,              /* LOGICALAND  */
    ELLIPSIS = 280,                /* ELLIPSIS  */
    tACTIVATABLE = 281,            /* tACTIVATABLE  */
    tAGGREGATABLE = 282,           /* tAGGREGATABLE  */
    tAGILE = 283,                  /* tAGILE  */
    tALLNODES = 284,               /* tALLNODES  */
    tALLOCATE = 285,               /* tALLOCATE  */
    tANNOTATION = 286,             /* tANNOTATION  */
    tAPICONTRACT = 287,            /* tAPICONTRACT  */
    tAPPOBJECT = 288,              /* tAPPOBJECT  */
    tASYNC = 289,                  /* tASYNC  */
    tASYNCUUID = 290,              /* tASYNCUUID  */
    tAUTOHANDLE = 291,             /* tAUTOHANDLE  */
    tBINDABLE = 292,               /* tBINDABLE  */
    tBOOLEAN = 293,                /* tBOOLEAN  */
    tBROADCAST = 294,              /* tBROADCAST  */
    tBYTE = 295,                   /* tBYTE  */
    tBYTECOUNT = 296,              /* tBYTECOUNT  */
    tCALLAS = 297,                 /* tCALLAS  */
    tCALLBACK = 298,               /* tCALLBACK  */
    tCASE = 299,                   /* tCASE  */
    tCDECL = 300,                  /* tCDECL  */
    tCHAR = 301,                   /* tCHAR  */
    tCOCLASS = 302,                /* tCOCLASS  */
    tCODE = 303,                   /* tCODE  */
    tCOMMSTATUS = 304,             /* tCOMMSTATUS  */
    tCONST = 305,                  /* tCONST  */
    tCONTEXTHANDLE = 306,          /* tCONTEXTHANDLE  */
    tCONTEXTHANDLENOSERIALIZE = 307, /* tCONTEXTHANDLENOSERIALIZE  */
    tCONTEXTHANDLESERIALIZE = 308, /* tCONTEXTHANDLESERIALIZE  */
    tCONTRACT = 309,               /* tCONTRACT  */
    tCONTRACTVERSION = 310,        /* tCONTRACTVERSION  */
    tCONTROL = 311,                /* tCONTROL  */
    tCPPQUOTE = 312,               /* tCPPQUOTE  */
    tCUSTOM = 313,                 /* tCUSTOM  */
    tDECLARE = 314,                /* tDECLARE  */
    tDECODE = 315,                 /* tDECODE  */
    tDEFAULT = 316,                /* tDEFAULT  */
    tDEFAULTBIND = 317,            /* tDEFAULTBIND  */
    tDELEGATE = 318,               /* tDELEGATE  */
    tDEFAULTCOLLELEM = 319,        /* tDEFAULTCOLLELEM  */
    tDEFAULTVALUE = 320,           /* tDEFAULTVALUE  */
    tDEFAULTVTABLE = 321,          /* tDEFAULTVTABLE  */
    tDISABLECONSISTENCYCHECK = 322, /* tDISABLECONSISTENCYCHECK  */
    tDISPLAYBIND = 323,            /* tDISPLAYBIND  */
    tDISPINTERFACE = 324,          /* tDISPINTERFACE  */
    tDLLNAME = 325,                /* tDLLNAME  */
    tDONTFREE = 326,               /* tDONTFREE  */
    tDOUBLE = 327,                 /* tDOUBLE  */
    tDUAL = 328,                   /* tDUAL  */
    tENABLEALLOCATE = 329,         /* tENABLEALLOCATE  */
    tENCODE = 330,                 /* tENCODE  */
    tENDPOINT = 331,               /* tENDPOINT  */
    tENTRY = 332,                  /* tENTRY  */
    tENUM = 333,                   /* tENUM  */
    tERRORSTATUST = 334,           /* tERRORSTATUST  */
    tEVENTADD = 335,               /* tEVENTADD  */
    tEVENTREMOVE = 336,            /* tEVENTREMOVE  */
    tEXCLUSIVETO = 337,            /* tEXCLUSIVETO  */
    tEXPLICITHANDLE = 338,         /* tEXPLICITHANDLE  */
    tEXTERN = 339,                 /* tEXTERN  */
    tFALSE = 340,                  /* tFALSE  */
    tFASTCALL = 341,               /* tFASTCALL  */
    tFAULTSTATUS = 342,            /* tFAULTSTATUS  */
    tFLAGS = 343,                  /* tFLAGS  */
    tFLOAT = 344,                  /* tFLOAT  */
    tFORCEALLOCATE = 345,          /* tFORCEALLOCATE  */
    tHANDLE = 346,                 /* tHANDLE  */
    tHANDLET = 347,                /* tHANDLET  */
    tHELPCONTEXT = 348,            /* tHELPCONTEXT  */
    tHELPFILE = 349,               /* tHELPFILE  */
    tHELPSTRING = 350,             /* tHELPSTRING  */
    tHELPSTRINGCONTEXT = 351,      /* tHELPSTRINGCONTEXT  */
    tHELPSTRINGDLL = 352,          /* tHELPSTRINGDLL  */
    tHIDDEN = 353,                 /* tHIDDEN  */
    tHYPER = 354,                  /* tHYPER  */
    tID = 355,                     /* tID  */
    tIDEMPOTENT = 356,             /* tIDEMPOTENT  */
    tIGNORE = 357,                 /* tIGNORE  */
    tIIDIS = 358,                  /* tIIDIS  */
    tIMMEDIATEBIND = 359,          /* tIMMEDIATEBIND  */
    tIMPLICITHANDLE = 360,         /* tIMPLICITHANDLE  */
    tIMPORT = 361,                 /* tIMPORT  */
    tIMPORTLIB = 362,              /* tIMPORTLIB  */
    tIN = 363,                     /* tIN  */
    tIN_LINE = 364,                /* tIN_LINE  */
    tINLINE = 365,                 /* tINLINE  */
    tINPUTSYNC = 366,              /* tINPUTSYNC  */
    tINT = 367,                    /* tINT  */
    tINT32 = 368,                  /* tINT32  */
    tINT3264 = 369,                /* tINT3264  */
    tINT64 = 370,                  /* tINT64  */
    tINTERFACE = 371,              /* tINTERFACE  */
    tLCID = 372,                   /* tLCID  */
    tLENGTHIS = 373,               /* tLENGTHIS  */
    tLIBRARY = 374,                /* tLIBRARY  */
    tLICENSED = 375,               /* tLICENSED  */
    tLOCAL = 376,                  /* tLOCAL  */
    tLONG = 377,                   /* tLONG  */
    tMARSHALINGBEHAVIOR = 378,     /* tMARSHALINGBEHAVIOR  */
    tMAYBE = 379,                  /* tMAYBE  */
    tMESSAGE = 380,                /* tMESSAGE  */
    tMETHODS = 381,                /* tMETHODS  */
    tMODULE = 382,                 /* tMODULE  */
    tMTA = 383,                    /* tMTA  */
    tNAMESPACE = 384,              /* tNAMESPACE  */
    tNOCODE = 385,                 /* tNOCODE  */
    tNONBROWSABLE = 386,           /* tNONBROWSABLE  */
    tNONCREATABLE = 387,           /* tNONCREATABLE  */
    tNONE = 388,                   /* tNONE  */
    tNONEXTENSIBLE = 389,          /* tNONEXTENSIBLE  */
    tNOTIFY = 390,                 /* tNOTIFY  */
    tNOTIFYFLAG = 391,             /* tNOTIFYFLAG  */
    tNULL = 392,                   /* tNULL  */
    tOBJECT = 393,                 /* tOBJECT  */
    tODL = 394,                    /* tODL  */
    tOLEAUTOMATION = 395,          /* tOLEAUTOMATION  */
    tOPTIMIZE = 396,               /* tOPTIMIZE  */
    tOPTIONAL = 397,               /* tOPTIONAL  */
    tOUT = 398,                    /* tOUT  */
    tPARTIALIGNORE = 399,          /* tPARTIALIGNORE  */
    tPASCAL = 400,                 /* tPASCAL  */
    tPOINTERDEFAULT = 401,         /* tPOINTERDEFAULT  */
    tPRAGMA_WARNING = 402,         /* tPRAGMA_WARNING  */
    tPROGID = 403,                 /* tPROGID  */
    tPROPERTIES = 404,             /* tPROPERTIES  */
    tPROPGET = 405,                /* tPROPGET  */
    tPROPPUT = 406,                /* tPROPPUT  */
    tPROPPUTREF = 407,             /* tPROPPUTREF  */
    tPROXY = 408,                  /* tPROXY  */
    tPTR = 409,                    /* tPTR  */
    tPUBLIC = 410,                 /* tPUBLIC  */
    tRANGE = 411,                  /* tRANGE  */
    tREADONLY = 412,               /* tREADONLY  */
    tREF = 413,                    /* tREF  */
    tREGISTER = 414,               /* tREGISTER  */
    tREPRESENTAS = 415,            /* tREPRESENTAS  */
    tREQUESTEDIT = 416,            /* tREQUESTEDIT  */
    tREQUIRES = 417,               /* tREQUIRES  */
    tRESTRICTED = 418,             /* tRESTRICTED  */
    tRETVAL = 419,                 /* tRETVAL  */
    tRUNTIMECLASS = 420,           /* tRUNTIMECLASS  */
    tSAFEARRAY = 421,              /* tSAFEARRAY  */
    tSHORT = 422,                  /* tSHORT  */
    tSIGNED = 423,                 /* tSIGNED  */
    tSINGLENODE = 424,             /* tSINGLENODE  */
    tSIZEIS = 425,                 /* tSIZEIS  */
    tSIZEOF = 426,                 /* tSIZEOF  */
    tSMALL = 427,                  /* tSMALL  */
    tSOURCE = 428,                 /* tSOURCE  */
    tSTANDARD = 429,               /* tSTANDARD  */
    tSTATIC = 430,                 /* tSTATIC  */
    tSTDCALL = 431,                /* tSTDCALL  */
    tSTRICTCONTEXTHANDLE = 432,    /* tSTRICTCONTEXTHANDLE  */
    tSTRING = 433,                 /* tSTRING  */
    tSTRUCT = 434,                 /* tSTRUCT  */
    tSWITCH = 435,                 /* tSWITCH  */
    tSWITCHIS = 436,               /* tSWITCHIS  */
    tSWITCHTYPE = 437,             /* tSWITCHTYPE  */
    tTHREADING = 438,              /* tTHREADING  */
    tTRANSMITAS = 439,             /* tTRANSMITAS  */
    tTRUE = 440,                   /* tTRUE  */
    tTYPEDEF = 441,                /* tTYPEDEF  */
    tUIDEFAULT = 442,              /* tUIDEFAULT  */
    tUNION = 443,                  /* tUNION  */
    tUNIQUE = 444,                 /* tUNIQUE  */
    tUNSIGNED = 445,               /* tUNSIGNED  */
    tUSESGETLASTERROR = 446,       /* tUSESGETLASTERROR  */
    tUSERMARSHAL = 447,            /* tUSERMARSHAL  */
    tUUID = 448,                   /* tUUID  */
    tV1ENUM = 449,                 /* tV1ENUM  */
    tVARARG = 450,                 /* tVARARG  */
    tVERSION = 451,                /* tVERSION  */
    tVIPROGID = 452,               /* tVIPROGID  */
    tVOID = 453,                   /* tVOID  */
    tWCHAR = 454,                  /* tWCHAR  */
    tWIREMARSHAL = 455,            /* tWIREMARSHAL  */
    tAPARTMENT = 456,              /* tAPARTMENT  */
    tNEUTRAL = 457,                /* tNEUTRAL  */
    tSINGLE = 458,                 /* tSINGLE  */
    tFREE = 459,                   /* tFREE  */
    tBOTH = 460,                   /* tBOTH  */
    CAST = 461,                    /* CAST  */
    PPTR = 462,                    /* PPTR  */
    POS = 463,                     /* POS  */
    NEG = 464,                     /* NEG  */
    ADDRESSOF = 465                /* ADDRESSOF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 140 "tools/widl/parser.y"

	attr_t *attr;
	attr_list_t *attr_list;
	str_list_t *str_list;
	expr_t *expr;
	expr_list_t *expr_list;
	type_t *type;
	type_list_t *typelist;
	var_t *var;
	var_list_t *var_list;
	declarator_t *declarator;
	declarator_list_t *declarator_list;
	statement_t *statement;
	statement_list_t *stmt_list;
	warning_t *warning;
	warning_list_t *warning_list;
	ifref_t *ifref;
	ifref_list_t *ifref_list;
	char *str;
	UUID *uuid;
	unsigned int num;
	double dbl;
	typelib_t *typelib;
	struct _import_t *import;
	struct _decl_spec_t *declspec;
	enum storage_class stgclass;
	enum type_qualifier type_qualifier;
	enum function_specifier function_specifier;

#line 304 "tools/widl/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE parser_lval;

int parser_parse (void);

#endif /* !YY_PARSER_TOOLS_WIDL_PARSER_TAB_H_INCLUDED  */

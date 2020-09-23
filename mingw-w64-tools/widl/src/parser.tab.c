/* A Bison parser, made by GNU Bison 3.7.3.  */

/* Bison implementation for Yacc-like parsers in C

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         parser_parse
#define yylex           parser_lex
#define yyerror         parser_error
#define yydebug         parser_debug
#define yynerrs         parser_nerrs
#define yylval          parser_lval
#define yychar          parser_char

/* First part of user prologue.  */
#line 1 "tools/widl/parser.y"

/*
 * IDL Compiler
 *
 * Copyright 2002 Ove Kaaven
 * Copyright 2006-2008 Robert Shearman
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>

#include "widl.h"
#include "utils.h"
#include "parser.h"
#include "header.h"
#include "typelib.h"
#include "typegen.h"
#include "expr.h"
#include "typetree.h"

struct _import_t
{
  char *name;
  int import_performed;
};

static str_list_t *append_str(str_list_t *list, char *str);
static type_list_t *append_type(type_list_t *list, type_t *type);
static type_list_t *append_types(type_list_t *list, type_list_t *types);
static attr_list_t *append_attr(attr_list_t *list, attr_t *attr);
static attr_list_t *append_attr_list(attr_list_t *new_list, attr_list_t *old_list);
static decl_spec_t *make_decl_spec(type_t *type, decl_spec_t *left, decl_spec_t *right,
        enum storage_class stgclass, enum type_qualifier qual, enum function_specifier func_specifier);
static attr_t *make_attr(enum attr_type type);
static attr_t *make_attrv(enum attr_type type, unsigned int val);
static attr_t *make_attrp(enum attr_type type, void *val);
static attr_t *make_custom_attr(UUID *id, expr_t *pval);
static expr_list_t *append_expr(expr_list_t *list, expr_t *expr);
static var_t *declare_var(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_t *decl, int top);
static var_list_t *set_var_types(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_list_t *decls);
static ifref_list_t *append_ifref(ifref_list_t *list, ifref_t *iface);
static ifref_t *make_ifref(type_t *iface);
static var_list_t *append_var_list(var_list_t *list, var_list_t *vars);
static declarator_list_t *append_declarator(declarator_list_t *list, declarator_t *p);
static declarator_t *make_declarator(var_t *var);
static type_t *make_safearray(type_t *type);
static typelib_t *make_library(const char *name, const attr_list_t *attrs);
static void append_array(declarator_t *decl, expr_t *expr);
static void append_chain_type(declarator_t *decl, type_t *type, enum type_qualifier qual);
static void append_chain_callconv(type_t *chain, char *callconv);
static warning_list_t *append_warning(warning_list_t *, int);

static type_t *reg_typedefs(decl_spec_t *decl_spec, var_list_t *names, attr_list_t *attrs);
static type_t *get_qualified_type(enum type_type type, char *name, int t);
static type_t *find_qualified_type_or_error(const char *name, int t);
static type_t *find_type_or_error(const char *name, int t);
static type_t *find_type_or_error2(char *name, int t);

static var_t *reg_const(var_t *var);

static void push_namespace(const char *name);
static void pop_namespace(const char *name);
static void push_lookup_namespace(const char *name);
static void push_parameters_namespace(const char *name);
static void pop_parameters_namespace(const char *name);

static statement_list_t *append_parameterized_type_stmts(statement_list_t *stmts);
static void check_arg_attrs(const var_t *arg);
static void check_statements(const statement_list_t *stmts, int is_inside_library);
static void check_all_user_types(const statement_list_t *stmts);
static attr_list_t *check_iface_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_function_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_typedef_attrs(attr_list_t *attrs);
static attr_list_t *check_enum_attrs(attr_list_t *attrs);
static attr_list_t *check_enum_member_attrs(attr_list_t *attrs);
static attr_list_t *check_struct_attrs(attr_list_t *attrs);
static attr_list_t *check_union_attrs(attr_list_t *attrs);
static attr_list_t *check_field_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_library_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_dispiface_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_module_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_coclass_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_runtimeclass_attrs(const char *name, attr_list_t *attrs);
static attr_list_t *check_apicontract_attrs(const char *name, attr_list_t *attrs);
const char *get_attr_display_name(enum attr_type type);
static void add_explicit_handle_if_necessary(const type_t *iface, var_t *func);
static void check_def(const type_t *t);

static void check_async_uuid(type_t *iface);

static statement_t *make_statement(enum statement_type type);
static statement_t *make_statement_type_decl(type_t *type);
static statement_t *make_statement_reference(type_t *type);
static statement_t *make_statement_declaration(var_t *var);
static statement_t *make_statement_library(typelib_t *typelib);
static statement_t *make_statement_pragma(const char *str);
static statement_t *make_statement_cppquote(const char *str);
static statement_t *make_statement_importlib(const char *str);
static statement_t *make_statement_module(type_t *type);
static statement_t *make_statement_typedef(var_list_t *names, int declonly);
static statement_t *make_statement_import(const char *str);
static statement_t *make_statement_parameterized_type(type_t *type, type_list_t *params);
static statement_t *make_statement_delegate(type_t *ret, var_list_t *args);
static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt);
static statement_list_t *append_statements(statement_list_t *, statement_list_t *);
static attr_list_t *append_attribs(attr_list_t *, attr_list_t *);

static struct namespace global_namespace = {
    NULL, NULL, LIST_INIT(global_namespace.entry), LIST_INIT(global_namespace.children)
};

static struct namespace *current_namespace = &global_namespace;
static struct namespace *lookup_namespace = &global_namespace;
static struct namespace *parameters_namespace = NULL;
static statement_list_t *parameterized_type_stmts = NULL;

static typelib_t *current_typelib;


#line 218 "tools/widl/parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_aIDENTIFIER = 3,                /* aIDENTIFIER  */
  YYSYMBOL_aPRAGMA = 4,                    /* aPRAGMA  */
  YYSYMBOL_aKNOWNTYPE = 5,                 /* aKNOWNTYPE  */
  YYSYMBOL_aNAMESPACE = 6,                 /* aNAMESPACE  */
  YYSYMBOL_aNUM = 7,                       /* aNUM  */
  YYSYMBOL_aHEXNUM = 8,                    /* aHEXNUM  */
  YYSYMBOL_aDOUBLE = 9,                    /* aDOUBLE  */
  YYSYMBOL_aSTRING = 10,                   /* aSTRING  */
  YYSYMBOL_aWSTRING = 11,                  /* aWSTRING  */
  YYSYMBOL_aSQSTRING = 12,                 /* aSQSTRING  */
  YYSYMBOL_aUUID = 13,                     /* aUUID  */
  YYSYMBOL_aEOF = 14,                      /* aEOF  */
  YYSYMBOL_aACF = 15,                      /* aACF  */
  YYSYMBOL_SHL = 16,                       /* SHL  */
  YYSYMBOL_SHR = 17,                       /* SHR  */
  YYSYMBOL_MEMBERPTR = 18,                 /* MEMBERPTR  */
  YYSYMBOL_EQUALITY = 19,                  /* EQUALITY  */
  YYSYMBOL_INEQUALITY = 20,                /* INEQUALITY  */
  YYSYMBOL_GREATEREQUAL = 21,              /* GREATEREQUAL  */
  YYSYMBOL_LESSEQUAL = 22,                 /* LESSEQUAL  */
  YYSYMBOL_LOGICALOR = 23,                 /* LOGICALOR  */
  YYSYMBOL_LOGICALAND = 24,                /* LOGICALAND  */
  YYSYMBOL_ELLIPSIS = 25,                  /* ELLIPSIS  */
  YYSYMBOL_tACTIVATABLE = 26,              /* tACTIVATABLE  */
  YYSYMBOL_tAGGREGATABLE = 27,             /* tAGGREGATABLE  */
  YYSYMBOL_tAGILE = 28,                    /* tAGILE  */
  YYSYMBOL_tALLNODES = 29,                 /* tALLNODES  */
  YYSYMBOL_tALLOCATE = 30,                 /* tALLOCATE  */
  YYSYMBOL_tANNOTATION = 31,               /* tANNOTATION  */
  YYSYMBOL_tAPICONTRACT = 32,              /* tAPICONTRACT  */
  YYSYMBOL_tAPPOBJECT = 33,                /* tAPPOBJECT  */
  YYSYMBOL_tASYNC = 34,                    /* tASYNC  */
  YYSYMBOL_tASYNCUUID = 35,                /* tASYNCUUID  */
  YYSYMBOL_tAUTOHANDLE = 36,               /* tAUTOHANDLE  */
  YYSYMBOL_tBINDABLE = 37,                 /* tBINDABLE  */
  YYSYMBOL_tBOOLEAN = 38,                  /* tBOOLEAN  */
  YYSYMBOL_tBROADCAST = 39,                /* tBROADCAST  */
  YYSYMBOL_tBYTE = 40,                     /* tBYTE  */
  YYSYMBOL_tBYTECOUNT = 41,                /* tBYTECOUNT  */
  YYSYMBOL_tCALLAS = 42,                   /* tCALLAS  */
  YYSYMBOL_tCALLBACK = 43,                 /* tCALLBACK  */
  YYSYMBOL_tCASE = 44,                     /* tCASE  */
  YYSYMBOL_tCDECL = 45,                    /* tCDECL  */
  YYSYMBOL_tCHAR = 46,                     /* tCHAR  */
  YYSYMBOL_tCOCLASS = 47,                  /* tCOCLASS  */
  YYSYMBOL_tCODE = 48,                     /* tCODE  */
  YYSYMBOL_tCOMMSTATUS = 49,               /* tCOMMSTATUS  */
  YYSYMBOL_tCONST = 50,                    /* tCONST  */
  YYSYMBOL_tCONTEXTHANDLE = 51,            /* tCONTEXTHANDLE  */
  YYSYMBOL_tCONTEXTHANDLENOSERIALIZE = 52, /* tCONTEXTHANDLENOSERIALIZE  */
  YYSYMBOL_tCONTEXTHANDLESERIALIZE = 53,   /* tCONTEXTHANDLESERIALIZE  */
  YYSYMBOL_tCONTRACT = 54,                 /* tCONTRACT  */
  YYSYMBOL_tCONTRACTVERSION = 55,          /* tCONTRACTVERSION  */
  YYSYMBOL_tCONTROL = 56,                  /* tCONTROL  */
  YYSYMBOL_tCPPQUOTE = 57,                 /* tCPPQUOTE  */
  YYSYMBOL_tCUSTOM = 58,                   /* tCUSTOM  */
  YYSYMBOL_tDECLARE = 59,                  /* tDECLARE  */
  YYSYMBOL_tDECODE = 60,                   /* tDECODE  */
  YYSYMBOL_tDEFAULT = 61,                  /* tDEFAULT  */
  YYSYMBOL_tDEFAULTBIND = 62,              /* tDEFAULTBIND  */
  YYSYMBOL_tDELEGATE = 63,                 /* tDELEGATE  */
  YYSYMBOL_tDEFAULTCOLLELEM = 64,          /* tDEFAULTCOLLELEM  */
  YYSYMBOL_tDEFAULTVALUE = 65,             /* tDEFAULTVALUE  */
  YYSYMBOL_tDEFAULTVTABLE = 66,            /* tDEFAULTVTABLE  */
  YYSYMBOL_tDISABLECONSISTENCYCHECK = 67,  /* tDISABLECONSISTENCYCHECK  */
  YYSYMBOL_tDISPLAYBIND = 68,              /* tDISPLAYBIND  */
  YYSYMBOL_tDISPINTERFACE = 69,            /* tDISPINTERFACE  */
  YYSYMBOL_tDLLNAME = 70,                  /* tDLLNAME  */
  YYSYMBOL_tDONTFREE = 71,                 /* tDONTFREE  */
  YYSYMBOL_tDOUBLE = 72,                   /* tDOUBLE  */
  YYSYMBOL_tDUAL = 73,                     /* tDUAL  */
  YYSYMBOL_tENABLEALLOCATE = 74,           /* tENABLEALLOCATE  */
  YYSYMBOL_tENCODE = 75,                   /* tENCODE  */
  YYSYMBOL_tENDPOINT = 76,                 /* tENDPOINT  */
  YYSYMBOL_tENTRY = 77,                    /* tENTRY  */
  YYSYMBOL_tENUM = 78,                     /* tENUM  */
  YYSYMBOL_tERRORSTATUST = 79,             /* tERRORSTATUST  */
  YYSYMBOL_tEVENTADD = 80,                 /* tEVENTADD  */
  YYSYMBOL_tEVENTREMOVE = 81,              /* tEVENTREMOVE  */
  YYSYMBOL_tEXCLUSIVETO = 82,              /* tEXCLUSIVETO  */
  YYSYMBOL_tEXPLICITHANDLE = 83,           /* tEXPLICITHANDLE  */
  YYSYMBOL_tEXTERN = 84,                   /* tEXTERN  */
  YYSYMBOL_tFALSE = 85,                    /* tFALSE  */
  YYSYMBOL_tFASTCALL = 86,                 /* tFASTCALL  */
  YYSYMBOL_tFAULTSTATUS = 87,              /* tFAULTSTATUS  */
  YYSYMBOL_tFLAGS = 88,                    /* tFLAGS  */
  YYSYMBOL_tFLOAT = 89,                    /* tFLOAT  */
  YYSYMBOL_tFORCEALLOCATE = 90,            /* tFORCEALLOCATE  */
  YYSYMBOL_tHANDLE = 91,                   /* tHANDLE  */
  YYSYMBOL_tHANDLET = 92,                  /* tHANDLET  */
  YYSYMBOL_tHELPCONTEXT = 93,              /* tHELPCONTEXT  */
  YYSYMBOL_tHELPFILE = 94,                 /* tHELPFILE  */
  YYSYMBOL_tHELPSTRING = 95,               /* tHELPSTRING  */
  YYSYMBOL_tHELPSTRINGCONTEXT = 96,        /* tHELPSTRINGCONTEXT  */
  YYSYMBOL_tHELPSTRINGDLL = 97,            /* tHELPSTRINGDLL  */
  YYSYMBOL_tHIDDEN = 98,                   /* tHIDDEN  */
  YYSYMBOL_tHYPER = 99,                    /* tHYPER  */
  YYSYMBOL_tID = 100,                      /* tID  */
  YYSYMBOL_tIDEMPOTENT = 101,              /* tIDEMPOTENT  */
  YYSYMBOL_tIGNORE = 102,                  /* tIGNORE  */
  YYSYMBOL_tIIDIS = 103,                   /* tIIDIS  */
  YYSYMBOL_tIMMEDIATEBIND = 104,           /* tIMMEDIATEBIND  */
  YYSYMBOL_tIMPLICITHANDLE = 105,          /* tIMPLICITHANDLE  */
  YYSYMBOL_tIMPORT = 106,                  /* tIMPORT  */
  YYSYMBOL_tIMPORTLIB = 107,               /* tIMPORTLIB  */
  YYSYMBOL_tIN = 108,                      /* tIN  */
  YYSYMBOL_tIN_LINE = 109,                 /* tIN_LINE  */
  YYSYMBOL_tINLINE = 110,                  /* tINLINE  */
  YYSYMBOL_tINPUTSYNC = 111,               /* tINPUTSYNC  */
  YYSYMBOL_tINT = 112,                     /* tINT  */
  YYSYMBOL_tINT32 = 113,                   /* tINT32  */
  YYSYMBOL_tINT3264 = 114,                 /* tINT3264  */
  YYSYMBOL_tINT64 = 115,                   /* tINT64  */
  YYSYMBOL_tINTERFACE = 116,               /* tINTERFACE  */
  YYSYMBOL_tLCID = 117,                    /* tLCID  */
  YYSYMBOL_tLENGTHIS = 118,                /* tLENGTHIS  */
  YYSYMBOL_tLIBRARY = 119,                 /* tLIBRARY  */
  YYSYMBOL_tLICENSED = 120,                /* tLICENSED  */
  YYSYMBOL_tLOCAL = 121,                   /* tLOCAL  */
  YYSYMBOL_tLONG = 122,                    /* tLONG  */
  YYSYMBOL_tMARSHALINGBEHAVIOR = 123,      /* tMARSHALINGBEHAVIOR  */
  YYSYMBOL_tMAYBE = 124,                   /* tMAYBE  */
  YYSYMBOL_tMESSAGE = 125,                 /* tMESSAGE  */
  YYSYMBOL_tMETHODS = 126,                 /* tMETHODS  */
  YYSYMBOL_tMODULE = 127,                  /* tMODULE  */
  YYSYMBOL_tMTA = 128,                     /* tMTA  */
  YYSYMBOL_tNAMESPACE = 129,               /* tNAMESPACE  */
  YYSYMBOL_tNOCODE = 130,                  /* tNOCODE  */
  YYSYMBOL_tNONBROWSABLE = 131,            /* tNONBROWSABLE  */
  YYSYMBOL_tNONCREATABLE = 132,            /* tNONCREATABLE  */
  YYSYMBOL_tNONE = 133,                    /* tNONE  */
  YYSYMBOL_tNONEXTENSIBLE = 134,           /* tNONEXTENSIBLE  */
  YYSYMBOL_tNOTIFY = 135,                  /* tNOTIFY  */
  YYSYMBOL_tNOTIFYFLAG = 136,              /* tNOTIFYFLAG  */
  YYSYMBOL_tNULL = 137,                    /* tNULL  */
  YYSYMBOL_tOBJECT = 138,                  /* tOBJECT  */
  YYSYMBOL_tODL = 139,                     /* tODL  */
  YYSYMBOL_tOLEAUTOMATION = 140,           /* tOLEAUTOMATION  */
  YYSYMBOL_tOPTIMIZE = 141,                /* tOPTIMIZE  */
  YYSYMBOL_tOPTIONAL = 142,                /* tOPTIONAL  */
  YYSYMBOL_tOUT = 143,                     /* tOUT  */
  YYSYMBOL_tPARTIALIGNORE = 144,           /* tPARTIALIGNORE  */
  YYSYMBOL_tPASCAL = 145,                  /* tPASCAL  */
  YYSYMBOL_tPOINTERDEFAULT = 146,          /* tPOINTERDEFAULT  */
  YYSYMBOL_tPRAGMA_WARNING = 147,          /* tPRAGMA_WARNING  */
  YYSYMBOL_tPROGID = 148,                  /* tPROGID  */
  YYSYMBOL_tPROPERTIES = 149,              /* tPROPERTIES  */
  YYSYMBOL_tPROPGET = 150,                 /* tPROPGET  */
  YYSYMBOL_tPROPPUT = 151,                 /* tPROPPUT  */
  YYSYMBOL_tPROPPUTREF = 152,              /* tPROPPUTREF  */
  YYSYMBOL_tPROXY = 153,                   /* tPROXY  */
  YYSYMBOL_tPTR = 154,                     /* tPTR  */
  YYSYMBOL_tPUBLIC = 155,                  /* tPUBLIC  */
  YYSYMBOL_tRANGE = 156,                   /* tRANGE  */
  YYSYMBOL_tREADONLY = 157,                /* tREADONLY  */
  YYSYMBOL_tREF = 158,                     /* tREF  */
  YYSYMBOL_tREGISTER = 159,                /* tREGISTER  */
  YYSYMBOL_tREPRESENTAS = 160,             /* tREPRESENTAS  */
  YYSYMBOL_tREQUESTEDIT = 161,             /* tREQUESTEDIT  */
  YYSYMBOL_tREQUIRES = 162,                /* tREQUIRES  */
  YYSYMBOL_tRESTRICTED = 163,              /* tRESTRICTED  */
  YYSYMBOL_tRETVAL = 164,                  /* tRETVAL  */
  YYSYMBOL_tRUNTIMECLASS = 165,            /* tRUNTIMECLASS  */
  YYSYMBOL_tSAFEARRAY = 166,               /* tSAFEARRAY  */
  YYSYMBOL_tSHORT = 167,                   /* tSHORT  */
  YYSYMBOL_tSIGNED = 168,                  /* tSIGNED  */
  YYSYMBOL_tSINGLENODE = 169,              /* tSINGLENODE  */
  YYSYMBOL_tSIZEIS = 170,                  /* tSIZEIS  */
  YYSYMBOL_tSIZEOF = 171,                  /* tSIZEOF  */
  YYSYMBOL_tSMALL = 172,                   /* tSMALL  */
  YYSYMBOL_tSOURCE = 173,                  /* tSOURCE  */
  YYSYMBOL_tSTANDARD = 174,                /* tSTANDARD  */
  YYSYMBOL_tSTATIC = 175,                  /* tSTATIC  */
  YYSYMBOL_tSTDCALL = 176,                 /* tSTDCALL  */
  YYSYMBOL_tSTRICTCONTEXTHANDLE = 177,     /* tSTRICTCONTEXTHANDLE  */
  YYSYMBOL_tSTRING = 178,                  /* tSTRING  */
  YYSYMBOL_tSTRUCT = 179,                  /* tSTRUCT  */
  YYSYMBOL_tSWITCH = 180,                  /* tSWITCH  */
  YYSYMBOL_tSWITCHIS = 181,                /* tSWITCHIS  */
  YYSYMBOL_tSWITCHTYPE = 182,              /* tSWITCHTYPE  */
  YYSYMBOL_tTHREADING = 183,               /* tTHREADING  */
  YYSYMBOL_tTRANSMITAS = 184,              /* tTRANSMITAS  */
  YYSYMBOL_tTRUE = 185,                    /* tTRUE  */
  YYSYMBOL_tTYPEDEF = 186,                 /* tTYPEDEF  */
  YYSYMBOL_tUIDEFAULT = 187,               /* tUIDEFAULT  */
  YYSYMBOL_tUNION = 188,                   /* tUNION  */
  YYSYMBOL_tUNIQUE = 189,                  /* tUNIQUE  */
  YYSYMBOL_tUNSIGNED = 190,                /* tUNSIGNED  */
  YYSYMBOL_tUSESGETLASTERROR = 191,        /* tUSESGETLASTERROR  */
  YYSYMBOL_tUSERMARSHAL = 192,             /* tUSERMARSHAL  */
  YYSYMBOL_tUUID = 193,                    /* tUUID  */
  YYSYMBOL_tV1ENUM = 194,                  /* tV1ENUM  */
  YYSYMBOL_tVARARG = 195,                  /* tVARARG  */
  YYSYMBOL_tVERSION = 196,                 /* tVERSION  */
  YYSYMBOL_tVIPROGID = 197,                /* tVIPROGID  */
  YYSYMBOL_tVOID = 198,                    /* tVOID  */
  YYSYMBOL_tWCHAR = 199,                   /* tWCHAR  */
  YYSYMBOL_tWIREMARSHAL = 200,             /* tWIREMARSHAL  */
  YYSYMBOL_tAPARTMENT = 201,               /* tAPARTMENT  */
  YYSYMBOL_tNEUTRAL = 202,                 /* tNEUTRAL  */
  YYSYMBOL_tSINGLE = 203,                  /* tSINGLE  */
  YYSYMBOL_tFREE = 204,                    /* tFREE  */
  YYSYMBOL_tBOTH = 205,                    /* tBOTH  */
  YYSYMBOL_206_ = 206,                     /* ','  */
  YYSYMBOL_207_ = 207,                     /* '?'  */
  YYSYMBOL_208_ = 208,                     /* ':'  */
  YYSYMBOL_209_ = 209,                     /* '|'  */
  YYSYMBOL_210_ = 210,                     /* '^'  */
  YYSYMBOL_211_ = 211,                     /* '&'  */
  YYSYMBOL_212_ = 212,                     /* '<'  */
  YYSYMBOL_213_ = 213,                     /* '>'  */
  YYSYMBOL_214_ = 214,                     /* '-'  */
  YYSYMBOL_215_ = 215,                     /* '+'  */
  YYSYMBOL_216_ = 216,                     /* '*'  */
  YYSYMBOL_217_ = 217,                     /* '/'  */
  YYSYMBOL_218_ = 218,                     /* '%'  */
  YYSYMBOL_219_ = 219,                     /* '!'  */
  YYSYMBOL_220_ = 220,                     /* '~'  */
  YYSYMBOL_CAST = 221,                     /* CAST  */
  YYSYMBOL_PPTR = 222,                     /* PPTR  */
  YYSYMBOL_POS = 223,                      /* POS  */
  YYSYMBOL_NEG = 224,                      /* NEG  */
  YYSYMBOL_ADDRESSOF = 225,                /* ADDRESSOF  */
  YYSYMBOL_226_ = 226,                     /* '.'  */
  YYSYMBOL_227_ = 227,                     /* '['  */
  YYSYMBOL_228_ = 228,                     /* ']'  */
  YYSYMBOL_229_ = 229,                     /* ';'  */
  YYSYMBOL_230_ = 230,                     /* '{'  */
  YYSYMBOL_231_ = 231,                     /* '}'  */
  YYSYMBOL_232_ = 232,                     /* '('  */
  YYSYMBOL_233_ = 233,                     /* ')'  */
  YYSYMBOL_234_ = 234,                     /* '='  */
  YYSYMBOL_YYACCEPT = 235,                 /* $accept  */
  YYSYMBOL_input = 236,                    /* input  */
  YYSYMBOL_m_acf = 237,                    /* m_acf  */
  YYSYMBOL_decl_statements = 238,          /* decl_statements  */
  YYSYMBOL_decl_block = 239,               /* decl_block  */
  YYSYMBOL_imp_decl_statements = 240,      /* imp_decl_statements  */
  YYSYMBOL_imp_decl_block = 241,           /* imp_decl_block  */
  YYSYMBOL_gbl_statements = 242,           /* gbl_statements  */
  YYSYMBOL_243_1 = 243,                    /* $@1  */
  YYSYMBOL_imp_statements = 244,           /* imp_statements  */
  YYSYMBOL_245_2 = 245,                    /* $@2  */
  YYSYMBOL_int_statements = 246,           /* int_statements  */
  YYSYMBOL_semicolon_opt = 247,            /* semicolon_opt  */
  YYSYMBOL_statement = 248,                /* statement  */
  YYSYMBOL_pragma_warning = 249,           /* pragma_warning  */
  YYSYMBOL_warnings = 250,                 /* warnings  */
  YYSYMBOL_typedecl = 251,                 /* typedecl  */
  YYSYMBOL_cppquote = 252,                 /* cppquote  */
  YYSYMBOL_import_start = 253,             /* import_start  */
  YYSYMBOL_import = 254,                   /* import  */
  YYSYMBOL_importlib = 255,                /* importlib  */
  YYSYMBOL_libraryhdr = 256,               /* libraryhdr  */
  YYSYMBOL_library_start = 257,            /* library_start  */
  YYSYMBOL_librarydef = 258,               /* librarydef  */
  YYSYMBOL_m_args = 259,                   /* m_args  */
  YYSYMBOL_arg_list = 260,                 /* arg_list  */
  YYSYMBOL_args = 261,                     /* args  */
  YYSYMBOL_arg = 262,                      /* arg  */
  YYSYMBOL_array = 263,                    /* array  */
  YYSYMBOL_m_attributes = 264,             /* m_attributes  */
  YYSYMBOL_attributes = 265,               /* attributes  */
  YYSYMBOL_attrib_list = 266,              /* attrib_list  */
  YYSYMBOL_str_list = 267,                 /* str_list  */
  YYSYMBOL_marshaling_behavior = 268,      /* marshaling_behavior  */
  YYSYMBOL_contract_ver = 269,             /* contract_ver  */
  YYSYMBOL_contract_req = 270,             /* contract_req  */
  YYSYMBOL_static_attr = 271,              /* static_attr  */
  YYSYMBOL_attribute = 272,                /* attribute  */
  YYSYMBOL_uuid_string = 273,              /* uuid_string  */
  YYSYMBOL_callconv = 274,                 /* callconv  */
  YYSYMBOL_cases = 275,                    /* cases  */
  YYSYMBOL_case = 276,                     /* case  */
  YYSYMBOL_enums = 277,                    /* enums  */
  YYSYMBOL_enum_list = 278,                /* enum_list  */
  YYSYMBOL_enum_member = 279,              /* enum_member  */
  YYSYMBOL_enum = 280,                     /* enum  */
  YYSYMBOL_enumdef = 281,                  /* enumdef  */
  YYSYMBOL_m_exprs = 282,                  /* m_exprs  */
  YYSYMBOL_m_expr = 283,                   /* m_expr  */
  YYSYMBOL_expr = 284,                     /* expr  */
  YYSYMBOL_expr_list_int_const = 285,      /* expr_list_int_const  */
  YYSYMBOL_expr_int_const = 286,           /* expr_int_const  */
  YYSYMBOL_expr_const = 287,               /* expr_const  */
  YYSYMBOL_fields = 288,                   /* fields  */
  YYSYMBOL_field = 289,                    /* field  */
  YYSYMBOL_ne_union_field = 290,           /* ne_union_field  */
  YYSYMBOL_ne_union_fields = 291,          /* ne_union_fields  */
  YYSYMBOL_union_field = 292,              /* union_field  */
  YYSYMBOL_s_field = 293,                  /* s_field  */
  YYSYMBOL_funcdef = 294,                  /* funcdef  */
  YYSYMBOL_declaration = 295,              /* declaration  */
  YYSYMBOL_m_ident = 296,                  /* m_ident  */
  YYSYMBOL_t_ident = 297,                  /* t_ident  */
  YYSYMBOL_ident = 298,                    /* ident  */
  YYSYMBOL_base_type = 299,                /* base_type  */
  YYSYMBOL_m_int = 300,                    /* m_int  */
  YYSYMBOL_int_std = 301,                  /* int_std  */
  YYSYMBOL_namespace_pfx = 302,            /* namespace_pfx  */
  YYSYMBOL_qualified_type = 303,           /* qualified_type  */
  YYSYMBOL_parameterized_type = 304,       /* parameterized_type  */
  YYSYMBOL_parameterized_types = 305,      /* parameterized_types  */
  YYSYMBOL_coclass = 306,                  /* coclass  */
  YYSYMBOL_coclasshdr = 307,               /* coclasshdr  */
  YYSYMBOL_coclassdef = 308,               /* coclassdef  */
  YYSYMBOL_runtimeclass = 309,             /* runtimeclass  */
  YYSYMBOL_runtimeclass_hdr = 310,         /* runtimeclass_hdr  */
  YYSYMBOL_runtimeclass_def = 311,         /* runtimeclass_def  */
  YYSYMBOL_apicontract = 312,              /* apicontract  */
  YYSYMBOL_namespacedef = 313,             /* namespacedef  */
  YYSYMBOL_class_interfaces = 314,         /* class_interfaces  */
  YYSYMBOL_class_interface = 315,          /* class_interface  */
  YYSYMBOL_dispinterface = 316,            /* dispinterface  */
  YYSYMBOL_dispinterfacehdr = 317,         /* dispinterfacehdr  */
  YYSYMBOL_dispint_props = 318,            /* dispint_props  */
  YYSYMBOL_dispint_meths = 319,            /* dispint_meths  */
  YYSYMBOL_dispinterfacedef = 320,         /* dispinterfacedef  */
  YYSYMBOL_inherit = 321,                  /* inherit  */
  YYSYMBOL_interface = 322,                /* interface  */
  YYSYMBOL_interfacehdr = 323,             /* interfacehdr  */
  YYSYMBOL_type_parameter = 324,           /* type_parameter  */
  YYSYMBOL_type_parameters = 325,          /* type_parameters  */
  YYSYMBOL_delegatedef = 326,              /* delegatedef  */
  YYSYMBOL_327_3 = 327,                    /* $@3  */
  YYSYMBOL_required_types = 328,           /* required_types  */
  YYSYMBOL_requires = 329,                 /* requires  */
  YYSYMBOL_interfacedef = 330,             /* interfacedef  */
  YYSYMBOL_331_4 = 331,                    /* $@4  */
  YYSYMBOL_interfacedec = 332,             /* interfacedec  */
  YYSYMBOL_333_5 = 333,                    /* $@5  */
  YYSYMBOL_module = 334,                   /* module  */
  YYSYMBOL_modulehdr = 335,                /* modulehdr  */
  YYSYMBOL_moduledef = 336,                /* moduledef  */
  YYSYMBOL_storage_cls_spec = 337,         /* storage_cls_spec  */
  YYSYMBOL_function_specifier = 338,       /* function_specifier  */
  YYSYMBOL_type_qualifier = 339,           /* type_qualifier  */
  YYSYMBOL_m_type_qual_list = 340,         /* m_type_qual_list  */
  YYSYMBOL_decl_spec = 341,                /* decl_spec  */
  YYSYMBOL_m_decl_spec_no_type = 342,      /* m_decl_spec_no_type  */
  YYSYMBOL_decl_spec_no_type = 343,        /* decl_spec_no_type  */
  YYSYMBOL_declarator = 344,               /* declarator  */
  YYSYMBOL_direct_declarator = 345,        /* direct_declarator  */
  YYSYMBOL_abstract_declarator = 346,      /* abstract_declarator  */
  YYSYMBOL_abstract_declarator_no_direct = 347, /* abstract_declarator_no_direct  */
  YYSYMBOL_m_abstract_declarator = 348,    /* m_abstract_declarator  */
  YYSYMBOL_abstract_direct_declarator = 349, /* abstract_direct_declarator  */
  YYSYMBOL_any_declarator = 350,           /* any_declarator  */
  YYSYMBOL_any_declarator_no_direct = 351, /* any_declarator_no_direct  */
  YYSYMBOL_m_any_declarator = 352,         /* m_any_declarator  */
  YYSYMBOL_any_direct_declarator = 353,    /* any_direct_declarator  */
  YYSYMBOL_declarator_list = 354,          /* declarator_list  */
  YYSYMBOL_m_bitfield = 355,               /* m_bitfield  */
  YYSYMBOL_struct_declarator = 356,        /* struct_declarator  */
  YYSYMBOL_struct_declarator_list = 357,   /* struct_declarator_list  */
  YYSYMBOL_init_declarator = 358,          /* init_declarator  */
  YYSYMBOL_threading_type = 359,           /* threading_type  */
  YYSYMBOL_pointer_type = 360,             /* pointer_type  */
  YYSYMBOL_structdef = 361,                /* structdef  */
  YYSYMBOL_type = 362,                     /* type  */
  YYSYMBOL_typedef = 363,                  /* typedef  */
  YYSYMBOL_uniondef = 364,                 /* uniondef  */
  YYSYMBOL_version = 365,                  /* version  */
  YYSYMBOL_acf_statements = 366,           /* acf_statements  */
  YYSYMBOL_acf_int_statements = 367,       /* acf_int_statements  */
  YYSYMBOL_acf_int_statement = 368,        /* acf_int_statement  */
  YYSYMBOL_acf_interface = 369,            /* acf_interface  */
  YYSYMBOL_acf_attributes = 370,           /* acf_attributes  */
  YYSYMBOL_acf_attribute_list = 371,       /* acf_attribute_list  */
  YYSYMBOL_acf_attribute = 372,            /* acf_attribute  */
  YYSYMBOL_allocate_option_list = 373,     /* allocate_option_list  */
  YYSYMBOL_allocate_option = 374           /* allocate_option  */
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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3341

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  235
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  140
/* YYNRULES -- Number of rules.  */
#define YYNRULES  489
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  891

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   465


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
       2,     2,     2,   219,     2,     2,     2,   218,   211,     2,
     232,   233,   216,   215,   206,   214,   226,   217,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   208,   229,
     212,   234,   213,   207,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   227,     2,   228,   210,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   230,   209,   231,   220,     2,     2,     2,
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
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   221,   222,   223,   224,   225
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   361,   361,   376,   376,   378,   379,   385,   387,   388,
     392,   394,   395,   395,   397,   398,   399,   400,   403,   406,
     408,   409,   411,   412,   413,   414,   417,   418,   419,   419,
     421,   422,   423,   424,   427,   429,   430,   432,   433,   434,
     435,   436,   439,   440,   443,   444,   448,   449,   450,   451,
     452,   453,   454,   457,   468,   469,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   484,   486,   494,   500,   504,
     505,   507,   511,   515,   516,   519,   520,   523,   524,   528,
     533,   540,   544,   545,   548,   549,   553,   556,   557,   558,
     561,   562,   566,   567,   568,   572,   573,   576,   582,   587,
     588,   589,   590,   591,   592,   593,   594,   595,   596,   597,
     598,   599,   600,   601,   602,   603,   604,   605,   606,   607,
     608,   609,   610,   611,   612,   613,   614,   615,   616,   617,
     618,   619,   620,   621,   622,   623,   626,   627,   628,   629,
     630,   631,   632,   633,   634,   635,   636,   637,   638,   639,
     640,   641,   642,   643,   644,   645,   646,   647,   648,   649,
     650,   652,   653,   654,   655,   656,   657,   658,   659,   660,
     661,   662,   663,   664,   665,   666,   667,   668,   669,   670,
     671,   672,   673,   674,   678,   679,   680,   681,   682,   683,
     684,   685,   686,   687,   688,   689,   690,   691,   692,   693,
     694,   695,   696,   697,   698,   699,   700,   701,   702,   706,
     707,   712,   713,   714,   715,   718,   719,   722,   726,   732,
     733,   734,   737,   741,   753,   758,   762,   767,   770,   771,
     774,   775,   778,   779,   780,   781,   782,   783,   784,   785,
     786,   787,   788,   789,   790,   791,   792,   793,   794,   795,
     796,   797,   798,   799,   800,   801,   802,   803,   804,   805,
     806,   807,   808,   809,   810,   811,   812,   813,   814,   815,
     817,   819,   820,   823,   824,   827,   833,   839,   840,   843,
     848,   855,   856,   859,   860,   864,   865,   868,   872,   878,
     886,   890,   895,   896,   899,   900,   901,   904,   906,   909,
     910,   911,   912,   913,   914,   915,   916,   917,   918,   919,
     922,   923,   926,   927,   928,   929,   930,   931,   932,   933,
     934,   938,   939,   943,   944,   947,   952,   953,   954,   955,
     956,   957,   961,   962,   970,   976,   981,   982,   989,   995,
     999,  1006,  1007,  1010,  1011,  1015,  1018,  1019,  1022,  1031,
    1032,  1035,  1036,  1039,  1045,  1051,  1052,  1053,  1056,  1057,
    1058,  1059,  1062,  1069,  1070,  1074,  1075,  1079,  1088,  1087,
    1101,  1102,  1103,  1105,  1106,  1109,  1116,  1116,  1125,  1130,
    1134,  1135,  1135,  1140,  1143,  1144,  1147,  1152,  1159,  1160,
    1161,  1165,  1169,  1172,  1173,  1176,  1177,  1181,  1182,  1186,
    1187,  1188,  1192,  1194,  1195,  1199,  1200,  1201,  1202,  1207,
    1209,  1210,  1215,  1217,  1221,  1222,  1227,  1228,  1229,  1230,
    1234,  1242,  1244,  1245,  1250,  1252,  1256,  1257,  1264,  1265,
    1266,  1267,  1268,  1272,  1279,  1280,  1283,  1284,  1287,  1294,
    1295,  1300,  1301,  1305,  1306,  1307,  1308,  1309,  1310,  1314,
    1315,  1316,  1319,  1322,  1323,  1324,  1325,  1326,  1327,  1328,
    1329,  1330,  1331,  1332,  1335,  1342,  1344,  1350,  1351,  1352,
    1356,  1357,  1361,  1362,  1366,  1373,  1382,  1383,  1387,  1388,
    1392,  1394,  1395,  1396,  1400,  1401,  1406,  1407,  1408,  1409
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "aIDENTIFIER",
  "aPRAGMA", "aKNOWNTYPE", "aNAMESPACE", "aNUM", "aHEXNUM", "aDOUBLE",
  "aSTRING", "aWSTRING", "aSQSTRING", "aUUID", "aEOF", "aACF", "SHL",
  "SHR", "MEMBERPTR", "EQUALITY", "INEQUALITY", "GREATEREQUAL",
  "LESSEQUAL", "LOGICALOR", "LOGICALAND", "ELLIPSIS", "tACTIVATABLE",
  "tAGGREGATABLE", "tAGILE", "tALLNODES", "tALLOCATE", "tANNOTATION",
  "tAPICONTRACT", "tAPPOBJECT", "tASYNC", "tASYNCUUID", "tAUTOHANDLE",
  "tBINDABLE", "tBOOLEAN", "tBROADCAST", "tBYTE", "tBYTECOUNT", "tCALLAS",
  "tCALLBACK", "tCASE", "tCDECL", "tCHAR", "tCOCLASS", "tCODE",
  "tCOMMSTATUS", "tCONST", "tCONTEXTHANDLE", "tCONTEXTHANDLENOSERIALIZE",
  "tCONTEXTHANDLESERIALIZE", "tCONTRACT", "tCONTRACTVERSION", "tCONTROL",
  "tCPPQUOTE", "tCUSTOM", "tDECLARE", "tDECODE", "tDEFAULT",
  "tDEFAULTBIND", "tDELEGATE", "tDEFAULTCOLLELEM", "tDEFAULTVALUE",
  "tDEFAULTVTABLE", "tDISABLECONSISTENCYCHECK", "tDISPLAYBIND",
  "tDISPINTERFACE", "tDLLNAME", "tDONTFREE", "tDOUBLE", "tDUAL",
  "tENABLEALLOCATE", "tENCODE", "tENDPOINT", "tENTRY", "tENUM",
  "tERRORSTATUST", "tEVENTADD", "tEVENTREMOVE", "tEXCLUSIVETO",
  "tEXPLICITHANDLE", "tEXTERN", "tFALSE", "tFASTCALL", "tFAULTSTATUS",
  "tFLAGS", "tFLOAT", "tFORCEALLOCATE", "tHANDLE", "tHANDLET",
  "tHELPCONTEXT", "tHELPFILE", "tHELPSTRING", "tHELPSTRINGCONTEXT",
  "tHELPSTRINGDLL", "tHIDDEN", "tHYPER", "tID", "tIDEMPOTENT", "tIGNORE",
  "tIIDIS", "tIMMEDIATEBIND", "tIMPLICITHANDLE", "tIMPORT", "tIMPORTLIB",
  "tIN", "tIN_LINE", "tINLINE", "tINPUTSYNC", "tINT", "tINT32", "tINT3264",
  "tINT64", "tINTERFACE", "tLCID", "tLENGTHIS", "tLIBRARY", "tLICENSED",
  "tLOCAL", "tLONG", "tMARSHALINGBEHAVIOR", "tMAYBE", "tMESSAGE",
  "tMETHODS", "tMODULE", "tMTA", "tNAMESPACE", "tNOCODE", "tNONBROWSABLE",
  "tNONCREATABLE", "tNONE", "tNONEXTENSIBLE", "tNOTIFY", "tNOTIFYFLAG",
  "tNULL", "tOBJECT", "tODL", "tOLEAUTOMATION", "tOPTIMIZE", "tOPTIONAL",
  "tOUT", "tPARTIALIGNORE", "tPASCAL", "tPOINTERDEFAULT",
  "tPRAGMA_WARNING", "tPROGID", "tPROPERTIES", "tPROPGET", "tPROPPUT",
  "tPROPPUTREF", "tPROXY", "tPTR", "tPUBLIC", "tRANGE", "tREADONLY",
  "tREF", "tREGISTER", "tREPRESENTAS", "tREQUESTEDIT", "tREQUIRES",
  "tRESTRICTED", "tRETVAL", "tRUNTIMECLASS", "tSAFEARRAY", "tSHORT",
  "tSIGNED", "tSINGLENODE", "tSIZEIS", "tSIZEOF", "tSMALL", "tSOURCE",
  "tSTANDARD", "tSTATIC", "tSTDCALL", "tSTRICTCONTEXTHANDLE", "tSTRING",
  "tSTRUCT", "tSWITCH", "tSWITCHIS", "tSWITCHTYPE", "tTHREADING",
  "tTRANSMITAS", "tTRUE", "tTYPEDEF", "tUIDEFAULT", "tUNION", "tUNIQUE",
  "tUNSIGNED", "tUSESGETLASTERROR", "tUSERMARSHAL", "tUUID", "tV1ENUM",
  "tVARARG", "tVERSION", "tVIPROGID", "tVOID", "tWCHAR", "tWIREMARSHAL",
  "tAPARTMENT", "tNEUTRAL", "tSINGLE", "tFREE", "tBOTH", "','", "'?'",
  "':'", "'|'", "'^'", "'&'", "'<'", "'>'", "'-'", "'+'", "'*'", "'/'",
  "'%'", "'!'", "'~'", "CAST", "PPTR", "POS", "NEG", "ADDRESSOF", "'.'",
  "'['", "']'", "';'", "'{'", "'}'", "'('", "')'", "'='", "$accept",
  "input", "m_acf", "decl_statements", "decl_block", "imp_decl_statements",
  "imp_decl_block", "gbl_statements", "$@1", "imp_statements", "$@2",
  "int_statements", "semicolon_opt", "statement", "pragma_warning",
  "warnings", "typedecl", "cppquote", "import_start", "import",
  "importlib", "libraryhdr", "library_start", "librarydef", "m_args",
  "arg_list", "args", "arg", "array", "m_attributes", "attributes",
  "attrib_list", "str_list", "marshaling_behavior", "contract_ver",
  "contract_req", "static_attr", "attribute", "uuid_string", "callconv",
  "cases", "case", "enums", "enum_list", "enum_member", "enum", "enumdef",
  "m_exprs", "m_expr", "expr", "expr_list_int_const", "expr_int_const",
  "expr_const", "fields", "field", "ne_union_field", "ne_union_fields",
  "union_field", "s_field", "funcdef", "declaration", "m_ident", "t_ident",
  "ident", "base_type", "m_int", "int_std", "namespace_pfx",
  "qualified_type", "parameterized_type", "parameterized_types", "coclass",
  "coclasshdr", "coclassdef", "runtimeclass", "runtimeclass_hdr",
  "runtimeclass_def", "apicontract", "namespacedef", "class_interfaces",
  "class_interface", "dispinterface", "dispinterfacehdr", "dispint_props",
  "dispint_meths", "dispinterfacedef", "inherit", "interface",
  "interfacehdr", "type_parameter", "type_parameters", "delegatedef",
  "$@3", "required_types", "requires", "interfacedef", "$@4",
  "interfacedec", "$@5", "module", "modulehdr", "moduledef",
  "storage_cls_spec", "function_specifier", "type_qualifier",
  "m_type_qual_list", "decl_spec", "m_decl_spec_no_type",
  "decl_spec_no_type", "declarator", "direct_declarator",
  "abstract_declarator", "abstract_declarator_no_direct",
  "m_abstract_declarator", "abstract_direct_declarator", "any_declarator",
  "any_declarator_no_direct", "m_any_declarator", "any_direct_declarator",
  "declarator_list", "m_bitfield", "struct_declarator",
  "struct_declarator_list", "init_declarator", "threading_type",
  "pointer_type", "structdef", "type", "typedef", "uniondef", "version",
  "acf_statements", "acf_int_statements", "acf_int_statement",
  "acf_interface", "acf_attributes", "acf_attribute_list", "acf_attribute",
  "allocate_option_list", "allocate_option", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,    44,    63,    58,   124,
      94,    38,    60,    62,    45,    43,    42,    47,    37,    33,
     126,   461,   462,   463,   464,   465,    46,    91,    93,    59,
     123,   125,    40,    41,    61
};
#endif

#define YYPACT_NINF (-684)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-477)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -684,   120,   938,  -684,  -684,  -684,  -139,   -37,  -684,  -684,
    -684,   192,  -684,   -96,  -118,   313,  -684,   360,  -684,  -684,
    -684,  -684,    37,   131,  -684,  -684,  -684,  -684,  -684,   252,
      37,    93,   -45,  -684,   368,   -29,    37,   782,  -684,  -684,
     410,   451,   782,  -684,  -684,  3141,  -684,  -684,  -684,  -684,
      18,  -684,  -684,  -684,  -684,  -684,   -22,  2797,    39,    48,
    -684,  -684,   393,    22,  -684,    64,     7,  -684,    72,    26,
    -684,    81,   118,   203,   142,   214,   -27,   125,  -684,  -684,
    -684,   230,  -684,   244,   244,   244,    56,  2983,   235,   244,
     239,   255,  -684,    51,  -684,   -37,   201,  -684,  -684,   314,
    -684,  -684,  -684,   177,  -684,   259,  -684,  -684,   264,  -684,
    -684,   456,  -684,  -684,  -684,   496,  -684,  -684,  2983,  -684,
    -684,   266,   270,  -127,  -120,  -684,   269,  -684,   271,  -684,
    -684,   272,  -684,  -684,  -684,   273,   274,  -684,  -684,  -684,
    -684,  -684,   275,   277,  -684,   278,  -684,  -684,  -684,  -684,
     279,  -684,  -684,  -684,   280,  -684,  -684,  -684,   282,   283,
    -684,  -684,   284,  -684,  -684,  -684,  -684,  -684,   292,   294,
     296,   298,   300,  -684,   301,  -684,  -684,   302,  -684,   303,
    -684,  -684,   305,   308,  -684,  -684,   311,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,   327,  -684,
    -684,  -684,   331,   336,  -684,  -684,  -684,  -684,  -684,  -684,
     338,  -684,  -684,   339,  -684,  -684,  -684,   340,  -684,   341,
    -684,  -684,   343,   344,   345,   347,  -684,  -684,  -684,   348,
     349,  -684,  -684,   351,   352,   355,   -91,  -684,  -684,  -684,
    1877,  1009,  2983,   361,   499,   466,   472,   473,   477,   478,
     359,   363,  -684,  -684,  -684,  -684,  -684,    56,   364,   367,
    -684,  -684,   371,  1773,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,   -32,  -684,  -684,  -684,  -684,   460,  -684,   428,  -684,
    -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,    56,    56,  -684,   365,   -41,  -684,  -684,  -684,   244,
    -684,  -684,  -684,   370,  -684,  -684,  -684,   -49,  -684,  -684,
     595,   375,   -60,   112,  -684,  -684,  -684,   395,   376,  -684,
     372,  -684,  2868,   600,   332,   482,   136,  2868,   604,   332,
     136,   602,   605,   136,  2868,   136,   606,   610,   136,   611,
     136,   136,  2310,   136,   136,    36,   612,   -68,   614,   136,
    2983,   136,  2868,   136,  2983,   221,  2983,  2983,   332,   210,
     615,  2983,  3141,   399,  -684,   397,   396,  -684,  -684,  -684,
    -684,   401,  -684,   402,  -684,   403,   406,  -684,  -684,  -684,
    -684,   214,   482,  2868,  -684,   407,   415,  -684,  -684,  -684,
    -684,   415,  -102,  -684,  -684,  -684,  -684,   188,   417,   -33,
     181,   189,  -684,   440,   -46,   425,   485,   428,    22,  -684,
     485,   492,   429,  1352,    44,   427,  -684,   136,   510,  2310,
    -684,  -684,    94,    51,  -684,   431,  -684,   492,  -684,   482,
     433,   459,   432,  -684,   655,  -684,   204,   361,   217,   436,
     464,   438,  -684,  -684,   439,   444,  -684,  -684,  -684,  -684,
    -684,  -684,  -684,  -684,  -684,   450,  -684,   136,   136,   136,
     136,   136,   136,   741,  2565,  -106,  -684,   452,   458,   454,
     483,  2565,   455,   457,  -684,  -101,   461,   463,   465,   467,
     468,   470,   471,   475,  1883,   480,  2868,    68,   484,   -98,
    -684,  2565,  -684,  -684,  -684,   487,   490,   494,   495,   486,
     500,   -82,   502,   491,  2224,   503,  -684,  -684,  -684,  -684,
    -684,  -684,   504,   506,   507,   508,   479,  -684,   512,   522,
     523,  -684,  3141,  -684,   681,  -684,  -684,  -684,  -684,  -684,
     -16,    56,   462,  -684,  -684,  1773,  -684,   214,   -12,  -684,
     214,  1216,  -684,   498,  2868,   481,  1754,   501,  -684,  -684,
    -684,     2,   469,    65,    22,  -684,   505,  -684,   214,  -684,
     529,  2868,  -684,  -684,  -684,  -684,   751,  -684,  2442,   524,
     537,  -684,  -684,  -684,  -684,  -684,  -684,   -66,  -684,  -684,
     532,   552,  -684,  -684,   218,   136,  -684,    29,  -684,  2868,
    -684,   533,  -684,   538,  -684,   539,  -684,   604,  -684,  -684,
    -684,  2868,    27,    27,    27,    27,    27,    27,  2303,   441,
     136,   136,   766,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     767,   136,   136,  -684,  -684,   764,  -684,   136,  -684,  -684,
     762,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,  -684,
    -684,  -684,    68,  -684,  1969,  -684,    68,  -684,  -684,  -684,
       4,  -684,   136,  -684,  -684,  -684,  -684,  -684,   136,  -684,
    -684,  -684,  2868,  -684,  -684,  -684,  -684,  -684,  -684,   768,
    -684,  -684,  -684,  -684,   -39,   541,  -684,  -684,  2310,  -684,
     570,  -684,  -684,  -684,  -684,  -684,  -684,  -684,    56,   224,
    -684,  -684,  2868,   548,  -684,  -684,   485,   549,   674,   575,
     492,  1423,  -684,  -684,  -684,  -684,  2186,    94,  -684,   557,
     555,   532,  1773,  -684,  -684,  -684,  -684,    68,   559,   482,
    -684,  -684,  -684,   441,  -684,  -684,  2115,  -684,   441,  -684,
     560,    87,   143,   143,  -684,   658,   658,   424,   424,  1556,
    2474,  2544,  2583,  2600,  2154,   424,   424,   212,   212,    27,
      27,    27,  -684,  2522,  -684,  -684,   562,  -684,  -684,    43,
    -684,   563,    68,   564,  -684,  2310,  -684,  -684,   565,  -684,
    -684,   492,  -684,   214,  1145,   485,   566,    56,  -684,  -684,
    -684,  -684,  -684,   492,   571,  -684,   214,  -684,  -684,  -684,
     785,  -684,  -684,    74,   592,  -684,   -51,  -684,   572,  -684,
     573,    88,  -684,   574,    68,   576,  -684,   136,  2310,  -684,
     136,  -684,  -684,  -684,    43,  -684,  -684,  -684,   577,  -684,
     591,  -684,  -684,    90,   214,  -684,  1559,  -684,  -684,   579,
     582,   136,  -684,    68,  -684,  -684,  -684,  -684,    43,  -684,
    -684,  -684,    27,   581,  2565,  -684,  -684,  1773,   580,  -684,
     214,  1630,  -684,  -684,  -684,  -684,    30,  -684,  -684,    99,
    2310,  -684,   214,   136,   596,  -684,  -684,   586,   585,  -684,
     597,   265,  -684,   214,   265,  -684,  -684,   593,  -684,  -684,
    -684
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int16 yydefact[] =
{
      11,     0,    84,     1,    51,   323,     0,   470,   307,   299,
     318,     0,   392,     0,     0,     0,   306,   294,   308,   388,
     305,   309,   310,     0,   391,   312,   319,   320,   317,     0,
     310,     0,     0,   390,     0,     0,   310,     0,   314,   389,
     294,   294,   304,   453,   300,    99,     2,    25,    24,    52,
       0,    46,    26,    49,    26,    23,     0,    85,   457,     0,
     456,   301,     0,   454,   455,     0,     0,    18,     0,     0,
      21,     0,     0,     0,     0,    44,     0,   355,    16,    15,
      14,     0,    22,   397,   397,   397,     0,     0,   459,   397,
       0,   461,   321,     0,     4,   470,     0,   332,   333,     0,
       5,   346,   347,   458,   296,     0,   311,   316,     0,   358,
     359,     0,   315,   341,   342,     0,   336,   337,     0,   313,
     302,   460,     0,   462,     0,   303,     0,   101,     0,   103,
     104,     0,   105,   106,   107,     0,     0,   110,   111,   112,
     113,   114,     0,     0,   117,     0,   119,   120,   121,   122,
       0,   124,   125,   126,     0,   128,   129,   130,     0,     0,
     133,   134,     0,   136,   137,   138,   139,   140,     0,     0,
       0,     0,     0,   146,     0,   148,   149,     0,   151,     0,
     153,   154,   157,     0,   158,   159,     0,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,     0,   173,
     174,   175,     0,     0,   178,   179,   180,   181,   451,   182,
       0,   184,   449,     0,   186,   187,   188,     0,   190,     0,
     192,   193,     0,     0,     0,     0,   198,   450,   199,     0,
       0,   203,   204,     0,     0,     0,     0,    87,   208,    47,
      84,    84,     0,    84,     0,   294,     0,     0,   294,   294,
       0,   457,   334,   338,   348,   362,   386,     0,   459,   461,
      48,   324,     0,     0,    17,   343,    20,   343,    19,    12,
     383,     0,    45,   379,   381,   380,     0,   376,   373,    42,
     401,   398,   400,   399,   297,   298,   211,   212,   213,   214,
     393,     0,     0,   405,   441,   404,   291,   457,   459,   397,
     461,   395,    50,     0,   482,   481,   483,     0,   478,   471,
       0,     0,     0,    84,    66,   360,   361,     0,     0,   277,
       0,   283,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   230,     0,     0,     0,     0,     0,
       0,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    99,    86,    67,     0,     0,    41,    38,    39,
      40,     0,    33,     0,    36,     0,     0,    31,    30,    27,
      37,    44,     0,     0,    85,     0,   458,    69,    70,   384,
     385,   460,   462,    71,   290,   322,   326,   327,   329,     0,
      84,    84,    11,     0,    84,     0,     0,   373,   356,   357,
       0,     0,     0,    84,     0,     0,   403,     0,     0,    73,
     407,   396,     0,     0,   477,     0,    65,     0,     7,     0,
       0,   221,   226,   222,     0,   463,    84,    84,    84,     0,
       0,     0,   210,   209,     0,     0,   241,   232,   233,   234,
     238,   239,   240,   235,   236,     0,   237,     0,     0,     0,
       0,     0,     0,     0,   275,     0,   273,     0,    95,     0,
       0,   276,     0,     0,    90,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   426,     0,     0,
     228,   231,    92,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   448,   443,   444,   445,
     446,   447,     0,     0,     0,     0,   467,   469,     0,     0,
       0,    88,    99,     8,     0,    32,    35,    34,    28,    72,
       0,     0,     0,   328,   330,     0,   325,    44,     0,   344,
      44,    84,   349,     0,     0,     0,     0,     0,   363,   364,
     365,     0,     0,     0,   370,   371,   374,    42,    44,    43,
       0,    85,   394,   402,   406,   442,     0,    83,     0,     0,
      77,    74,    75,   488,   486,   489,   487,     0,   484,   479,
     472,     0,   224,   227,    84,     0,    54,     0,   452,     0,
     278,     0,   465,    85,   284,     0,   100,     0,   102,   202,
     108,     0,   265,   264,   263,   266,   261,   262,     0,   414,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   109,   115,     0,   116,     0,   123,   127,
       0,   131,   132,   135,   141,   142,   143,   144,   145,   147,
     150,   152,   426,   393,    73,   431,   426,   428,   427,    80,
     423,   156,   230,   155,   160,   172,   176,   177,     0,   185,
     189,   191,     0,   194,   195,   197,   196,   200,   201,     0,
     205,   206,   207,    89,     0,     0,    26,   368,    73,   434,
     464,   340,   331,   335,   345,   339,    13,   351,     0,   459,
     350,   353,     0,     0,   289,   354,     0,     0,     0,   355,
       0,    84,   387,    82,    81,   408,     0,     0,   480,   476,
       0,   472,     0,   223,   225,    55,    53,     0,   461,   292,
     282,   281,    97,   414,   272,   393,    73,   418,   414,   415,
       0,   411,   254,   255,   267,   248,   249,   252,   253,   243,
     244,     0,   245,   246,   247,   251,   250,   257,   256,   259,
     260,   258,   268,     0,   274,    96,     0,    91,    79,   426,
     393,     0,   426,     0,   422,    73,   430,   229,     0,    98,
     468,     0,    10,    44,    84,     0,     0,     0,   287,   352,
     366,   382,    42,     0,     0,   372,    44,    78,    76,   485,
       0,   475,   473,     0,   436,   439,     0,   280,     0,   293,
       0,   414,   393,     0,   426,     0,   410,     0,    73,   417,
       0,   271,   118,   421,   426,   432,   425,   429,     0,   183,
       0,    68,    29,     0,    44,   435,    84,    42,   375,     0,
       0,     0,   438,     0,   279,   215,   270,   409,   426,   419,
     413,   416,   269,     0,   242,   424,   433,     0,     0,   367,
      44,    84,   474,     6,   437,   440,     0,   412,   420,     0,
      73,   378,    44,     0,     0,   466,   216,     0,     0,   377,
       0,    84,     9,    44,    84,   286,   218,     0,   369,   217,
     285
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -684,  -684,  -684,  -684,  -684,  -684,  -684,   419,  -684,   -52,
    -684,  -526,  -205,    10,  -684,  -684,  -684,  -684,  -684,   115,
    -684,  -684,  -684,    13,  -532,  -684,  -684,  -307,  -286,  -238,
      -2,  -684,  -684,  -684,   227,  -275,  -684,  -308,  -244,   -80,
    -684,  -684,  -684,  -684,  -684,   243,     8,   488,   167,  -235,
    -684,  -306,  -310,  -684,  -684,  -684,  -684,   -42,  -285,  -684,
     285,  -684,    42,   -85,  -250,    95,   299,   803,  -243,  -252,
    -493,     6,  -684,    15,    12,  -684,    16,    17,    19,   568,
    -684,   781,  -684,  -684,  -684,  -684,   134,   -19,  -684,   139,
    -380,    20,  -684,   137,   442,    23,  -684,    14,  -684,  -684,
    -684,    24,  -684,  -684,  -374,  -577,   -53,   -34,   -17,  -264,
    -684,  -684,  -684,  -641,  -684,  -683,  -684,  -447,  -684,  -684,
    -684,     3,  -684,   601,  -684,   513,     1,   -48,  -684,     5,
    -684,   753,   129,  -684,  -684,   133,  -684,   434,  -684,   144
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    46,   312,    47,   684,   367,     2,   402,   240,
     686,   413,   273,   559,    49,   587,    50,    51,    52,    53,
     369,   250,    54,   370,   569,   570,   571,   572,   655,    56,
     384,   236,   475,   495,   469,   439,   502,   237,   444,   656,
     866,   876,   430,   431,   432,   433,   297,   489,   490,   464,
     465,   466,   472,   436,   590,   594,   438,   886,   887,   703,
      59,   808,   105,   657,    60,   107,    61,    62,    63,    64,
     399,   371,    66,   372,   373,    69,   374,   375,   376,   400,
     539,    73,    74,   404,   546,    75,   278,    76,    77,   550,
     551,   377,   785,   556,   412,   378,   410,   379,   406,   256,
      81,   380,    83,    84,    85,   414,    86,   280,    87,   294,
     295,   739,   815,   740,   741,   658,   773,   659,   660,   690,
     842,   805,   806,   296,   512,   238,   298,    89,    90,   300,
     518,    94,   720,   721,    95,    96,   307,   308,   577,   578
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,   293,   241,    88,   257,   383,   292,    91,    65,   420,
      58,   398,    48,   396,    68,    55,    80,    67,    70,    71,
     397,    72,    78,   476,   409,    79,    82,   415,   416,   478,
     553,   711,   481,   408,   483,   485,   725,   488,   255,   299,
     562,   242,   692,   499,   804,   612,   284,   284,   285,   285,
     282,   283,   467,  -295,   521,   301,   427,    15,   258,   284,
     320,   285,   259,   252,   492,   251,   281,   281,   281,   253,
     318,   284,   281,   285,   873,   429,   769,   781,  -295,  -476,
     543,   303,   122,   124,    29,   470,   208,    92,   286,   286,
     212,   874,   810,    12,    12,   471,   113,   816,   471,   114,
     632,   286,   -61,  -295,    29,   640,   484,   565,   662,   491,
     321,   304,   100,   286,   515,   362,   491,   403,   504,   545,
       3,   227,   771,   573,   662,   112,   305,   633,  -295,   287,
     287,   119,   641,   286,   306,   663,    99,   363,    12,   446,
     717,   108,   287,   447,   448,   449,   450,   451,   452,   106,
     563,   670,   591,   595,   287,   843,   786,   423,   811,   555,
     804,   612,   538,   538,   243,   574,   544,   718,   554,   493,
     847,   428,   293,   535,   287,   560,   529,   292,   844,   424,
     536,    45,   471,   568,   581,   274,   418,   115,   288,   288,
      93,   419,   782,   824,   382,    97,   687,    98,   589,   544,
     544,   288,   275,   118,   813,   768,   293,   293,   706,   774,
     494,   292,   292,   288,   683,   707,   688,   516,   517,   289,
     289,   453,   602,   603,   604,   605,   606,   607,   608,   803,
     612,   418,   289,   288,   263,   848,   775,   265,    57,    57,
     445,    88,    88,   828,   289,    91,    91,   239,    58,    58,
     368,   368,   405,   630,   631,   109,   267,   110,     6,   653,
     290,   875,   726,   575,   289,   421,   836,   689,   -56,   440,
     418,   706,   290,   454,   440,   654,   291,   260,   709,   724,
     535,   477,   281,   398,   653,   396,   853,   840,   291,   487,
     122,   124,   397,   264,    12,   418,   706,   530,   576,   503,
     654,   266,   500,   858,   735,   535,   505,   455,   513,   514,
     268,   861,   877,   520,   418,   418,   101,   310,   102,   818,
     736,   456,   823,   737,   311,   826,   764,   766,    19,   293,
     531,   605,   693,   276,   292,   695,   120,   277,   878,    45,
     486,   125,   442,  -219,   582,   443,   429,   457,   269,   506,
     458,   459,   460,   712,    24,   461,   462,   625,   626,   627,
     628,   629,   778,   103,   869,   104,   487,   850,   463,   630,
     631,   116,   271,   117,   776,   742,   743,   855,   745,   746,
     747,   748,   749,   750,   751,   752,   753,   754,   755,   756,
     757,   758,   759,   760,   761,   562,   763,   779,   261,   262,
     263,   867,   471,    33,   533,   833,   -57,  -295,    45,   798,
     609,   561,   537,   121,    88,   104,    45,   486,    91,    39,
     540,    58,   507,   508,   509,   510,   511,   491,   627,   628,
     629,    45,   270,   652,   788,   588,   593,   562,   630,   631,
     610,   611,   612,   272,    45,    45,   293,   737,   592,  -220,
     562,   292,   737,  -288,   123,   819,   104,  -288,   555,   315,
     279,   316,   262,   407,   -58,     5,     6,   554,   302,   386,
     398,   104,   396,   560,   562,   387,   389,   388,   390,   397,
     391,   392,   104,   104,   -60,   284,   286,   285,   548,   313,
     549,   698,    45,   314,   885,   -59,  -295,     5,     6,   317,
     319,   322,   385,   323,   324,   325,   326,   327,   257,   328,
     329,   330,   331,   446,   332,   333,   334,   447,   448,   449,
     450,   451,   452,   835,   335,   737,   336,   287,   337,   738,
     338,   864,   339,   340,   341,   342,   727,   343,   830,    57,
     344,   409,    88,   345,   702,   699,    91,    65,   733,    58,
     408,    48,   694,    68,    55,    80,    67,    70,    71,   346,
      72,    78,   258,   347,    79,    82,   259,   880,   348,   251,
     349,   350,   351,   352,   772,   353,   354,   355,   831,   356,
     357,   358,   852,   359,   360,   854,   288,   361,    45,   393,
     411,   838,   -62,   -63,   728,   453,   -64,   395,   560,   417,
     425,   487,   422,   434,   437,   398,   471,   396,   426,   435,
     441,   468,   473,   293,   397,   474,   479,   289,   292,   440,
     480,   482,   496,   560,   498,   519,   522,   523,   524,   859,
     525,   526,   527,   534,   784,   487,   528,   532,   625,   626,
     627,   628,   629,   544,   809,  -295,   544,   454,   542,   257,
     630,   631,   486,   738,   547,   871,   814,   735,   738,   557,
     564,   580,   586,   487,   583,   584,   585,   879,   418,   596,
     597,   598,   599,   736,   610,   611,   612,   600,   888,   615,
     616,   455,   601,   487,   635,   634,   486,   636,   638,   637,
     639,   685,   668,   691,   642,   456,   643,   672,   644,   708,
     645,   646,   293,   647,   648,   679,   697,   292,   649,   561,
     700,   710,    88,   651,   486,   243,    91,   661,   719,    58,
     664,   457,   487,   665,   458,   459,   566,   666,   667,   461,
     462,   738,   705,   669,   486,   671,   674,   675,   567,   676,
     677,   678,   463,   716,   446,   680,     5,     6,   447,   448,
     449,   450,   451,   452,   446,   681,   682,   715,   447,   448,
     449,   450,   451,   452,   722,   487,   729,   730,   731,   744,
     762,   765,   767,   486,   783,   780,   787,   789,   791,     8,
      23,     9,    57,   793,    93,    88,   801,    10,   807,    91,
     839,    12,    58,   817,   368,   822,   825,   827,   829,   834,
     841,   837,   845,   857,   881,   884,   846,   849,   862,   851,
     856,   863,   870,    16,   868,   882,   486,   487,   883,   245,
      18,   541,   890,   792,   732,    19,   453,   723,    10,   777,
      20,   704,   111,    21,   561,   401,   453,    88,   254,   501,
      22,    91,   889,   794,    58,   790,   865,   795,   309,   552,
     802,    24,   800,    25,    26,    27,    28,   579,   394,   561,
     497,   799,    88,    30,     0,     0,    91,     0,   486,    58,
     623,   624,   625,   626,   627,   628,   629,     0,   454,     0,
       0,    22,     0,     0,   630,   631,     0,     0,   454,     0,
       0,     0,     0,     0,    25,    26,    27,    28,     0,     0,
      33,     0,     0,     0,    30,     0,     0,    35,    36,    37,
       0,     0,   455,    38,     0,     0,    39,     0,     0,     0,
     248,     0,   455,     0,     0,     0,   456,     0,     0,   249,
       0,    42,     0,     0,     0,     0,   456,     0,    -3,    43,
      44,     0,     4,     5,     6,     0,     0,     0,     0,    36,
       0,     0,   457,     7,    38,   458,   459,   460,     0,     0,
     461,   462,   457,     0,     0,   458,   459,   460,     0,     0,
     461,   462,     0,   463,     0,     0,     8,     0,     9,   713,
       0,     0,     0,   463,    10,    11,     0,     0,    12,     0,
       0,     0,     0,     0,     0,    13,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    15,     0,     0,
      16,     0,     0,     4,     5,     6,    17,    18,     0,     0,
       0,     0,    19,     0,     0,     0,     0,    20,     0,     0,
      21,     0,     0,     0,     0,     0,     0,    22,     0,     0,
       0,     0,     0,     0,    23,     0,     0,     8,    24,     9,
      25,    26,    27,    28,    29,    10,    11,     0,     0,    12,
      30,     0,     0,     0,     0,     0,    13,    31,   365,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    15,     0,
       0,    16,     0,     0,     0,    32,     0,    17,    18,     0,
       0,     0,     0,    19,     0,     0,     0,    33,    20,     0,
       0,    21,     0,    34,    35,    36,    37,     0,    22,     0,
      38,     0,     0,    39,     0,    23,   366,    40,     0,    24,
       0,    25,    26,    27,    28,    29,    41,     0,    42,     0,
       0,    30,     0,     0,     0,     0,    43,    44,    31,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     6,     0,     0,     0,     0,    32,     0,     0,     0,
       0,     0,     0,     0,     0,    45,     0,     0,    33,     0,
       0,     0,     0,     0,    34,    35,    36,    37,     0,     0,
       0,    38,     0,     8,    39,     9,     0,     0,    40,     0,
       0,    10,    11,     0,     0,    12,     0,    41,     0,    42,
       0,     0,    13,     0,   365,     0,     0,    43,    44,     0,
       0,     0,     0,     0,    15,     0,     0,    16,     0,     0,
       4,     5,     6,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,     0,    20,     0,    45,    21,     0,     0,
     381,     0,     0,     0,    22,     0,     0,     0,     0,     0,
       0,    23,   366,     0,     8,    24,     9,    25,    26,    27,
      28,    29,    10,    11,     0,     0,    12,    30,     0,     0,
       0,     0,     0,    13,    31,    14,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,    16,     0,
       0,     0,    32,     0,    17,    18,     0,     0,     0,     0,
      19,     0,     0,     0,    33,    20,     0,     0,    21,     0,
      34,    35,    36,    37,     0,    22,     0,    38,     0,     0,
      39,     0,    23,     0,    40,     0,    24,     0,    25,    26,
      27,    28,    29,    41,     0,    42,     0,     0,    30,     0,
       0,     0,     0,    43,    44,    31,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,     5,     6,     0,
       0,     0,     0,    32,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,    33,   832,     0,     0,     0,
       0,    34,    35,    36,    37,     0,     0,     0,    38,     0,
       8,    39,     9,     0,     0,    40,     0,     0,    10,     0,
       0,     0,    12,     0,    41,     0,    42,     0,     0,    13,
       0,     0,     0,     0,    43,    44,     0,     0,     0,     0,
       0,     0,     0,     0,    16,     0,     0,     4,     5,     6,
      17,    18,     0,     0,     0,     0,    19,     0,     0,     0,
       0,    20,     0,    45,    21,     0,     0,   696,     0,     0,
       0,    22,     0,     0,     0,     0,     0,     0,    23,     0,
       0,     8,    24,     9,    25,    26,    27,    28,     0,    10,
       0,     0,     0,    12,    30,     0,     0,     0,     0,     0,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,     0,     0,     0,    32,
       0,    17,    18,     0,     0,     0,     0,    19,     0,     0,
       0,    33,    20,     0,     0,    21,     0,     0,    35,    36,
      37,     0,    22,     0,    38,     0,     0,    39,     0,    23,
       0,    40,     0,    24,     0,    25,    26,    27,    28,     0,
      41,     0,    42,     0,     0,    30,     0,     0,     0,     0,
      43,    44,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     5,     6,     0,     0,     0,     0,
      32,     0,   610,   611,   612,   613,   614,   615,   616,    45,
     618,     0,    33,   558,     0,     0,     0,     0,     0,    35,
      36,    37,     0,     0,     0,    38,     0,     8,    39,     9,
       0,     0,    40,     0,     0,    10,     0,     0,     0,    12,
       0,    41,     0,    42,     0,     0,    13,     0,     0,     0,
       0,    43,    44,     0,     0,     0,     0,     0,     0,     0,
       0,    16,     0,     0,     4,     5,     6,    17,    18,     0,
       0,     0,     0,    19,     0,     0,     0,     0,    20,     0,
      45,    21,     0,     0,   796,     0,     0,     0,    22,     0,
       0,     0,     0,     0,     0,    23,     0,     0,     8,    24,
       9,    25,    26,    27,    28,     0,    10,     0,     0,     0,
      12,    30,     0,     0,     0,     0,     0,    13,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    16,     0,     0,     0,    32,     0,    17,    18,
       0,     0,     0,     0,    19,     0,     0,     0,    33,    20,
       0,     0,    21,     0,     0,    35,    36,    37,     0,    22,
       0,    38,     0,     0,    39,     0,    23,     0,    40,     0,
      24,     0,    25,    26,    27,    28,     0,    41,     0,    42,
       0,     0,    30,     0,     0,     0,     0,    43,    44,     5,
       6,     0,     0,     0,     0,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,     0,     0,    32,     5,     6,
       0,     0,   630,   631,     0,     0,    45,     0,     0,    33,
     860,     0,     8,     0,     9,     0,    35,    36,    37,     0,
      10,     0,    38,     0,    12,    39,     0,     0,     0,    40,
       0,     8,     0,     9,     0,     0,     0,     0,    41,    10,
      42,     0,     0,     0,     0,     0,    16,     0,    43,    44,
       0,     0,   245,    18,     0,     0,     0,     0,    19,     0,
       0,     0,     0,    20,     0,    16,    21,     0,     0,     0,
       0,     0,    18,    22,     0,     0,     0,    45,     0,     0,
       0,   872,    20,     0,    24,    21,    25,    26,    27,    28,
       0,     0,    22,     0,     0,     0,    30,     0,     0,     0,
       0,     4,     5,     6,     0,    25,    26,    27,    28,     0,
       0,   364,     0,     0,     0,    30,     0,     0,     0,   610,
     611,   612,   613,   614,   615,   616,   617,   618,     0,     0,
       0,     0,     0,    33,     0,     8,     0,     9,     0,     0,
      35,    36,    37,    10,    11,     0,    38,    12,     0,    39,
       0,     0,     0,   248,    13,     0,   365,     0,     0,     0,
      36,    37,   249,     0,    42,    38,    15,     0,     0,    16,
       0,     0,    43,    44,     0,    17,    18,     0,     0,     0,
       0,    19,     0,    42,     0,     0,    20,     0,     0,    21,
       0,     0,    44,     0,     5,     6,    22,     0,     0,     0,
       0,    45,     0,    23,   366,   701,     0,    24,     0,    25,
      26,    27,    28,    29,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,     0,     0,    31,     8,     0,     9,
       0,     0,     0,     0,   286,    10,     0,     0,     0,    12,
       0,     0,     0,     0,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,     0,     0,
       0,    16,    34,    35,    36,    37,     0,   245,    18,    38,
       0,     0,    39,    19,     0,   287,    40,     0,    20,     0,
       0,    21,     0,     0,     0,    41,     0,    42,    22,     0,
       0,     0,     0,     0,     0,    43,    44,     0,     0,    24,
       0,    25,    26,    27,    28,     0,     0,     0,     0,     0,
     619,    30,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,     0,     0,    45,     0,     0,     0,     0,   630,
     631,     0,     0,     0,   288,     0,   650,     0,     0,     0,
       5,     6,     0,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,    35,    36,    37,     0,     0,
       0,    38,     0,     0,    39,   289,     0,     0,   248,     0,
       0,     0,     0,     8,     0,     9,     0,   249,     0,    42,
     286,    10,     0,     0,     0,    12,     0,    43,    44,     0,
     610,   611,   612,   613,   614,   615,   616,     0,     0,     0,
       0,     0,     0,     0,     0,   770,     0,    16,     0,     0,
       0,     5,     6,   245,    18,     0,    45,     0,     0,    19,
       0,   287,     0,     0,    20,     0,     0,    21,     0,     0,
       0,   797,     0,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     8,    24,     9,    25,    26,    27,
      28,     0,    10,     0,     0,     0,    12,    30,     0,     0,
     610,   611,   612,   613,   614,   615,   616,   617,   618,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,     0,
     288,     0,     0,     0,   245,    18,     0,     0,     0,     0,
      19,     0,     0,     0,    33,    20,     0,     0,    21,     0,
       0,    35,    36,    37,     0,    22,     0,    38,     0,     0,
      39,   289,     0,     0,   248,     0,    24,     0,    25,    26,
      27,    28,     0,   249,     0,    42,     0,     0,    30,     0,
       0,     0,     0,    43,    44,     5,     6,     0,     0,   610,
     611,   612,   613,   614,   615,   616,   617,   618,     0,     0,
       0,   812,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    45,     0,     0,    33,     0,     0,     8,     0,
       9,     0,    35,    36,    37,     0,    10,     0,    38,     0,
      12,    39,     0,     0,     0,   248,   623,   624,   625,   626,
     627,   628,   629,     0,   249,     0,    42,     0,     0,     0,
     630,   631,    16,     0,    43,    44,     0,     0,   245,    18,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    20,
       0,     0,    21,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
      24,     0,    25,    26,    27,    28,     0,     0,     0,     0,
       0,   619,    30,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,     0,     0,     0,     0,     0,     0,     0,
     630,   631,     0,     0,     0,     0,     0,   673,   610,   611,
     612,   613,   614,   615,   616,   617,   618,     0,     0,    33,
       0,     0,     0,     0,     0,     0,    35,    36,    37,     0,
       0,     0,    38,     0,     0,    39,     0,     0,     0,   248,
     610,   611,   612,   613,   614,   615,   616,     0,   249,     0,
      42,     0,     0,     0,     0,     0,     0,     0,    43,    44,
     619,     0,   620,   621,   622,   623,   624,   625,   626,   627,
     628,   629,     0,     0,     0,     0,     0,     0,     0,   630,
     631,     0,     0,     0,     0,     0,   734,    45,   610,   611,
     612,   613,   614,   615,   616,   617,   618,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     610,   611,   612,   613,   614,   615,   616,   617,   618,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   610,   611,   612,   613,   614,   615,   616,   617,   618,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   610,
     611,   612,   613,   614,   615,   616,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   610,   611,   612,   613,
     614,   615,   616,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   619,
       0,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,     0,     0,     0,     0,     0,     0,     0,   630,   631,
     714,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,     0,     0,     0,     0,     0,     0,     0,
     630,   631,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   619,
       0,   620,   621,   622,   623,   624,   625,   626,   627,   628,
     629,     0,     0,     0,     0,     0,     0,     0,   630,   631,
     821,   619,   820,   620,   621,   622,   623,   624,   625,   626,
     627,   628,   629,     0,     0,     0,     0,     0,     0,     0,
     630,   631,   619,     0,   620,   621,   622,   623,   624,   625,
     626,   627,   628,   629,     0,     0,     0,     0,     0,     0,
       0,   630,   631,   621,   622,   623,   624,   625,   626,   627,
     628,   629,     5,     6,     0,     0,     0,     0,     0,   630,
     631,   622,   623,   624,   625,   626,   627,   628,   629,     0,
       0,     0,     0,     0,     0,     0,   630,   631,     0,   244,
       0,     0,     0,     0,     0,     8,     0,     9,     0,     0,
       0,     0,     0,    10,    11,     0,     0,    12,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,     0,     0,    16,
       0,     0,     0,     5,     6,   245,    18,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    20,     0,     0,    21,
       0,     0,     0,     0,     0,     0,    22,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     8,    24,     9,    25,
      26,    27,    28,    29,    10,     0,   246,     0,    12,    30,
       0,     0,     0,     0,   247,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,   245,    18,     0,     0,
       0,     0,    19,     0,     0,     0,    33,    20,     0,     0,
      21,     0,    34,    35,    36,    37,     0,    22,     0,    38,
       0,     0,    39,     0,     0,     0,   248,     0,    24,     0,
      25,    26,    27,    28,     0,   249,     0,    42,     5,     6,
      30,     0,     0,     0,     0,    43,    44,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     9,     0,     0,     0,    33,     0,    10,
       0,     0,     0,     0,    35,    36,    37,     0,     0,     0,
      38,     0,     0,    39,     0,     0,     0,   248,     0,     0,
       0,     0,     0,     0,     0,    16,   249,     0,    42,     0,
       0,   245,    18,     0,     0,     0,    43,    44,     0,     0,
       0,     0,    20,     0,     0,    21,     0,     0,     0,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,    27,    28,     0,
       0,     0,     0,     0,     0,    30,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      36,    37,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,   248,     0,     0,     0,     0,   126,   127,     0,
       0,   249,   128,    42,   129,   130,   131,   132,   133,     0,
     134,    43,    44,   135,     0,   136,     0,     0,     0,   137,
     138,     0,   139,   140,   141,   142,   143,   144,     0,   145,
       0,   146,   147,   148,     0,   149,   150,   151,   152,   153,
       0,   154,     0,     0,   155,   156,   157,   158,   159,     0,
       0,   160,   161,   162,   163,     0,     0,     0,   164,   165,
       0,   166,   167,     0,   168,   169,   170,   171,   172,   173,
       0,   174,   175,   176,   177,   178,   179,     0,     0,   180,
       0,     0,   181,     0,     0,     0,     0,     0,   182,   183,
       0,   184,   185,     0,   186,   187,   188,     0,     0,     0,
       0,   189,   190,   191,     0,   192,   193,   194,     0,   195,
     196,   197,   198,   199,   200,   201,     0,   202,     0,   203,
       0,   204,   205,   206,   207,   208,   209,   210,   211,   212,
       0,   213,   214,     0,   215,   216,     0,     0,     0,     0,
       0,   217,     0,     0,   218,     0,   219,     0,   220,   221,
       0,     0,   222,   223,   224,   225,     0,     0,   226,     0,
     227,     0,   228,   229,   230,   231,   232,   233,   234,     0,
       0,   235
};

static const yytype_int16 yycheck[] =
{
       2,    86,    54,     2,    57,   243,    86,     2,     2,   295,
       2,   263,     2,   263,     2,     2,     2,     2,     2,     2,
     263,     2,     2,   333,   276,     2,     2,   291,   292,   335,
     410,   557,   338,   276,   340,   342,     7,   343,    57,    87,
     414,    63,   535,   349,   727,    18,     3,     3,     5,     5,
      84,    85,   327,   180,   362,    89,   116,    69,    57,     3,
     180,     5,    57,    57,    28,    57,    83,    84,    85,    57,
     118,     3,    89,     5,    44,   313,   653,   116,   180,   116,
     126,    30,    40,    41,   116,   329,   154,   226,    45,    45,
     158,    61,   733,    50,    50,   330,     3,   738,   333,     6,
     206,    45,   229,   230,   116,   206,   341,   417,   206,   344,
     230,    60,   230,    45,   358,   206,   351,   149,   353,   404,
       0,   189,   654,    29,   206,    30,    75,   233,   230,    86,
      86,    36,   233,    45,    83,   233,   232,   228,    50,     3,
     206,    10,    86,     7,     8,     9,    10,    11,    12,   112,
     414,   233,   437,   438,    86,   206,   688,   206,   735,   411,
     843,    18,   400,   401,   186,    71,   404,   233,   411,   133,
     811,   231,   257,   206,    86,   413,   381,   257,   229,   228,
     213,   227,   417,   418,   427,   212,   227,   232,   145,   145,
     227,   232,   231,   770,   242,     3,   212,     5,   436,   437,
     438,   145,   229,   232,   736,   652,   291,   292,   206,   656,
     174,   291,   292,   145,   522,   213,   232,     7,     8,   176,
     176,    85,   457,   458,   459,   460,   461,   462,   463,   722,
      18,   227,   176,   145,   212,   812,   232,   230,   240,   241,
     325,   240,   241,   775,   176,   240,   241,   229,   240,   241,
     240,   241,   271,   226,   227,     3,   230,     5,     6,   216,
     216,   231,   233,   169,   176,   299,   792,   531,   229,   322,
     227,   206,   216,   137,   327,   232,   232,   229,   213,   585,
     206,   334,   299,   535,   216,   535,   818,   213,   232,   342,
     248,   249,   535,   229,    50,   227,   206,   382,   204,   352,
     232,   229,   350,   213,   216,   206,   354,   171,   356,   357,
     229,   837,   213,   361,   227,   227,     3,   116,     5,   232,
     232,   185,   769,   609,    10,   772,   632,   637,    84,   414,
     383,   566,   537,   208,   414,   540,    37,   212,   870,   227,
     342,    42,    10,   231,   429,    13,   584,   211,   230,   128,
     214,   215,   216,   558,   110,   219,   220,   214,   215,   216,
     217,   218,   668,     3,   857,     5,   419,   814,   232,   226,
     227,     3,   230,     5,   660,   610,   611,   824,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   769,   631,   672,     5,     6,
     212,   848,   637,   159,   216,   785,   229,   230,   227,   716,
     463,   413,   231,     3,   413,     5,   227,   419,   413,   175,
     231,   413,   201,   202,   203,   204,   205,   662,   216,   217,
     218,   227,   229,   486,   698,   231,   438,   811,   226,   227,
      16,    17,    18,   229,   227,   227,   531,   733,   231,   231,
     824,   531,   738,   229,     3,   741,     5,   233,   710,     3,
     230,     5,     6,     3,   229,     5,     6,   710,   229,     3,
     722,     5,   722,   711,   848,     3,     3,     5,     5,   722,
       3,     3,     5,     5,   229,     3,    45,     5,     3,   230,
       5,   544,   227,   229,   229,   229,   230,     5,     6,     3,
     230,   232,     3,   232,   232,   232,   232,   232,   561,   232,
     232,   232,   232,     3,   232,   232,   232,     7,     8,     9,
      10,    11,    12,   787,   232,   811,   232,    86,   232,   609,
     232,   841,   232,   232,   232,   232,   589,   232,   781,   541,
     232,   793,   541,   232,   546,   544,   541,   541,   601,   541,
     793,   541,   538,   541,   541,   541,   541,   541,   541,   232,
     541,   541,   561,   232,   541,   541,   561,   873,   232,   561,
     232,   232,   232,   232,   654,   232,   232,   232,   783,   232,
     232,   232,   817,   232,   232,   820,   145,   232,   227,   230,
     162,   796,   229,   229,   589,    85,   229,   226,   836,   234,
       5,   654,   232,   208,   232,   857,   841,   857,   233,   233,
      10,     7,    10,   698,   857,    10,    10,   176,   698,   672,
      10,    10,    10,   861,    10,    10,   227,   230,   232,   834,
     229,   229,   229,   216,   686,   688,   230,   230,   214,   215,
     216,   217,   218,   881,   729,   230,   884,   137,   208,   702,
     226,   227,   654,   733,   229,   860,   736,   216,   738,   230,
     233,   230,     7,   716,   231,   206,   234,   872,   227,   233,
     206,   233,   233,   232,    16,    17,    18,   233,   883,    21,
      22,   171,   232,   736,   226,   233,   688,   233,   233,   206,
     233,    10,   206,   231,   233,   185,   233,   206,   233,   230,
     233,   233,   787,   233,   233,   226,   208,   787,   233,   711,
     229,   206,   711,   233,   716,   186,   711,   233,   186,   711,
     233,   211,   775,   233,   214,   215,   216,   233,   233,   219,
     220,   811,   231,   233,   736,   233,   233,   233,   228,   233,
     233,   233,   232,   206,     3,   233,     5,     6,     7,     8,
       9,    10,    11,    12,     3,   233,   233,   233,     7,     8,
       9,    10,    11,    12,   212,   818,   233,   229,   229,     3,
       3,     7,    10,   775,   233,     7,   206,   229,   229,    38,
     106,    40,   784,   208,   227,   784,   231,    46,   229,   784,
       5,    50,   784,   233,   784,   233,   233,   233,   233,   233,
     208,   230,   230,   212,   208,   208,   233,   233,   229,   233,
     233,   229,   232,    72,   233,   229,   818,   870,   233,    78,
      79,   402,   229,   708,   597,    84,    85,   584,    46,   662,
      89,   546,    29,    92,   836,   267,    85,   836,    57,   351,
      99,   836,   884,   709,   836,   706,   843,   710,    95,   407,
     721,   110,   719,   112,   113,   114,   115,   423,   257,   861,
     347,   717,   861,   122,    -1,    -1,   861,    -1,   870,   861,
     212,   213,   214,   215,   216,   217,   218,    -1,   137,    -1,
      -1,    99,    -1,    -1,   226,   227,    -1,    -1,   137,    -1,
      -1,    -1,    -1,    -1,   112,   113,   114,   115,    -1,    -1,
     159,    -1,    -1,    -1,   122,    -1,    -1,   166,   167,   168,
      -1,    -1,   171,   172,    -1,    -1,   175,    -1,    -1,    -1,
     179,    -1,   171,    -1,    -1,    -1,   185,    -1,    -1,   188,
      -1,   190,    -1,    -1,    -1,    -1,   185,    -1,     0,   198,
     199,    -1,     4,     5,     6,    -1,    -1,    -1,    -1,   167,
      -1,    -1,   211,    15,   172,   214,   215,   216,    -1,    -1,
     219,   220,   211,    -1,    -1,   214,   215,   216,    -1,    -1,
     219,   220,    -1,   232,    -1,    -1,    38,    -1,    40,   228,
      -1,    -1,    -1,   232,    46,    47,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,
      72,    -1,    -1,     4,     5,     6,    78,    79,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,
      92,    -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,
      -1,    -1,    -1,    -1,   106,    -1,    -1,    38,   110,    40,
     112,   113,   114,   115,   116,    46,    47,    -1,    -1,    50,
     122,    -1,    -1,    -1,    -1,    -1,    57,   129,    59,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    72,    -1,    -1,    -1,   147,    -1,    78,    79,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,   159,    89,    -1,
      -1,    92,    -1,   165,   166,   167,   168,    -1,    99,    -1,
     172,    -1,    -1,   175,    -1,   106,   107,   179,    -1,   110,
      -1,   112,   113,   114,   115,   116,   188,    -1,   190,    -1,
      -1,   122,    -1,    -1,    -1,    -1,   198,   199,   129,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,
       5,     6,    -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   227,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,   165,   166,   167,   168,    -1,    -1,
      -1,   172,    -1,    38,   175,    40,    -1,    -1,   179,    -1,
      -1,    46,    47,    -1,    -1,    50,    -1,   188,    -1,   190,
      -1,    -1,    57,    -1,    59,    -1,    -1,   198,   199,    -1,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    72,    -1,    -1,
       4,     5,     6,    78,    79,    -1,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    89,    -1,   227,    92,    -1,    -1,
     231,    -1,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,    -1,    38,   110,    40,   112,   113,   114,
     115,   116,    46,    47,    -1,    -1,    50,   122,    -1,    -1,
      -1,    -1,    -1,    57,   129,    59,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    72,    -1,
      -1,    -1,   147,    -1,    78,    79,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,   159,    89,    -1,    -1,    92,    -1,
     165,   166,   167,   168,    -1,    99,    -1,   172,    -1,    -1,
     175,    -1,   106,    -1,   179,    -1,   110,    -1,   112,   113,
     114,   115,   116,   188,    -1,   190,    -1,    -1,   122,    -1,
      -1,    -1,    -1,   198,   199,   129,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,    -1,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,   159,   231,    -1,    -1,    -1,
      -1,   165,   166,   167,   168,    -1,    -1,    -1,   172,    -1,
      38,   175,    40,    -1,    -1,   179,    -1,    -1,    46,    -1,
      -1,    -1,    50,    -1,   188,    -1,   190,    -1,    -1,    57,
      -1,    -1,    -1,    -1,   198,   199,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    72,    -1,    -1,     4,     5,     6,
      78,    79,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    89,    -1,   227,    92,    -1,    -1,   231,    -1,    -1,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,   106,    -1,
      -1,    38,   110,    40,   112,   113,   114,   115,    -1,    46,
      -1,    -1,    -1,    50,   122,    -1,    -1,    -1,    -1,    -1,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,    -1,    -1,    -1,   147,
      -1,    78,    79,    -1,    -1,    -1,    -1,    84,    -1,    -1,
      -1,   159,    89,    -1,    -1,    92,    -1,    -1,   166,   167,
     168,    -1,    99,    -1,   172,    -1,    -1,   175,    -1,   106,
      -1,   179,    -1,   110,    -1,   112,   113,   114,   115,    -1,
     188,    -1,   190,    -1,    -1,   122,    -1,    -1,    -1,    -1,
     198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     4,     5,     6,    -1,    -1,    -1,    -1,
     147,    -1,    16,    17,    18,    19,    20,    21,    22,   227,
      24,    -1,   159,   231,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,   172,    -1,    38,   175,    40,
      -1,    -1,   179,    -1,    -1,    46,    -1,    -1,    -1,    50,
      -1,   188,    -1,   190,    -1,    -1,    57,    -1,    -1,    -1,
      -1,   198,   199,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    72,    -1,    -1,     4,     5,     6,    78,    79,    -1,
      -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,    -1,
     227,    92,    -1,    -1,   231,    -1,    -1,    -1,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   106,    -1,    -1,    38,   110,
      40,   112,   113,   114,   115,    -1,    46,    -1,    -1,    -1,
      50,   122,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    72,    -1,    -1,    -1,   147,    -1,    78,    79,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,   159,    89,
      -1,    -1,    92,    -1,    -1,   166,   167,   168,    -1,    99,
      -1,   172,    -1,    -1,   175,    -1,   106,    -1,   179,    -1,
     110,    -1,   112,   113,   114,   115,    -1,   188,    -1,   190,
      -1,    -1,   122,    -1,    -1,    -1,    -1,   198,   199,     5,
       6,    -1,    -1,    -1,    -1,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,    -1,    -1,   147,     5,     6,
      -1,    -1,   226,   227,    -1,    -1,   227,    -1,    -1,   159,
     231,    -1,    38,    -1,    40,    -1,   166,   167,   168,    -1,
      46,    -1,   172,    -1,    50,   175,    -1,    -1,    -1,   179,
      -1,    38,    -1,    40,    -1,    -1,    -1,    -1,   188,    46,
     190,    -1,    -1,    -1,    -1,    -1,    72,    -1,   198,   199,
      -1,    -1,    78,    79,    -1,    -1,    -1,    -1,    84,    -1,
      -1,    -1,    -1,    89,    -1,    72,    92,    -1,    -1,    -1,
      -1,    -1,    79,    99,    -1,    -1,    -1,   227,    -1,    -1,
      -1,   231,    89,    -1,   110,    92,   112,   113,   114,   115,
      -1,    -1,    99,    -1,    -1,    -1,   122,    -1,    -1,    -1,
      -1,     4,     5,     6,    -1,   112,   113,   114,   115,    -1,
      -1,    14,    -1,    -1,    -1,   122,    -1,    -1,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,   159,    -1,    38,    -1,    40,    -1,    -1,
     166,   167,   168,    46,    47,    -1,   172,    50,    -1,   175,
      -1,    -1,    -1,   179,    57,    -1,    59,    -1,    -1,    -1,
     167,   168,   188,    -1,   190,   172,    69,    -1,    -1,    72,
      -1,    -1,   198,   199,    -1,    78,    79,    -1,    -1,    -1,
      -1,    84,    -1,   190,    -1,    -1,    89,    -1,    -1,    92,
      -1,    -1,   199,    -1,     5,     6,    99,    -1,    -1,    -1,
      -1,   227,    -1,   106,   107,   231,    -1,   110,    -1,   112,
     113,   114,   115,   116,    -1,    -1,    -1,    -1,    -1,   122,
      -1,    -1,    -1,    -1,    -1,    -1,   129,    38,    -1,    40,
      -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,    -1,
      -1,    72,   165,   166,   167,   168,    -1,    78,    79,   172,
      -1,    -1,   175,    84,    -1,    86,   179,    -1,    89,    -1,
      -1,    92,    -1,    -1,    -1,   188,    -1,   190,    99,    -1,
      -1,    -1,    -1,    -1,    -1,   198,   199,    -1,    -1,   110,
      -1,   112,   113,   114,   115,    -1,    -1,    -1,    -1,    -1,
     207,   122,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,   227,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,   145,    -1,   233,    -1,    -1,    -1,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,
      -1,   172,    -1,    -1,   175,   176,    -1,    -1,   179,    -1,
      -1,    -1,    -1,    38,    -1,    40,    -1,   188,    -1,   190,
      45,    46,    -1,    -1,    -1,    50,    -1,   198,   199,    -1,
      16,    17,    18,    19,    20,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   216,    -1,    72,    -1,    -1,
      -1,     5,     6,    78,    79,    -1,   227,    -1,    -1,    84,
      -1,    86,    -1,    -1,    89,    -1,    -1,    92,    -1,    -1,
      -1,    25,    -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,   110,    40,   112,   113,   114,
     115,    -1,    46,    -1,    -1,    -1,    50,   122,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    72,    -1,
     145,    -1,    -1,    -1,    78,    79,    -1,    -1,    -1,    -1,
      84,    -1,    -1,    -1,   159,    89,    -1,    -1,    92,    -1,
      -1,   166,   167,   168,    -1,    99,    -1,   172,    -1,    -1,
     175,   176,    -1,    -1,   179,    -1,   110,    -1,   112,   113,
     114,   115,    -1,   188,    -1,   190,    -1,    -1,   122,    -1,
      -1,    -1,    -1,   198,   199,     5,     6,    -1,    -1,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,   159,    -1,    -1,    38,    -1,
      40,    -1,   166,   167,   168,    -1,    46,    -1,   172,    -1,
      50,   175,    -1,    -1,    -1,   179,   212,   213,   214,   215,
     216,   217,   218,    -1,   188,    -1,   190,    -1,    -1,    -1,
     226,   227,    72,    -1,   198,   199,    -1,    -1,    78,    79,
      -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,    -1,    89,
      -1,    -1,    92,    -1,    -1,    -1,    -1,    -1,    -1,    99,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
     110,    -1,   112,   113,   114,   115,    -1,    -1,    -1,    -1,
      -1,   207,   122,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,   233,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,   159,
      -1,    -1,    -1,    -1,    -1,    -1,   166,   167,   168,    -1,
      -1,    -1,   172,    -1,    -1,   175,    -1,    -1,    -1,   179,
      16,    17,    18,    19,    20,    21,    22,    -1,   188,    -1,
     190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   198,   199,
     207,    -1,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,
     227,    -1,    -1,    -1,    -1,    -1,   233,   227,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      17,    18,    19,    20,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
     228,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   207,
      -1,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   226,   227,
     228,   207,   208,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     226,   227,   207,    -1,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   226,   227,   210,   211,   212,   213,   214,   215,   216,
     217,   218,     5,     6,    -1,    -1,    -1,    -1,    -1,   226,
     227,   211,   212,   213,   214,   215,   216,   217,   218,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   226,   227,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    40,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    -1,    50,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,    -1,    72,
      -1,    -1,    -1,     5,     6,    78,    79,    -1,    -1,    -1,
      -1,    84,    -1,    -1,    -1,    -1,    89,    -1,    -1,    92,
      -1,    -1,    -1,    -1,    -1,    -1,    99,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,   110,    40,   112,
     113,   114,   115,   116,    46,    -1,   119,    -1,    50,   122,
      -1,    -1,    -1,    -1,   127,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      72,    -1,    -1,    -1,    -1,    -1,    78,    79,    -1,    -1,
      -1,    -1,    84,    -1,    -1,    -1,   159,    89,    -1,    -1,
      92,    -1,   165,   166,   167,   168,    -1,    99,    -1,   172,
      -1,    -1,   175,    -1,    -1,    -1,   179,    -1,   110,    -1,
     112,   113,   114,   115,    -1,   188,    -1,   190,     5,     6,
     122,    -1,    -1,    -1,    -1,   198,   199,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    40,    -1,    -1,    -1,   159,    -1,    46,
      -1,    -1,    -1,    -1,   166,   167,   168,    -1,    -1,    -1,
     172,    -1,    -1,   175,    -1,    -1,    -1,   179,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    72,   188,    -1,   190,    -1,
      -1,    78,    79,    -1,    -1,    -1,   198,   199,    -1,    -1,
      -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   112,   113,   114,   115,    -1,
      -1,    -1,    -1,    -1,    -1,   122,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   166,
     167,   168,    -1,    -1,    -1,   172,    -1,    -1,    -1,    -1,
      -1,    -1,   179,    -1,    -1,    -1,    -1,    26,    27,    -1,
      -1,   188,    31,   190,    33,    34,    35,    36,    37,    -1,
      39,   198,   199,    42,    -1,    44,    -1,    -1,    -1,    48,
      49,    -1,    51,    52,    53,    54,    55,    56,    -1,    58,
      -1,    60,    61,    62,    -1,    64,    65,    66,    67,    68,
      -1,    70,    -1,    -1,    73,    74,    75,    76,    77,    -1,
      -1,    80,    81,    82,    83,    -1,    -1,    -1,    87,    88,
      -1,    90,    91,    -1,    93,    94,    95,    96,    97,    98,
      -1,   100,   101,   102,   103,   104,   105,    -1,    -1,   108,
      -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,   117,   118,
      -1,   120,   121,    -1,   123,   124,   125,    -1,    -1,    -1,
      -1,   130,   131,   132,    -1,   134,   135,   136,    -1,   138,
     139,   140,   141,   142,   143,   144,    -1,   146,    -1,   148,
      -1,   150,   151,   152,   153,   154,   155,   156,   157,   158,
      -1,   160,   161,    -1,   163,   164,    -1,    -1,    -1,    -1,
      -1,   170,    -1,    -1,   173,    -1,   175,    -1,   177,   178,
      -1,    -1,   181,   182,   183,   184,    -1,    -1,   187,    -1,
     189,    -1,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,   200
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,   236,   242,     0,     4,     5,     6,    15,    38,    40,
      46,    47,    50,    57,    59,    69,    72,    78,    79,    84,
      89,    92,    99,   106,   110,   112,   113,   114,   115,   116,
     122,   129,   147,   159,   165,   166,   167,   168,   172,   175,
     179,   188,   190,   198,   199,   227,   237,   239,   248,   249,
     251,   252,   253,   254,   257,   258,   264,   265,   281,   295,
     299,   301,   302,   303,   304,   306,   307,   308,   309,   310,
     311,   312,   313,   316,   317,   320,   322,   323,   326,   330,
     332,   335,   336,   337,   338,   339,   341,   343,   361,   362,
     363,   364,   226,   227,   366,   369,   370,     3,     5,   232,
     230,     3,     5,     3,     5,   297,   112,   300,    10,     3,
       5,   302,   300,     3,     6,   232,     3,     5,   232,   300,
     301,     3,   297,     3,   297,   301,    26,    27,    31,    33,
      34,    35,    36,    37,    39,    42,    44,    48,    49,    51,
      52,    53,    54,    55,    56,    58,    60,    61,    62,    64,
      65,    66,    67,    68,    70,    73,    74,    75,    76,    77,
      80,    81,    82,    83,    87,    88,    90,    91,    93,    94,
      95,    96,    97,    98,   100,   101,   102,   103,   104,   105,
     108,   111,   117,   118,   120,   121,   123,   124,   125,   130,
     131,   132,   134,   135,   136,   138,   139,   140,   141,   142,
     143,   144,   146,   148,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   160,   161,   163,   164,   170,   173,   175,
     177,   178,   181,   182,   183,   184,   187,   189,   191,   192,
     193,   194,   195,   196,   197,   200,   266,   272,   360,   229,
     244,   244,    63,   186,    32,    78,   119,   127,   179,   188,
     256,   281,   306,   309,   316,   322,   334,   341,   361,   364,
     229,     5,     6,   212,   229,   230,   229,   230,   229,   230,
     229,   230,   229,   247,   212,   229,   208,   212,   321,   230,
     342,   343,   342,   342,     3,     5,    45,    86,   145,   176,
     216,   232,   274,   298,   344,   345,   358,   281,   361,   362,
     364,   342,   229,    30,    60,    75,    83,   371,   372,   366,
     116,    10,   238,   230,   229,     3,     5,     3,   362,   230,
     180,   230,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   206,   228,    14,    59,   107,   241,   248,   255,
     258,   306,   308,   309,   311,   312,   313,   326,   330,   332,
     336,   231,   362,   264,   265,     3,     3,     3,     5,     3,
       5,     3,     3,   230,   358,   226,   299,   303,   304,   305,
     314,   314,   243,   149,   318,   322,   333,     3,   303,   304,
     331,   162,   329,   246,   340,   344,   344,   234,   227,   232,
     263,   342,   232,   206,   228,     5,   233,   116,   231,   264,
     277,   278,   279,   280,   208,   233,   288,   232,   291,   270,
     341,    10,    10,    13,   273,   298,     3,     7,     8,     9,
      10,    11,    12,    85,   137,   171,   185,   211,   214,   215,
     216,   219,   220,   232,   284,   285,   286,   270,     7,   269,
     273,   284,   287,    10,    10,   267,   287,   341,   286,    10,
      10,   286,    10,   286,   284,   262,   265,   341,   286,   282,
     283,   284,    28,   133,   174,   268,    10,   360,    10,   286,
     362,   282,   271,   341,   284,   362,   128,   201,   202,   203,
     204,   205,   359,   362,   362,   273,     7,     8,   365,    10,
     362,   272,   227,   230,   232,   229,   229,   229,   230,   247,
     298,   341,   230,   216,   216,   206,   213,   231,   264,   315,
     231,   242,   208,   126,   264,   293,   319,   229,     3,     5,
     324,   325,   329,   325,   303,   304,   328,   230,   231,   248,
     264,   265,   339,   344,   233,   287,   216,   228,   284,   259,
     260,   261,   262,    29,    71,   169,   204,   373,   374,   372,
     230,   303,   298,   231,   206,   234,     7,   250,   231,   264,
     289,   293,   231,   265,   290,   293,   233,   206,   233,   233,
     233,   232,   284,   284,   284,   284,   284,   284,   284,   341,
      16,    17,    18,    19,    20,    21,    22,    23,    24,   207,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     226,   227,   206,   233,   233,   226,   233,   206,   233,   233,
     206,   233,   233,   233,   233,   233,   233,   233,   233,   233,
     233,   233,   341,   216,   232,   263,   274,   298,   350,   352,
     353,   233,   206,   233,   233,   233,   233,   233,   206,   233,
     233,   233,   206,   233,   233,   233,   233,   233,   233,   226,
     233,   233,   233,   272,   240,    10,   245,   212,   232,   344,
     354,   231,   305,   247,   332,   247,   231,   208,   341,   361,
     229,   231,   265,   294,   295,   231,   206,   213,   230,   213,
     206,   246,   247,   228,   228,   233,   206,   206,   233,   186,
     367,   368,   212,   280,   286,     7,   233,   341,   364,   233,
     229,   229,   269,   341,   233,   216,   232,   263,   274,   346,
     348,   349,   284,   284,     3,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,     3,   284,   286,     7,   287,    10,   352,   340,
     216,   259,   274,   351,   352,   232,   263,   283,   286,   270,
       7,   116,   231,   233,   244,   327,   259,   206,   344,   229,
     324,   229,   254,   208,   321,   328,   231,    25,   262,   374,
     370,   231,   367,   305,   350,   356,   357,   229,   296,   298,
     348,   340,   216,   259,   274,   347,   348,   233,   232,   263,
     208,   228,   233,   352,   340,   233,   352,   233,   259,   233,
     303,   247,   231,   325,   233,   344,   246,   230,   247,     5,
     213,   208,   355,   206,   229,   230,   233,   348,   340,   233,
     352,   233,   284,   259,   284,   352,   233,   212,   213,   247,
     231,   246,   229,   229,   287,   356,   275,   352,   233,   305,
     232,   247,   231,    44,    61,   231,   276,   213,   259,   247,
     286,   208,   229,   233,   208,   229,   292,   293,   247,   292,
     229
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int16 yyr1[] =
{
       0,   235,   236,   237,   237,   238,   238,   239,   240,   240,
     241,   242,   243,   242,   242,   242,   242,   242,   242,   242,
     242,   242,   242,   242,   242,   242,   244,   244,   245,   244,
     244,   244,   244,   244,   244,   244,   244,   244,   244,   244,
     244,   244,   246,   246,   247,   247,   248,   248,   248,   248,
     248,   248,   248,   249,   250,   250,   251,   251,   251,   251,
     251,   251,   251,   251,   251,   252,   253,   254,   255,   256,
     256,   257,   258,   259,   259,   260,   260,   261,   261,   262,
     262,   263,   263,   263,   264,   264,   265,   266,   266,   266,
     267,   267,   268,   268,   268,   269,   269,   270,   271,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   273,
     273,   274,   274,   274,   274,   275,   275,   276,   276,   277,
     277,   277,   278,   278,   279,   280,   280,   281,   282,   282,
     283,   283,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,   284,
     284,   284,   284,   285,   285,   286,   287,   288,   288,   289,
     289,   290,   290,   291,   291,   292,   292,   293,   293,   294,
     295,   295,   296,   296,   297,   297,   297,   298,   298,   299,
     299,   299,   299,   299,   299,   299,   299,   299,   299,   299,
     300,   300,   301,   301,   301,   301,   301,   301,   301,   301,
     301,   302,   302,   303,   303,   304,   305,   305,   305,   305,
     305,   305,   306,   306,   307,   308,   309,   309,   310,   311,
     312,   313,   313,   314,   314,   315,   316,   316,   317,   318,
     318,   319,   319,   320,   320,   321,   321,   321,   322,   322,
     322,   322,   323,   324,   324,   325,   325,   326,   327,   326,
     328,   328,   328,   329,   329,   330,   331,   330,   330,   330,
     332,   333,   332,   332,   334,   334,   335,   336,   337,   337,
     337,   338,   339,   340,   340,   341,   341,   342,   342,   343,
     343,   343,   344,   344,   344,   345,   345,   345,   345,   346,
     346,   346,   347,   347,   348,   348,   349,   349,   349,   349,
     349,   350,   350,   350,   351,   351,   352,   352,   353,   353,
     353,   353,   353,   353,   354,   354,   355,   355,   356,   357,
     357,   358,   358,   359,   359,   359,   359,   359,   359,   360,
     360,   360,   361,   362,   362,   362,   362,   362,   362,   362,
     362,   362,   362,   362,   363,   364,   364,   365,   365,   365,
     366,   366,   367,   367,   368,   369,   370,   370,   371,   371,
     372,   372,   372,   372,   373,   373,   374,   374,   374,   374
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     0,     7,     4,     0,     7,
       4,     0,     0,     6,     2,     2,     2,     3,     2,     3,
       3,     2,     2,     2,     2,     2,     0,     2,     0,     6,
       2,     2,     3,     2,     3,     3,     2,     2,     2,     2,
       2,     2,     0,     2,     0,     1,     1,     2,     2,     1,
       2,     1,     1,     6,     1,     2,     1,     2,     1,     2,
       1,     2,     2,     2,     2,     4,     3,     3,     5,     2,
       2,     3,     4,     0,     1,     1,     3,     1,     3,     3,
       2,     3,     3,     2,     0,     1,     3,     1,     3,     4,
       1,     3,     1,     1,     1,     1,     3,     3,     3,     0,
       4,     1,     4,     1,     1,     1,     1,     1,     4,     4,
       1,     1,     1,     1,     1,     4,     4,     1,     6,     1,
       1,     1,     1,     4,     1,     1,     1,     4,     1,     1,
       1,     4,     4,     1,     1,     4,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     1,     4,     1,     1,
       4,     1,     4,     1,     1,     4,     4,     1,     1,     1,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     4,     1,     1,     1,     4,     4,     1,     1,
       1,     1,     1,     6,     1,     4,     1,     1,     1,     4,
       1,     4,     1,     1,     4,     4,     4,     4,     1,     1,
       4,     4,     4,     1,     1,     4,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     0,     2,     4,     3,     0,
       2,     1,     1,     3,     2,     3,     1,     5,     1,     3,
       0,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     2,     3,     3,     5,
       5,     4,     3,     1,     3,     1,     1,     0,     2,     4,
       3,     2,     2,     0,     2,     2,     1,     3,     2,     1,
       3,     2,     0,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       0,     1,     1,     2,     1,     2,     2,     1,     1,     1,
       1,     2,     3,     1,     2,     4,     1,     1,     2,     1,
       2,     3,     2,     2,     2,     5,     2,     2,     2,     5,
       5,     2,     2,     0,     2,     2,     2,     2,     2,     2,
       3,     2,     3,     5,     5,     0,     2,     2,     2,     2,
       3,     3,     2,     1,     1,     1,     3,     8,     0,    12,
       1,     1,     3,     0,     2,     7,     0,    10,     9,     2,
       2,     0,     6,     2,     2,     2,     2,     5,     1,     1,
       1,     1,     1,     0,     2,     2,     3,     0,     1,     2,
       2,     2,     3,     2,     1,     1,     3,     2,     4,     3,
       2,     1,     3,     2,     0,     1,     3,     2,     1,     3,
       4,     3,     2,     1,     3,     2,     0,     1,     1,     3,
       2,     1,     3,     4,     1,     3,     0,     2,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     1,     1,     1,     1,     1,     2,     1,
       2,     1,     2,     4,     5,     5,    10,     1,     3,     1,
       0,     2,     0,     2,     4,     6,     0,     3,     1,     3,
       4,     1,     1,     1,     1,     3,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* input: gbl_statements m_acf  */
#line 361 "tools/widl/parser.y"
                                                { (yyvsp[-1].stmt_list) = append_parameterized_type_stmts((yyvsp[-1].stmt_list));
						  check_statements((yyvsp[-1].stmt_list), FALSE);
						  check_all_user_types((yyvsp[-1].stmt_list));
						  write_header((yyvsp[-1].stmt_list));
						  write_id_data((yyvsp[-1].stmt_list));
						  write_proxies((yyvsp[-1].stmt_list));
						  write_client((yyvsp[-1].stmt_list));
						  write_server((yyvsp[-1].stmt_list));
						  write_regscript((yyvsp[-1].stmt_list));
						  write_typelib_regscript((yyvsp[-1].stmt_list));
						  write_dlldata((yyvsp[-1].stmt_list));
						  write_local_stubs((yyvsp[-1].stmt_list));
						}
#line 3065 "tools/widl/parser.tab.c"
    break;

  case 5: /* decl_statements: %empty  */
#line 378 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3071 "tools/widl/parser.tab.c"
    break;

  case 6: /* decl_statements: decl_statements tINTERFACE qualified_type '<' parameterized_types '>' ';'  */
#line 380 "tools/widl/parser.y"
                                                { parameterized_type_stmts = append_statement(parameterized_type_stmts, make_statement_parameterized_type((yyvsp[-4].type), (yyvsp[-2].typelist)));
						  (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typelist))));
						}
#line 3079 "tools/widl/parser.tab.c"
    break;

  case 7: /* decl_block: tDECLARE '{' decl_statements '}'  */
#line 385 "tools/widl/parser.y"
                                             { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3085 "tools/widl/parser.tab.c"
    break;

  case 8: /* imp_decl_statements: %empty  */
#line 387 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3091 "tools/widl/parser.tab.c"
    break;

  case 9: /* imp_decl_statements: imp_decl_statements tINTERFACE qualified_type '<' parameterized_types '>' ';'  */
#line 389 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-6].stmt_list), make_statement_reference(type_parameterized_type_specialize_declare((yyvsp[-4].type), (yyvsp[-2].typelist)))); }
#line 3097 "tools/widl/parser.tab.c"
    break;

  case 10: /* imp_decl_block: tDECLARE '{' imp_decl_statements '}'  */
#line 392 "tools/widl/parser.y"
                                                     { (yyval.stmt_list) = (yyvsp[-1].stmt_list); }
#line 3103 "tools/widl/parser.tab.c"
    break;

  case 11: /* gbl_statements: %empty  */
#line 394 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3109 "tools/widl/parser.tab.c"
    break;

  case 12: /* $@1: %empty  */
#line 395 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3115 "tools/widl/parser.tab.c"
    break;

  case 13: /* gbl_statements: gbl_statements namespacedef '{' $@1 gbl_statements '}'  */
#line 396 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3121 "tools/widl/parser.tab.c"
    break;

  case 14: /* gbl_statements: gbl_statements interfacedec  */
#line 397 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3127 "tools/widl/parser.tab.c"
    break;

  case 15: /* gbl_statements: gbl_statements interfacedef  */
#line 398 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3133 "tools/widl/parser.tab.c"
    break;

  case 16: /* gbl_statements: gbl_statements delegatedef  */
#line 399 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3139 "tools/widl/parser.tab.c"
    break;

  case 17: /* gbl_statements: gbl_statements coclass ';'  */
#line 400 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list);
						  reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0);
						}
#line 3147 "tools/widl/parser.tab.c"
    break;

  case 18: /* gbl_statements: gbl_statements coclassdef  */
#line 403 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3155 "tools/widl/parser.tab.c"
    break;

  case 19: /* gbl_statements: gbl_statements apicontract ';'  */
#line 406 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_type_decl((yyvsp[-1].type)));
	                                          reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3162 "tools/widl/parser.tab.c"
    break;

  case 20: /* gbl_statements: gbl_statements runtimeclass ';'  */
#line 408 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3168 "tools/widl/parser.tab.c"
    break;

  case 21: /* gbl_statements: gbl_statements runtimeclass_def  */
#line 409 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3175 "tools/widl/parser.tab.c"
    break;

  case 22: /* gbl_statements: gbl_statements moduledef  */
#line 411 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3181 "tools/widl/parser.tab.c"
    break;

  case 23: /* gbl_statements: gbl_statements librarydef  */
#line 412 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3187 "tools/widl/parser.tab.c"
    break;

  case 24: /* gbl_statements: gbl_statements statement  */
#line 413 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3193 "tools/widl/parser.tab.c"
    break;

  case 25: /* gbl_statements: gbl_statements decl_block  */
#line 414 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3199 "tools/widl/parser.tab.c"
    break;

  case 26: /* imp_statements: %empty  */
#line 417 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3205 "tools/widl/parser.tab.c"
    break;

  case 27: /* imp_statements: imp_statements interfacedec  */
#line 418 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_reference((yyvsp[0].type))); }
#line 3211 "tools/widl/parser.tab.c"
    break;

  case 28: /* $@2: %empty  */
#line 419 "tools/widl/parser.y"
                                          { push_namespace((yyvsp[-1].str)); }
#line 3217 "tools/widl/parser.tab.c"
    break;

  case 29: /* imp_statements: imp_statements namespacedef '{' $@2 imp_statements '}'  */
#line 420 "tools/widl/parser.y"
                                                { pop_namespace((yyvsp[-4].str)); (yyval.stmt_list) = append_statements((yyvsp[-5].stmt_list), (yyvsp[-1].stmt_list)); }
#line 3223 "tools/widl/parser.tab.c"
    break;

  case 30: /* imp_statements: imp_statements interfacedef  */
#line 421 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3229 "tools/widl/parser.tab.c"
    break;

  case 31: /* imp_statements: imp_statements delegatedef  */
#line 422 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type))); }
#line 3235 "tools/widl/parser.tab.c"
    break;

  case 32: /* imp_statements: imp_statements coclass ';'  */
#line 423 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3241 "tools/widl/parser.tab.c"
    break;

  case 33: /* imp_statements: imp_statements coclassdef  */
#line 424 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
						  reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0);
						}
#line 3249 "tools/widl/parser.tab.c"
    break;

  case 34: /* imp_statements: imp_statements apicontract ';'  */
#line 427 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-2].stmt_list), make_statement_type_decl((yyvsp[-1].type)));
	                                          reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3256 "tools/widl/parser.tab.c"
    break;

  case 35: /* imp_statements: imp_statements runtimeclass ';'  */
#line 429 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = (yyvsp[-2].stmt_list); reg_type((yyvsp[-1].type), (yyvsp[-1].type)->name, current_namespace, 0); }
#line 3262 "tools/widl/parser.tab.c"
    break;

  case 36: /* imp_statements: imp_statements runtimeclass_def  */
#line 430 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_type_decl((yyvsp[0].type)));
	                                          reg_type((yyvsp[0].type), (yyvsp[0].type)->name, current_namespace, 0); }
#line 3269 "tools/widl/parser.tab.c"
    break;

  case 37: /* imp_statements: imp_statements moduledef  */
#line 432 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_module((yyvsp[0].type))); }
#line 3275 "tools/widl/parser.tab.c"
    break;

  case 38: /* imp_statements: imp_statements statement  */
#line 433 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3281 "tools/widl/parser.tab.c"
    break;

  case 39: /* imp_statements: imp_statements importlib  */
#line 434 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_importlib((yyvsp[0].str))); }
#line 3287 "tools/widl/parser.tab.c"
    break;

  case 40: /* imp_statements: imp_statements librarydef  */
#line 435 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), make_statement_library((yyvsp[0].typelib))); }
#line 3293 "tools/widl/parser.tab.c"
    break;

  case 41: /* imp_statements: imp_statements imp_decl_block  */
#line 436 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statements((yyvsp[-1].stmt_list), (yyvsp[0].stmt_list)); }
#line 3299 "tools/widl/parser.tab.c"
    break;

  case 42: /* int_statements: %empty  */
#line 439 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = NULL; }
#line 3305 "tools/widl/parser.tab.c"
    break;

  case 43: /* int_statements: int_statements statement  */
#line 440 "tools/widl/parser.y"
                                                { (yyval.stmt_list) = append_statement((yyvsp[-1].stmt_list), (yyvsp[0].statement)); }
#line 3311 "tools/widl/parser.tab.c"
    break;

  case 46: /* statement: cppquote  */
#line 448 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_cppquote((yyvsp[0].str)); }
#line 3317 "tools/widl/parser.tab.c"
    break;

  case 47: /* statement: typedecl ';'  */
#line 449 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_type_decl((yyvsp[-1].type)); }
#line 3323 "tools/widl/parser.tab.c"
    break;

  case 48: /* statement: declaration ';'  */
#line 450 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_declaration((yyvsp[-1].var)); }
#line 3329 "tools/widl/parser.tab.c"
    break;

  case 49: /* statement: import  */
#line 451 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_import((yyvsp[0].str)); }
#line 3335 "tools/widl/parser.tab.c"
    break;

  case 50: /* statement: typedef ';'  */
#line 452 "tools/widl/parser.y"
                                                { (yyval.statement) = (yyvsp[-1].statement); }
#line 3341 "tools/widl/parser.tab.c"
    break;

  case 51: /* statement: aPRAGMA  */
#line 453 "tools/widl/parser.y"
                                                { (yyval.statement) = make_statement_pragma((yyvsp[0].str)); }
#line 3347 "tools/widl/parser.tab.c"
    break;

  case 52: /* statement: pragma_warning  */
#line 454 "tools/widl/parser.y"
                         { (yyval.statement) = NULL; }
#line 3353 "tools/widl/parser.tab.c"
    break;

  case 53: /* pragma_warning: tPRAGMA_WARNING '(' aIDENTIFIER ':' warnings ')'  */
#line 458 "tools/widl/parser.y"
                  {
                      int result;
                      (yyval.statement) = NULL;
                      result = do_warning((yyvsp[-3].str), (yyvsp[-1].warning_list));
                      if(!result)
                          error_loc("expected \"disable\" or \"enable\"\n");
                  }
#line 3365 "tools/widl/parser.tab.c"
    break;

  case 54: /* warnings: aNUM  */
#line 468 "tools/widl/parser.y"
               { (yyval.warning_list) = append_warning(NULL, (yyvsp[0].num)); }
#line 3371 "tools/widl/parser.tab.c"
    break;

  case 55: /* warnings: warnings aNUM  */
#line 469 "tools/widl/parser.y"
                        { (yyval.warning_list) = append_warning((yyvsp[-1].warning_list), (yyvsp[0].num)); }
#line 3377 "tools/widl/parser.tab.c"
    break;

  case 57: /* typedecl: tENUM aIDENTIFIER  */
#line 474 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3383 "tools/widl/parser.tab.c"
    break;

  case 59: /* typedecl: tSTRUCT aIDENTIFIER  */
#line 476 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 3389 "tools/widl/parser.tab.c"
    break;

  case 61: /* typedecl: tUNION aIDENTIFIER  */
#line 478 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 3395 "tools/widl/parser.tab.c"
    break;

  case 62: /* typedecl: attributes enumdef  */
#line 479 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_enum_attrs((yyvsp[-1].attr_list)); }
#line 3401 "tools/widl/parser.tab.c"
    break;

  case 63: /* typedecl: attributes structdef  */
#line 480 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_struct_attrs((yyvsp[-1].attr_list)); }
#line 3407 "tools/widl/parser.tab.c"
    break;

  case 64: /* typedecl: attributes uniondef  */
#line 481 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); (yyval.type)->attrs = check_union_attrs((yyvsp[-1].attr_list)); }
#line 3413 "tools/widl/parser.tab.c"
    break;

  case 65: /* cppquote: tCPPQUOTE '(' aSTRING ')'  */
#line 484 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-1].str); }
#line 3419 "tools/widl/parser.tab.c"
    break;

  case 66: /* import_start: tIMPORT aSTRING ';'  */
#line 486 "tools/widl/parser.y"
                                                { assert(yychar == YYEMPTY);
						  (yyval.import) = xmalloc(sizeof(struct _import_t));
						  (yyval.import)->name = (yyvsp[-1].str);
						  (yyval.import)->import_performed = do_import((yyvsp[-1].str));
						  if (!(yyval.import)->import_performed) yychar = aEOF;
						}
#line 3430 "tools/widl/parser.tab.c"
    break;

  case 67: /* import: import_start imp_statements aEOF  */
#line 494 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].import)->name;
						  if ((yyvsp[-2].import)->import_performed) pop_import();
						  free((yyvsp[-2].import));
						}
#line 3439 "tools/widl/parser.tab.c"
    break;

  case 68: /* importlib: tIMPORTLIB '(' aSTRING ')' semicolon_opt  */
#line 501 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[-2].str); if(!parse_only) add_importlib((yyvsp[-2].str), current_typelib); }
#line 3445 "tools/widl/parser.tab.c"
    break;

  case 69: /* libraryhdr: tLIBRARY aIDENTIFIER  */
#line 504 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3451 "tools/widl/parser.tab.c"
    break;

  case 70: /* libraryhdr: tLIBRARY aKNOWNTYPE  */
#line 505 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 3457 "tools/widl/parser.tab.c"
    break;

  case 71: /* library_start: attributes libraryhdr '{'  */
#line 507 "tools/widl/parser.y"
                                                { (yyval.typelib) = make_library((yyvsp[-1].str), check_library_attrs((yyvsp[-1].str), (yyvsp[-2].attr_list)));
						  if (!parse_only && do_typelib) current_typelib = (yyval.typelib);
						}
#line 3465 "tools/widl/parser.tab.c"
    break;

  case 72: /* librarydef: library_start imp_statements '}' semicolon_opt  */
#line 512 "tools/widl/parser.y"
                                                { (yyval.typelib) = (yyvsp[-3].typelib); (yyval.typelib)->stmts = (yyvsp[-2].stmt_list); }
#line 3471 "tools/widl/parser.tab.c"
    break;

  case 73: /* m_args: %empty  */
#line 515 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 3477 "tools/widl/parser.tab.c"
    break;

  case 75: /* arg_list: arg  */
#line 519 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( NULL, (yyvsp[0].var) ); }
#line 3483 "tools/widl/parser.tab.c"
    break;

  case 76: /* arg_list: arg_list ',' arg  */
#line 520 "tools/widl/parser.y"
                                                { check_arg_attrs((yyvsp[0].var)); (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) ); }
#line 3489 "tools/widl/parser.tab.c"
    break;

  case 78: /* args: arg_list ',' ELLIPSIS  */
#line 524 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), make_var(strdup("...")) ); }
#line 3495 "tools/widl/parser.tab.c"
    break;

  case 79: /* arg: attributes decl_spec m_any_declarator  */
#line 528 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3505 "tools/widl/parser.tab.c"
    break;

  case 80: /* arg: decl_spec m_any_declarator  */
#line 533 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->stgclass != STG_NONE && (yyvsp[-1].declspec)->stgclass != STG_REGISTER)
						    error_loc("invalid storage class for function parameter\n");
						  (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), TRUE);
						  free((yyvsp[-1].declspec)); free((yyvsp[0].declarator));
						}
#line 3515 "tools/widl/parser.tab.c"
    break;

  case 81: /* array: '[' expr ']'  */
#line 540 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr);
						  if (!(yyval.expr)->is_const || (yyval.expr)->cval <= 0)
						      error_loc("array dimension is not a positive integer constant\n");
						}
#line 3524 "tools/widl/parser.tab.c"
    break;

  case 82: /* array: '[' '*' ']'  */
#line 544 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3530 "tools/widl/parser.tab.c"
    break;

  case 83: /* array: '[' ']'  */
#line 545 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 3536 "tools/widl/parser.tab.c"
    break;

  case 84: /* m_attributes: %empty  */
#line 548 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 3542 "tools/widl/parser.tab.c"
    break;

  case 86: /* attributes: '[' attrib_list ']'  */
#line 553 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 3548 "tools/widl/parser.tab.c"
    break;

  case 87: /* attrib_list: attribute  */
#line 556 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( NULL, (yyvsp[0].attr) ); }
#line 3554 "tools/widl/parser.tab.c"
    break;

  case 88: /* attrib_list: attrib_list ',' attribute  */
#line 557 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-2].attr_list), (yyvsp[0].attr) ); }
#line 3560 "tools/widl/parser.tab.c"
    break;

  case 89: /* attrib_list: attrib_list ']' '[' attribute  */
#line 558 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr( (yyvsp[-3].attr_list), (yyvsp[0].attr) ); }
#line 3566 "tools/widl/parser.tab.c"
    break;

  case 90: /* str_list: aSTRING  */
#line 561 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( NULL, (yyvsp[0].str) ); }
#line 3572 "tools/widl/parser.tab.c"
    break;

  case 91: /* str_list: str_list ',' aSTRING  */
#line 562 "tools/widl/parser.y"
                                                { (yyval.str_list) = append_str( (yyvsp[-2].str_list), (yyvsp[0].str) ); }
#line 3578 "tools/widl/parser.tab.c"
    break;

  case 92: /* marshaling_behavior: tAGILE  */
#line 566 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_AGILE; }
#line 3584 "tools/widl/parser.tab.c"
    break;

  case 93: /* marshaling_behavior: tNONE  */
#line 567 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_NONE; }
#line 3590 "tools/widl/parser.tab.c"
    break;

  case 94: /* marshaling_behavior: tSTANDARD  */
#line 568 "tools/widl/parser.y"
                                                { (yyval.num) = MARSHALING_STANDARD; }
#line 3596 "tools/widl/parser.tab.c"
    break;

  case 95: /* contract_ver: aNUM  */
#line 572 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION(0, (yyvsp[0].num)); }
#line 3602 "tools/widl/parser.tab.c"
    break;

  case 96: /* contract_ver: aNUM '.' aNUM  */
#line 573 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), (yyvsp[-2].num)); }
#line 3608 "tools/widl/parser.tab.c"
    break;

  case 97: /* contract_req: decl_spec ',' contract_ver  */
#line 576 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_APICONTRACT)
						      error_loc("type %s is not an apicontract\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num));
						  (yyval.expr) = make_exprt(EXPR_GTREQL, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyval.expr));
						}
#line 3618 "tools/widl/parser.tab.c"
    break;

  case 98: /* static_attr: decl_spec ',' contract_req  */
#line 582 "tools/widl/parser.y"
                                                { if ((yyvsp[-2].declspec)->type->type_type != TYPE_INTERFACE)
						      error_loc("type %s is not an interface\n", (yyvsp[-2].declspec)->type->name);
						  (yyval.expr) = make_exprt(EXPR_MEMBER, declare_var(NULL, (yyvsp[-2].declspec), make_declarator(NULL), 0), (yyvsp[0].expr));
						}
#line 3627 "tools/widl/parser.tab.c"
    break;

  case 99: /* attribute: %empty  */
#line 587 "tools/widl/parser.y"
                                                { (yyval.attr) = NULL; }
#line 3633 "tools/widl/parser.tab.c"
    break;

  case 100: /* attribute: tACTIVATABLE '(' contract_req ')'  */
#line 588 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ACTIVATABLE, (yyvsp[-1].expr)); }
#line 3639 "tools/widl/parser.tab.c"
    break;

  case 101: /* attribute: tAGGREGATABLE  */
#line 589 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AGGREGATABLE); }
#line 3645 "tools/widl/parser.tab.c"
    break;

  case 102: /* attribute: tANNOTATION '(' aSTRING ')'  */
#line 590 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ANNOTATION, (yyvsp[-1].str)); }
#line 3651 "tools/widl/parser.tab.c"
    break;

  case 103: /* attribute: tAPPOBJECT  */
#line 591 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_APPOBJECT); }
#line 3657 "tools/widl/parser.tab.c"
    break;

  case 104: /* attribute: tASYNC  */
#line 592 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ASYNC); }
#line 3663 "tools/widl/parser.tab.c"
    break;

  case 105: /* attribute: tAUTOHANDLE  */
#line 593 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_AUTO_HANDLE); }
#line 3669 "tools/widl/parser.tab.c"
    break;

  case 106: /* attribute: tBINDABLE  */
#line 594 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BINDABLE); }
#line 3675 "tools/widl/parser.tab.c"
    break;

  case 107: /* attribute: tBROADCAST  */
#line 595 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_BROADCAST); }
#line 3681 "tools/widl/parser.tab.c"
    break;

  case 108: /* attribute: tCALLAS '(' ident ')'  */
#line 596 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CALLAS, (yyvsp[-1].var)); }
#line 3687 "tools/widl/parser.tab.c"
    break;

  case 109: /* attribute: tCASE '(' expr_list_int_const ')'  */
#line 597 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CASE, (yyvsp[-1].expr_list)); }
#line 3693 "tools/widl/parser.tab.c"
    break;

  case 110: /* attribute: tCODE  */
#line 598 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CODE); }
#line 3699 "tools/widl/parser.tab.c"
    break;

  case 111: /* attribute: tCOMMSTATUS  */
#line 599 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_COMMSTATUS); }
#line 3705 "tools/widl/parser.tab.c"
    break;

  case 112: /* attribute: tCONTEXTHANDLE  */
#line 600 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); }
#line 3711 "tools/widl/parser.tab.c"
    break;

  case 113: /* attribute: tCONTEXTHANDLENOSERIALIZE  */
#line 601 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_DONT_SERIALIZE */ }
#line 3717 "tools/widl/parser.tab.c"
    break;

  case 114: /* attribute: tCONTEXTHANDLESERIALIZE  */
#line 602 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTEXTHANDLE, 0); /* RPC_CONTEXT_HANDLE_SERIALIZE */ }
#line 3723 "tools/widl/parser.tab.c"
    break;

  case 115: /* attribute: tCONTRACT '(' contract_req ')'  */
#line 603 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_CONTRACT, (yyvsp[-1].expr)); }
#line 3729 "tools/widl/parser.tab.c"
    break;

  case 116: /* attribute: tCONTRACTVERSION '(' contract_ver ')'  */
#line 604 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_CONTRACTVERSION, (yyvsp[-1].num)); }
#line 3735 "tools/widl/parser.tab.c"
    break;

  case 117: /* attribute: tCONTROL  */
#line 605 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_CONTROL); }
#line 3741 "tools/widl/parser.tab.c"
    break;

  case 118: /* attribute: tCUSTOM '(' uuid_string ',' expr_const ')'  */
#line 606 "tools/widl/parser.y"
                                                     { (yyval.attr) = make_custom_attr((yyvsp[-3].uuid), (yyvsp[-1].expr)); }
#line 3747 "tools/widl/parser.tab.c"
    break;

  case 119: /* attribute: tDECODE  */
#line 607 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 3753 "tools/widl/parser.tab.c"
    break;

  case 120: /* attribute: tDEFAULT  */
#line 608 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULT); }
#line 3759 "tools/widl/parser.tab.c"
    break;

  case 121: /* attribute: tDEFAULTBIND  */
#line 609 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTBIND); }
#line 3765 "tools/widl/parser.tab.c"
    break;

  case 122: /* attribute: tDEFAULTCOLLELEM  */
#line 610 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTCOLLELEM); }
#line 3771 "tools/widl/parser.tab.c"
    break;

  case 123: /* attribute: tDEFAULTVALUE '(' expr_const ')'  */
#line 611 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DEFAULTVALUE, (yyvsp[-1].expr)); }
#line 3777 "tools/widl/parser.tab.c"
    break;

  case 124: /* attribute: tDEFAULTVTABLE  */
#line 612 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DEFAULTVTABLE); }
#line 3783 "tools/widl/parser.tab.c"
    break;

  case 125: /* attribute: tDISABLECONSISTENCYCHECK  */
#line 613 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISABLECONSISTENCYCHECK); }
#line 3789 "tools/widl/parser.tab.c"
    break;

  case 126: /* attribute: tDISPLAYBIND  */
#line 614 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DISPLAYBIND); }
#line 3795 "tools/widl/parser.tab.c"
    break;

  case 127: /* attribute: tDLLNAME '(' aSTRING ')'  */
#line 615 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_DLLNAME, (yyvsp[-1].str)); }
#line 3801 "tools/widl/parser.tab.c"
    break;

  case 128: /* attribute: tDUAL  */
#line 616 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DUAL); }
#line 3807 "tools/widl/parser.tab.c"
    break;

  case 129: /* attribute: tENABLEALLOCATE  */
#line 617 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENABLEALLOCATE); }
#line 3813 "tools/widl/parser.tab.c"
    break;

  case 130: /* attribute: tENCODE  */
#line 618 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 3819 "tools/widl/parser.tab.c"
    break;

  case 131: /* attribute: tENDPOINT '(' str_list ')'  */
#line 619 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENDPOINT, (yyvsp[-1].str_list)); }
#line 3825 "tools/widl/parser.tab.c"
    break;

  case 132: /* attribute: tENTRY '(' expr_const ')'  */
#line 620 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ENTRY, (yyvsp[-1].expr)); }
#line 3831 "tools/widl/parser.tab.c"
    break;

  case 133: /* attribute: tEVENTADD  */
#line 621 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTADD); }
#line 3837 "tools/widl/parser.tab.c"
    break;

  case 134: /* attribute: tEVENTREMOVE  */
#line 622 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EVENTREMOVE); }
#line 3843 "tools/widl/parser.tab.c"
    break;

  case 135: /* attribute: tEXCLUSIVETO '(' decl_spec ')'  */
#line 623 "tools/widl/parser.y"
                                                { if ((yyvsp[-1].declspec)->type->type_type != TYPE_RUNTIMECLASS)
						      error_loc("type %s is not a runtimeclass\n", (yyvsp[-1].declspec)->type->name);
						  (yyval.attr) = make_attrp(ATTR_EXCLUSIVETO, (yyvsp[-1].declspec)->type); }
#line 3851 "tools/widl/parser.tab.c"
    break;

  case 136: /* attribute: tEXPLICITHANDLE  */
#line 626 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 3857 "tools/widl/parser.tab.c"
    break;

  case 137: /* attribute: tFAULTSTATUS  */
#line 627 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FAULTSTATUS); }
#line 3863 "tools/widl/parser.tab.c"
    break;

  case 138: /* attribute: tFLAGS  */
#line 628 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FLAGS); }
#line 3869 "tools/widl/parser.tab.c"
    break;

  case 139: /* attribute: tFORCEALLOCATE  */
#line 629 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_FORCEALLOCATE); }
#line 3875 "tools/widl/parser.tab.c"
    break;

  case 140: /* attribute: tHANDLE  */
#line 630 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HANDLE); }
#line 3881 "tools/widl/parser.tab.c"
    break;

  case 141: /* attribute: tHELPCONTEXT '(' expr_int_const ')'  */
#line 631 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPCONTEXT, (yyvsp[-1].expr)); }
#line 3887 "tools/widl/parser.tab.c"
    break;

  case 142: /* attribute: tHELPFILE '(' aSTRING ')'  */
#line 632 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPFILE, (yyvsp[-1].str)); }
#line 3893 "tools/widl/parser.tab.c"
    break;

  case 143: /* attribute: tHELPSTRING '(' aSTRING ')'  */
#line 633 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRING, (yyvsp[-1].str)); }
#line 3899 "tools/widl/parser.tab.c"
    break;

  case 144: /* attribute: tHELPSTRINGCONTEXT '(' expr_int_const ')'  */
#line 634 "tools/widl/parser.y"
                                                        { (yyval.attr) = make_attrp(ATTR_HELPSTRINGCONTEXT, (yyvsp[-1].expr)); }
#line 3905 "tools/widl/parser.tab.c"
    break;

  case 145: /* attribute: tHELPSTRINGDLL '(' aSTRING ')'  */
#line 635 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_HELPSTRINGDLL, (yyvsp[-1].str)); }
#line 3911 "tools/widl/parser.tab.c"
    break;

  case 146: /* attribute: tHIDDEN  */
#line 636 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_HIDDEN); }
#line 3917 "tools/widl/parser.tab.c"
    break;

  case 147: /* attribute: tID '(' expr_int_const ')'  */
#line 637 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ID, (yyvsp[-1].expr)); }
#line 3923 "tools/widl/parser.tab.c"
    break;

  case 148: /* attribute: tIDEMPOTENT  */
#line 638 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IDEMPOTENT); }
#line 3929 "tools/widl/parser.tab.c"
    break;

  case 149: /* attribute: tIGNORE  */
#line 639 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IGNORE); }
#line 3935 "tools/widl/parser.tab.c"
    break;

  case 150: /* attribute: tIIDIS '(' expr ')'  */
#line 640 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IIDIS, (yyvsp[-1].expr)); }
#line 3941 "tools/widl/parser.tab.c"
    break;

  case 151: /* attribute: tIMMEDIATEBIND  */
#line 641 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IMMEDIATEBIND); }
#line 3947 "tools/widl/parser.tab.c"
    break;

  case 152: /* attribute: tIMPLICITHANDLE '(' arg ')'  */
#line 642 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_IMPLICIT_HANDLE, (yyvsp[-1].var)); }
#line 3953 "tools/widl/parser.tab.c"
    break;

  case 153: /* attribute: tIN  */
#line 643 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_IN); }
#line 3959 "tools/widl/parser.tab.c"
    break;

  case 154: /* attribute: tINPUTSYNC  */
#line 644 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_INPUTSYNC); }
#line 3965 "tools/widl/parser.tab.c"
    break;

  case 155: /* attribute: tLENGTHIS '(' m_exprs ')'  */
#line 645 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LENGTHIS, (yyvsp[-1].expr_list)); }
#line 3971 "tools/widl/parser.tab.c"
    break;

  case 156: /* attribute: tLCID '(' expr_int_const ')'  */
#line 646 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_LIBLCID, (yyvsp[-1].expr)); }
#line 3977 "tools/widl/parser.tab.c"
    break;

  case 157: /* attribute: tLCID  */
#line 647 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARAMLCID); }
#line 3983 "tools/widl/parser.tab.c"
    break;

  case 158: /* attribute: tLICENSED  */
#line 648 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LICENSED); }
#line 3989 "tools/widl/parser.tab.c"
    break;

  case 159: /* attribute: tLOCAL  */
#line 649 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_LOCAL); }
#line 3995 "tools/widl/parser.tab.c"
    break;

  case 160: /* attribute: tMARSHALINGBEHAVIOR '(' marshaling_behavior ')'  */
#line 651 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_MARSHALING_BEHAVIOR, (yyvsp[-1].num)); }
#line 4001 "tools/widl/parser.tab.c"
    break;

  case 161: /* attribute: tMAYBE  */
#line 652 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MAYBE); }
#line 4007 "tools/widl/parser.tab.c"
    break;

  case 162: /* attribute: tMESSAGE  */
#line 653 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_MESSAGE); }
#line 4013 "tools/widl/parser.tab.c"
    break;

  case 163: /* attribute: tNOCODE  */
#line 654 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOCODE); }
#line 4019 "tools/widl/parser.tab.c"
    break;

  case 164: /* attribute: tNONBROWSABLE  */
#line 655 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONBROWSABLE); }
#line 4025 "tools/widl/parser.tab.c"
    break;

  case 165: /* attribute: tNONCREATABLE  */
#line 656 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONCREATABLE); }
#line 4031 "tools/widl/parser.tab.c"
    break;

  case 166: /* attribute: tNONEXTENSIBLE  */
#line 657 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NONEXTENSIBLE); }
#line 4037 "tools/widl/parser.tab.c"
    break;

  case 167: /* attribute: tNOTIFY  */
#line 658 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFY); }
#line 4043 "tools/widl/parser.tab.c"
    break;

  case 168: /* attribute: tNOTIFYFLAG  */
#line 659 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_NOTIFYFLAG); }
#line 4049 "tools/widl/parser.tab.c"
    break;

  case 169: /* attribute: tOBJECT  */
#line 660 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OBJECT); }
#line 4055 "tools/widl/parser.tab.c"
    break;

  case 170: /* attribute: tODL  */
#line 661 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ODL); }
#line 4061 "tools/widl/parser.tab.c"
    break;

  case 171: /* attribute: tOLEAUTOMATION  */
#line 662 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OLEAUTOMATION); }
#line 4067 "tools/widl/parser.tab.c"
    break;

  case 172: /* attribute: tOPTIMIZE '(' aSTRING ')'  */
#line 663 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_OPTIMIZE, (yyvsp[-1].str)); }
#line 4073 "tools/widl/parser.tab.c"
    break;

  case 173: /* attribute: tOPTIONAL  */
#line 664 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OPTIONAL); }
#line 4079 "tools/widl/parser.tab.c"
    break;

  case 174: /* attribute: tOUT  */
#line 665 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_OUT); }
#line 4085 "tools/widl/parser.tab.c"
    break;

  case 175: /* attribute: tPARTIALIGNORE  */
#line 666 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PARTIALIGNORE); }
#line 4091 "tools/widl/parser.tab.c"
    break;

  case 176: /* attribute: tPOINTERDEFAULT '(' pointer_type ')'  */
#line 667 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERDEFAULT, (yyvsp[-1].num)); }
#line 4097 "tools/widl/parser.tab.c"
    break;

  case 177: /* attribute: tPROGID '(' aSTRING ')'  */
#line 668 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_PROGID, (yyvsp[-1].str)); }
#line 4103 "tools/widl/parser.tab.c"
    break;

  case 178: /* attribute: tPROPGET  */
#line 669 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPGET); }
#line 4109 "tools/widl/parser.tab.c"
    break;

  case 179: /* attribute: tPROPPUT  */
#line 670 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUT); }
#line 4115 "tools/widl/parser.tab.c"
    break;

  case 180: /* attribute: tPROPPUTREF  */
#line 671 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROPPUTREF); }
#line 4121 "tools/widl/parser.tab.c"
    break;

  case 181: /* attribute: tPROXY  */
#line 672 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PROXY); }
#line 4127 "tools/widl/parser.tab.c"
    break;

  case 182: /* attribute: tPUBLIC  */
#line 673 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_PUBLIC); }
#line 4133 "tools/widl/parser.tab.c"
    break;

  case 183: /* attribute: tRANGE '(' expr_int_const ',' expr_int_const ')'  */
#line 675 "tools/widl/parser.y"
                                                { expr_list_t *list = append_expr( NULL, (yyvsp[-3].expr) );
						  list = append_expr( list, (yyvsp[-1].expr) );
						  (yyval.attr) = make_attrp(ATTR_RANGE, list); }
#line 4141 "tools/widl/parser.tab.c"
    break;

  case 184: /* attribute: tREADONLY  */
#line 678 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_READONLY); }
#line 4147 "tools/widl/parser.tab.c"
    break;

  case 185: /* attribute: tREPRESENTAS '(' type ')'  */
#line 679 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_REPRESENTAS, (yyvsp[-1].type)); }
#line 4153 "tools/widl/parser.tab.c"
    break;

  case 186: /* attribute: tREQUESTEDIT  */
#line 680 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_REQUESTEDIT); }
#line 4159 "tools/widl/parser.tab.c"
    break;

  case 187: /* attribute: tRESTRICTED  */
#line 681 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RESTRICTED); }
#line 4165 "tools/widl/parser.tab.c"
    break;

  case 188: /* attribute: tRETVAL  */
#line 682 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_RETVAL); }
#line 4171 "tools/widl/parser.tab.c"
    break;

  case 189: /* attribute: tSIZEIS '(' m_exprs ')'  */
#line 683 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SIZEIS, (yyvsp[-1].expr_list)); }
#line 4177 "tools/widl/parser.tab.c"
    break;

  case 190: /* attribute: tSOURCE  */
#line 684 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_SOURCE); }
#line 4183 "tools/widl/parser.tab.c"
    break;

  case 191: /* attribute: tSTATIC '(' static_attr ')'  */
#line 685 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_STATIC, (yyvsp[-1].expr)); }
#line 4189 "tools/widl/parser.tab.c"
    break;

  case 192: /* attribute: tSTRICTCONTEXTHANDLE  */
#line 686 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRICTCONTEXTHANDLE); }
#line 4195 "tools/widl/parser.tab.c"
    break;

  case 193: /* attribute: tSTRING  */
#line 687 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_STRING); }
#line 4201 "tools/widl/parser.tab.c"
    break;

  case 194: /* attribute: tSWITCHIS '(' expr ')'  */
#line 688 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHIS, (yyvsp[-1].expr)); }
#line 4207 "tools/widl/parser.tab.c"
    break;

  case 195: /* attribute: tSWITCHTYPE '(' type ')'  */
#line 689 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_SWITCHTYPE, (yyvsp[-1].type)); }
#line 4213 "tools/widl/parser.tab.c"
    break;

  case 196: /* attribute: tTRANSMITAS '(' type ')'  */
#line 690 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_TRANSMITAS, (yyvsp[-1].type)); }
#line 4219 "tools/widl/parser.tab.c"
    break;

  case 197: /* attribute: tTHREADING '(' threading_type ')'  */
#line 691 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_THREADING, (yyvsp[-1].num)); }
#line 4225 "tools/widl/parser.tab.c"
    break;

  case 198: /* attribute: tUIDEFAULT  */
#line 692 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_UIDEFAULT); }
#line 4231 "tools/widl/parser.tab.c"
    break;

  case 199: /* attribute: tUSESGETLASTERROR  */
#line 693 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_USESGETLASTERROR); }
#line 4237 "tools/widl/parser.tab.c"
    break;

  case 200: /* attribute: tUSERMARSHAL '(' type ')'  */
#line 694 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_USERMARSHAL, (yyvsp[-1].type)); }
#line 4243 "tools/widl/parser.tab.c"
    break;

  case 201: /* attribute: tUUID '(' uuid_string ')'  */
#line 695 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_UUID, (yyvsp[-1].uuid)); }
#line 4249 "tools/widl/parser.tab.c"
    break;

  case 202: /* attribute: tASYNCUUID '(' uuid_string ')'  */
#line 696 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_ASYNCUUID, (yyvsp[-1].uuid)); }
#line 4255 "tools/widl/parser.tab.c"
    break;

  case 203: /* attribute: tV1ENUM  */
#line 697 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_V1ENUM); }
#line 4261 "tools/widl/parser.tab.c"
    break;

  case 204: /* attribute: tVARARG  */
#line 698 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_VARARG); }
#line 4267 "tools/widl/parser.tab.c"
    break;

  case 205: /* attribute: tVERSION '(' version ')'  */
#line 699 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_VERSION, (yyvsp[-1].num)); }
#line 4273 "tools/widl/parser.tab.c"
    break;

  case 206: /* attribute: tVIPROGID '(' aSTRING ')'  */
#line 700 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_VIPROGID, (yyvsp[-1].str)); }
#line 4279 "tools/widl/parser.tab.c"
    break;

  case 207: /* attribute: tWIREMARSHAL '(' type ')'  */
#line 701 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrp(ATTR_WIREMARSHAL, (yyvsp[-1].type)); }
#line 4285 "tools/widl/parser.tab.c"
    break;

  case 208: /* attribute: pointer_type  */
#line 702 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_POINTERTYPE, (yyvsp[0].num)); }
#line 4291 "tools/widl/parser.tab.c"
    break;

  case 210: /* uuid_string: aSTRING  */
#line 707 "tools/widl/parser.y"
                                                { if (!is_valid_uuid((yyvsp[0].str)))
						    error_loc("invalid UUID: %s\n", (yyvsp[0].str));
						  (yyval.uuid) = parse_uuid((yyvsp[0].str)); }
#line 4299 "tools/widl/parser.tab.c"
    break;

  case 211: /* callconv: tCDECL  */
#line 712 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__cdecl"); }
#line 4305 "tools/widl/parser.tab.c"
    break;

  case 212: /* callconv: tFASTCALL  */
#line 713 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__fastcall"); }
#line 4311 "tools/widl/parser.tab.c"
    break;

  case 213: /* callconv: tPASCAL  */
#line 714 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__pascal"); }
#line 4317 "tools/widl/parser.tab.c"
    break;

  case 214: /* callconv: tSTDCALL  */
#line 715 "tools/widl/parser.y"
                                                { (yyval.str) = xstrdup("__stdcall"); }
#line 4323 "tools/widl/parser.tab.c"
    break;

  case 215: /* cases: %empty  */
#line 718 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4329 "tools/widl/parser.tab.c"
    break;

  case 216: /* cases: cases case  */
#line 719 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4335 "tools/widl/parser.tab.c"
    break;

  case 217: /* case: tCASE expr_int_const ':' union_field  */
#line 722 "tools/widl/parser.y"
                                                { attr_t *a = make_attrp(ATTR_CASE, append_expr( NULL, (yyvsp[-2].expr) ));
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4344 "tools/widl/parser.tab.c"
    break;

  case 218: /* case: tDEFAULT ':' union_field  */
#line 726 "tools/widl/parser.y"
                                                { attr_t *a = make_attr(ATTR_DEFAULT);
						  (yyval.var) = (yyvsp[0].var); if (!(yyval.var)) (yyval.var) = make_var(NULL);
						  (yyval.var)->attrs = append_attr( (yyval.var)->attrs, a );
						}
#line 4353 "tools/widl/parser.tab.c"
    break;

  case 219: /* enums: %empty  */
#line 732 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4359 "tools/widl/parser.tab.c"
    break;

  case 220: /* enums: enum_list ','  */
#line 733 "tools/widl/parser.y"
                                                { (yyval.var_list) = (yyvsp[-1].var_list); }
#line 4365 "tools/widl/parser.tab.c"
    break;

  case 222: /* enum_list: enum  */
#line 737 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
						    (yyvsp[0].var)->eval = make_exprl(EXPR_NUM, 0 /* default for first enum entry */);
                                                  (yyval.var_list) = append_var( NULL, (yyvsp[0].var) );
						}
#line 4374 "tools/widl/parser.tab.c"
    break;

  case 223: /* enum_list: enum_list ',' enum  */
#line 741 "tools/widl/parser.y"
                                                { if (!(yyvsp[0].var)->eval)
                                                  {
                                                    var_t *last = LIST_ENTRY( list_tail((yyval.var_list)), var_t, entry );
                                                    enum expr_type type = EXPR_NUM;
                                                    if (last->eval->type == EXPR_HEXNUM) type = EXPR_HEXNUM;
                                                    if (last->eval->cval + 1 < 0) type = EXPR_HEXNUM;
                                                    (yyvsp[0].var)->eval = make_exprl(type, last->eval->cval + 1);
                                                  }
                                                  (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[0].var) );
						}
#line 4389 "tools/widl/parser.tab.c"
    break;

  case 224: /* enum_member: m_attributes ident  */
#line 753 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  (yyval.var)->attrs = check_enum_member_attrs((yyvsp[-1].attr_list));
						}
#line 4397 "tools/widl/parser.tab.c"
    break;

  case 225: /* enum: enum_member '=' expr_int_const  */
#line 758 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[-2].var));
						  (yyval.var)->eval = (yyvsp[0].expr);
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4406 "tools/widl/parser.tab.c"
    break;

  case 226: /* enum: enum_member  */
#line 762 "tools/widl/parser.y"
                                                { (yyval.var) = reg_const((yyvsp[0].var));
                                                  (yyval.var)->declspec.type = type_new_int(TYPE_BASIC_INT, 0);
						}
#line 4414 "tools/widl/parser.tab.c"
    break;

  case 227: /* enumdef: tENUM t_ident '{' enums '}'  */
#line 767 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 4420 "tools/widl/parser.tab.c"
    break;

  case 228: /* m_exprs: m_expr  */
#line 770 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4426 "tools/widl/parser.tab.c"
    break;

  case 229: /* m_exprs: m_exprs ',' m_expr  */
#line 771 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4432 "tools/widl/parser.tab.c"
    break;

  case 230: /* m_expr: %empty  */
#line 774 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr(EXPR_VOID); }
#line 4438 "tools/widl/parser.tab.c"
    break;

  case 232: /* expr: aNUM  */
#line 778 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, (yyvsp[0].num)); }
#line 4444 "tools/widl/parser.tab.c"
    break;

  case 233: /* expr: aHEXNUM  */
#line 779 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_HEXNUM, (yyvsp[0].num)); }
#line 4450 "tools/widl/parser.tab.c"
    break;

  case 234: /* expr: aDOUBLE  */
#line 780 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprd(EXPR_DOUBLE, (yyvsp[0].dbl)); }
#line 4456 "tools/widl/parser.tab.c"
    break;

  case 235: /* expr: tFALSE  */
#line 781 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 0); }
#line 4462 "tools/widl/parser.tab.c"
    break;

  case 236: /* expr: tNULL  */
#line 782 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_NUM, 0); }
#line 4468 "tools/widl/parser.tab.c"
    break;

  case 237: /* expr: tTRUE  */
#line 783 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprl(EXPR_TRUEFALSE, 1); }
#line 4474 "tools/widl/parser.tab.c"
    break;

  case 238: /* expr: aSTRING  */
#line 784 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_STRLIT, (yyvsp[0].str)); }
#line 4480 "tools/widl/parser.tab.c"
    break;

  case 239: /* expr: aWSTRING  */
#line 785 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_WSTRLIT, (yyvsp[0].str)); }
#line 4486 "tools/widl/parser.tab.c"
    break;

  case 240: /* expr: aSQSTRING  */
#line 786 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_CHARCONST, (yyvsp[0].str)); }
#line 4492 "tools/widl/parser.tab.c"
    break;

  case 241: /* expr: aIDENTIFIER  */
#line 787 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str)); }
#line 4498 "tools/widl/parser.tab.c"
    break;

  case 242: /* expr: expr '?' expr ':' expr  */
#line 788 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr3(EXPR_COND, (yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4504 "tools/widl/parser.tab.c"
    break;

  case 243: /* expr: expr LOGICALOR expr  */
#line 789 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4510 "tools/widl/parser.tab.c"
    break;

  case 244: /* expr: expr LOGICALAND expr  */
#line 790 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LOGAND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4516 "tools/widl/parser.tab.c"
    break;

  case 245: /* expr: expr '|' expr  */
#line 791 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_OR , (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4522 "tools/widl/parser.tab.c"
    break;

  case 246: /* expr: expr '^' expr  */
#line 792 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_XOR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4528 "tools/widl/parser.tab.c"
    break;

  case 247: /* expr: expr '&' expr  */
#line 793 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_AND, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4534 "tools/widl/parser.tab.c"
    break;

  case 248: /* expr: expr EQUALITY expr  */
#line 794 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_EQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4540 "tools/widl/parser.tab.c"
    break;

  case 249: /* expr: expr INEQUALITY expr  */
#line 795 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_INEQUALITY, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4546 "tools/widl/parser.tab.c"
    break;

  case 250: /* expr: expr '>' expr  */
#line 796 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4552 "tools/widl/parser.tab.c"
    break;

  case 251: /* expr: expr '<' expr  */
#line 797 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESS, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4558 "tools/widl/parser.tab.c"
    break;

  case 252: /* expr: expr GREATEREQUAL expr  */
#line 798 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_GTREQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4564 "tools/widl/parser.tab.c"
    break;

  case 253: /* expr: expr LESSEQUAL expr  */
#line 799 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_LESSEQL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4570 "tools/widl/parser.tab.c"
    break;

  case 254: /* expr: expr SHL expr  */
#line 800 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4576 "tools/widl/parser.tab.c"
    break;

  case 255: /* expr: expr SHR expr  */
#line 801 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SHR, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4582 "tools/widl/parser.tab.c"
    break;

  case 256: /* expr: expr '+' expr  */
#line 802 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ADD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4588 "tools/widl/parser.tab.c"
    break;

  case 257: /* expr: expr '-' expr  */
#line 803 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_SUB, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4594 "tools/widl/parser.tab.c"
    break;

  case 258: /* expr: expr '%' expr  */
#line 804 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MOD, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4600 "tools/widl/parser.tab.c"
    break;

  case 259: /* expr: expr '*' expr  */
#line 805 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MUL, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4606 "tools/widl/parser.tab.c"
    break;

  case 260: /* expr: expr '/' expr  */
#line 806 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_DIV, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 4612 "tools/widl/parser.tab.c"
    break;

  case 261: /* expr: '!' expr  */
#line 807 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_LOGNOT, (yyvsp[0].expr)); }
#line 4618 "tools/widl/parser.tab.c"
    break;

  case 262: /* expr: '~' expr  */
#line 808 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NOT, (yyvsp[0].expr)); }
#line 4624 "tools/widl/parser.tab.c"
    break;

  case 263: /* expr: '+' expr  */
#line 809 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_POS, (yyvsp[0].expr)); }
#line 4630 "tools/widl/parser.tab.c"
    break;

  case 264: /* expr: '-' expr  */
#line 810 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_NEG, (yyvsp[0].expr)); }
#line 4636 "tools/widl/parser.tab.c"
    break;

  case 265: /* expr: '&' expr  */
#line 811 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_ADDRESSOF, (yyvsp[0].expr)); }
#line 4642 "tools/widl/parser.tab.c"
    break;

  case 266: /* expr: '*' expr  */
#line 812 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr1(EXPR_PPTR, (yyvsp[0].expr)); }
#line 4648 "tools/widl/parser.tab.c"
    break;

  case 267: /* expr: expr MEMBERPTR aIDENTIFIER  */
#line 813 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, make_expr1(EXPR_PPTR, (yyvsp[-2].expr)), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4654 "tools/widl/parser.tab.c"
    break;

  case 268: /* expr: expr '.' aIDENTIFIER  */
#line 814 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_MEMBER, (yyvsp[-2].expr), make_exprs(EXPR_IDENTIFIER, (yyvsp[0].str))); }
#line 4660 "tools/widl/parser.tab.c"
    break;

  case 269: /* expr: '(' decl_spec m_abstract_declarator ')' expr  */
#line 816 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_CAST, declare_var(NULL, (yyvsp[-3].declspec), (yyvsp[-2].declarator), 0), (yyvsp[0].expr)); free((yyvsp[-3].declspec)); free((yyvsp[-2].declarator)); }
#line 4666 "tools/widl/parser.tab.c"
    break;

  case 270: /* expr: tSIZEOF '(' decl_spec m_abstract_declarator ')'  */
#line 818 "tools/widl/parser.y"
                                                { (yyval.expr) = make_exprt(EXPR_SIZEOF, declare_var(NULL, (yyvsp[-2].declspec), (yyvsp[-1].declarator), 0), NULL); free((yyvsp[-2].declspec)); free((yyvsp[-1].declarator)); }
#line 4672 "tools/widl/parser.tab.c"
    break;

  case 271: /* expr: expr '[' expr ']'  */
#line 819 "tools/widl/parser.y"
                                                { (yyval.expr) = make_expr2(EXPR_ARRAY, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 4678 "tools/widl/parser.tab.c"
    break;

  case 272: /* expr: '(' expr ')'  */
#line 820 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[-1].expr); }
#line 4684 "tools/widl/parser.tab.c"
    break;

  case 273: /* expr_list_int_const: expr_int_const  */
#line 823 "tools/widl/parser.y"
                                                { (yyval.expr_list) = append_expr( NULL, (yyvsp[0].expr) ); }
#line 4690 "tools/widl/parser.tab.c"
    break;

  case 274: /* expr_list_int_const: expr_list_int_const ',' expr_int_const  */
#line 824 "tools/widl/parser.y"
                                                        { (yyval.expr_list) = append_expr( (yyvsp[-2].expr_list), (yyvsp[0].expr) ); }
#line 4696 "tools/widl/parser.tab.c"
    break;

  case 275: /* expr_int_const: expr  */
#line 827 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const)
						      error_loc("expression is not an integer constant\n");
						}
#line 4705 "tools/widl/parser.tab.c"
    break;

  case 276: /* expr_const: expr  */
#line 833 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr);
						  if (!(yyval.expr)->is_const && (yyval.expr)->type != EXPR_STRLIT && (yyval.expr)->type != EXPR_WSTRLIT)
						      error_loc("expression is not constant\n");
						}
#line 4714 "tools/widl/parser.tab.c"
    break;

  case 277: /* fields: %empty  */
#line 839 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4720 "tools/widl/parser.tab.c"
    break;

  case 278: /* fields: fields field  */
#line 840 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var_list((yyvsp[-1].var_list), (yyvsp[0].var_list)); }
#line 4726 "tools/widl/parser.tab.c"
    break;

  case 279: /* field: m_attributes decl_spec struct_declarator_list ';'  */
#line 844 "tools/widl/parser.y"
                                                { const char *first = LIST_ENTRY(list_head((yyvsp[-1].declarator_list)), declarator_t, entry)->var->name;
						  check_field_attrs(first, (yyvsp[-3].attr_list));
						  (yyval.var_list) = set_var_types((yyvsp[-3].attr_list), (yyvsp[-2].declspec), (yyvsp[-1].declarator_list));
						}
#line 4735 "tools/widl/parser.tab.c"
    break;

  case 280: /* field: m_attributes uniondef ';'  */
#line 848 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[-1].type); v->attrs = (yyvsp[-2].attr_list);
						  (yyval.var_list) = append_var(NULL, v);
						}
#line 4744 "tools/widl/parser.tab.c"
    break;

  case 281: /* ne_union_field: s_field ';'  */
#line 855 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4750 "tools/widl/parser.tab.c"
    break;

  case 282: /* ne_union_field: attributes ';'  */
#line 856 "tools/widl/parser.y"
                                                { (yyval.var) = make_var(NULL); (yyval.var)->attrs = (yyvsp[-1].attr_list); }
#line 4756 "tools/widl/parser.tab.c"
    break;

  case 283: /* ne_union_fields: %empty  */
#line 859 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 4762 "tools/widl/parser.tab.c"
    break;

  case 284: /* ne_union_fields: ne_union_fields ne_union_field  */
#line 860 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-1].var_list), (yyvsp[0].var) ); }
#line 4768 "tools/widl/parser.tab.c"
    break;

  case 285: /* union_field: s_field ';'  */
#line 864 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[-1].var); }
#line 4774 "tools/widl/parser.tab.c"
    break;

  case 286: /* union_field: ';'  */
#line 865 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4780 "tools/widl/parser.tab.c"
    break;

  case 287: /* s_field: m_attributes decl_spec declarator  */
#line 868 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(check_field_attrs((yyvsp[0].declarator)->var->name, (yyvsp[-2].attr_list)),
						                (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4789 "tools/widl/parser.tab.c"
    break;

  case 288: /* s_field: m_attributes structdef  */
#line 872 "tools/widl/parser.y"
                                                { var_t *v = make_var(NULL);
						  v->declspec.type = (yyvsp[0].type); v->attrs = (yyvsp[-1].attr_list);
						  (yyval.var) = v;
						}
#line 4798 "tools/widl/parser.tab.c"
    break;

  case 289: /* funcdef: declaration  */
#line 878 "tools/widl/parser.y"
                                                { (yyval.var) = (yyvsp[0].var);
						  if (type_get_type((yyval.var)->declspec.type) != TYPE_FUNCTION)
						    error_loc("only methods may be declared inside the methods section of a dispinterface\n");
						  check_function_attrs((yyval.var)->name, (yyval.var)->attrs);
						}
#line 4808 "tools/widl/parser.tab.c"
    break;

  case 290: /* declaration: attributes decl_spec init_declarator  */
#line 887 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var((yyvsp[-2].attr_list), (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4816 "tools/widl/parser.tab.c"
    break;

  case 291: /* declaration: decl_spec init_declarator  */
#line 890 "tools/widl/parser.y"
                                                { (yyval.var) = declare_var(NULL, (yyvsp[-1].declspec), (yyvsp[0].declarator), FALSE);
						  free((yyvsp[0].declarator));
						}
#line 4824 "tools/widl/parser.tab.c"
    break;

  case 292: /* m_ident: %empty  */
#line 895 "tools/widl/parser.y"
                                                { (yyval.var) = NULL; }
#line 4830 "tools/widl/parser.tab.c"
    break;

  case 294: /* t_ident: %empty  */
#line 899 "tools/widl/parser.y"
                                                { (yyval.str) = NULL; }
#line 4836 "tools/widl/parser.tab.c"
    break;

  case 295: /* t_ident: aIDENTIFIER  */
#line 900 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4842 "tools/widl/parser.tab.c"
    break;

  case 296: /* t_ident: aKNOWNTYPE  */
#line 901 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 4848 "tools/widl/parser.tab.c"
    break;

  case 297: /* ident: aIDENTIFIER  */
#line 904 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4854 "tools/widl/parser.tab.c"
    break;

  case 298: /* ident: aKNOWNTYPE  */
#line 906 "tools/widl/parser.y"
                                                { (yyval.var) = make_var((yyvsp[0].str)); }
#line 4860 "tools/widl/parser.tab.c"
    break;

  case 299: /* base_type: tBYTE  */
#line 909 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4866 "tools/widl/parser.tab.c"
    break;

  case 300: /* base_type: tWCHAR  */
#line 910 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4872 "tools/widl/parser.tab.c"
    break;

  case 302: /* base_type: tSIGNED int_std  */
#line 912 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), -1); }
#line 4878 "tools/widl/parser.tab.c"
    break;

  case 303: /* base_type: tUNSIGNED int_std  */
#line 913 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(type_basic_get_type((yyvsp[0].type)), 1); }
#line 4884 "tools/widl/parser.tab.c"
    break;

  case 304: /* base_type: tUNSIGNED  */
#line 914 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 1); }
#line 4890 "tools/widl/parser.tab.c"
    break;

  case 305: /* base_type: tFLOAT  */
#line 915 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4896 "tools/widl/parser.tab.c"
    break;

  case 306: /* base_type: tDOUBLE  */
#line 916 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4902 "tools/widl/parser.tab.c"
    break;

  case 307: /* base_type: tBOOLEAN  */
#line 917 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4908 "tools/widl/parser.tab.c"
    break;

  case 308: /* base_type: tERRORSTATUST  */
#line 918 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4914 "tools/widl/parser.tab.c"
    break;

  case 309: /* base_type: tHANDLET  */
#line 919 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4920 "tools/widl/parser.tab.c"
    break;

  case 312: /* int_std: tINT  */
#line 926 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT, 0); }
#line 4926 "tools/widl/parser.tab.c"
    break;

  case 313: /* int_std: tSHORT m_int  */
#line 927 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT16, 0); }
#line 4932 "tools/widl/parser.tab.c"
    break;

  case 314: /* int_std: tSMALL  */
#line 928 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT8, 0); }
#line 4938 "tools/widl/parser.tab.c"
    break;

  case 315: /* int_std: tLONG m_int  */
#line 929 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_LONG, 0); }
#line 4944 "tools/widl/parser.tab.c"
    break;

  case 316: /* int_std: tHYPER m_int  */
#line 930 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_HYPER, 0); }
#line 4950 "tools/widl/parser.tab.c"
    break;

  case 317: /* int_std: tINT64  */
#line 931 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT64, 0); }
#line 4956 "tools/widl/parser.tab.c"
    break;

  case 318: /* int_std: tCHAR  */
#line 932 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_CHAR, 0); }
#line 4962 "tools/widl/parser.tab.c"
    break;

  case 319: /* int_std: tINT32  */
#line 933 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT32, 0); }
#line 4968 "tools/widl/parser.tab.c"
    break;

  case 320: /* int_std: tINT3264  */
#line 934 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_int(TYPE_BASIC_INT3264, 0); }
#line 4974 "tools/widl/parser.tab.c"
    break;

  case 321: /* namespace_pfx: aNAMESPACE '.'  */
#line 938 "tools/widl/parser.y"
                                                { push_lookup_namespace((yyvsp[-1].str)); }
#line 4980 "tools/widl/parser.tab.c"
    break;

  case 322: /* namespace_pfx: namespace_pfx aNAMESPACE '.'  */
#line 939 "tools/widl/parser.y"
                                                { push_lookup_namespace((yyvsp[-1].str)); }
#line 4986 "tools/widl/parser.tab.c"
    break;

  case 323: /* qualified_type: aKNOWNTYPE  */
#line 943 "tools/widl/parser.y"
                                                { (yyval.type) = find_type_or_error((yyvsp[0].str), 0); }
#line 4992 "tools/widl/parser.tab.c"
    break;

  case 324: /* qualified_type: namespace_pfx aKNOWNTYPE  */
#line 944 "tools/widl/parser.y"
                                                { (yyval.type) = find_qualified_type_or_error((yyvsp[0].str), 0); }
#line 4998 "tools/widl/parser.tab.c"
    break;

  case 325: /* parameterized_type: qualified_type '<' parameterized_types '>'  */
#line 948 "tools/widl/parser.y"
                                                { (yyval.type) = find_parameterized_type((yyvsp[-3].type), (yyvsp[-1].typelist), 0); }
#line 5004 "tools/widl/parser.tab.c"
    break;

  case 326: /* parameterized_types: base_type  */
#line 952 "tools/widl/parser.y"
                                                { (yyval.typelist) = append_type(NULL, (yyvsp[0].type)); }
#line 5010 "tools/widl/parser.tab.c"
    break;

  case 327: /* parameterized_types: qualified_type  */
#line 953 "tools/widl/parser.y"
                                                { (yyval.typelist) = append_type(NULL, (yyvsp[0].type)); }
#line 5016 "tools/widl/parser.tab.c"
    break;

  case 328: /* parameterized_types: qualified_type '*'  */
#line 954 "tools/widl/parser.y"
                                                { (yyval.typelist) = append_type(NULL, type_new_pointer((yyvsp[-1].type))); }
#line 5022 "tools/widl/parser.tab.c"
    break;

  case 329: /* parameterized_types: parameterized_type  */
#line 955 "tools/widl/parser.y"
                                                { (yyval.typelist) = append_type(NULL, (yyvsp[0].type)); }
#line 5028 "tools/widl/parser.tab.c"
    break;

  case 330: /* parameterized_types: parameterized_type '*'  */
#line 956 "tools/widl/parser.y"
                                                { (yyval.typelist) = append_type(NULL, type_new_pointer((yyvsp[-1].type))); }
#line 5034 "tools/widl/parser.tab.c"
    break;

  case 331: /* parameterized_types: parameterized_types ',' parameterized_types  */
#line 958 "tools/widl/parser.y"
                                                { (yyval.typelist) = append_types((yyvsp[-2].typelist), (yyvsp[0].typelist)); }
#line 5040 "tools/widl/parser.tab.c"
    break;

  case 332: /* coclass: tCOCLASS aIDENTIFIER  */
#line 961 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_coclass((yyvsp[0].str)); }
#line 5046 "tools/widl/parser.tab.c"
    break;

  case 333: /* coclass: tCOCLASS aKNOWNTYPE  */
#line 962 "tools/widl/parser.y"
                                                { (yyval.type) = find_type((yyvsp[0].str), NULL, 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_COCLASS)
						    error_loc("%s was not declared a coclass at %s:%d\n",
							      (yyvsp[0].str), (yyval.type)->loc_info.input_name,
							      (yyval.type)->loc_info.line_number);
						}
#line 5057 "tools/widl/parser.tab.c"
    break;

  case 334: /* coclasshdr: attributes coclass  */
#line 970 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_coclass_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 5066 "tools/widl/parser.tab.c"
    break;

  case 335: /* coclassdef: coclasshdr '{' class_interfaces '}' semicolon_opt  */
#line 977 "tools/widl/parser.y"
                                                { (yyval.type) = type_coclass_define((yyvsp[-4].type), (yyvsp[-2].ifref_list)); }
#line 5072 "tools/widl/parser.tab.c"
    break;

  case 336: /* runtimeclass: tRUNTIMECLASS aIDENTIFIER  */
#line 981 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_runtimeclass((yyvsp[0].str), current_namespace); }
#line 5078 "tools/widl/parser.tab.c"
    break;

  case 337: /* runtimeclass: tRUNTIMECLASS aKNOWNTYPE  */
#line 982 "tools/widl/parser.y"
                                                { (yyval.type) = find_type((yyvsp[0].str), NULL, 0);
						  if (type_get_type_detect_alias((yyval.type)) != TYPE_RUNTIMECLASS)
						    error_loc("%s was not declared a runtimeclass at %s:%d\n", (yyvsp[0].str),
						              (yyval.type)->loc_info.input_name, (yyval.type)->loc_info.line_number);
						}
#line 5088 "tools/widl/parser.tab.c"
    break;

  case 338: /* runtimeclass_hdr: attributes runtimeclass  */
#line 989 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_runtimeclass_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 5097 "tools/widl/parser.tab.c"
    break;

  case 339: /* runtimeclass_def: runtimeclass_hdr '{' class_interfaces '}' semicolon_opt  */
#line 996 "tools/widl/parser.y"
                                                { (yyval.type) = type_runtimeclass_define((yyvsp[-4].type), (yyvsp[-2].ifref_list)); }
#line 5103 "tools/widl/parser.tab.c"
    break;

  case 340: /* apicontract: attributes tAPICONTRACT aIDENTIFIER '{' '}'  */
#line 1000 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_APICONTRACT, (yyvsp[-2].str), current_namespace, 0);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_apicontract_attrs((yyval.type)->name, (yyvsp[-4].attr_list));
						}
#line 5112 "tools/widl/parser.tab.c"
    break;

  case 341: /* namespacedef: tNAMESPACE aIDENTIFIER  */
#line 1006 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5118 "tools/widl/parser.tab.c"
    break;

  case 342: /* namespacedef: tNAMESPACE aNAMESPACE  */
#line 1007 "tools/widl/parser.y"
                                                { (yyval.str) = (yyvsp[0].str); }
#line 5124 "tools/widl/parser.tab.c"
    break;

  case 343: /* class_interfaces: %empty  */
#line 1010 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = NULL; }
#line 5130 "tools/widl/parser.tab.c"
    break;

  case 344: /* class_interfaces: class_interfaces class_interface  */
#line 1011 "tools/widl/parser.y"
                                                { (yyval.ifref_list) = append_ifref( (yyvsp[-1].ifref_list), (yyvsp[0].ifref) ); }
#line 5136 "tools/widl/parser.tab.c"
    break;

  case 345: /* class_interface: m_attributes interfacedec  */
#line 1015 "tools/widl/parser.y"
                                                { (yyval.ifref) = make_ifref((yyvsp[0].type)); (yyval.ifref)->attrs = (yyvsp[-1].attr_list); }
#line 5142 "tools/widl/parser.tab.c"
    break;

  case 346: /* dispinterface: tDISPINTERFACE aIDENTIFIER  */
#line 1018 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5148 "tools/widl/parser.tab.c"
    break;

  case 347: /* dispinterface: tDISPINTERFACE aKNOWNTYPE  */
#line 1019 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5154 "tools/widl/parser.tab.c"
    break;

  case 348: /* dispinterfacehdr: attributes dispinterface  */
#line 1022 "tools/widl/parser.y"
                                                { attr_t *attrs;
						  (yyval.type) = (yyvsp[0].type);
						  check_def((yyval.type));
						  attrs = make_attr(ATTR_DISPINTERFACE);
						  (yyval.type)->attrs = append_attr( check_dispiface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list)), attrs );
						  (yyval.type)->defined = TRUE;
						}
#line 5166 "tools/widl/parser.tab.c"
    break;

  case 349: /* dispint_props: tPROPERTIES ':'  */
#line 1031 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5172 "tools/widl/parser.tab.c"
    break;

  case 350: /* dispint_props: dispint_props s_field ';'  */
#line 1032 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5178 "tools/widl/parser.tab.c"
    break;

  case 351: /* dispint_meths: tMETHODS ':'  */
#line 1035 "tools/widl/parser.y"
                                                { (yyval.var_list) = NULL; }
#line 5184 "tools/widl/parser.tab.c"
    break;

  case 352: /* dispint_meths: dispint_meths funcdef ';'  */
#line 1036 "tools/widl/parser.y"
                                                { (yyval.var_list) = append_var( (yyvsp[-2].var_list), (yyvsp[-1].var) ); }
#line 5190 "tools/widl/parser.tab.c"
    break;

  case 353: /* dispinterfacedef: dispinterfacehdr '{' dispint_props dispint_meths '}'  */
#line 1042 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define((yyval.type), (yyvsp[-2].var_list), (yyvsp[-1].var_list));
						}
#line 5198 "tools/widl/parser.tab.c"
    break;

  case 354: /* dispinterfacedef: dispinterfacehdr '{' interface ';' '}'  */
#line 1046 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
						  type_dispinterface_define_from_iface((yyval.type), (yyvsp[-2].type));
						}
#line 5206 "tools/widl/parser.tab.c"
    break;

  case 355: /* inherit: %empty  */
#line 1051 "tools/widl/parser.y"
                                                { (yyval.type) = NULL; }
#line 5212 "tools/widl/parser.tab.c"
    break;

  case 356: /* inherit: ':' qualified_type  */
#line 1052 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5218 "tools/widl/parser.tab.c"
    break;

  case 357: /* inherit: ':' parameterized_type  */
#line 1053 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5224 "tools/widl/parser.tab.c"
    break;

  case 358: /* interface: tINTERFACE aIDENTIFIER  */
#line 1056 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5230 "tools/widl/parser.tab.c"
    break;

  case 359: /* interface: tINTERFACE aKNOWNTYPE  */
#line 1057 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_INTERFACE, (yyvsp[0].str), current_namespace, 0); }
#line 5236 "tools/widl/parser.tab.c"
    break;

  case 360: /* interface: tINTERFACE namespace_pfx aIDENTIFIER  */
#line 1058 "tools/widl/parser.y"
                                                { (yyval.type) = get_qualified_type(TYPE_INTERFACE, (yyvsp[0].str), 0); }
#line 5242 "tools/widl/parser.tab.c"
    break;

  case 361: /* interface: tINTERFACE namespace_pfx aKNOWNTYPE  */
#line 1059 "tools/widl/parser.y"
                                                { (yyval.type) = get_qualified_type(TYPE_INTERFACE, (yyvsp[0].str), 0); }
#line 5248 "tools/widl/parser.tab.c"
    break;

  case 362: /* interfacehdr: attributes interface  */
#line 1062 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  check_def((yyvsp[0].type));
						  (yyvsp[0].type)->attrs = check_iface_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						  (yyvsp[0].type)->defined = TRUE;
						}
#line 5258 "tools/widl/parser.tab.c"
    break;

  case 363: /* type_parameter: aIDENTIFIER  */
#line 1069 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_PARAMETER, (yyvsp[0].str), parameters_namespace, 0); }
#line 5264 "tools/widl/parser.tab.c"
    break;

  case 364: /* type_parameter: aKNOWNTYPE  */
#line 1070 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_PARAMETER, (yyvsp[0].str), parameters_namespace, 0); }
#line 5270 "tools/widl/parser.tab.c"
    break;

  case 365: /* type_parameters: type_parameter  */
#line 1074 "tools/widl/parser.y"
                                                { (yyval.typelist) = append_type(NULL, (yyvsp[0].type)); }
#line 5276 "tools/widl/parser.tab.c"
    break;

  case 366: /* type_parameters: type_parameters ',' type_parameter  */
#line 1075 "tools/widl/parser.y"
                                                { (yyval.typelist) = append_type((yyvsp[-2].typelist), (yyvsp[0].type)); }
#line 5282 "tools/widl/parser.tab.c"
    break;

  case 367: /* delegatedef: m_attributes tDELEGATE type ident '(' m_args ')' semicolon_opt  */
#line 1080 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_DELEGATE, (yyvsp[-4].var)->name, current_namespace, 0);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_iface_attrs((yyval.type)->name, (yyvsp[-7].attr_list));
						  (yyval.type)->defined = TRUE;
						  type_delegate_define((yyval.type), append_statement(NULL, make_statement_delegate((yyvsp[-5].type), (yyvsp[-2].var_list))));
						  check_async_uuid((yyval.type));
						}
#line 5294 "tools/widl/parser.tab.c"
    break;

  case 368: /* $@3: %empty  */
#line 1088 "tools/widl/parser.y"
              { push_parameters_namespace((yyvsp[-1].var)->name); }
#line 5300 "tools/widl/parser.tab.c"
    break;

  case 369: /* delegatedef: m_attributes tDELEGATE type ident '<' $@3 type_parameters '>' '(' m_args ')' semicolon_opt  */
#line 1090 "tools/widl/parser.y"
                                                { (yyval.type) = get_type(TYPE_DELEGATE, (yyvsp[-8].var)->name, current_namespace, 0);
						  check_def((yyval.type));
						  (yyval.type)->attrs = check_iface_attrs((yyval.type)->name, (yyvsp[-11].attr_list));
						  (yyval.type)->defined = TRUE;
						  type_parameterized_delegate_define((yyval.type), (yyvsp[-5].typelist), append_statement(NULL, make_statement_delegate((yyvsp[-9].type), (yyvsp[-2].var_list))));
						  check_async_uuid((yyval.type));
						  pop_parameters_namespace((yyvsp[-8].var)->name);
						}
#line 5313 "tools/widl/parser.tab.c"
    break;

  case 370: /* required_types: qualified_type  */
#line 1101 "tools/widl/parser.y"
                                                { (yyval.typelist) = append_type(NULL, (yyvsp[0].type)); }
#line 5319 "tools/widl/parser.tab.c"
    break;

  case 371: /* required_types: parameterized_type  */
#line 1102 "tools/widl/parser.y"
                                                { (yyval.typelist) = append_type(NULL, (yyvsp[0].type)); }
#line 5325 "tools/widl/parser.tab.c"
    break;

  case 372: /* required_types: required_types ',' required_types  */
#line 1103 "tools/widl/parser.y"
                                                { (yyval.typelist) = append_types((yyvsp[-2].typelist), (yyvsp[0].typelist)); }
#line 5331 "tools/widl/parser.tab.c"
    break;

  case 373: /* requires: %empty  */
#line 1105 "tools/widl/parser.y"
                                                { (yyval.typelist) = NULL; }
#line 5337 "tools/widl/parser.tab.c"
    break;

  case 374: /* requires: tREQUIRES required_types  */
#line 1106 "tools/widl/parser.y"
                                                { (yyval.typelist) = (yyvsp[0].typelist); }
#line 5343 "tools/widl/parser.tab.c"
    break;

  case 375: /* interfacedef: interfacehdr inherit requires '{' int_statements '}' semicolon_opt  */
#line 1110 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-6].type);
						  if((yyval.type) == (yyvsp[-5].type))
						    error_loc("Interface can't inherit from itself\n");
						  type_interface_define((yyval.type), (yyvsp[-5].type), (yyvsp[-2].stmt_list), (yyvsp[-4].typelist));
						  check_async_uuid((yyval.type));
						}
#line 5354 "tools/widl/parser.tab.c"
    break;

  case 376: /* $@4: %empty  */
#line 1116 "tools/widl/parser.y"
                           { push_parameters_namespace((yyvsp[-1].type)->name); }
#line 5360 "tools/widl/parser.tab.c"
    break;

  case 377: /* interfacedef: interfacehdr '<' $@4 type_parameters '>' inherit '{' int_statements '}' semicolon_opt  */
#line 1117 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-9].type);
						  if((yyval.type) == (yyvsp[-4].type)) error_loc("Interface can't inherit from itself\n");
						  type_parameterized_interface_define((yyval.type), (yyvsp[-6].typelist), (yyvsp[-4].type), (yyvsp[-2].stmt_list));
						  check_async_uuid((yyval.type));
						  pop_parameters_namespace((yyvsp[-9].type)->name);
						}
#line 5371 "tools/widl/parser.tab.c"
    break;

  case 378: /* interfacedef: interfacehdr ':' aIDENTIFIER requires '{' import int_statements '}' semicolon_opt  */
#line 1127 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-8].type);
						  type_interface_define((yyval.type), find_type_or_error2((yyvsp[-6].str), 0), (yyvsp[-2].stmt_list), (yyvsp[-5].typelist));
						}
#line 5379 "tools/widl/parser.tab.c"
    break;

  case 379: /* interfacedef: dispinterfacedef semicolon_opt  */
#line 1130 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5385 "tools/widl/parser.tab.c"
    break;

  case 380: /* interfacedec: interface ';'  */
#line 1134 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5391 "tools/widl/parser.tab.c"
    break;

  case 381: /* $@5: %empty  */
#line 1135 "tools/widl/parser.y"
                        { push_parameters_namespace((yyvsp[-1].type)->name); }
#line 5397 "tools/widl/parser.tab.c"
    break;

  case 382: /* interfacedec: interface '<' $@5 type_parameters '>' ';'  */
#line 1136 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-5].type);
						  type_parameterized_interface_declare((yyval.type), (yyvsp[-2].typelist));
						  pop_parameters_namespace((yyvsp[-5].type)->name);
						}
#line 5406 "tools/widl/parser.tab.c"
    break;

  case 383: /* interfacedec: dispinterface ';'  */
#line 1140 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-1].type); }
#line 5412 "tools/widl/parser.tab.c"
    break;

  case 384: /* module: tMODULE aIDENTIFIER  */
#line 1143 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5418 "tools/widl/parser.tab.c"
    break;

  case 385: /* module: tMODULE aKNOWNTYPE  */
#line 1144 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_module((yyvsp[0].str)); }
#line 5424 "tools/widl/parser.tab.c"
    break;

  case 386: /* modulehdr: attributes module  */
#line 1147 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type);
						  (yyval.type)->attrs = check_module_attrs((yyvsp[0].type)->name, (yyvsp[-1].attr_list));
						}
#line 5432 "tools/widl/parser.tab.c"
    break;

  case 387: /* moduledef: modulehdr '{' int_statements '}' semicolon_opt  */
#line 1153 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[-4].type);
                                                  type_module_define((yyval.type), (yyvsp[-2].stmt_list));
						}
#line 5440 "tools/widl/parser.tab.c"
    break;

  case 388: /* storage_cls_spec: tEXTERN  */
#line 1159 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_EXTERN; }
#line 5446 "tools/widl/parser.tab.c"
    break;

  case 389: /* storage_cls_spec: tSTATIC  */
#line 1160 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_STATIC; }
#line 5452 "tools/widl/parser.tab.c"
    break;

  case 390: /* storage_cls_spec: tREGISTER  */
#line 1161 "tools/widl/parser.y"
                                                { (yyval.stgclass) = STG_REGISTER; }
#line 5458 "tools/widl/parser.tab.c"
    break;

  case 391: /* function_specifier: tINLINE  */
#line 1165 "tools/widl/parser.y"
                                                { (yyval.function_specifier) = FUNCTION_SPECIFIER_INLINE; }
#line 5464 "tools/widl/parser.tab.c"
    break;

  case 392: /* type_qualifier: tCONST  */
#line 1169 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = TYPE_QUALIFIER_CONST; }
#line 5470 "tools/widl/parser.tab.c"
    break;

  case 393: /* m_type_qual_list: %empty  */
#line 1172 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = 0; }
#line 5476 "tools/widl/parser.tab.c"
    break;

  case 394: /* m_type_qual_list: m_type_qual_list type_qualifier  */
#line 1173 "tools/widl/parser.y"
                                                { (yyval.type_qualifier) = (yyvsp[-1].type_qualifier) | (yyvsp[0].type_qualifier); }
#line 5482 "tools/widl/parser.tab.c"
    break;

  case 395: /* decl_spec: type m_decl_spec_no_type  */
#line 1176 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[0].declspec), NULL, STG_NONE, 0, 0); }
#line 5488 "tools/widl/parser.tab.c"
    break;

  case 396: /* decl_spec: decl_spec_no_type type m_decl_spec_no_type  */
#line 1178 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec((yyvsp[-1].type), (yyvsp[-2].declspec), (yyvsp[0].declspec), STG_NONE, 0, 0); }
#line 5494 "tools/widl/parser.tab.c"
    break;

  case 397: /* m_decl_spec_no_type: %empty  */
#line 1181 "tools/widl/parser.y"
                                                { (yyval.declspec) = NULL; }
#line 5500 "tools/widl/parser.tab.c"
    break;

  case 399: /* decl_spec_no_type: type_qualifier m_decl_spec_no_type  */
#line 1186 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, (yyvsp[-1].type_qualifier), 0); }
#line 5506 "tools/widl/parser.tab.c"
    break;

  case 400: /* decl_spec_no_type: function_specifier m_decl_spec_no_type  */
#line 1187 "tools/widl/parser.y"
                                                  { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, STG_NONE, 0, (yyvsp[-1].function_specifier)); }
#line 5512 "tools/widl/parser.tab.c"
    break;

  case 401: /* decl_spec_no_type: storage_cls_spec m_decl_spec_no_type  */
#line 1188 "tools/widl/parser.y"
                                                { (yyval.declspec) = make_decl_spec(NULL, (yyvsp[0].declspec), NULL, (yyvsp[-1].stgclass), 0, 0); }
#line 5518 "tools/widl/parser.tab.c"
    break;

  case 402: /* declarator: '*' m_type_qual_list declarator  */
#line 1193 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5524 "tools/widl/parser.tab.c"
    break;

  case 403: /* declarator: callconv declarator  */
#line 1194 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5530 "tools/widl/parser.tab.c"
    break;

  case 405: /* direct_declarator: ident  */
#line 1199 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5536 "tools/widl/parser.tab.c"
    break;

  case 406: /* direct_declarator: '(' declarator ')'  */
#line 1200 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5542 "tools/widl/parser.tab.c"
    break;

  case 407: /* direct_declarator: direct_declarator array  */
#line 1201 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5548 "tools/widl/parser.tab.c"
    break;

  case 408: /* direct_declarator: direct_declarator '(' m_args ')'  */
#line 1202 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator); append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0); }
#line 5554 "tools/widl/parser.tab.c"
    break;

  case 409: /* abstract_declarator: '*' m_type_qual_list m_abstract_declarator  */
#line 1208 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5560 "tools/widl/parser.tab.c"
    break;

  case 410: /* abstract_declarator: callconv m_abstract_declarator  */
#line 1209 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5566 "tools/widl/parser.tab.c"
    break;

  case 412: /* abstract_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1216 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5572 "tools/widl/parser.tab.c"
    break;

  case 413: /* abstract_declarator_no_direct: callconv m_any_declarator  */
#line 1217 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5578 "tools/widl/parser.tab.c"
    break;

  case 414: /* m_abstract_declarator: %empty  */
#line 1221 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5584 "tools/widl/parser.tab.c"
    break;

  case 416: /* abstract_direct_declarator: '(' abstract_declarator_no_direct ')'  */
#line 1227 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5590 "tools/widl/parser.tab.c"
    break;

  case 417: /* abstract_direct_declarator: abstract_direct_declarator array  */
#line 1228 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5596 "tools/widl/parser.tab.c"
    break;

  case 418: /* abstract_direct_declarator: array  */
#line 1229 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5602 "tools/widl/parser.tab.c"
    break;

  case 419: /* abstract_direct_declarator: '(' m_args ')'  */
#line 1231 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5610 "tools/widl/parser.tab.c"
    break;

  case 420: /* abstract_direct_declarator: abstract_direct_declarator '(' m_args ')'  */
#line 1235 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5618 "tools/widl/parser.tab.c"
    break;

  case 421: /* any_declarator: '*' m_type_qual_list m_any_declarator  */
#line 1243 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5624 "tools/widl/parser.tab.c"
    break;

  case 422: /* any_declarator: callconv m_any_declarator  */
#line 1244 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5630 "tools/widl/parser.tab.c"
    break;

  case 424: /* any_declarator_no_direct: '*' m_type_qual_list m_any_declarator  */
#line 1251 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_type((yyval.declarator), type_new_pointer(NULL), (yyvsp[-1].type_qualifier)); }
#line 5636 "tools/widl/parser.tab.c"
    break;

  case 425: /* any_declarator_no_direct: callconv m_any_declarator  */
#line 1252 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); append_chain_callconv((yyval.declarator)->type, (yyvsp[-1].str)); }
#line 5642 "tools/widl/parser.tab.c"
    break;

  case 426: /* m_any_declarator: %empty  */
#line 1256 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); }
#line 5648 "tools/widl/parser.tab.c"
    break;

  case 428: /* any_direct_declarator: ident  */
#line 1264 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator((yyvsp[0].var)); }
#line 5654 "tools/widl/parser.tab.c"
    break;

  case 429: /* any_direct_declarator: '(' any_declarator_no_direct ')'  */
#line 1265 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); }
#line 5660 "tools/widl/parser.tab.c"
    break;

  case 430: /* any_direct_declarator: any_direct_declarator array  */
#line 1266 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5666 "tools/widl/parser.tab.c"
    break;

  case 431: /* any_direct_declarator: array  */
#line 1267 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL); append_array((yyval.declarator), (yyvsp[0].expr)); }
#line 5672 "tools/widl/parser.tab.c"
    break;

  case 432: /* any_direct_declarator: '(' m_args ')'  */
#line 1269 "tools/widl/parser.y"
                                                { (yyval.declarator) = make_declarator(NULL);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5680 "tools/widl/parser.tab.c"
    break;

  case 433: /* any_direct_declarator: any_direct_declarator '(' m_args ')'  */
#line 1273 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-3].declarator);
						  append_chain_type((yyval.declarator), type_new_function((yyvsp[-1].var_list)), 0);
						}
#line 5688 "tools/widl/parser.tab.c"
    break;

  case 434: /* declarator_list: declarator  */
#line 1279 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5694 "tools/widl/parser.tab.c"
    break;

  case 435: /* declarator_list: declarator_list ',' declarator  */
#line 1280 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5700 "tools/widl/parser.tab.c"
    break;

  case 436: /* m_bitfield: %empty  */
#line 1283 "tools/widl/parser.y"
                                                { (yyval.expr) = NULL; }
#line 5706 "tools/widl/parser.tab.c"
    break;

  case 437: /* m_bitfield: ':' expr_const  */
#line 1284 "tools/widl/parser.y"
                                                { (yyval.expr) = (yyvsp[0].expr); }
#line 5712 "tools/widl/parser.tab.c"
    break;

  case 438: /* struct_declarator: any_declarator m_bitfield  */
#line 1287 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-1].declarator); (yyval.declarator)->bits = (yyvsp[0].expr);
						  if (!(yyval.declarator)->bits && !(yyval.declarator)->var->name)
						    error_loc("unnamed fields are not allowed\n");
						}
#line 5721 "tools/widl/parser.tab.c"
    break;

  case 439: /* struct_declarator_list: struct_declarator  */
#line 1294 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( NULL, (yyvsp[0].declarator) ); }
#line 5727 "tools/widl/parser.tab.c"
    break;

  case 440: /* struct_declarator_list: struct_declarator_list ',' struct_declarator  */
#line 1296 "tools/widl/parser.y"
                                                { (yyval.declarator_list) = append_declarator( (yyvsp[-2].declarator_list), (yyvsp[0].declarator) ); }
#line 5733 "tools/widl/parser.tab.c"
    break;

  case 441: /* init_declarator: declarator  */
#line 1300 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[0].declarator); }
#line 5739 "tools/widl/parser.tab.c"
    break;

  case 442: /* init_declarator: declarator '=' expr_const  */
#line 1301 "tools/widl/parser.y"
                                                { (yyval.declarator) = (yyvsp[-2].declarator); (yyvsp[-2].declarator)->var->eval = (yyvsp[0].expr); }
#line 5745 "tools/widl/parser.tab.c"
    break;

  case 443: /* threading_type: tAPARTMENT  */
#line 1305 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_APARTMENT; }
#line 5751 "tools/widl/parser.tab.c"
    break;

  case 444: /* threading_type: tNEUTRAL  */
#line 1306 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_NEUTRAL; }
#line 5757 "tools/widl/parser.tab.c"
    break;

  case 445: /* threading_type: tSINGLE  */
#line 1307 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_SINGLE; }
#line 5763 "tools/widl/parser.tab.c"
    break;

  case 446: /* threading_type: tFREE  */
#line 1308 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_FREE; }
#line 5769 "tools/widl/parser.tab.c"
    break;

  case 447: /* threading_type: tBOTH  */
#line 1309 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_BOTH; }
#line 5775 "tools/widl/parser.tab.c"
    break;

  case 448: /* threading_type: tMTA  */
#line 1310 "tools/widl/parser.y"
                                                { (yyval.num) = THREADING_MTA; }
#line 5781 "tools/widl/parser.tab.c"
    break;

  case 449: /* pointer_type: tREF  */
#line 1314 "tools/widl/parser.y"
                                                { (yyval.num) = FC_RP; }
#line 5787 "tools/widl/parser.tab.c"
    break;

  case 450: /* pointer_type: tUNIQUE  */
#line 1315 "tools/widl/parser.y"
                                                { (yyval.num) = FC_UP; }
#line 5793 "tools/widl/parser.tab.c"
    break;

  case 451: /* pointer_type: tPTR  */
#line 1316 "tools/widl/parser.y"
                                                { (yyval.num) = FC_FP; }
#line 5799 "tools/widl/parser.tab.c"
    break;

  case 452: /* structdef: tSTRUCT t_ident '{' fields '}'  */
#line 1319 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[-3].str), current_namespace, TRUE, (yyvsp[-1].var_list)); }
#line 5805 "tools/widl/parser.tab.c"
    break;

  case 453: /* type: tVOID  */
#line 1322 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_void(); }
#line 5811 "tools/widl/parser.tab.c"
    break;

  case 454: /* type: qualified_type  */
#line 1323 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5817 "tools/widl/parser.tab.c"
    break;

  case 455: /* type: parameterized_type  */
#line 1324 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5823 "tools/widl/parser.tab.c"
    break;

  case 456: /* type: base_type  */
#line 1325 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5829 "tools/widl/parser.tab.c"
    break;

  case 457: /* type: enumdef  */
#line 1326 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5835 "tools/widl/parser.tab.c"
    break;

  case 458: /* type: tENUM aIDENTIFIER  */
#line 1327 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_enum((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5841 "tools/widl/parser.tab.c"
    break;

  case 459: /* type: structdef  */
#line 1328 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5847 "tools/widl/parser.tab.c"
    break;

  case 460: /* type: tSTRUCT aIDENTIFIER  */
#line 1329 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_struct((yyvsp[0].str), current_namespace, FALSE, NULL); }
#line 5853 "tools/widl/parser.tab.c"
    break;

  case 461: /* type: uniondef  */
#line 1330 "tools/widl/parser.y"
                                                { (yyval.type) = (yyvsp[0].type); }
#line 5859 "tools/widl/parser.tab.c"
    break;

  case 462: /* type: tUNION aIDENTIFIER  */
#line 1331 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[0].str), FALSE, NULL); }
#line 5865 "tools/widl/parser.tab.c"
    break;

  case 463: /* type: tSAFEARRAY '(' type ')'  */
#line 1332 "tools/widl/parser.y"
                                                { (yyval.type) = make_safearray((yyvsp[-1].type)); }
#line 5871 "tools/widl/parser.tab.c"
    break;

  case 464: /* typedef: m_attributes tTYPEDEF m_attributes decl_spec declarator_list  */
#line 1336 "tools/widl/parser.y"
                                                { (yyvsp[-4].attr_list) = append_attribs((yyvsp[-4].attr_list), (yyvsp[-2].attr_list));
						  reg_typedefs((yyvsp[-1].declspec), (yyvsp[0].declarator_list), check_typedef_attrs((yyvsp[-4].attr_list)));
						  (yyval.statement) = make_statement_typedef((yyvsp[0].declarator_list), !(yyvsp[-1].declspec)->type->defined);
						}
#line 5880 "tools/widl/parser.tab.c"
    break;

  case 465: /* uniondef: tUNION t_ident '{' ne_union_fields '}'  */
#line 1343 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_nonencapsulated_union((yyvsp[-3].str), TRUE, (yyvsp[-1].var_list)); }
#line 5886 "tools/widl/parser.tab.c"
    break;

  case 466: /* uniondef: tUNION t_ident tSWITCH '(' s_field ')' m_ident '{' cases '}'  */
#line 1346 "tools/widl/parser.y"
                                                { (yyval.type) = type_new_encapsulated_union((yyvsp[-8].str), (yyvsp[-5].var), (yyvsp[-3].var), (yyvsp[-1].var_list)); }
#line 5892 "tools/widl/parser.tab.c"
    break;

  case 467: /* version: aNUM  */
#line 1350 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[0].num), 0); }
#line 5898 "tools/widl/parser.tab.c"
    break;

  case 468: /* version: aNUM '.' aNUM  */
#line 1351 "tools/widl/parser.y"
                                                { (yyval.num) = MAKEVERSION((yyvsp[-2].num), (yyvsp[0].num)); }
#line 5904 "tools/widl/parser.tab.c"
    break;

  case 469: /* version: aHEXNUM  */
#line 1352 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5910 "tools/widl/parser.tab.c"
    break;

  case 474: /* acf_int_statement: tTYPEDEF acf_attributes aKNOWNTYPE ';'  */
#line 1367 "tools/widl/parser.y"
                                                { type_t *type = find_type_or_error((yyvsp[-1].str), 0);
                                                  type->attrs = append_attr_list(type->attrs, (yyvsp[-2].attr_list));
                                                }
#line 5918 "tools/widl/parser.tab.c"
    break;

  case 475: /* acf_interface: acf_attributes tINTERFACE aKNOWNTYPE '{' acf_int_statements '}'  */
#line 1374 "tools/widl/parser.y"
                                                {  type_t *iface = find_type_or_error2((yyvsp[-3].str), 0);
                                                   if (type_get_type(iface) != TYPE_INTERFACE)
                                                       error_loc("%s is not an interface\n", iface->name);
                                                   iface->attrs = append_attr_list(iface->attrs, (yyvsp[-5].attr_list));
                                                }
#line 5928 "tools/widl/parser.tab.c"
    break;

  case 476: /* acf_attributes: %empty  */
#line 1382 "tools/widl/parser.y"
                                                { (yyval.attr_list) = NULL; }
#line 5934 "tools/widl/parser.tab.c"
    break;

  case 477: /* acf_attributes: '[' acf_attribute_list ']'  */
#line 1383 "tools/widl/parser.y"
                                                { (yyval.attr_list) = (yyvsp[-1].attr_list); }
#line 5940 "tools/widl/parser.tab.c"
    break;

  case 478: /* acf_attribute_list: acf_attribute  */
#line 1387 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr(NULL, (yyvsp[0].attr)); }
#line 5946 "tools/widl/parser.tab.c"
    break;

  case 479: /* acf_attribute_list: acf_attribute_list ',' acf_attribute  */
#line 1388 "tools/widl/parser.y"
                                                { (yyval.attr_list) = append_attr((yyvsp[-2].attr_list), (yyvsp[0].attr)); }
#line 5952 "tools/widl/parser.tab.c"
    break;

  case 480: /* acf_attribute: tALLOCATE '(' allocate_option_list ')'  */
#line 1393 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attrv(ATTR_ALLOCATE, (yyvsp[-1].num)); }
#line 5958 "tools/widl/parser.tab.c"
    break;

  case 481: /* acf_attribute: tENCODE  */
#line 1394 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_ENCODE); }
#line 5964 "tools/widl/parser.tab.c"
    break;

  case 482: /* acf_attribute: tDECODE  */
#line 1395 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_DECODE); }
#line 5970 "tools/widl/parser.tab.c"
    break;

  case 483: /* acf_attribute: tEXPLICITHANDLE  */
#line 1396 "tools/widl/parser.y"
                                                { (yyval.attr) = make_attr(ATTR_EXPLICIT_HANDLE); }
#line 5976 "tools/widl/parser.tab.c"
    break;

  case 484: /* allocate_option_list: allocate_option  */
#line 1400 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[0].num); }
#line 5982 "tools/widl/parser.tab.c"
    break;

  case 485: /* allocate_option_list: allocate_option_list ',' allocate_option  */
#line 1402 "tools/widl/parser.y"
                                                { (yyval.num) = (yyvsp[-2].num) | (yyvsp[0].num); }
#line 5988 "tools/widl/parser.tab.c"
    break;

  case 486: /* allocate_option: tDONTFREE  */
#line 1406 "tools/widl/parser.y"
                                                { (yyval.num) = FC_DONT_FREE; }
#line 5994 "tools/widl/parser.tab.c"
    break;

  case 487: /* allocate_option: tFREE  */
#line 1407 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6000 "tools/widl/parser.tab.c"
    break;

  case 488: /* allocate_option: tALLNODES  */
#line 1408 "tools/widl/parser.y"
                                                { (yyval.num) = FC_ALLOCATE_ALL_NODES; }
#line 6006 "tools/widl/parser.tab.c"
    break;

  case 489: /* allocate_option: tSINGLENODE  */
#line 1409 "tools/widl/parser.y"
                                                { (yyval.num) = 0; }
#line 6012 "tools/widl/parser.tab.c"
    break;


#line 6016 "tools/widl/parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1412 "tools/widl/parser.y"


static void decl_builtin_basic(const char *name, enum type_basic_type type)
{
  type_t *t = type_new_basic(type);
  reg_type(t, name, NULL, 0);
}

static void decl_builtin_alias(const char *name, type_t *t)
{
    const decl_spec_t ds = {.type = t};
    reg_type(type_new_alias(&ds, name), name, NULL, 0);
}

void init_types(void)
{
  decl_builtin_basic("byte", TYPE_BASIC_BYTE);
  decl_builtin_basic("wchar_t", TYPE_BASIC_WCHAR);
  decl_builtin_basic("float", TYPE_BASIC_FLOAT);
  decl_builtin_basic("double", TYPE_BASIC_DOUBLE);
  decl_builtin_basic("error_status_t", TYPE_BASIC_ERROR_STATUS_T);
  decl_builtin_basic("handle_t", TYPE_BASIC_HANDLE);
  decl_builtin_alias("boolean", type_new_basic(TYPE_BASIC_CHAR));
}

static str_list_t *append_str(str_list_t *list, char *str)
{
    struct str_list_entry_t *entry;

    if (!str) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    entry = xmalloc( sizeof(*entry) );
    entry->str = str;
    list_add_tail( list, &entry->entry );
    return list;
}

static type_list_t *append_type(type_list_t *list, type_t *type)
{
    type_list_t *entry;
    if (!type) return list;
    entry = xmalloc( sizeof(*entry) );
    entry->type = type;
    entry->next = list;
    return entry;
}

static type_list_t *append_types(type_list_t *list, type_list_t *types)
{
    type_list_t *entry;
    if (!list) return types;
    if (!types) return list;
    for (entry = list; entry->next; entry = entry->next) {}
    entry->next = types;
    return list;
}

static attr_list_t *move_attr(attr_list_t *dst, attr_list_t *src, enum attr_type type)
{
  attr_t *attr;
  if (!src) return dst;
  LIST_FOR_EACH_ENTRY(attr, src, attr_t, entry)
    if (attr->type == type)
    {
      list_remove(&attr->entry);
      return append_attr(dst, attr);
    }
  return dst;
}

static attr_list_t *append_attr_list(attr_list_t *new_list, attr_list_t *old_list)
{
  struct list *entry;

  if (!old_list) return new_list;

  while ((entry = list_head(old_list)))
  {
    attr_t *attr = LIST_ENTRY(entry, attr_t, entry);
    list_remove(entry);
    new_list = append_attr(new_list, attr);
  }
  return new_list;
}

typedef int (*map_attrs_filter_t)(attr_list_t*,const attr_t*);

static attr_list_t *map_attrs(const attr_list_t *list, map_attrs_filter_t filter)
{
  attr_list_t *new_list;
  const attr_t *attr;
  attr_t *new_attr;

  if (!list) return NULL;

  new_list = xmalloc( sizeof(*list) );
  list_init( new_list );
  LIST_FOR_EACH_ENTRY(attr, list, const attr_t, entry)
  {
    if (filter && !filter(new_list, attr)) continue;
    new_attr = xmalloc(sizeof(*new_attr));
    *new_attr = *attr;
    list_add_tail(new_list, &new_attr->entry);
  }
  return new_list;
}

static decl_spec_t *make_decl_spec(type_t *type, decl_spec_t *left, decl_spec_t *right,
        enum storage_class stgclass, enum type_qualifier qual, enum function_specifier func_specifier)
{
  decl_spec_t *declspec = left ? left : right;
  if (!declspec)
  {
    declspec = xmalloc(sizeof(*declspec));
    declspec->type = NULL;
    declspec->stgclass = STG_NONE;
    declspec->qualifier = 0;
    declspec->func_specifier = 0;
  }
  declspec->type = type;
  if (left && declspec != left)
  {
    if (declspec->stgclass == STG_NONE)
      declspec->stgclass = left->stgclass;
    else if (left->stgclass != STG_NONE)
      error_loc("only one storage class can be specified\n");
    declspec->qualifier |= left->qualifier;
    declspec->func_specifier |= left->func_specifier;
    assert(!left->type);
    free(left);
  }
  if (right && declspec != right)
  {
    if (declspec->stgclass == STG_NONE)
      declspec->stgclass = right->stgclass;
    else if (right->stgclass != STG_NONE)
      error_loc("only one storage class can be specified\n");
    declspec->qualifier |= right->qualifier;
    declspec->func_specifier |= right->func_specifier;
    assert(!right->type);
    free(right);
  }

  if (declspec->stgclass == STG_NONE)
    declspec->stgclass = stgclass;
  else if (stgclass != STG_NONE)
    error_loc("only one storage class can be specified\n");
  declspec->qualifier |= qual;
  declspec->func_specifier |= func_specifier;

  return declspec;
}

static attr_t *make_attr(enum attr_type type)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  a->type = type;
  a->u.ival = 0;
  return a;
}

static attr_t *make_attrv(enum attr_type type, unsigned int val)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  a->type = type;
  a->u.ival = val;
  return a;
}

static attr_t *make_attrp(enum attr_type type, void *val)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  a->type = type;
  a->u.pval = val;
  return a;
}

static attr_t *make_custom_attr(UUID *id, expr_t *pval)
{
  attr_t *a = xmalloc(sizeof(attr_t));
  attr_custdata_t *cstdata = xmalloc(sizeof(attr_custdata_t));
  a->type = ATTR_CUSTOM;
  cstdata->id = *id;
  cstdata->pval = pval;
  a->u.pval = cstdata;
  return a;
}

static expr_list_t *append_expr(expr_list_t *list, expr_t *expr)
{
    if (!expr) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &expr->entry );
    return list;
}

static void append_array(declarator_t *decl, expr_t *expr)
{
    type_t *array;

    if (!expr)
        return;

    /* An array is always a reference pointer unless explicitly marked otherwise
     * (regardless of what the default pointer attribute is). */
    array = type_new_array(NULL, NULL, FALSE, expr->is_const ? expr->cval : 0,
            expr->is_const ? NULL : expr, NULL);

    append_chain_type(decl, array, 0);
}

static struct list type_pool = LIST_INIT(type_pool);
typedef struct
{
  type_t data;
  struct list link;
} type_pool_node_t;

type_t *alloc_type(void)
{
  type_pool_node_t *node = xmalloc(sizeof *node);
  list_add_tail(&type_pool, &node->link);
  return &node->data;
}

void set_all_tfswrite(int val)
{
  type_pool_node_t *node;
  LIST_FOR_EACH_ENTRY(node, &type_pool, type_pool_node_t, link)
    node->data.tfswrite = val;
}

void clear_all_offsets(void)
{
  type_pool_node_t *node;
  LIST_FOR_EACH_ENTRY(node, &type_pool, type_pool_node_t, link)
    node->data.typestring_offset = node->data.ptrdesc = 0;
}

static void type_function_add_head_arg(type_t *type, var_t *arg)
{
    if (!type->details.function->args)
    {
        type->details.function->args = xmalloc( sizeof(*type->details.function->args) );
        list_init( type->details.function->args );
    }
    list_add_head( type->details.function->args, &arg->entry );
}

static int is_allowed_range_type(const type_t *type)
{
    switch (type_get_type(type))
    {
    case TYPE_ENUM:
        return TRUE;
    case TYPE_BASIC:
        switch (type_basic_get_type(type))
        {
        case TYPE_BASIC_INT8:
        case TYPE_BASIC_INT16:
        case TYPE_BASIC_INT32:
        case TYPE_BASIC_INT64:
        case TYPE_BASIC_INT:
        case TYPE_BASIC_INT3264:
        case TYPE_BASIC_LONG:
        case TYPE_BASIC_BYTE:
        case TYPE_BASIC_CHAR:
        case TYPE_BASIC_WCHAR:
        case TYPE_BASIC_HYPER:
            return TRUE;
        case TYPE_BASIC_FLOAT:
        case TYPE_BASIC_DOUBLE:
        case TYPE_BASIC_ERROR_STATUS_T:
        case TYPE_BASIC_HANDLE:
            return FALSE;
        }
        return FALSE;
    default:
        return FALSE;
    }
}

static type_t *get_chain_ref(type_t *type)
{
    if (is_ptr(type))
        return type_pointer_get_ref_type(type);
    else if (is_array(type))
        return type_array_get_element_type(type);
    else if (is_func(type))
        return type_function_get_rettype(type);
    return NULL;
}

static type_t *get_chain_end(type_t *type)
{
    type_t *inner;
    while ((inner = get_chain_ref(type)))
        type = inner;
    return type;
}

static void append_chain_type(declarator_t *decl, type_t *type, enum type_qualifier qual)
{
    type_t *chain_type;

    if (!decl->type)
    {
        decl->type = type;
        decl->qualifier = qual;
        return;
    }
    chain_type = get_chain_end(decl->type);

    if (is_ptr(chain_type))
    {
        chain_type->details.pointer.ref.type = type;
        chain_type->details.pointer.ref.qualifier = qual;
    }
    else if (is_array(chain_type))
    {
        chain_type->details.array.elem.type = type;
        chain_type->details.array.elem.qualifier = qual;
    }
    else if (is_func(chain_type))
    {
        chain_type->details.function->retval->declspec.type = type;
        chain_type->details.function->retval->declspec.qualifier = qual;
    }
    else
        assert(0);

    if (!is_func(chain_type))
        type->attrs = move_attr(type->attrs, chain_type->attrs, ATTR_CALLCONV);
}

static void append_chain_callconv(type_t *chain, char *callconv)
{
    type_t *chain_end;

    if (chain && (chain_end = get_chain_end(chain)))
        chain_end->attrs = append_attr(chain_end->attrs, make_attrp(ATTR_CALLCONV, callconv));
    else
        error_loc("calling convention applied to non-function type\n");
}

static warning_list_t *append_warning(warning_list_t *list, int num)
{
    warning_t *entry;

    if(!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    entry = xmalloc( sizeof(*entry) );
    entry->num = num;
    list_add_tail( list, &entry->entry );
    return list;
}

static var_t *declare_var(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_t *decl,
                       int top)
{
  var_t *v = decl->var;
  expr_list_t *sizes = get_attrp(attrs, ATTR_SIZEIS);
  expr_list_t *lengs = get_attrp(attrs, ATTR_LENGTHIS);
  expr_t *dim;
  type_t **ptype;
  type_t *type = decl_spec->type;

  if (decl_spec->func_specifier & FUNCTION_SPECIFIER_INLINE)
  {
    if (!decl || !is_func(decl->type))
      error_loc("inline attribute applied to non-function type\n");
  }

  /* add type onto the end of the pointers in pident->type */
  append_chain_type(decl, type, decl_spec->qualifier);
  v->declspec = *decl_spec;
  v->declspec.type = decl->type;
  v->declspec.qualifier = decl->qualifier;
  v->attrs = attrs;
  v->declonly = !type->defined;

  if (is_attr(type->attrs, ATTR_CALLCONV) && !is_func(type))
    error_loc("calling convention applied to non-function type\n");

  /* check for pointer attribute being applied to non-pointer, non-array
   * type */
  if (!is_array(v->declspec.type))
  {
    int ptr_attr = get_attrv(v->attrs, ATTR_POINTERTYPE);
    const type_t *ptr = NULL;
    for (ptr = v->declspec.type; ptr && !ptr_attr; )
    {
      ptr_attr = get_attrv(ptr->attrs, ATTR_POINTERTYPE);
      if (!ptr_attr && type_is_alias(ptr))
        ptr = type_alias_get_aliasee_type(ptr);
      else
        break;
    }
    if (is_ptr(ptr))
    {
      if (ptr_attr && ptr_attr != FC_UP &&
          type_get_type(type_pointer_get_ref_type(ptr)) == TYPE_INTERFACE)
          warning_loc_info(&v->loc_info,
                           "%s: pointer attribute applied to interface "
                           "pointer type has no effect\n", v->name);
      if (!ptr_attr && top)
      {
        /* FIXME: this is a horrible hack to cope with the issue that we
         * store an offset to the typeformat string in the type object, but
         * two typeformat strings may be written depending on whether the
         * pointer is a toplevel parameter or not */
        v->declspec.type = duptype(v->declspec.type, 1);
      }
    }
    else if (ptr_attr)
       error_loc("%s: pointer attribute applied to non-pointer type\n", v->name);
  }

  if (is_attr(v->attrs, ATTR_STRING))
  {
    type_t *t = type;

    if (!is_ptr(v->declspec.type) && !is_array(v->declspec.type))
      error_loc("'%s': [string] attribute applied to non-pointer, non-array type\n",
                v->name);

    for (;;)
    {
        if (is_ptr(t))
            t = type_pointer_get_ref_type(t);
        else if (is_array(t))
            t = type_array_get_element_type(t);
        else
            break;
    }

    if (type_get_type(t) != TYPE_BASIC &&
        (get_basic_fc(t) != FC_CHAR &&
         get_basic_fc(t) != FC_BYTE &&
         get_basic_fc(t) != FC_WCHAR))
    {
      error_loc("'%s': [string] attribute is only valid on 'char', 'byte', or 'wchar_t' pointers and arrays\n",
                v->name);
    }
  }

  if (is_attr(v->attrs, ATTR_V1ENUM))
  {
    if (type_get_type_detect_alias(v->declspec.type) != TYPE_ENUM)
      error_loc("'%s': [v1_enum] attribute applied to non-enum type\n", v->name);
  }

  if (is_attr(v->attrs, ATTR_RANGE) && !is_allowed_range_type(v->declspec.type))
    error_loc("'%s': [range] attribute applied to non-integer type\n",
              v->name);

  ptype = &v->declspec.type;
  if (sizes) LIST_FOR_EACH_ENTRY(dim, sizes, expr_t, entry)
  {
    if (dim->type != EXPR_VOID)
    {
      if (is_array(*ptype))
      {
        if (!type_array_get_conformance(*ptype) ||
            type_array_get_conformance(*ptype)->type != EXPR_VOID)
          error_loc("%s: cannot specify size_is for an already sized array\n", v->name);
        else
          *ptype = type_new_array((*ptype)->name,
                                  type_array_get_element(*ptype), FALSE,
                                  0, dim, NULL);
      }
      else if (is_ptr(*ptype))
        *ptype = type_new_array((*ptype)->name, type_pointer_get_ref(*ptype), TRUE,
                                0, dim, NULL);
      else
        error_loc("%s: size_is attribute applied to illegal type\n", v->name);
    }

    if (is_ptr(*ptype))
      ptype = &(*ptype)->details.pointer.ref.type;
    else if (is_array(*ptype))
      ptype = &(*ptype)->details.array.elem.type;
    else
      error_loc("%s: too many expressions in size_is attribute\n", v->name);
  }

  ptype = &v->declspec.type;
  if (lengs) LIST_FOR_EACH_ENTRY(dim, lengs, expr_t, entry)
  {
    if (dim->type != EXPR_VOID)
    {
      if (is_array(*ptype))
      {
        *ptype = type_new_array((*ptype)->name,
                                type_array_get_element(*ptype),
                                type_array_is_decl_as_ptr(*ptype),
                                type_array_get_dim(*ptype),
                                type_array_get_conformance(*ptype), dim);
      }
      else
        error_loc("%s: length_is attribute applied to illegal type\n", v->name);
    }

    if (is_ptr(*ptype))
      ptype = &(*ptype)->details.pointer.ref.type;
    else if (is_array(*ptype))
      ptype = &(*ptype)->details.array.elem.type;
    else
      error_loc("%s: too many expressions in length_is attribute\n", v->name);
  }

  if (decl->bits)
    v->declspec.type = type_new_bitfield(v->declspec.type, decl->bits);

  return v;
}

static var_list_t *set_var_types(attr_list_t *attrs, decl_spec_t *decl_spec, declarator_list_t *decls)
{
  declarator_t *decl, *next;
  var_list_t *var_list = NULL;

  LIST_FOR_EACH_ENTRY_SAFE( decl, next, decls, declarator_t, entry )
  {
    var_t *var = declare_var(attrs, decl_spec, decl, 0);
    var_list = append_var(var_list, var);
    free(decl);
  }
  free(decl_spec);
  return var_list;
}

static ifref_list_t *append_ifref(ifref_list_t *list, ifref_t *iface)
{
    if (!iface) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &iface->entry );
    return list;
}

static ifref_t *make_ifref(type_t *iface)
{
  ifref_t *l = xmalloc(sizeof(ifref_t));
  l->iface = iface;
  l->attrs = NULL;
  return l;
}

var_list_t *append_var(var_list_t *list, var_t *var)
{
    if (!var) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &var->entry );
    return list;
}

static var_list_t *append_var_list(var_list_t *list, var_list_t *vars)
{
    if (!vars) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_move_tail( list, vars );
    return list;
}

var_t *make_var(char *name)
{
  var_t *v = xmalloc(sizeof(var_t));
  v->name = name;
  init_declspec(&v->declspec, NULL);
  v->attrs = NULL;
  v->eval = NULL;
  init_loc_info(&v->loc_info);
  v->declonly = FALSE;
  return v;
}

static var_t *copy_var(var_t *src, char *name, map_attrs_filter_t attr_filter)
{
  var_t *v = xmalloc(sizeof(var_t));
  v->name = name;
  v->declspec = src->declspec;
  v->attrs = map_attrs(src->attrs, attr_filter);
  v->eval = src->eval;
  v->loc_info = src->loc_info;
  return v;
}

static declarator_list_t *append_declarator(declarator_list_t *list, declarator_t *d)
{
  if (!d) return list;
  if (!list) {
    list = xmalloc(sizeof(*list));
    list_init(list);
  }
  list_add_tail(list, &d->entry);
  return list;
}

static declarator_t *make_declarator(var_t *var)
{
  declarator_t *d = xmalloc(sizeof(*d));
  d->var = var ? var : make_var(NULL);
  d->type = NULL;
  d->qualifier = 0;
  d->bits = NULL;
  return d;
}

static type_t *make_safearray(type_t *type)
{
    decl_spec_t ds = {.type = type};
    ds.type = type_new_alias(&ds, "SAFEARRAY");
    return type_new_array(NULL, &ds, TRUE, 0, NULL, NULL);
}

static typelib_t *make_library(const char *name, const attr_list_t *attrs)
{
    typelib_t *typelib = xmalloc(sizeof(*typelib));
    memset(typelib, 0, sizeof(*typelib));
    typelib->name = xstrdup(name);
    typelib->attrs = attrs;
    list_init( &typelib->importlibs );
    return typelib;
}

static int hash_ident(const char *name)
{
  const char *p = name;
  int sum = 0;
  /* a simple sum hash is probably good enough */
  while (*p) {
    sum += *p;
    p++;
  }
  return sum & (HASHMAX-1);
}

/***** type repository *****/

static struct namespace *find_sub_namespace(struct namespace *namespace, const char *name)
{
  struct namespace *cur;

  LIST_FOR_EACH_ENTRY(cur, &namespace->children, struct namespace, entry) {
    if(!strcmp(cur->name, name))
      return cur;
  }

  return NULL;
}

static void push_namespace(const char *name)
{
  struct namespace *namespace;

  namespace = find_sub_namespace(current_namespace, name);
  if(!namespace) {
    namespace = xmalloc(sizeof(*namespace));
    namespace->name = xstrdup(name);
    namespace->parent = current_namespace;
    list_add_tail(&current_namespace->children, &namespace->entry);
    list_init(&namespace->children);
    memset(namespace->type_hash, 0, sizeof(namespace->type_hash));
  }

  current_namespace = namespace;
}

static void pop_namespace(const char *name)
{
  assert(!strcmp(current_namespace->name, name) && current_namespace->parent);
  current_namespace = current_namespace->parent;
}

static void push_lookup_namespace(const char *name)
{
    struct namespace *namespace;
    if (!(namespace = find_sub_namespace(lookup_namespace, name)))
        error_loc("namespace '%s' not found\n", name);
    lookup_namespace = namespace;
}

static void push_parameters_namespace(const char *name)
{
    struct namespace *namespace;

    if (!(namespace = find_sub_namespace(current_namespace, name)))
    {
        namespace = xmalloc(sizeof(*namespace));
        namespace->name = xstrdup(name);
        namespace->parent = current_namespace;
        list_add_tail(&current_namespace->children, &namespace->entry);
        list_init(&namespace->children);
        memset(namespace->type_hash, 0, sizeof(namespace->type_hash));
    }

    parameters_namespace = namespace;
}

static void pop_parameters_namespace(const char *name)
{
    assert(!strcmp(parameters_namespace->name, name) && parameters_namespace->parent);
    parameters_namespace = NULL;
}

struct rtype {
  const char *name;
  type_t *type;
  int t;
  struct rtype *next;
};

type_t *reg_type(type_t *type, const char *name, struct namespace *namespace, int t)
{
  struct rtype *nt;
  int hash;
  if (!name) {
    error_loc("registering named type without name\n");
    return type;
  }
  if (!namespace)
    namespace = &global_namespace;
  hash = hash_ident(name);
  nt = xmalloc(sizeof(struct rtype));
  nt->name = name;
  if (is_global_namespace(namespace))
    type->c_name = name;
  else
    type->c_name = format_namespace(namespace, "__x_", "_C", name, use_abi_namespace ? "ABI" : NULL);
  nt->type = type;
  nt->t = t;
  nt->next = namespace->type_hash[hash];
  namespace->type_hash[hash] = nt;
  return type;
}

static type_t *reg_typedefs(decl_spec_t *decl_spec, declarator_list_t *decls, attr_list_t *attrs)
{
  declarator_t *decl;
  type_t *type = decl_spec->type;

  if (is_attr(attrs, ATTR_UUID) && !is_attr(attrs, ATTR_PUBLIC))
    attrs = append_attr( attrs, make_attr(ATTR_PUBLIC) );

  /* We must generate names for tagless enum, struct or union.
     Typedef-ing a tagless enum, struct or union means we want the typedef
     to be included in a library hence the public attribute.  */
  if (type_get_type_detect_alias(type) == TYPE_ENUM ||
      type_get_type_detect_alias(type) == TYPE_STRUCT ||
      type_get_type_detect_alias(type) == TYPE_UNION ||
      type_get_type_detect_alias(type) == TYPE_ENCAPSULATED_UNION)
  {
    if (!type->name)
    {
      type->name = gen_name();
      if (!is_attr(attrs, ATTR_PUBLIC))
        attrs = append_attr(attrs, make_attr(ATTR_PUBLIC));
    }

    /* replace existing attributes when generating a typelib */
    if (do_typelib)
        type->attrs = attrs;
  }

  LIST_FOR_EACH_ENTRY( decl, decls, declarator_t, entry )
  {

    if (decl->var->name) {
      type_t *cur;
      var_t *name;

      cur = find_type(decl->var->name, current_namespace, 0);

      /*
       * MIDL allows shadowing types that are declared in imported files.
       * We don't throw an error in this case and instead add a new type
       * (which is earlier on the list in hash table, so it will be used
       * instead of shadowed type).
       *
       * FIXME: We may consider string separated type tables for each input
       *        for cleaner solution.
       */
      if (cur && input_name == cur->loc_info.input_name)
          error_loc("%s: redefinition error; original definition was at %s:%d\n",
                    cur->name, cur->loc_info.input_name,
                    cur->loc_info.line_number);

      name = declare_var(attrs, decl_spec, decl, 0);
      cur = type_new_alias(&name->declspec, name->name);
      cur->attrs = attrs;

      reg_type(cur, cur->name, current_namespace, 0);
    }
  }
  return type;
}

type_t *find_type(const char *name, struct namespace *namespace, int t)
{
  struct rtype *cur;

  if(namespace && namespace != &global_namespace) {
    for(cur = namespace->type_hash[hash_ident(name)]; cur; cur = cur->next) {
      if(cur->t == t && !strcmp(cur->name, name))
        return cur->type;
    }
  }
  for(cur = global_namespace.type_hash[hash_ident(name)]; cur; cur = cur->next) {
    if(cur->t == t && !strcmp(cur->name, name))
      return cur->type;
  }
  return NULL;
}

static type_t *get_qualified_type(enum type_type type_type, char *name, int t)
{
    type_t *type = get_type(type_type, name, lookup_namespace, t);
    lookup_namespace = &global_namespace;
    return type;
}

static type_t *find_qualified_type_or_error(const char *name, int t)
{
    type_t *type;
    if (!(type = find_type(name, lookup_namespace, t)))
    {
        error_loc("type '%s' not found\n", name);
        return NULL;
    }
    lookup_namespace = &global_namespace;
    return type;
}

static type_t *find_type_or_error(const char *name, int t)
{
    type_t *type;
    if (!(type = find_type(name, current_namespace, t)) &&
        !(type = find_type(name, parameters_namespace, t)))
    {
        error_loc("type '%s' not found\n", name);
        return NULL;
    }
    return type;
}

static type_t *find_type_or_error2(char *name, int t)
{
  type_t *tp = find_type_or_error(name, t);
  free(name);
  return tp;
}

int is_type(const char *name)
{
    if (lookup_namespace != &global_namespace)
        return find_type(name, lookup_namespace, 0) != NULL;
    else
        return find_type(name, current_namespace, 0) != NULL ||
               find_type(name, parameters_namespace, 0) != NULL;
}

int is_namespace(const char *name)
{
    if (!winrt_mode) return 0;
    return find_sub_namespace(lookup_namespace, name) != NULL;
}

type_t *get_type(enum type_type type, char *name, struct namespace *namespace, int t)
{
  type_t *tp;
  if (!namespace)
    namespace = &global_namespace;
  if (name) {
    tp = find_type(name, namespace, t);
    if (tp) {
      free(name);
      return tp;
    }
  }
  tp = make_type(type);
  tp->name = name;
  tp->namespace = namespace;
  if (!name) return tp;
  return reg_type(tp, name, namespace, t);
}

/***** constant repository *****/

struct rconst {
  char *name;
  var_t *var;
  struct rconst *next;
};

struct rconst *const_hash[HASHMAX];

static var_t *reg_const(var_t *var)
{
  struct rconst *nc;
  int hash;
  if (!var->name) {
    error_loc("registering constant without name\n");
    return var;
  }
  hash = hash_ident(var->name);
  nc = xmalloc(sizeof(struct rconst));
  nc->name = var->name;
  nc->var = var;
  nc->next = const_hash[hash];
  const_hash[hash] = nc;
  return var;
}

var_t *find_const(const char *name, int f)
{
  struct rconst *cur = const_hash[hash_ident(name)];
  while (cur && strcmp(cur->name, name))
    cur = cur->next;
  if (!cur) {
    if (f) error_loc("constant '%s' not found\n", name);
    return NULL;
  }
  return cur->var;
}

char *gen_name(void)
{
  static unsigned long n = 0;
  static const char *file_id;

  if (! file_id)
  {
    char *dst = dup_basename(input_idl_name, ".idl");
    file_id = dst;

    for (; *dst; ++dst)
      if (! isalnum((unsigned char) *dst))
        *dst = '_';
  }
  return strmake("__WIDL_%s_generated_name_%08lX", file_id, n++);
}

struct allowed_attr
{
    unsigned int dce_compatible : 1;
    unsigned int acf : 1;
    unsigned int multiple : 1;

    unsigned int on_interface : 1;
    unsigned int on_function : 1;
    unsigned int on_arg : 1;
    unsigned int on_type : 1;
    unsigned int on_enum : 1;
    unsigned int on_enum_member : 1;
    unsigned int on_struct : 2;
    unsigned int on_union : 1;
    unsigned int on_field : 1;
    unsigned int on_library : 1;
    unsigned int on_dispinterface : 1;
    unsigned int on_module : 1;
    unsigned int on_coclass : 1;
    unsigned int on_apicontract : 1;
    unsigned int on_runtimeclass : 1;
    const char *display_name;
};

struct allowed_attr allowed_attr[] =
{
    /* attr                        { D ACF M   I Fn ARG T En Enm St Un Fi L  DI M  C AC  R  <display name> } */
    /* ATTR_ACTIVATABLE */         { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "activatable" },
    /* ATTR_AGGREGATABLE */        { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "aggregatable" },
    /* ATTR_ALLOCATE */            { 0, 1, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "allocate" },
    /* ATTR_ANNOTATION */          { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "annotation" },
    /* ATTR_APPOBJECT */           { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "appobject" },
    /* ATTR_ASYNC */               { 0, 1, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "async" },
    /* ATTR_ASYNCUUID */           { 1, 0, 0,  1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "async_uuid" },
    /* ATTR_AUTO_HANDLE */         { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "auto_handle" },
    /* ATTR_BINDABLE */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "bindable" },
    /* ATTR_BROADCAST */           { 1, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "broadcast" },
    /* ATTR_CALLAS */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "call_as" },
    /* ATTR_CALLCONV */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_CASE */                { 1, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "case" },
    /* ATTR_CODE */                { 0, 1, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "code" },
    /* ATTR_COMMSTATUS */          { 0, 0, 0,  0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "comm_status" },
    /* ATTR_CONTEXTHANDLE */       { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "context_handle" },
    /* ATTR_CONTRACT */            { 0, 0, 0,  1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, "contract" },
    /* ATTR_CONTRACTVERSION */     { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, "contractversion" },
    /* ATTR_CONTROL */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, "control" },
    /* ATTR_CUSTOM */              { 0, 0, 1,  1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, "custom" },
    /* ATTR_DECODE */              { 0, 0, 0,  1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "decode" },
    /* ATTR_DEFAULT */             { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, "default" },
    /* ATTR_DEFAULTBIND */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultbind" },
    /* ATTR_DEFAULTCOLLELEM */     { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultcollelem" },
    /* ATTR_DEFAULTVALUE */        { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "defaultvalue" },
    /* ATTR_DEFAULTVTABLE */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "defaultvtable" },
 /* ATTR_DISABLECONSISTENCYCHECK */{ 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "disable_consistency_check" },
    /* ATTR_DISPINTERFACE */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, NULL },
    /* ATTR_DISPLAYBIND */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "displaybind" },
    /* ATTR_DLLNAME */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, "dllname" },
    /* ATTR_DUAL */                { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "dual" },
    /* ATTR_ENABLEALLOCATE */      { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "enable_allocate" },
    /* ATTR_ENCODE */              { 0, 0, 0,  1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "encode" },
    /* ATTR_ENDPOINT */            { 1, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "endpoint" },
    /* ATTR_ENTRY */               { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "entry" },
    /* ATTR_EVENTADD */            { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "eventadd" },
    /* ATTR_EVENTREMOVE */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "eventremove" },
    /* ATTR_EXCLUSIVETO */         { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "exclusive_to" },
    /* ATTR_EXPLICIT_HANDLE */     { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "explicit_handle" },
    /* ATTR_FAULTSTATUS */         { 0, 0, 0,  0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "fault_status" },
    /* ATTR_FLAGS */               { 0, 0, 0,  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "flags" },
    /* ATTR_FORCEALLOCATE */       { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "force_allocate" },
    /* ATTR_HANDLE */              { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "handle" },
    /* ATTR_HELPCONTEXT */         { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "helpcontext" },
    /* ATTR_HELPFILE */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "helpfile" },
    /* ATTR_HELPSTRING */          { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "helpstring" },
    /* ATTR_HELPSTRINGCONTEXT */   { 0, 0, 0,  1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, "helpstringcontext" },
    /* ATTR_HELPSTRINGDLL */       { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "helpstringdll" },
    /* ATTR_HIDDEN */              { 0, 0, 0,  1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, "hidden" },
    /* ATTR_ID */                  { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, "id" },
    /* ATTR_IDEMPOTENT */          { 1, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "idempotent" },
    /* ATTR_IGNORE */              { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "ignore" },
    /* ATTR_IIDIS */               { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "iid_is" },
    /* ATTR_IMMEDIATEBIND */       { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "immediatebind" },
    /* ATTR_IMPLICIT_HANDLE */     { 1, 1, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "implicit_handle" },
    /* ATTR_IN */                  { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "in" },
    /* ATTR_INPUTSYNC */           { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "inputsync" },
    /* ATTR_LENGTHIS */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "length_is" },
    /* ATTR_LIBLCID */             { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, "lcid" },
    /* ATTR_LICENSED */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "licensed" },
    /* ATTR_LOCAL */               { 1, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "local" },
    /* ATTR_MARSHALING_BEHAVIOR */ { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "marshaling_behavior" },
    /* ATTR_MAYBE */               { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "maybe" },
    /* ATTR_MESSAGE */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "message" },
    /* ATTR_NOCODE */              { 0, 1, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nocode" },
    /* ATTR_NONBROWSABLE */        { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonbrowsable" },
    /* ATTR_NONCREATABLE */        { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "noncreatable" },
    /* ATTR_NONEXTENSIBLE */       { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "nonextensible" },
    /* ATTR_NOTIFY */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify" },
    /* ATTR_NOTIFYFLAG */          { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "notify_flag" },
    /* ATTR_OBJECT */              { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "object" },
    /* ATTR_ODL */                 { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "odl" },
    /* ATTR_OLEAUTOMATION */       { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "oleautomation" },
    /* ATTR_OPTIMIZE */            { 0, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optimize" },
    /* ATTR_OPTIONAL */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "optional" },
    /* ATTR_OUT */                 { 1, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "out" },
    /* ATTR_PARAMLCID */           { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "lcid" },
    /* ATTR_PARTIALIGNORE */       { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "partial_ignore" },
    /* ATTR_POINTERDEFAULT */      { 1, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "pointer_default" },
    /* ATTR_POINTERTYPE */         { 1, 0, 0,  0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "ref, unique or ptr" },
    /* ATTR_PROGID */              { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "progid" },
    /* ATTR_PROPGET */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propget" },
    /* ATTR_PROPPUT */             { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propput" },
    /* ATTR_PROPPUTREF */          { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "propputref" },
    /* ATTR_PROXY */               { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "proxy" },
    /* ATTR_PUBLIC */              { 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "public" },
    /* ATTR_RANGE */               { 0, 0, 0,  0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "range" },
    /* ATTR_READONLY */            { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "readonly" },
    /* ATTR_REPRESENTAS */         { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "represent_as" },
    /* ATTR_REQUESTEDIT */         { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "requestedit" },
    /* ATTR_RESTRICTED */          { 0, 0, 0,  1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, "restricted" },
    /* ATTR_RETVAL */              { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "retval" },
    /* ATTR_SIZEIS */              { 0, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "size_is" },
    /* ATTR_SOURCE */              { 0, 0, 0,  1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, "source" },
    /* ATTR_STATIC */              { 0, 0, 1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, "static" },
    /* ATTR_STRICTCONTEXTHANDLE */ { 0, 0, 0,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "strict_context_handle" },
    /* ATTR_STRING */              { 1, 0, 0,  0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "string" },
    /* ATTR_SWITCHIS */            { 1, 0, 0,  0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "switch_is" },
    /* ATTR_SWITCHTYPE */          { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, "switch_type" },
    /* ATTR_THREADING */           { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, "threading" },
    /* ATTR_TRANSMITAS */          { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "transmit_as" },
    /* ATTR_UIDEFAULT */           { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "uidefault" },
    /* ATTR_USESGETLASTERROR */    { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "usesgetlasterror" },
    /* ATTR_USERMARSHAL */         { 0, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "user_marshal" },
    /* ATTR_UUID */                { 1, 0, 0,  1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, "uuid" },
    /* ATTR_V1ENUM */              { 0, 0, 0,  0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "v1_enum" },
    /* ATTR_VARARG */              { 0, 0, 0,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "vararg" },
    /* ATTR_VERSION */             { 1, 0, 0,  1, 0, 0, 1, 1, 0, 2, 0, 0, 1, 0, 0, 1, 0, 1, "version" },
    /* ATTR_VIPROGID */            { 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, "vi_progid" },
    /* ATTR_WIREMARSHAL */         { 1, 0, 0,  0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, "wire_marshal" },
};

static attr_list_t *append_attr(attr_list_t *list, attr_t *attr)
{
    attr_t *attr_existing;
    if (!attr) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    if (!allowed_attr[attr->type].multiple)
    {
        LIST_FOR_EACH_ENTRY(attr_existing, list, attr_t, entry)
            if (attr_existing->type == attr->type)
            {
                parser_warning("duplicate attribute %s\n", get_attr_display_name(attr->type));
                /* use the last attribute, like MIDL does */
                list_remove(&attr_existing->entry);
                break;
            }
    }
    list_add_tail( list, &attr->entry );
    return list;
}

const char *get_attr_display_name(enum attr_type type)
{
    return allowed_attr[type].display_name;
}

static attr_list_t *check_iface_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_interface)
      error_loc("inapplicable attribute %s for interface %s\n",
                allowed_attr[attr->type].display_name, name);
    if (attr->type == ATTR_IMPLICIT_HANDLE)
    {
        const var_t *var = attr->u.pval;
        if (type_get_type( var->declspec.type) == TYPE_BASIC &&
            type_basic_get_type( var->declspec.type ) == TYPE_BASIC_HANDLE)
            continue;
        if (is_aliaschain_attr( var->declspec.type, ATTR_HANDLE ))
            continue;
      error_loc("attribute %s requires a handle type in interface %s\n",
                allowed_attr[attr->type].display_name, name);
    }
  }
  return attrs;
}

static attr_list_t *check_function_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_function)
      error_loc("inapplicable attribute %s for function %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static void check_arg_attrs(const var_t *arg)
{
  const attr_t *attr;

  if (arg->attrs)
  {
    LIST_FOR_EACH_ENTRY(attr, arg->attrs, const attr_t, entry)
    {
      if (!allowed_attr[attr->type].on_arg)
        error_loc("inapplicable attribute %s for argument %s\n",
                  allowed_attr[attr->type].display_name, arg->name);
    }
  }
}

static attr_list_t *check_typedef_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_type)
      error_loc("inapplicable attribute %s for typedef\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_enum_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_enum)
      error_loc("inapplicable attribute %s for enum\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_enum_member_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_enum_member)
      error_loc("inapplicable attribute %s for enum member\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_struct_attrs(attr_list_t *attrs)
{
  int mask = winrt_mode ? 3 : 1;
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!(allowed_attr[attr->type].on_struct & mask))
      error_loc("inapplicable attribute %s for struct\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_union_attrs(attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_union)
      error_loc("inapplicable attribute %s for union\n",
                allowed_attr[attr->type].display_name);
  }
  return attrs;
}

static attr_list_t *check_field_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_field)
      error_loc("inapplicable attribute %s for field %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static attr_list_t *check_library_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_library)
      error_loc("inapplicable attribute %s for library %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static attr_list_t *check_dispiface_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_dispinterface)
      error_loc("inapplicable attribute %s for dispinterface %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static attr_list_t *check_module_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_module)
      error_loc("inapplicable attribute %s for module %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static attr_list_t *check_coclass_attrs(const char *name, attr_list_t *attrs)
{
  const attr_t *attr;
  if (!attrs) return attrs;
  LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
  {
    if (!allowed_attr[attr->type].on_coclass)
      error_loc("inapplicable attribute %s for coclass %s\n",
                allowed_attr[attr->type].display_name, name);
  }
  return attrs;
}

static attr_list_t *check_runtimeclass_attrs(const char *name, attr_list_t *attrs)
{
    const attr_t *attr;
    if (!attrs) return attrs;
    LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
        if (!allowed_attr[attr->type].on_runtimeclass)
            error_loc("inapplicable attribute %s for runtimeclass %s\n",
                      allowed_attr[attr->type].display_name, name);
    return attrs;
}

static attr_list_t *check_apicontract_attrs(const char *name, attr_list_t *attrs)
{
    const attr_t *attr;
    if (!attrs) return attrs;
    LIST_FOR_EACH_ENTRY(attr, attrs, const attr_t, entry)
        if (!allowed_attr[attr->type].on_apicontract)
            error_loc("inapplicable attribute %s for apicontract %s\n",
                      allowed_attr[attr->type].display_name, name);
    return attrs;
}

static int is_allowed_conf_type(const type_t *type)
{
    switch (type_get_type(type))
    {
    case TYPE_ENUM:
        return TRUE;
    case TYPE_BASIC:
        switch (type_basic_get_type(type))
        {
        case TYPE_BASIC_INT8:
        case TYPE_BASIC_INT16:
        case TYPE_BASIC_INT32:
        case TYPE_BASIC_INT64:
        case TYPE_BASIC_INT:
        case TYPE_BASIC_LONG:
        case TYPE_BASIC_CHAR:
        case TYPE_BASIC_HYPER:
        case TYPE_BASIC_BYTE:
        case TYPE_BASIC_WCHAR:
            return TRUE;
        default:
            return FALSE;
        }
    case TYPE_ALIAS:
        /* shouldn't get here because of type_get_type call above */
        assert(0);
        /* fall through */
    case TYPE_STRUCT:
    case TYPE_UNION:
    case TYPE_ENCAPSULATED_UNION:
    case TYPE_ARRAY:
    case TYPE_POINTER:
    case TYPE_VOID:
    case TYPE_MODULE:
    case TYPE_COCLASS:
    case TYPE_FUNCTION:
    case TYPE_INTERFACE:
    case TYPE_BITFIELD:
    case TYPE_RUNTIMECLASS:
    case TYPE_DELEGATE:
        return FALSE;
    case TYPE_APICONTRACT:
    case TYPE_PARAMETERIZED_TYPE:
    case TYPE_PARAMETER:
        /* not supposed to be here */
        assert(0);
        break;
    }
    return FALSE;
}

static int is_ptr_guid_type(const type_t *type)
{
    /* first, make sure it is a pointer to something */
    if (!is_ptr(type)) return FALSE;

    /* second, make sure it is a pointer to something of size sizeof(GUID),
     * i.e. 16 bytes */
    return (type_memsize(type_pointer_get_ref_type(type)) == 16);
}

static void check_conformance_expr_list(const char *attr_name, const var_t *arg, const type_t *container_type, expr_list_t *expr_list)
{
    expr_t *dim;
    struct expr_loc expr_loc;
    expr_loc.v = arg;
    expr_loc.attr = attr_name;
    if (expr_list) LIST_FOR_EACH_ENTRY(dim, expr_list, expr_t, entry)
    {
        if (dim->type != EXPR_VOID)
        {
            const type_t *expr_type = expr_resolve_type(&expr_loc, container_type, dim);
            if (!is_allowed_conf_type(expr_type))
                error_loc_info(&arg->loc_info, "expression must resolve to integral type <= 32bits for attribute %s\n",
                               attr_name);
        }
    }
}

static void check_remoting_fields(const var_t *var, type_t *type);

/* checks that properties common to fields and arguments are consistent */
static void check_field_common(const type_t *container_type,
                               const char *container_name, const var_t *arg)
{
    type_t *type = arg->declspec.type;
    int more_to_do;
    const char *container_type_name;
    const char *var_type;

    switch (type_get_type(container_type))
    {
    case TYPE_STRUCT:
        container_type_name = "struct";
        var_type = "field";
        break;
    case TYPE_UNION:
        container_type_name = "union";
        var_type = "arm";
        break;
    case TYPE_ENCAPSULATED_UNION:
        container_type_name = "encapsulated union";
        var_type = "arm";
        break;
    case TYPE_FUNCTION:
        container_type_name = "function";
        var_type = "parameter";
        break;
    default:
        /* should be no other container types */
        assert(0);
        return;
    }

    if (is_attr(arg->attrs, ATTR_LENGTHIS) &&
        (is_attr(arg->attrs, ATTR_STRING) || is_aliaschain_attr(arg->declspec.type, ATTR_STRING)))
        error_loc_info(&arg->loc_info,
                       "string and length_is specified for argument %s are mutually exclusive attributes\n",
                       arg->name);

    if (is_attr(arg->attrs, ATTR_SIZEIS))
    {
        expr_list_t *size_is_exprs = get_attrp(arg->attrs, ATTR_SIZEIS);
        check_conformance_expr_list("size_is", arg, container_type, size_is_exprs);
    }
    if (is_attr(arg->attrs, ATTR_LENGTHIS))
    {
        expr_list_t *length_is_exprs = get_attrp(arg->attrs, ATTR_LENGTHIS);
        check_conformance_expr_list("length_is", arg, container_type, length_is_exprs);
    }
    if (is_attr(arg->attrs, ATTR_IIDIS))
    {
        struct expr_loc expr_loc;
        expr_t *expr = get_attrp(arg->attrs, ATTR_IIDIS);
        if (expr->type != EXPR_VOID)
        {
            const type_t *expr_type;
            expr_loc.v = arg;
            expr_loc.attr = "iid_is";
            expr_type = expr_resolve_type(&expr_loc, container_type, expr);
            if (!expr_type || !is_ptr_guid_type(expr_type))
                error_loc_info(&arg->loc_info, "expression must resolve to pointer to GUID type for attribute iid_is\n");
        }
    }
    if (is_attr(arg->attrs, ATTR_SWITCHIS))
    {
        struct expr_loc expr_loc;
        expr_t *expr = get_attrp(arg->attrs, ATTR_SWITCHIS);
        if (expr->type != EXPR_VOID)
        {
            const type_t *expr_type;
            expr_loc.v = arg;
            expr_loc.attr = "switch_is";
            expr_type = expr_resolve_type(&expr_loc, container_type, expr);
            if (!expr_type || !is_allowed_conf_type(expr_type))
                error_loc_info(&arg->loc_info, "expression must resolve to integral type <= 32bits for attribute %s\n",
                               expr_loc.attr);
        }
    }

    do
    {
        more_to_do = FALSE;

        switch (typegen_detect_type(type, arg->attrs, TDT_IGNORE_STRINGS))
        {
        case TGT_STRUCT:
        case TGT_UNION:
            check_remoting_fields(arg, type);
            break;
        case TGT_INVALID:
        {
            const char *reason = "is invalid";
            switch (type_get_type(type))
            {
            case TYPE_VOID:
                reason = "cannot derive from void *";
                break;
            case TYPE_FUNCTION:
                reason = "cannot be a function pointer";
                break;
            case TYPE_BITFIELD:
                reason = "cannot be a bit-field";
                break;
            case TYPE_COCLASS:
                reason = "cannot be a class";
                break;
            case TYPE_INTERFACE:
                reason = "cannot be a non-pointer to an interface";
                break;
            case TYPE_MODULE:
                reason = "cannot be a module";
                break;
            default:
                break;
            }
            error_loc_info(&arg->loc_info, "%s \'%s\' of %s \'%s\' %s\n",
                           var_type, arg->name, container_type_name, container_name, reason);
            break;
        }
        case TGT_CTXT_HANDLE:
        case TGT_CTXT_HANDLE_POINTER:
            if (type_get_type(container_type) != TYPE_FUNCTION)
                error_loc_info(&arg->loc_info,
                               "%s \'%s\' of %s \'%s\' cannot be a context handle\n",
                               var_type, arg->name, container_type_name,
                               container_name);
            break;
        case TGT_STRING:
        {
            const type_t *t = type;
            while (is_ptr(t))
                t = type_pointer_get_ref_type(t);
            if (is_aliaschain_attr(t, ATTR_RANGE))
                warning_loc_info(&arg->loc_info, "%s: range not verified for a string of ranged types\n", arg->name);
            break;
        }
        case TGT_POINTER:
            type = type_pointer_get_ref_type(type);
            more_to_do = TRUE;
            break;
        case TGT_ARRAY:
            type = type_array_get_element_type(type);
            more_to_do = TRUE;
            break;
        case TGT_ENUM:
            type = type_get_real_type(type);
            if (!type_is_complete(type))
            {
                error_loc_info(&arg->loc_info, "undefined type declaration \"enum %s\"\n", type->name);
            }
        case TGT_USER_TYPE:
        case TGT_IFACE_POINTER:
        case TGT_BASIC:
        case TGT_RANGE:
            /* nothing to do */
            break;
        }
    } while (more_to_do);
}

static void check_remoting_fields(const var_t *var, type_t *type)
{
    const var_t *field;
    const var_list_t *fields = NULL;

    type = type_get_real_type(type);

    if (type->checked)
        return;

    type->checked = TRUE;

    if (type_get_type(type) == TYPE_STRUCT)
    {
        if (type_is_complete(type))
            fields = type_struct_get_fields(type);
        else
            error_loc_info(&var->loc_info, "undefined type declaration \"struct %s\"\n", type->name);
    }
    else if (type_get_type(type) == TYPE_UNION || type_get_type(type) == TYPE_ENCAPSULATED_UNION)
    {
        if (type_is_complete(type))
            fields = type_union_get_cases(type);
        else
            error_loc_info(&var->loc_info, "undefined type declaration \"union %s\"\n", type->name);
    }

    if (fields) LIST_FOR_EACH_ENTRY( field, fields, const var_t, entry )
        if (field->declspec.type) check_field_common(type, type->name, field);
}

/* checks that arguments for a function make sense for marshalling and unmarshalling */
static void check_remoting_args(const var_t *func)
{
    const char *funcname = func->name;
    const var_t *arg;

    if (!type_function_get_args(func->declspec.type))
        return;

    LIST_FOR_EACH_ENTRY( arg, type_function_get_args(func->declspec.type), const var_t, entry )
    {
        const type_t *type = arg->declspec.type;

        /* check that [out] parameters have enough pointer levels */
        if (is_attr(arg->attrs, ATTR_OUT))
        {
            switch (typegen_detect_type(type, arg->attrs, TDT_ALL_TYPES))
            {
            case TGT_BASIC:
            case TGT_ENUM:
            case TGT_RANGE:
            case TGT_STRUCT:
            case TGT_UNION:
            case TGT_CTXT_HANDLE:
            case TGT_USER_TYPE:
                error_loc_info(&arg->loc_info, "out parameter \'%s\' of function \'%s\' is not a pointer\n", arg->name, funcname);
                break;
            case TGT_IFACE_POINTER:
                error_loc_info(&arg->loc_info, "out interface pointer \'%s\' of function \'%s\' is not a double pointer\n", arg->name, funcname);
                break;
            case TGT_STRING:
                if (is_array(type))
                {
                    /* needs conformance or fixed dimension */
                    if (type_array_has_conformance(type) &&
                        type_array_get_conformance(type)->type != EXPR_VOID) break;
                    if (!type_array_has_conformance(type) && type_array_get_dim(type)) break;
                }
                if (is_attr( arg->attrs, ATTR_IN )) break;
                error_loc_info(&arg->loc_info, "out parameter \'%s\' of function \'%s\' cannot be an unsized string\n", arg->name, funcname);
                break;
            case TGT_INVALID:
                /* already error'd before we get here */
            case TGT_CTXT_HANDLE_POINTER:
            case TGT_POINTER:
            case TGT_ARRAY:
                /* OK */
                break;
            }
        }

        check_field_common(func->declspec.type, funcname, arg);
    }

    if (type_get_type(type_function_get_rettype(func->declspec.type)) != TYPE_VOID)
    {
        var_t var;
        var = *func;
        var.declspec.type = type_function_get_rettype(func->declspec.type);
        var.name = xstrdup("return value");
        check_field_common(func->declspec.type, funcname, &var);
        free(var.name);
    }
}

static void add_explicit_handle_if_necessary(const type_t *iface, var_t *func)
{
    unsigned char explicit_fc, implicit_fc;

    /* check for a defined binding handle */
    if (!get_func_handle_var( iface, func, &explicit_fc, &implicit_fc ) || !explicit_fc)
    {
        /* no explicit handle specified so add
         * "[in] handle_t IDL_handle" as the first parameter to the
         * function */
        var_t *idl_handle = make_var(xstrdup("IDL_handle"));
        idl_handle->attrs = append_attr(NULL, make_attr(ATTR_IN));
        idl_handle->declspec.type = find_type_or_error("handle_t", 0);
        type_function_add_head_arg(func->declspec.type, idl_handle);
    }
}

static void check_functions(const type_t *iface, int is_inside_library)
{
    const statement_t *stmt;
    /* check for duplicates */
    if (is_attr(iface->attrs, ATTR_DISPINTERFACE))
    {
        var_list_t *methods = type_dispiface_get_methods(iface);
        var_t *func, *func_iter;

        if (methods) LIST_FOR_EACH_ENTRY( func, methods, var_t, entry )
        {
            LIST_FOR_EACH_ENTRY( func_iter, methods, var_t, entry )
            {
                if (func == func_iter) break;
                if (strcmp(func->name, func_iter->name)) continue;
                if (is_attr(func->attrs, ATTR_EVENTADD) != is_attr(func_iter->attrs, ATTR_EVENTADD)) continue;
                if (is_attr(func->attrs, ATTR_EVENTREMOVE) != is_attr(func_iter->attrs, ATTR_EVENTREMOVE)) continue;
                if (is_attr(func->attrs, ATTR_PROPGET) != is_attr(func_iter->attrs, ATTR_PROPGET)) continue;
                if (is_attr(func->attrs, ATTR_PROPPUT) != is_attr(func_iter->attrs, ATTR_PROPPUT)) continue;
                if (is_attr(func->attrs, ATTR_PROPPUTREF) != is_attr(func_iter->attrs, ATTR_PROPPUTREF)) continue;
                error_loc_info(&func->loc_info, "duplicated function \'%s\'\n", func->name);
            }
        }
    }
    if (is_attr(iface->attrs, ATTR_EXPLICIT_HANDLE))
    {
        STATEMENTS_FOR_EACH_FUNC( stmt, type_iface_get_stmts(iface) )
        {
            var_t *func = stmt->u.var;
            add_explicit_handle_if_necessary(iface, func);
        }
    }
    if (!is_inside_library && !is_attr(iface->attrs, ATTR_LOCAL))
    {
        STATEMENTS_FOR_EACH_FUNC( stmt, type_iface_get_stmts(iface) )
        {
            const var_t *func = stmt->u.var;
            if (!is_attr(func->attrs, ATTR_LOCAL))
                check_remoting_args(func);
        }
    }
}

static int async_iface_attrs(attr_list_t *attrs, const attr_t *attr)
{
    switch(attr->type)
    {
    case ATTR_UUID:
        return 0;
    case ATTR_ASYNCUUID:
        append_attr(attrs, make_attrp(ATTR_UUID, attr->u.pval));
        return 0;
    default:
        return 1;
    }
}

static int arg_in_attrs(attr_list_t *attrs, const attr_t *attr)
{
    return attr->type != ATTR_OUT && attr->type != ATTR_RETVAL;
}

static int arg_out_attrs(attr_list_t *attrs, const attr_t *attr)
{
    return attr->type != ATTR_IN;
}

static void check_async_uuid(type_t *iface)
{
    statement_list_t *stmts = NULL;
    statement_t *stmt;
    type_t *async_iface;
    type_t *inherit;

    if (!is_attr(iface->attrs, ATTR_ASYNCUUID)) return;

    inherit = type_iface_get_inherit(iface);
    if (inherit && strcmp(inherit->name, "IUnknown"))
        inherit = type_iface_get_async_iface(inherit);
    if (!inherit)
        error_loc("async_uuid applied to an interface with incompatible parent\n");

    async_iface = get_type(TYPE_INTERFACE, strmake("Async%s", iface->name), iface->namespace, 0);
    async_iface->attrs = map_attrs(iface->attrs, async_iface_attrs);

    STATEMENTS_FOR_EACH_FUNC( stmt, type_iface_get_stmts(iface) )
    {
        var_t *begin_func, *finish_func, *func = stmt->u.var, *arg;
        var_list_t *begin_args = NULL, *finish_args = NULL, *args;

        args = type_function_get_args(func->declspec.type);
        if (args) LIST_FOR_EACH_ENTRY(arg, args, var_t, entry)
        {
            if (is_attr(arg->attrs, ATTR_IN) || !is_attr(arg->attrs, ATTR_OUT))
                begin_args = append_var(begin_args, copy_var(arg, strdup(arg->name), arg_in_attrs));
            if (is_attr(arg->attrs, ATTR_OUT))
                finish_args = append_var(finish_args, copy_var(arg, strdup(arg->name), arg_out_attrs));
        }

        begin_func = copy_var(func, strmake("Begin_%s", func->name), NULL);
        begin_func->declspec.type = type_new_function(begin_args);
        begin_func->declspec.type->attrs = func->attrs;
        begin_func->declspec.type->details.function->retval = func->declspec.type->details.function->retval;
        stmts = append_statement(stmts, make_statement_declaration(begin_func));

        finish_func = copy_var(func, strmake("Finish_%s", func->name), NULL);
        finish_func->declspec.type = type_new_function(finish_args);
        finish_func->declspec.type->attrs = func->attrs;
        finish_func->declspec.type->details.function->retval = func->declspec.type->details.function->retval;
        stmts = append_statement(stmts, make_statement_declaration(finish_func));
    }

    type_interface_define(async_iface, inherit, stmts, NULL);
    iface->details.iface->async_iface = async_iface->details.iface->async_iface = async_iface;
}

static statement_list_t *append_parameterized_type_stmts(statement_list_t *stmts)
{
    statement_t *stmt, *next;
    if (stmts && parameterized_type_stmts) LIST_FOR_EACH_ENTRY_SAFE(stmt, next, parameterized_type_stmts, statement_t, entry)
    {
        switch(stmt->type) {
        case STMT_TYPE:
            stmt->u.type = type_parameterized_type_specialize_define(stmt->u.type_list->type, stmt->u.type_list->next);
            stmt->declonly = FALSE;
            list_remove(&stmt->entry);
            stmts = append_statement(stmts, stmt);
            break;
        default:
            assert(0); /* should not be there */
            break;
        }
    }

    return stmts;
}

static void check_statements(const statement_list_t *stmts, int is_inside_library)
{
    const statement_t *stmt;

    if (stmts) LIST_FOR_EACH_ENTRY(stmt, stmts, const statement_t, entry)
    {
        switch(stmt->type) {
        case STMT_LIBRARY:
            check_statements(stmt->u.lib->stmts, TRUE);
            break;
        case STMT_TYPE:
            switch(type_get_type(stmt->u.type)) {
            case TYPE_INTERFACE:
                check_functions(stmt->u.type, is_inside_library);
                break;
            case TYPE_COCLASS:
                if(winrt_mode)
                    error_loc("coclass is not allowed in Windows Runtime mode\n");
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }
}

static void check_all_user_types(const statement_list_t *stmts)
{
  const statement_t *stmt;
  const var_t *v;

  if (stmts) LIST_FOR_EACH_ENTRY(stmt, stmts, const statement_t, entry)
  {
    if (stmt->type == STMT_LIBRARY)
      check_all_user_types(stmt->u.lib->stmts);
    else if (stmt->type == STMT_TYPE && type_get_type(stmt->u.type) == TYPE_INTERFACE &&
             !is_local(stmt->u.type->attrs))
    {
      const statement_t *stmt_func;
      STATEMENTS_FOR_EACH_FUNC(stmt_func, type_iface_get_stmts(stmt->u.type)) {
        const var_t *func = stmt_func->u.var;
        if (type_function_get_args(func->declspec.type))
          LIST_FOR_EACH_ENTRY( v, type_function_get_args(func->declspec.type), const var_t, entry )
            check_for_additional_prototype_types(v->declspec.type);
        check_for_additional_prototype_types(type_function_get_rettype(func->declspec.type));
      }
    }
  }
}

int is_valid_uuid(const char *s)
{
  int i;

  for (i = 0; i < 36; ++i)
    if (i == 8 || i == 13 || i == 18 || i == 23)
    {
      if (s[i] != '-')
        return FALSE;
    }
    else
      if (!isxdigit(s[i]))
        return FALSE;

  return s[i] == '\0';
}

static statement_t *make_statement(enum statement_type type)
{
    statement_t *stmt = xmalloc(sizeof(*stmt));
    stmt->type = type;
    return stmt;
}

static statement_t *make_statement_type_decl(type_t *type)
{
    statement_t *stmt = make_statement(STMT_TYPE);
    stmt->u.type = type;
    stmt->declonly = !type->defined;
    return stmt;
}

static statement_t *make_statement_reference(type_t *type)
{
    statement_t *stmt = make_statement(STMT_TYPEREF);
    stmt->u.type = type;
    return stmt;
}

static statement_t *make_statement_declaration(var_t *var)
{
    statement_t *stmt = make_statement(STMT_DECLARATION);
    stmt->u.var = var;
    if (var->declspec.stgclass == STG_EXTERN && var->eval)
        warning("'%s' initialised and declared extern\n", var->name);
    if (is_const_decl(var))
    {
        if (var->eval)
            reg_const(var);
    }
    else if (type_get_type(var->declspec.type) == TYPE_FUNCTION)
        check_function_attrs(var->name, var->attrs);
    else if (var->declspec.stgclass == STG_NONE || var->declspec.stgclass == STG_REGISTER)
        error_loc("instantiation of data is illegal\n");
    return stmt;
}

static statement_t *make_statement_library(typelib_t *typelib)
{
    statement_t *stmt = make_statement(STMT_LIBRARY);
    stmt->u.lib = typelib;
    return stmt;
}

static statement_t *make_statement_pragma(const char *str)
{
    statement_t *stmt = make_statement(STMT_PRAGMA);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_cppquote(const char *str)
{
    statement_t *stmt = make_statement(STMT_CPPQUOTE);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_importlib(const char *str)
{
    statement_t *stmt = make_statement(STMT_IMPORTLIB);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_import(const char *str)
{
    statement_t *stmt = make_statement(STMT_IMPORT);
    stmt->u.str = str;
    return stmt;
}

static statement_t *make_statement_module(type_t *type)
{
    statement_t *stmt = make_statement(STMT_MODULE);
    stmt->u.type = type;
    return stmt;
}

static statement_t *make_statement_typedef(declarator_list_t *decls, int declonly)
{
    declarator_t *decl, *next;
    statement_t *stmt;
    type_list_t **type_list;

    if (!decls) return NULL;

    stmt = make_statement(STMT_TYPEDEF);
    stmt->u.type_list = NULL;
    type_list = &stmt->u.type_list;
    stmt->declonly = declonly;

    LIST_FOR_EACH_ENTRY_SAFE( decl, next, decls, declarator_t, entry )
    {
        var_t *var = decl->var;
        type_t *type = find_type_or_error(var->name, 0);
        *type_list = xmalloc(sizeof(type_list_t));
        (*type_list)->type = type;
        (*type_list)->next = NULL;

        type_list = &(*type_list)->next;
        free(decl);
        free(var);
    }

    return stmt;
}

static statement_t *make_statement_parameterized_type(type_t *type, type_list_t *params)
{
    statement_t *stmt = make_statement(STMT_TYPE);
    stmt->u.type_list = xmalloc(sizeof(type_list_t));
    stmt->u.type_list->type = type;
    stmt->u.type_list->next = params;
    return stmt;
}

static statement_t *make_statement_delegate(type_t *ret, var_list_t *args)
{
    declarator_t *decl = make_declarator(make_var(xstrdup("Invoke")));
    decl_spec_t *spec = make_decl_spec(ret, NULL, NULL, STG_NONE, 0, 0);
    append_chain_type(decl, type_new_function(args), 0);
    return make_statement_declaration(declare_var(NULL, spec, decl, FALSE));
}

static statement_list_t *append_statements(statement_list_t *l1, statement_list_t *l2)
{
    if (!l2) return l1;
    if (!l1 || l1 == l2) return l2;
    list_move_tail (l1, l2);
    return l1;
}

static attr_list_t *append_attribs(attr_list_t *l1, attr_list_t *l2)
{
    if (!l2) return l1;
    if (!l1 || l1 == l2) return l2;
    list_move_tail (l1, l2);
    return l1;
}

static statement_list_t *append_statement(statement_list_t *list, statement_t *stmt)
{
    if (!stmt) return list;
    if (!list)
    {
        list = xmalloc( sizeof(*list) );
        list_init( list );
    }
    list_add_tail( list, &stmt->entry );
    return list;
}

void init_loc_info(loc_info_t *i)
{
    i->input_name = input_name ? input_name : "stdin";
    i->line_number = line_number;
    i->near_text = parser_text;
}

static void check_def(const type_t *t)
{
    if (t->defined)
        error_loc("%s: redefinition error; original definition was at %s:%d\n",
                  t->name, t->loc_info.input_name, t->loc_info.line_number);
}

type_t *find_parameterized_type(type_t *type, type_list_t *params, int t)
{
    char *name = format_parameterized_type_name(type, params);

    if (parameters_namespace)
    {
        assert(type->type_type == TYPE_PARAMETERIZED_TYPE);
        type = type_parameterized_type_specialize_partial(type, params);
    }
    else if ((type = find_type(name, type->namespace, t)))
        assert(type->type_type != TYPE_PARAMETERIZED_TYPE);
    else
        error_loc("parameterized type '%s' not declared\n", name);

    free(name);
    return type;
}

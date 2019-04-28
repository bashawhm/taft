/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     BBEGIN = 259,
     END = 260,
     PROCEDURE = 261,
     FUNCTION = 262,
     IDENT = 263,
     INTEGER = 264,
     REAL = 265,
     ARRAY = 266,
     OF = 267,
     ASSIGNOP = 268,
     RELOP = 269,
     EQ = 270,
     NE = 271,
     LT = 272,
     LE = 273,
     GT = 274,
     GE = 275,
     ADDOP = 276,
     PLUS = 277,
     MINUS = 278,
     OR = 279,
     MULOP = 280,
     STAR = 281,
     SLASH = 282,
     AND = 283,
     NOT = 284,
     DOTDOT = 285,
     ID = 286,
     INUM = 287,
     RNUM = 288,
     VAR = 289,
     IF = 290,
     THEN = 291,
     ELSE = 292,
     WHILE = 293,
     FOR = 294,
     DO = 295,
     ARRAY_ACCESS = 296,
     FUNCTION_CALL = 297,
     PROCEDURE_CALL = 298,
     COMMA = 299,
     SEMICOLON = 300
   };
#endif
/* Tokens.  */
#define PROGRAM 258
#define BBEGIN 259
#define END 260
#define PROCEDURE 261
#define FUNCTION 262
#define IDENT 263
#define INTEGER 264
#define REAL 265
#define ARRAY 266
#define OF 267
#define ASSIGNOP 268
#define RELOP 269
#define EQ 270
#define NE 271
#define LT 272
#define LE 273
#define GT 274
#define GE 275
#define ADDOP 276
#define PLUS 277
#define MINUS 278
#define OR 279
#define MULOP 280
#define STAR 281
#define SLASH 282
#define AND 283
#define NOT 284
#define DOTDOT 285
#define ID 286
#define INUM 287
#define RNUM 288
#define VAR 289
#define IF 290
#define THEN 291
#define ELSE 292
#define WHILE 293
#define FOR 294
#define DO 295
#define ARRAY_ACCESS 296
#define FUNCTION_CALL 297
#define PROCEDURE_CALL 298
#define COMMA 299
#define SEMICOLON 300




/* Copy the first part of user declarations.  */
#line 1 "pc.y"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "scope.h"
#include "core_semantic.h"
#include "codegen.h"
#include "y.tab.h"

extern int yyerror(char*);
extern FILE *yyin;
extern int yylex();
extern int line_num;

scope_t *scope;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 19 "pc.y"
{
    int iVal;    /* INUM */
    float rVal;  /* RNUM */
    int opVal;   /* RELOP ADDOP MULOP */
    char *sVal;  /* ID */

    //Symantics
    tree_t *tVal;
}
/* Line 193 of yacc.c.  */
#line 214 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 227 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  54
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,     2,     2,    50,     2,    49,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    51,    48,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,    16,    18,    22,    29,    30,    32,
      41,    43,    45,    49,    50,    55,    56,    64,    65,    71,
      75,    76,    80,    86,    90,    92,    93,    95,    99,   103,
     105,   107,   112,   119,   124,   133,   135,   140,   142,   147,
     149,   153,   155,   159,   161,   164,   168,   170,   174,   176,
     181,   186,   188,   190,   194
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    -1,     3,    31,    56,    46,    57,    47,
      48,    58,    61,    68,    49,    -1,    31,    -1,    57,    50,
      31,    -1,    58,    34,    57,    51,    59,    48,    -1,    -1,
      60,    -1,    11,    52,    32,    30,    32,    53,    12,    60,
      -1,     9,    -1,    10,    -1,    61,    62,    48,    -1,    -1,
      63,    58,    61,    68,    -1,    -1,     7,    31,    64,    66,
      51,    60,    48,    -1,    -1,     6,    31,    65,    66,    48,
      -1,    46,    67,    47,    -1,    -1,    57,    51,    59,    -1,
      67,    48,    57,    51,    59,    -1,     4,    69,     5,    -1,
      70,    -1,    -1,    71,    -1,    70,    48,    71,    -1,    72,
      13,    75,    -1,    73,    -1,    68,    -1,    35,    75,    36,
      71,    -1,    35,    75,    36,    71,    37,    71,    -1,    38,
      75,    40,    71,    -1,    39,    71,    48,    75,    48,    71,
      40,    71,    -1,    31,    -1,    31,    52,    75,    53,    -1,
      31,    -1,    31,    46,    74,    47,    -1,    75,    -1,    74,
      50,    75,    -1,    76,    -1,    76,    14,    76,    -1,    77,
      -1,    21,    77,    -1,    76,    21,    77,    -1,    78,    -1,
      77,    25,    78,    -1,    31,    -1,    31,    46,    74,    47,
      -1,    31,    52,    75,    53,    -1,    32,    -1,    33,    -1,
      46,    74,    47,    -1,    29,    78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    85,    85,    85,   105,   109,   116,   120,   124,   128,
     135,   136,   140,   141,   145,   149,   149,   161,   161,   165,
     166,   170,   171,   176,   183,   184,   188,   189,   193,   194,
     195,   196,   197,   198,   199,   203,   204,   208,   209,   215,
     216,   220,   221,   225,   226,   227,   231,   232,   236,   237,
     238,   239,   240,   241,   242
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "BBEGIN", "END", "PROCEDURE",
  "FUNCTION", "IDENT", "INTEGER", "REAL", "ARRAY", "OF", "ASSIGNOP",
  "RELOP", "EQ", "NE", "LT", "LE", "GT", "GE", "ADDOP", "PLUS", "MINUS",
  "OR", "MULOP", "STAR", "SLASH", "AND", "NOT", "DOTDOT", "ID", "INUM",
  "RNUM", "VAR", "IF", "THEN", "ELSE", "WHILE", "FOR", "DO",
  "ARRAY_ACCESS", "FUNCTION_CALL", "PROCEDURE_CALL", "COMMA", "SEMICOLON",
  "'('", "')'", "';'", "'.'", "','", "':'", "'['", "']'", "$accept",
  "program", "@1", "identifier_list", "declarations", "type",
  "standard_type", "subprogram_declarations", "subprogram_declaration",
  "subprogram_head", "@2", "@3", "arguments", "parameter_list",
  "compound_statement", "optional_statements", "statement_list",
  "statement", "variable", "procedure_statement", "expression_list",
  "expression", "simple_expression", "term", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    40,    41,    59,    46,
      44,    58,    91,    93
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    56,    55,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    64,    63,    65,    63,    66,
      66,    67,    67,    68,    69,    69,    70,    70,    71,    71,
      71,    71,    71,    71,    71,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    77,    77,    78,    78,
      78,    78,    78,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,    11,     1,     3,     6,     0,     1,     8,
       1,     1,     3,     0,     4,     0,     7,     0,     5,     3,
       0,     3,     5,     3,     1,     0,     1,     3,     3,     1,
       1,     4,     6,     4,     8,     1,     4,     1,     4,     1,
       3,     1,     3,     1,     2,     3,     1,     3,     1,     4,
       4,     1,     1,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     0,     4,     0,     0,
       0,     7,     5,    13,     0,     0,     0,    25,     0,     0,
       0,     7,     0,     0,    37,     0,     0,     0,    30,     0,
      24,    26,     0,    29,    17,    15,    12,    13,     3,    10,
      11,     0,     0,     8,     0,     0,     0,     0,    48,    51,
      52,     0,     0,    41,    43,    46,     0,     0,    23,     0,
       0,    20,    20,     0,     0,     6,     0,    39,     0,    44,
      54,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,    28,     0,     0,     0,    14,     0,    38,     0,    36,
       0,     0,    53,    31,    42,    45,    47,    33,     0,     0,
       0,    18,     0,     0,    40,    49,    50,     0,     0,     0,
      19,     0,     0,     0,    32,     0,    21,     0,    16,     0,
       0,     0,     0,    34,    22,     9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     5,     8,    13,    42,    43,    15,    20,    21,
      62,    61,    83,   100,    28,    29,    30,    31,    32,    33,
      66,    67,    53,    54,    55
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -101
static const yytype_int8 yypact[] =
{
      27,     5,    46,  -101,  -101,     8,    31,  -101,   -15,    29,
      47,  -101,  -101,    45,    31,    20,   -31,     3,    49,    52,
      36,  -101,    37,    60,    -7,   -17,   -17,     3,  -101,    80,
      39,  -101,    75,  -101,  -101,  -101,  -101,    45,  -101,  -101,
    -101,    38,    41,  -101,   -17,   -17,    26,    26,   -29,  -101,
    -101,   -17,    55,     4,    67,  -101,    53,    48,  -101,     3,
     -17,    54,    54,    20,    63,  -101,    -3,  -101,    50,    67,
    -101,   -17,   -17,    13,     3,   -17,    26,    26,     3,   -17,
    -101,  -101,    31,    51,    56,  -101,    68,  -101,   -17,  -101,
      14,    57,  -101,    65,    83,    67,  -101,  -101,    58,     0,
      19,  -101,    64,    69,  -101,  -101,  -101,     3,     3,    60,
    -101,    31,    61,    59,  -101,    71,  -101,    25,  -101,    93,
       3,    60,    64,  -101,  -101,  -101
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -101,  -101,  -101,   -14,    87,  -100,   -94,    76,  -101,  -101,
    -101,  -101,    62,  -101,   -10,  -101,  -101,   -26,  -101,  -101,
     -40,   -23,    40,   -36,   -34
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -36
static const yytype_int8 yytable[] =
{
      16,    57,    52,    56,    46,    22,   -35,    17,   112,   116,
      69,    73,    47,    70,    48,    49,    50,    71,    75,    10,
      23,   124,    68,    72,    17,    76,    18,    19,   125,    51,
       1,    90,     9,    80,    24,    10,     3,    81,    25,    44,
      95,    26,    27,    96,    87,    45,     4,    88,    93,    91,
      10,   109,    97,    85,     6,    47,    98,    48,    49,    50,
      92,   105,     7,    88,    88,   104,   110,   111,    99,    39,
      40,    41,    51,    39,    40,    10,   121,    11,    12,    14,
      34,   114,   115,    35,    36,    58,    38,    59,    60,    65,
      64,    74,    77,    78,   123,    86,    79,   117,   103,   101,
      82,   113,   107,    89,    76,   122,   108,   102,    37,   118,
     106,   120,   119,    63,     0,    94,     0,     0,     0,     0,
       0,     0,     0,     0,    84
};

static const yytype_int8 yycheck[] =
{
      14,    27,    25,    26,    21,    15,    13,     4,   102,   109,
      46,    51,    29,    47,    31,    32,    33,    46,    14,    50,
      51,   121,    45,    52,     4,    21,     6,     7,   122,    46,
       3,    71,    47,    59,    31,    50,    31,    60,    35,    46,
      76,    38,    39,    77,    47,    52,     0,    50,    74,    72,
      50,    51,    78,    63,    46,    29,    79,    31,    32,    33,
      47,    47,    31,    50,    50,    88,    47,    48,    82,     9,
      10,    11,    46,     9,    10,    50,    51,    48,    31,    34,
      31,   107,   108,    31,    48,     5,    49,    48,    13,    48,
      52,    36,    25,    40,   120,    32,    48,   111,    30,    48,
      46,    32,    37,    53,    21,    12,    48,    51,    21,    48,
      53,    40,    53,    37,    -1,    75,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    62
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    55,    31,     0,    56,    46,    31,    57,    47,
      50,    48,    31,    58,    34,    61,    57,     4,     6,     7,
      62,    63,    68,    51,    31,    35,    38,    39,    68,    69,
      70,    71,    72,    73,    31,    31,    48,    58,    49,     9,
      10,    11,    59,    60,    46,    52,    21,    29,    31,    32,
      33,    46,    75,    76,    77,    78,    75,    71,     5,    48,
      13,    65,    64,    61,    52,    48,    74,    75,    75,    77,
      78,    46,    52,    74,    36,    14,    21,    25,    40,    48,
      71,    75,    46,    66,    66,    68,    32,    47,    50,    53,
      74,    75,    47,    71,    76,    77,    78,    71,    75,    57,
      67,    48,    51,    30,    75,    47,    53,    37,    48,    51,
      47,    48,    60,    32,    71,    71,    59,    57,    48,    53,
      40,    51,    12,    71,    59,    60
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 85 "pc.y"
    {
            gen_prelude();
            scope = mkscope();
        }
    break;

  case 3:
#line 93 "pc.y"
    {
            if (strcmp((yyvsp[(2) - (11)].sVal), "main") == 0) {
                gen_func(scope, (yyvsp[(10) - (11)].tVal), "main1");
                gen_tail("main1");
            } else {
                gen_func(scope, (yyvsp[(10) - (11)].tVal), (yyvsp[(2) - (11)].sVal));
                gen_tail((yyvsp[(2) - (11)].sVal));
            }
        }
    break;

  case 4:
#line 106 "pc.y"
    {
            (yyval.tVal) = mkid(scope_insert(scope, (yyvsp[(1) - (1)].sVal)));
        }
    break;

  case 5:
#line 110 "pc.y"
    {
            (yyval.tVal) = mktree(COMMA, (yyvsp[(1) - (3)].tVal), mkid(scope_insert(scope, (yyvsp[(3) - (3)].sVal))));
        }
    break;

  case 6:
#line 117 "pc.y"
    {
            scope_type(scope, (yyvsp[(5) - (6)].tVal));
        }
    break;

  case 8:
#line 125 "pc.y"
    {
            (yyval.tVal) = (yyvsp[(1) - (1)].tVal);
        }
    break;

  case 9:
#line 129 "pc.y"
    {
            (yyval.tVal) = mkarray((yyvsp[(8) - (8)].tVal), (yyvsp[(3) - (8)].iVal), (yyvsp[(5) - (8)].iVal));
        }
    break;

  case 10:
#line 135 "pc.y"
    {/*$$ = mkinum(INUM);*/ (yyval.tVal) = mktree(INUM, NULL, NULL); }
    break;

  case 11:
#line 136 "pc.y"
    {/*$$ = mkrnum(RNUM);*/ (yyval.tVal) = mktree(RNUM, NULL, NULL); }
    break;

  case 14:
#line 145 "pc.y"
    { gen_tag((yyvsp[(1) - (4)].sVal)); gen_tree(scope, (yyvsp[(4) - (4)].tVal)); scope = pop_scope(scope);}
    break;

  case 15:
#line 149 "pc.y"
    {
        /*Insert function name into outer scope*/
        scope_insert_type(scope, (yyvsp[(2) - (2)].sVal), FUNCTION);
        /*Push scope for function arguments*/
        scope = push_scope(scope);
    }
    break;

  case 16:
#line 154 "pc.y"
    {
        /*Type the function*/
        scope_type_function(scope, (yyvsp[(2) - (7)].sVal), (yyvsp[(6) - (7)].tVal)->type);
        /*Add args to function node*/
        tree_to_args(scope_search_all(scope, (yyvsp[(2) - (7)].sVal)), (yyvsp[(4) - (7)].tVal));
        (yyval.sVal) = (yyvsp[(2) - (7)].sVal);
    }
    break;

  case 17:
#line 161 "pc.y"
    { scope_insert_type(scope, (yyvsp[(2) - (2)].sVal), PROCEDURE); scope = push_scope(scope); }
    break;

  case 18:
#line 161 "pc.y"
    {tree_to_args(scope_search_all(scope, (yyvsp[(2) - (5)].sVal)), (yyvsp[(4) - (5)].tVal)); (yyval.sVal) = (yyvsp[(2) - (5)].sVal);}
    break;

  case 19:
#line 165 "pc.y"
    { (yyval.tVal) = (yyvsp[(2) - (3)].tVal); }
    break;

  case 20:
#line 166 "pc.y"
    { (yyval.tVal) = NULL; }
    break;

  case 21:
#line 170 "pc.y"
    { (yyval.tVal) = mktree(COMMA, NULL, (yyvsp[(1) - (3)].tVal)); scope_type(scope, (yyvsp[(3) - (3)].tVal)); }
    break;

  case 22:
#line 171 "pc.y"
    { (yyval.tVal) = mktree(COMMA, (yyvsp[(1) - (5)].tVal), (yyvsp[(3) - (5)].tVal)); scope_type(scope, (yyvsp[(5) - (5)].tVal)); }
    break;

  case 23:
#line 177 "pc.y"
    { 
        (yyval.tVal) = (yyvsp[(2) - (3)].tVal); 
    }
    break;

  case 24:
#line 183 "pc.y"
    { (yyval.tVal) = (yyvsp[(1) - (1)].tVal); }
    break;

  case 25:
#line 184 "pc.y"
    { (yyval.tVal) = NULL; }
    break;

  case 26:
#line 188 "pc.y"
    { (yyval.tVal) = (yyvsp[(1) - (1)].tVal); }
    break;

  case 27:
#line 189 "pc.y"
    { (yyval.tVal) = mktree(SEMICOLON, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal)); }
    break;

  case 28:
#line 193 "pc.y"
    { (yyval.tVal) = mktree(ASSIGNOP, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal)); check_tree_type((yyval.tVal)); }
    break;

  case 29:
#line 194 "pc.y"
    { (yyval.tVal) = (yyvsp[(1) - (1)].tVal); }
    break;

  case 30:
#line 195 "pc.y"
    { (yyval.tVal) = (yyvsp[(1) - (1)].tVal); }
    break;

  case 31:
#line 196 "pc.y"
    { (yyval.tVal) = mktree(IF, (yyvsp[(2) - (4)].tVal), mktree(THEN, (yyvsp[(4) - (4)].tVal), NULL)); check_relop((yyvsp[(2) - (4)].tVal)); }
    break;

  case 32:
#line 197 "pc.y"
    { (yyval.tVal) = mktree(IF, (yyvsp[(2) - (6)].tVal), mktree(THEN, (yyvsp[(4) - (6)].tVal), (yyvsp[(6) - (6)].tVal))); check_relop((yyvsp[(2) - (6)].tVal)); }
    break;

  case 33:
#line 198 "pc.y"
    { (yyval.tVal) = mktree(WHILE, (yyvsp[(2) - (4)].tVal), (yyvsp[(4) - (4)].tVal)); check_relop((yyvsp[(2) - (4)].tVal)); }
    break;

  case 34:
#line 199 "pc.y"
    { (yyval.tVal) = mktree(FOR, mktree(COMMA, (yyvsp[(2) - (8)].tVal), mktree(COMMA, (yyvsp[(4) - (8)].tVal), (yyvsp[(6) - (8)].tVal))), (yyvsp[(8) - (8)].tVal)); check_relop((yyvsp[(4) - (8)].tVal)); }
    break;

  case 35:
#line 203 "pc.y"
    { (yyval.tVal) = mkid(check_scope(scope_search_all(scope, (yyvsp[(1) - (1)].sVal)), (yyvsp[(1) - (1)].sVal))); }
    break;

  case 36:
#line 204 "pc.y"
    { (yyval.tVal) = mktree(ARRAY_ACCESS, mkid(check_scope(scope_search_all(scope, (yyvsp[(1) - (4)].sVal)), (yyvsp[(1) - (4)].sVal))), (yyvsp[(3) - (4)].tVal)); }
    break;

  case 37:
#line 208 "pc.y"
    { (yyval.tVal) = mkid(check_scope(scope_search_all(scope, (yyvsp[(1) - (1)].sVal)), (yyvsp[(1) - (1)].sVal))); }
    break;

  case 38:
#line 209 "pc.y"
    { (yyval.tVal) = mktree(PROCEDURE_CALL, mkid(check_scope(scope_search_all(scope, (yyvsp[(1) - (4)].sVal)), (yyvsp[(1) - (4)].sVal))), (yyvsp[(3) - (4)].tVal)); check_arg_type((yyval.tVal)); }
    break;

  case 39:
#line 215 "pc.y"
    { (yyval.tVal)  = (yyvsp[(1) - (1)].tVal); }
    break;

  case 40:
#line 216 "pc.y"
    { (yyval.tVal) = mktree(COMMA, (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal)); }
    break;

  case 41:
#line 220 "pc.y"
    { (yyval.tVal) = (yyvsp[(1) - (1)].tVal); }
    break;

  case 42:
#line 221 "pc.y"
    { (yyval.tVal) = mkop(RELOP, (yyvsp[(2) - (3)].opVal), (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal)); check_tree_type((yyval.tVal)); }
    break;

  case 43:
#line 225 "pc.y"
    { (yyval.tVal) = (yyvsp[(1) - (1)].tVal); }
    break;

  case 44:
#line 226 "pc.y"
    { (yyval.tVal) = mkop(ADDOP, (yyvsp[(1) - (2)].opVal), (yyvsp[(2) - (2)].tVal), NULL); check_tree_type((yyval.tVal)); }
    break;

  case 45:
#line 227 "pc.y"
    { (yyval.tVal) = mkop(ADDOP, (yyvsp[(2) - (3)].opVal), (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal)); check_tree_type((yyval.tVal)); }
    break;

  case 46:
#line 231 "pc.y"
    { (yyval.tVal) = (yyvsp[(1) - (1)].tVal); }
    break;

  case 47:
#line 232 "pc.y"
    { (yyval.tVal) = mkop(MULOP, (yyvsp[(2) - (3)].opVal), (yyvsp[(1) - (3)].tVal), (yyvsp[(3) - (3)].tVal)); check_tree_type((yyval.tVal)); }
    break;

  case 48:
#line 236 "pc.y"
    { (yyval.tVal) = mkid(check_scope(scope_search_all(scope, (yyvsp[(1) - (1)].sVal)), (yyvsp[(1) - (1)].sVal))); }
    break;

  case 49:
#line 237 "pc.y"
    { (yyval.tVal) = mktree(FUNCTION_CALL, mkid(check_scope(scope_search_all(scope, (yyvsp[(1) - (4)].sVal)), (yyvsp[(1) - (4)].sVal))), (yyvsp[(3) - (4)].tVal)); check_arg_type((yyval.tVal)); }
    break;

  case 50:
#line 238 "pc.y"
    { (yyval.tVal) = mktree(ARRAY_ACCESS, mkid(check_scope(scope_search_all(scope, (yyvsp[(1) - (4)].sVal)), (yyvsp[(1) - (4)].sVal))), (yyvsp[(3) - (4)].tVal)); }
    break;

  case 51:
#line 239 "pc.y"
    { (yyval.tVal) = mkinum((yyvsp[(1) - (1)].iVal)); }
    break;

  case 52:
#line 240 "pc.y"
    { (yyval.tVal) = mkrnum((yyvsp[(1) - (1)].rVal)); }
    break;

  case 53:
#line 241 "pc.y"
    { (yyval.tVal) = (yyvsp[(2) - (3)].tVal); }
    break;

  case 54:
#line 242 "pc.y"
    { (yyval.tVal) = mktree(NOT, (yyvsp[(2) - (2)].tVal), NULL); }
    break;


/* Line 1267 of yacc.c.  */
#line 1814 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 247 "pc.y"


int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        yyin = file;
    }
    yyparse();
    return 0;
}


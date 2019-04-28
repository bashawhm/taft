/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 149 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


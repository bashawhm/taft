%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "base_tree.h"
#include "y.tab.h"

int line_num = 1;
%}

whitespace  [ \t]+
number      [0-9]+
ident       [A-Za-z][A-Za-z0-9]*

%x COMMENT_MODE
%x COMMENT_MODE_SINGLE

%%

"(*"               {/*fprintf(stderr, "[COMMENT]");*/ BEGIN(COMMENT_MODE);}
<COMMENT_MODE>"*)" {/*fprintf(stderr, "[END COMMENT]");*/ BEGIN(INITIAL);}
<COMMENT_MODE>\n   {/*fprintf(stderr, "\n", yytext);*/ line_num++;}
<COMMENT_MODE>.    {/*fprintf(stderr, "%s", yytext);*/ }
"//"               {/*fprintf(stderr, "[COMMENT]");*/ BEGIN(COMMENT_MODE_SINGLE);}
<COMMENT_MODE_SINGLE>\n {BEGIN(INITIAL);}
<COMMENT_MODE_SINGLE>.  {}

{whitespace}       ;

"program"          {/*fprintf(stderr, "[PROGRAM]");*/ return PROGRAM; }
"var"              {/*fprintf(stderr, "[VAR]");*/ return VAR; }
"array"            {/*fprintf(stderr, "[ARRAY]");*/ return ARRAY; }
"of"               {/*fprintf(stderr, "[OF]");*/ return OF; }
"procedure"        {/*fprintf(stderr, "[PROCEDURE]");*/ return PROCEDURE; }
"function"         {/*fprintf(stderr, "[FUNCTION]");*/ return FUNCTION; }
"begin"            {/*fprintf(stderr, "[BEGIN]");*/ return BBEGIN; }
"end"              {/*fprintf(stderr, "[END]");*/ return END; }
"integer"          {/*fprintf(stderr, "[INTEGER]");*/ return INTEGER; }
"real"             {/*fprintf(stderr, "[REAL]");*/ return REAL; }
"if"               {/*fprintf(stderr, "[IF]");*/ return IF; }
"then"             {/*fprintf(stderr, "[THEN]");*/ return THEN; }
"else"             {/*fprintf(stderr, "[ELSE]");*/ return ELSE; }
"while"            {/*fprintf(stderr, "[WHILE]");*/ return WHILE; }
"for"              {/*fprintf(stderr, "[FOR]");*/ return FOR; }
"do"               {/*fprintf(stderr, "[DO]");*/ return DO; }

".."               {/*fprintf(stderr, "[DOTDOT]");*/ return DOTDOT; }

":="               {/*fprintf(stderr, "[ASSIGNOP]");*/ return ASSIGNOP; }

"="                {/*fprintf(stderr, "[RELOP;%d]", yylval.opVal = EQ);*/ yylval.opVal = EQ; return RELOP; }
"<>"               {/*fprintf(stderr, "[RELOP;%d]", yylval.opVal = NE);*/ yylval.opVal = NE; return RELOP; }
"<="               {/*fprintf(stderr, "[RELOP;%d]", yylval.opVal = LE);*/ yylval.opVal = LE; return RELOP; }
">="               {/*fprintf(stderr, "[RELOP;%d]", yylval.opVal = GE);*/ yylval.opVal = GE; return RELOP; }
"<"                {/*fprintf(stderr, "[RELOP;%d]", yylval.opVal = LT);*/ yylval.opVal = LT; return RELOP; }
">"                {/*fprintf(stderr, "[RELOP;%d]", yylval.opVal = GT);*/ yylval.opVal = GT; return RELOP; }

"+"                {/*fprintf(stderr, "[ADDOP;%d]", yylval.opVal = PLUS);*/yylval.opVal = PLUS; return ADDOP; }
"-"                {/*fprintf(stderr, "[ADDOP;%d]", yylval.opVal = MINUS);*/yylval.opVal = MINUS; return ADDOP; }
"or"               {/*fprintf(stderr, "[ADDOP;%d]", yylval.opVal = OR);*/yylval.opVal = OR; return ADDOP; }

"*"                {/*fprintf(stderr, "[MULOP;%d]", yylval.opVal = STAR);*/ yylval.opVal = STAR; return MULOP; }
"/"                {/*fprintf(stderr, "[MULOP;%d]", yylval.opVal = SLASH);*/ yylval.opVal = SLASH; return MULOP; }
"and"              {/*fprintf(stderr, "[MULOP;%d]", yylval.opVal = AND);*/ yylval.opVal = AND; return MULOP; }

"not"              {/*fprintf(stderr, "[NOT]");*/ return NOT; }


{number}            {/*fprintf(stderr, "[INUM;%d]", yylval.iVal = atoi(yytext));*/ yylval.iVal = atoi(yytext);  return INUM; }
{number}"."{number} {/*fprintf(stderr, "[RNUM;%f]", yylval.rVal = atof(yytext));*/ yylval.rVal = atof(yytext); return RNUM; }
{ident}             {/*fprintf(stderr, "[ID;%s]", yytext);*/ yylval.sVal = strdup(yytext); return ID; }

\n                  {/*fprintf(stderr, "\n");*/ line_num++;}
.                   {/*fprintf(stderr, "{%c}", yytext[0]);*/ return yytext[0];}
%%

int yyerror(char *msg) {
    fprintf(stderr, "ERROR ON LINE %d: %s\n", line_num, msg);
    exit(-1);
}

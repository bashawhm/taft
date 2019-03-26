%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "scope.h"
#include "node.h"
#include "y.tab.h"

extern int yyerror(char*);
extern int yylex();

scope_t *scope;
%}

%union {
    int iVal;    /* INUM */
    float rVal;  /* RNUM */
    int opVal;   /* RELOP ADDOP MULOP */
    char *sVal;  /* ID */

    //Symantics
    tree_t *tVal;
}

%token PROGRAM  /* Keyword PROGRAM */
%token BBEGIN
%token END
%token PROCEDURE
%token FUNCTION
%token IDENT
%token INTEGER REAL
%token ARRAY OF

%token ASSIGNOP
%token <opVal> RELOP 
%token EQ NE LT LE GT GE
%token <opVal> ADDOP 
%token PLUS MINUS OR
%token <opVal> MULOP 
%token STAR SLASH AND

%token NOT

%token DOTDOT

%token <sVal> ID
%token <iVal> INUM 
%token <rVal> RNUM
%token VAR
%token IF THEN ELSE WHILE DO

%token ARRAY_ACCESS
%token FUNCTION_CALL
%token PROCEDURE_CALL
%token COMMA
%token SEMICOLON

%type <tVal> factor
%type <tVal> simple_expression
%type <tVal> term
%type <tVal> expression
%type <tVal> expression_list
%type <tVal> variable
%type <tVal> procedure_statement
%type <tVal> statement
%type <tVal> statement_list
%type <tVal> optional_statements
%type <tVal> compound_statement
%type <tVal> identifier_list

%%

program: 
        PROGRAM ID {
            scope = mkscope();
        } '(' identifier_list ')' ';'
        declarations
        subprogram_declarations
        compound_statement
        '.'
    ;

identifier_list
    : ID
        {
            $$ = mkid(scope_insert(scope, $1));
        }
    | identifier_list ',' ID
        {
            $$ = mktree(COMMA, $1, mkid(scope_insert(scope, $3)));
        }
    ;

declarations
    : declarations VAR identifier_list ':' type ';'
        {
            /* update_type_info($3, $5);*/
        }
    | /* empty */ 
    ;

type
    : standard_type
        {
            /*$$ = NULL;*/
        }
    | ARRAY '[' INUM DOTDOT INUM ']' OF standard_type
        {
            /*$$ = NULL;*/
        }
    ;

standard_type
    : INTEGER
    | REAL
    ;

subprogram_declarations
    : subprogram_declarations subprogram_declaration ';'
    | /* Empty */
    ;

subprogram_declaration
    : subprogram_head declarations subprogram_declarations compound_statement
    ;

subprogram_head
    : FUNCTION ID { scope_insert(scope, $2); } arguments ':' standard_type ';'
    | PROCEDURE ID { scope_insert(scope, $2); } arguments ';'
    ;

arguments
    : '(' parameter_list ')'
    | /* Empty */
    ;

parameter_list
    : identifier_list ':' type
    | parameter_list ';' identifier_list ':' type



compound_statement
    : BBEGIN optional_statements END  
    { 
        $$ = $2; 
        fprintf(stderr, "\n\nBEGIN TREE PRINT\n\n");
        tree_print($$);
        fprintf(stderr, "\nEND TREE PRINT\n\n");
    }
    ;

optional_statements
    : statement_list  { $$ = $1; }
    | /* Empty */     { $$ = NULL; }
    ;

statement_list
    : statement  { $$ = $1; }
    | statement_list ';' statement  { $$ = mktree(SEMICOLON, $1, $3); }
    ;

statement
    : variable ASSIGNOP expression  { $$ = mktree(ASSIGNOP, $1, $3); }
    | procedure_statement   { $$ = $1; }
    | compound_statement    { $$ = $1; }
    | IF expression THEN statement  { $$ = mktree(IF, $2, mktree(THEN, $4, NULL)); }
    | IF expression THEN statement ELSE statement  { $$ = mktree(IF, $2, mktree(THEN, $4, $6)); }
    | WHILE expression DO statement  { $$ = mktree(WHILE, $2, $4); }
    ;

variable
    : ID  { $$ = mkid(scope_search(scope, $1)); }
    | ID '[' expression ']'  { $$ = mktree(ARRAY_ACCESS, mkid(scope_search(scope, $1)), $3); }
    ;

procedure_statement
    : ID    { $$ = mkid(scope_search(scope, $1)); }
    | ID '(' expression_list ')' { $$ = mktree(PROCEDURE_CALL, mkid(scope_search(scope, $1)), $3); }
    ;



expression_list
    : expression                     { $$  = $1; }
    | expression_list ',' expression { $$ = mktree(COMMA, $1, $3); }
    ;

expression
    : simple_expression  { $$ = $1; }
    | simple_expression RELOP simple_expression { $$ = mkop(RELOP, $2, $1, $3);}
    ;

simple_expression
    : term                         { $$ = $1; }
    | ADDOP term                   { $$ = mkop(ADDOP, $1, $2, NULL); }
    | simple_expression ADDOP term { $$ = mkop(MULOP, $2, $1, $3);}
    ;

term
    : factor             { $$ = $1; }
    | term MULOP factor  { $$ = mkop(MULOP, $2, $1, $3); }
    ;

factor
    : ID                          { $$ = mkid(scope_search(scope, $1)); }
    | ID '(' expression_list ')'  { $$ = mktree(FUNCTION_CALL, mkid(scope_search(scope, $1)), $3); }
    | ID '[' expression ']'       { $$ = mktree(ARRAY_ACCESS, mkid(scope_search(scope, $1)), $3); }
    | INUM                        { $$ = mkinum($1); }
    | RNUM                        { $$ = mkrnum($1); }
    | '(' expression_list ')'     { $$ = $2; }
    | NOT factor                  { $$ = mktree(NOT, $2, NULL); }
    ;



%%

int main() {
    yyparse();
    return 0;
}

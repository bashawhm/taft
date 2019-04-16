%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "scope.h"
#include "core_semantic.h"
#include "codegen.h"
#include "y.tab.h"

extern int yyerror(char*);
extern int yylex();
extern int line_num;

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
%nonassoc THEN
%nonassoc ELSE

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
%type <tVal> type
%type <tVal> standard_type
%type <tVal> arguments
%type <tVal> parameter_list
%type <sVal> subprogram_head

%%

program: 
        PROGRAM ID {
            gen_prelude();
            scope = mkscope();
        } '(' identifier_list ')' ';'
        declarations
        subprogram_declarations
        compound_statement
        '.'
        {
            if (strcmp($2, "main") == 0) {
                gen_func(scope, $10, "main1");
                gen_tail("main1");
            } else {
                gen_func(scope, $10, $2);
                gen_tail($2);
            }
        }
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
            scope_type(scope, $5);
        }
    | /* empty */ 
    ;

type
    : standard_type
        {
            $$ = $1;
        }
    | ARRAY '[' INUM DOTDOT INUM ']' OF standard_type
        {
            $$ = mkarray($8, $3, $5);
        }
    ;

standard_type
    : INTEGER {/*$$ = mkinum(INUM);*/ $$ = mktree(INUM, NULL, NULL); }
    | REAL    {/*$$ = mkrnum(RNUM);*/ $$ = mktree(RNUM, NULL, NULL); }
    ;

subprogram_declarations
    : subprogram_declarations subprogram_declaration ';'
    | /* Empty */
    ;

subprogram_declaration
    : subprogram_head declarations subprogram_declarations compound_statement { gen_tag($1); gen_tree(scope, $4); scope = pop_scope(scope);}
    ;

subprogram_head
    : FUNCTION ID {
        /*Insert function name into outer scope*/
        scope_insert_type(scope, $2, FUNCTION);
        /*Push scope for function arguments*/
        scope = push_scope(scope);
    } arguments ':' standard_type ';' {
        /*Type the function*/
        scope_type_function(scope, $2, $6->type);
        /*Add args to function node*/
        tree_to_args(scope_search_all(scope, $2), $4);
        $$ = $2;
    }
    | PROCEDURE ID { scope_insert_type(scope, $2, PROCEDURE); scope = push_scope(scope); } arguments ';' {tree_to_args(scope_search_all(scope, $2), $4); $$ = $2;}
    ;

arguments
    : '(' parameter_list ')'  { $$ = $2; }
    | /* Empty */  { $$ = NULL; }
    ;

parameter_list
    : identifier_list ':' type                     { $$ = mktree(COMMA, NULL, $1); scope_type(scope, $3); }
    | parameter_list ';' identifier_list ':' type  { $$ = mktree(COMMA, $1, $3); scope_type(scope, $5); }



compound_statement
    : BBEGIN optional_statements END  
    { 
        $$ = $2; 
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
    : variable ASSIGNOP expression  { $$ = mktree(ASSIGNOP, $1, $3); check_tree_type($$); }
    | procedure_statement   { $$ = $1; }
    | compound_statement    { $$ = $1; }
    | IF expression THEN statement  { $$ = mktree(IF, $2, mktree(THEN, $4, NULL)); }
    | IF expression THEN statement ELSE statement  { $$ = mktree(IF, $2, mktree(THEN, $4, $6)); }
    | WHILE expression DO statement  { $$ = mktree(WHILE, $2, $4); }
    ;

variable
    : ID  { $$ = mkid(check_scope(scope_search_all(scope, $1), $1)); }
    | ID '[' expression ']'  { $$ = mktree(ARRAY_ACCESS, mkid(check_scope(scope_search_all(scope, $1), $1)), $3); }
    ;

procedure_statement
    : ID    { $$ = mkid(check_scope(scope_search_all(scope, $1), $1)); }
    | ID '(' expression_list ')' { $$ = mktree(PROCEDURE_CALL, mkid(check_scope(scope_search_all(scope, $1), $1)), $3); check_arg_type($$); }
    ;



expression_list
    : expression                     { $$  = $1; }
    | expression_list ',' expression { $$ = mktree(COMMA, $1, $3); }
    ;

expression
    : simple_expression  { $$ = $1; }
    | simple_expression RELOP simple_expression { $$ = mkop(RELOP, $2, $1, $3); check_tree_type($$); }
    ;

simple_expression
    : term                         { $$ = $1; }
    | ADDOP term                   { $$ = mkop(ADDOP, $1, $2, NULL); check_tree_type($$); }
    | simple_expression ADDOP term { $$ = mkop(ADDOP, $2, $1, $3); check_tree_type($$); }
    ;

term
    : factor             { $$ = $1; }
    | term MULOP factor  { $$ = mkop(MULOP, $2, $1, $3); check_tree_type($$); }
    ;

factor
    : ID                          { $$ = mkid(check_scope(scope_search_all(scope, $1), $1)); }
    | ID '(' expression_list ')'  { $$ = mktree(FUNCTION_CALL, mkid(check_scope(scope_search_all(scope, $1), $1)), $3); check_arg_type($$); }
    | ID '[' expression ']'       { $$ = mktree(ARRAY_ACCESS, mkid(check_scope(scope_search_all(scope, $1), $1)), $3); }
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

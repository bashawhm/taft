#include <stdio.h>
#include "codegen.h"
#include "base_tree.h"
#include "scope.h"
#include "y.tab.h"

extern int yyerror(char*);

extern FILE *taft_asm;

void gen_prelude() {
    taft_asm = fopen("a.s", "w");
    //Gen stuff (formatting) for write and writeln
}

void gen_tail() {
    fclose(taft_asm);
}

void gen_tag(char *name) {
    fprintf(taft_asm, "%s:\n", name);
}

void gen_offset(scope_t *top) {
    int offset = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        node_t *tmp = top -> table[i];
        if (tmp != NULL) {
            do {
                if (tmp->type == INUM || tmp->type == RNUM) {
                    tmp->offset = offset;
                    offset++;
                }
                tmp = tmp -> next;
            } while (tmp != NULL);
        }
    }
}

void gen_tree(scope_t *top, tree_t *t) {
    //Gen func code by recursing down tree similar to print
    tree_label(t);
    gen_offset(top);
    fprintf(stderr, "\n\n");
    tree_print(t);
    fprintf(stderr, "\n\n");
    scope_print(top);

}

void gen_func(scope_t *top, tree_t *t, char *name) {
    //Gen function tag and call aux
    gen_tag(name);
    gen_tree(top, t);
}

char *get_intel_asm(int op) {
    switch (op) {
    case PLUS:
        return "addl\t";
    case MINUS:
        return "subl\t";
    case STAR:
        return "imull\t";
    case SLASH:
        return "idivl\t";
    case ASSIGNOP:
        return "movl\t";
    case FUNCTION_CALL:
    case PROCEDURE_CALL:
        return "call\t";
    default:
        yyerror("Error in getting intel asm");
    }
    return "ERR: Not supported instruction";
}
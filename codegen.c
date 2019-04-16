#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "codegen.h"
#include "base_tree.h"
#include "scope.h"
#include "core_semantic.h"
#include "y.tab.h"

extern int yyerror(char*);

extern FILE *taft_asm;

reg_stack_t *mkreg_stack(char *reg) {
    reg_stack_t *s = (reg_stack_t*)malloc(sizeof(reg_stack_t));
    s->reg = strdup(reg);
    s->next = NULL;
    return s;
}

void free_reg(reg_stack_t *top) {
    free(top);
}

reg_stack_t *reg_push(reg_stack_t *top, char *name) {
    reg_stack_t *s = mkreg_stack(name);
    s->next = top;
    return s;
}

reg_stack_t *reg_pop(reg_stack_t *top, char **name) {
    reg_stack_t *s = top->next;
    *name = strdup(top->reg);
    free(top->reg);
    free_reg(top);
    return s;
}

reg_stack_t *reg_swap(reg_stack_t *top) {
    assert(top -> next != NULL);
    char *tmp = top->reg;
    top->reg = top->next->reg;
    top->next->reg = tmp;
    return top;
}

void gen_prelude() {
    taft_asm = fopen("a.s", "w");
    fprintf(taft_asm, "\t.globl _main\n");
    //Gen stuff (formatting) for write and writeln as well as read
    fprintf(taft_asm, "str.write.inum:\n\t.asciz \"%%d\"\n");
    fprintf(taft_asm, "str.writeln.inum:\n\t.asciz \"%%d\\n\"\n");

    fprintf(taft_asm, "str.write.rnum:\n\t.asciz \"%%f\"\n");
    fprintf(taft_asm, "str.writeln.rnum:\n\t.asciz \"%%f\\n\"\n");
}

void gen_tail(char *name_main) {
    fprintf(taft_asm, "_main:\n");
    fprintf(taft_asm, "\tcall %s\n", name_main);
    fprintf(taft_asm, "\tpopq %%rbp\n");
    fprintf(taft_asm, "\tretq\n");
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

void gen_func_call(scope_t *top, tree_t *t, reg_stack_t *regs) {
    //Gen args
    // fprintf(taft_asm, "\tmovq %d, %%rsi\n");
    //call func
    if (strcmp(t->left->attribute.nVal->name, "writeln") == 0 && check_tree_type(t->right) == INUM) {
        fprintf(taft_asm, "\tleaq str.writeln.inum(%%rip), %%rdi\n");
        fprintf(taft_asm, "\tcall _printf\n");
        return;
    } else if (strcmp(t->left->attribute.nVal->name, "writeln") == 0 && check_tree_type(t->right) == RNUM) {
        fprintf(taft_asm, "\tleaq str.writeln.rnum(%%rip), %%rdi\n");
        fprintf(taft_asm, "\tcall _printf\n");
        return;
    } else if (strcmp(t->left->attribute.nVal->name, "write") == 0 && check_tree_type(t->right) == INUM) {
        fprintf(taft_asm, "\tleaq str.write.inum(%%rip), %%rdi\n");
        fprintf(taft_asm, "\tcall _printf\n");
        return;
    } else if (strcmp(t->left->attribute.nVal->name, "write") == 0 && check_tree_type(t->right) == RNUM) {
        fprintf(taft_asm, "\tleaq str.write.rnum(%%rip), %%rdi\n");
        fprintf(taft_asm, "\tcall _printf\n");
        return;
    }

    fprintf(taft_asm, "\tcall %s\n", t->left->attribute.nVal->name);
}

//Gen code for expressions
void gen_expr(scope_t *top, tree_t *t, reg_stack_t *regs) {
    if (t == NULL) {

    }
    //If left node (case 0)
    if (t->left == NULL && t->right == NULL && t->label == 1) {
        char *name = (char*)malloc(100*sizeof(char));
        if (t->type == ID) {
            if (t->attribute.nVal->array == ARRAY) {
                return;
            } else {
                if (t->attribute.nVal->offset != -1) {
                    sprintf(name, "-%d(%%rbp),%s", ((t->attribute.nVal->offset+1) * 8), regs->reg);
                } else {
                    sprintf(name, "INVALID OFFSET");
                }
            }
        } else if (t->type == INUM) {
            sprintf(name, "$%d,%s", t->attribute.iVal, regs->reg);
        } else if (t->type == RNUM) {
            sprintf(name, "$%f,%s", t->attribute.rVal, regs->reg);
        } else {
            yyerror("failed to get value");
            exit(-6);
        }
        fprintf(taft_asm, "\tmovq %s\n", name);
    }

    aux_gen_tree(top, t->left, regs);
    aux_gen_tree(top, t->right, regs);
}

//Gen code for statements
void aux_gen_tree(scope_t *top, tree_t *t, reg_stack_t *regs) {
    if (t == NULL) {
        return;
    }
    if (t->type == FUNCTION_CALL || t->type == PROCEDURE_CALL) {
        gen_func_call(top, t, regs);
    }

    aux_gen_tree(top, t->left, regs);
    aux_gen_tree(top, t->right, regs);

}

void gen_tree(scope_t *top, tree_t *t) {
    //Gen func code by recursing down tree similar to print
    tree_label(t);
    gen_offset(top);
    fprintf(stderr, "\n\n");
    tree_print(t);
    fprintf(stderr, "\n\n");
    scope_print(top);
    reg_stack_t *regs = mkreg_stack("rax");
    regs->next = mkreg_stack("rbx");
    regs->next->next = mkreg_stack("rcx");
    regs->next->next->next = mkreg_stack("rdx");
    fprintf(taft_asm, "\tpushq %%rbp\n");
    fprintf(taft_asm, "\tmovq %%rsp, %%rbp\n");
    fprintf(taft_asm, "\tsubq $%d, %%rsp\n", 8*scope_get_size(top));
    aux_gen_tree(top, t, regs);
    fprintf(taft_asm, "\tleave\n");
    fprintf(taft_asm, "\tretq\n");

}

void gen_func(scope_t *top, tree_t *t, char *name) {
    //Gen function tag and call aux
    gen_tag(name);
    gen_tree(top, t);
}

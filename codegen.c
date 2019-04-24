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
    //call func
    if (strcmp(t->left->attribute.nVal->name, "writeln") == 0 && check_tree_type(t->right) == INUM) {
        if (t->right->type == INUM) {
            fprintf(taft_asm, "\tmovl $%d, %%esi\n", t->right->attribute.iVal);
            fprintf(taft_asm, "\tleaq str.writeln.inum(%%rip), %%rdi\n");
            fprintf(taft_asm, "\tpushq %%rax\n");
            fprintf(taft_asm, "\tpushq %%rcx\n");
            fprintf(taft_asm, "\tmovb $0, %%al\n");
            fprintf(taft_asm, "\tcall _printf\n");
            fprintf(taft_asm, "\tpopq %%rcx\n");
            fprintf(taft_asm, "\tpopq %%rax\n");
        } else if (t->right->type == ID) {
            //TODO: Handle variables
            if (t->right->attribute.nVal->type == INUM) {
                fprintf(taft_asm, "\tmovq -%d(%%rbp), %%rsi\n", (t->right->attribute.nVal->offset+1)*8);
                fprintf(taft_asm, "\tleaq str.writeln.inum(%%rip), %%rdi\n");
                fprintf(taft_asm, "\tpushq %%rax\n");
                fprintf(taft_asm, "\tpushq %%rcx\n");
                fprintf(taft_asm, "\tmovb $0, %%al\n");
                fprintf(taft_asm, "\tcall _printf\n");
                fprintf(taft_asm, "\tpopq %%rcx\n");
                fprintf(taft_asm, "\tpopq %%rax\n");
            } else {
                //TODO: support real numbers
            }
        } else {
            gen_expr(top, t->right, regs);
            fprintf(taft_asm, "\tmovq %%%s, %%rsi\n", regs->reg);
            fprintf(taft_asm, "\tleaq str.writeln.inum(%%rip), %%rdi\n");
            fprintf(taft_asm, "\tpushq %%rax\n");
            fprintf(taft_asm, "\tpushq %%rcx\n");
            fprintf(taft_asm, "\tmovb $0, %%al\n");
            fprintf(taft_asm, "\tcall _printf\n");
            fprintf(taft_asm, "\tpopq %%rcx\n");
            fprintf(taft_asm, "\tpopq %%rax\n");
        }
        return;
        
    } else if (strcmp(t->left->attribute.nVal->name, "writeln") == 0 && check_tree_type(t->right) == RNUM) {
        fprintf(taft_asm, "\tleaq str.writeln.rnum(%%rip), %%rdi\n");
        fprintf(taft_asm, "\tcall _printf\n");
        return;
    } else if (strcmp(t->left->attribute.nVal->name, "write") == 0 && check_tree_type(t->right) == INUM) {
        if (t->right->type == INUM) {
            fprintf(taft_asm, "\tmovl $%d, %%esi\n", t->right->attribute.iVal);
            fprintf(taft_asm, "\tleaq str.write.inum(%%rip), %%rdi\n");
            fprintf(taft_asm, "\tpushq %%rax\n");
            fprintf(taft_asm, "\tpushq %%rcx\n");
            fprintf(taft_asm, "\tmovb $0, %%al\n");
            fprintf(taft_asm, "\tcall _printf\n");
            fprintf(taft_asm, "\tpopq %%rcx\n");
            fprintf(taft_asm, "\tpopq %%rax\n");
        } else if (t->right->type == ID) {
            //TODO: Handle variables
            if (t->right->attribute.nVal->type == INUM) {
                fprintf(taft_asm, "\tmovq -%d(%%rbp), %%rsi\n", (t->right->attribute.nVal->offset+1)*8);
                fprintf(taft_asm, "\tleaq str.write.inum(%%rip), %%rdi\n");
                fprintf(taft_asm, "\tpushq %%rax\n");
                fprintf(taft_asm, "\tpushq %%rcx\n");
                fprintf(taft_asm, "\tmovb $0, %%al\n");
                fprintf(taft_asm, "\tcall _printf\n");
                fprintf(taft_asm, "\tpopq %%rcx\n");
                fprintf(taft_asm, "\tpopq %%rax\n");
            } else {
                //TODO: support real numbers
            }
        } else {
            gen_expr(top, t->right, regs);
            fprintf(taft_asm, "\tmovq %%%s, %%rsi\n", regs->reg);
            fprintf(taft_asm, "\tleaq str.write.inum(%%rip), %%rdi\n");
            fprintf(taft_asm, "\tpushq %%rax\n");
            fprintf(taft_asm, "\tpushq %%rcx\n");
            fprintf(taft_asm, "\tmovb $0, %%al\n");
            fprintf(taft_asm, "\tcall _printf\n");
            fprintf(taft_asm, "\tpopq %%rcx\n");
            fprintf(taft_asm, "\tpopq %%rax\n");
        }
        return;
    } else if (strcmp(t->left->attribute.nVal->name, "write") == 0 && check_tree_type(t->right) == RNUM) {
        fprintf(taft_asm, "\tleaq str.write.rnum(%%rip), %%rdi\n");
        fprintf(taft_asm, "\tcall _printf\n");
        return;
    }

    if (strcmp(t->left->attribute.nVal->name, "read") == 0 && check_tree_type(t->right) == INUM) {
        if (t->right->type == ID) {
                fprintf(taft_asm, "\tleaq str.write.inum(%%rip), %%rdi\n");
                fprintf(taft_asm, "\tleaq -%d(%%rbp), %%rsi\n", (t->right->attribute.nVal->offset+1)*8);
                fprintf(taft_asm, "\tpushq %%rax\n");
                fprintf(taft_asm, "\tpushq %%rcx\n");
                fprintf(taft_asm, "\tmovb $0, %%al\n");
                fprintf(taft_asm, "\tcall _scanf\n");
                fprintf(taft_asm, "\tpopq %%rcx\n");
                fprintf(taft_asm, "\tpopq %%rax\n");
        } else {
            yyerror("Failed to put variable into INUM");
        }
        return;
    } else if (strcmp(t->left->attribute.nVal->name, "read") == 0 && check_tree_type(t->right) == RNUM) {
        yyerror("REading floating point numbers is not supported");
    }

    fprintf(taft_asm, "\tcall %s\n", t->left->attribute.nVal->name);
}

//Gen code for expressions
void gen_expr(scope_t *top, tree_t *t, reg_stack_t *regs) {
    if (t == NULL) {
        return;
    }
    // fprintf(stderr, "type: %d\n", t->type);
    //TODO: if function call mixed in handle that
    //If left node (case 0)
    if (t->left == NULL && t->right == NULL /*&& t->label == 1*/) {
        // fprintf(stderr, "case 0\n");
        char *name = (char*)malloc(MAX_OPERAND_LEN*sizeof(char));
        if (t->type == ID) {
            if (t->attribute.nVal->array == ARRAY) {
                return;
            } else {
                if (t->attribute.nVal->offset != -1) {
                    sprintf(name, "-%d(%%rbp), %%%s", ((t->attribute.nVal->offset+1) * 8), regs->reg);
                } else {
                    sprintf(name, "INVALID OFFSET");
                }
            }
        } else if (t->type == INUM) {
            sprintf(name, "$%d, %%%s", t->attribute.iVal, regs->reg);
        } else if (t->type == RNUM) {
            sprintf(name, "$%f, %%%s", t->attribute.rVal, regs->reg);
        } else {
            yyerror("failed to get value");
            exit(-6);
        }
        fprintf(taft_asm, "\tmovq %s\n", name);
        return;
    }
    if (t->right != NULL) {
        //If the right child is a node (Case 1)
        if (t->right->left == NULL && t->right->right == NULL) {
            // fprintf(stderr, "case 1\n");
            if (t->type == FUNCTION_CALL) {
                gen_func_call(top, t, regs);
                fprintf(taft_asm, "\tmovq %%rax, %%%s\n", regs->reg);
                return;
            }
            gen_expr(top, t->left, regs);
            char *name = (char*)malloc(MAX_OPERAND_LEN*sizeof(char));
            if (t->right->type == INUM) {
                sprintf(name, "$%d, %%%s", t->right->attribute.iVal, regs->reg);
            } else if (t->right->type == RNUM) {
                sprintf(name, "$%f, %%%s", t->right->attribute.rVal, regs->reg);
            } else {
                yyerror("failed to get value");
                exit(-7);
            }

            fprintf(taft_asm, "\t%s %s\n", get_IA64_op(t->attribute.opVal), name);
            return;
        }
    }
    if (t->left != NULL && t->right != NULL) {
        //If label n1 < label n2 (Case 2)
        if (t->left->label < t->right->label && t->left->label < NUM_REGISTERS) {
            // fprintf(stderr, "case 2\n");
            if (t->type == FUNCTION_CALL) {
                return;
            }
            regs = reg_swap(regs);
            gen_expr(top, t->right, regs);
            char *tmp_reg;
            regs = reg_pop(regs, &tmp_reg);
            gen_expr(top, t->left, regs);
            fprintf(taft_asm, "\t%s %%%s, %%%s\n", get_IA64_op(t->attribute.opVal), tmp_reg, regs->reg);
            regs = reg_push(regs, tmp_reg);
            regs = reg_swap(regs);
            return;
        }
    
        //If label n2 <= label n1 (case 3)
        if (t->right->label <= t->left->label && t->right->label < NUM_REGISTERS) {
            // fprintf(stderr, "case 3\n");
            if (t->type == FUNCTION_CALL) {
                return;
            }
            gen_expr(top, t->left, regs);
            char *tmp_reg;
            regs = reg_pop(regs, &tmp_reg);
            gen_expr(top, t->right, regs);
            fprintf(taft_asm, "\t%s %%%s, %%%s\n", get_IA64_op(t->attribute.opVal), regs->reg, tmp_reg);
            regs = reg_push(regs, tmp_reg);
            return;
        }
        //Case 4
        if (t->right->label >= NUM_REGISTERS || t->left->label >= NUM_REGISTERS) {
            yyerror("used too many registers, bye");
        }
    }
    // fprintf(stderr, "Nope\n");
    gen_expr(top, t->left, regs);
    gen_expr(top, t->right, regs);
}

//Gen code for statements
void aux_gen_tree(scope_t *top, tree_t *t, reg_stack_t *regs) {
    if (t == NULL) {
        return;
    }
    if (t->type == FUNCTION_CALL || t->type == PROCEDURE_CALL) {
        gen_func_call(top, t, regs);
    }

    if (t -> type == ASSIGNOP) {
        gen_expr(top, t->right, regs);
        if (t->left->type == ID) {
            if (t->left->attribute.nVal->type == FUNCTION) {
                //Function return
                fprintf(taft_asm, "\tmovq %%%s, %%rax\n", regs->reg);
            } else {
                fprintf(taft_asm, "\tmovq %%%s, -%d(%%rbp)\n", regs->reg, (t->left->attribute.nVal->offset+1) * 8);
            }
        }
        aux_gen_tree(top, t->left, regs);
        return;
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
    reg_stack_t *regs = mkreg_stack("rbx");
    regs->next = mkreg_stack("rcx");
    regs->next->next = mkreg_stack("rdx");
    // regs->next->next->next = mkreg_stack("rsi");
    fprintf(taft_asm, "\tpushq %%rbp\n");
    fprintf(taft_asm, "\tmovq %%rsp, %%rbp\n");
    if (scope_get_size(top) > 1) { //TODO: Probably want to keep 16 byte allighnment on all odd number values
        fprintf(taft_asm, "\tsubq $%d, %%rsp\n", 8*scope_get_size(top));
    } else {
        fprintf(taft_asm, "\tsubq $8, %%rsp\n");
    }
    aux_gen_tree(top, t, regs);
    if (scope_get_size(top) > 1) {
        fprintf(taft_asm, "\taddq $%d, %%rsp\n", 8*scope_get_size(top));
    } else {
        fprintf(taft_asm, "\taddq $8, %%rsp\n");
    }
    fprintf(taft_asm, "\tpop %%rbp\n");
    fprintf(taft_asm, "\tretq\n");

}

void gen_func(scope_t *top, tree_t *t, char *name) {
    //Gen function tag and call aux
    gen_tag(name);
    gen_tree(top, t);
}

char *get_IA64_op(int op) {
    // fprintf(stderr, "%d\n", op);
    switch (op) {
    case PLUS:
        return "addq";
    case MINUS:
        return "subq";
    case STAR:
        return "imulq";
    case SLASH:
        return "idivq";
    default: {
        char err[MAX_OPERAND_LEN];
        sprintf(err, "Failed to get op: %d", op);
        yyerror(err);
        exit(-8);
    }
    }
}

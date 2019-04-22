#pragma once
#include <stdio.h>
#include "base_tree.h"
#include "scope.h"

#define MAX_OPERAND_LEN 100

FILE *taft_asm;

typedef struct reg_stack_s {
    char *reg;
    struct reg_stack_s *next;
} reg_stack_t;

reg_stack_t *mkreg_stack(char *);
void free_reg(reg_stack_t *);
reg_stack_t *reg_push(reg_stack_t *, char *);
reg_stack_t *reg_pop(reg_stack_t *, char **);
reg_stack_t *reg_swap(reg_stack_t *);

void gen_prelude();
void gen_tail();
void gen_tag(char *);
void gen_func(scope_t *, tree_t *, char *);
void gen_expr(scope_t *, tree_t *, reg_stack_t *);
void gen_func_call(scope_t *, tree_t *, reg_stack_t *);
void aux_gen_tree(scope_t *, tree_t *, reg_stack_t *);
void gen_tree(scope_t *, tree_t *);
void gen_offset(scope_t *);
char *get_IA64_op(int);
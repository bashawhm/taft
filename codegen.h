#pragma once
#include <stdio.h>
#include "base_tree.h"
#include "scope.h"

FILE *taft_asm;

void gen_prelude();
void gen_tail();
void gen_tag(char *);
void gen_func(scope_t *, tree_t *, char *);
void gen_tree(scope_t *, tree_t *);
char *get_intel_asm(int);
void gen_offset(scope_t *);
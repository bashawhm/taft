#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "node.h"
#include "base_tree.h"
#include "base_semantic.h"

arg_list_t *aux_tree_to_arg_list(tree_t *, bool);
arg_list_t *tree_to_arg_list(tree_t *);
void tree_to_args(node_t *, tree_t *);
node_t *check_scope(node_t *n, char *name);
bool check_arg_type(tree_t *t);
void arg_list_print(arg_list_t*);
int check_tree_type(tree_t *t);
void check_array_index(tree_t *t);
bool check_relop(tree_t *);
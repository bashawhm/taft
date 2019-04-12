#pragma once

#include "common.h"

typedef struct node_s {
    char *name;
    struct node_s *next;

    //Variable Stuff
    int type;
    int offset;
    //Array stuff
    int array;
    int l_bound;
    int r_bound;
    //Function stuff
    int ret_type;
    int argc;
    struct node_s **arg_list;
} node_t;

node_t *mknode(char *);
node_t *mknode_array(char *, int, int);
node_t *node_dup(node_t *);

node_t *node_search(node_t *, char *);
node_t *node_insert(node_t *, char *);
bool node_is_typed(node_t *);
void node_print(node_t *);
void node_add_arg(node_t *, node_t *);
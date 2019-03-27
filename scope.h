#pragma once

#include "node.h"

#define HASH_SIZE 211

typedef struct scope_s {
    node_t *table[HASH_SIZE];
    struct scope_s *next;
} scope_t;

scope_t *mkscope();
void free_scope(scope_t *);

scope_t *push_scope(scope_t *);
scope_t  *pop_scope(scope_t *);

void                   scope_type_all(scope_t *top, int type);
void      scope_type_node(scope_t *top, char *name, int type);
void                       scope_type(scope_t *top, int type);
node_t            *scope_search_all(scope_t *top, char *name);
node_t                *scope_search(scope_t *top, char *name);
node_t                *scope_insert(scope_t *top, char *name);
void                                scope_print(scope_t *top);
node_t *scope_insert_type(scope_t *top, char *name, int type);
node_t                   *scope_del(scope_t *top, char *name);

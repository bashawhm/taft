#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "node.h"
#include "core_semantic.h"
#include "y.tab.h"

/* Constructors */
node_t *mknode(char *s) {
    node_t *p = (node_t *) malloc(sizeof(node_t));
    assert(p != NULL);
    p->name = strdup(s);
    p->next = NULL;
    p->type = 0;
    p->argc = 0;
    p->arg_list = NULL;
    return p;
}

node_t *node_dup(node_t *n) {
    assert(n != NULL);
    node_t *new_node = mknode(n->name);
    new_node -> type = n -> type;
    new_node -> ret_type = n -> ret_type;
    new_node -> next = n -> next;
    new_node -> argc = n -> argc;
    new_node -> arg_list = n -> arg_list;
    return new_node;
}

/* Helpers */
node_t *node_search(node_t *top, char *name) {
    node_t *p = top;

    while(p != NULL){
        if (strcmp(p->name, name) == 0) return p;
        p = p->next;
    }
    return NULL;
}

node_t *node_insert(node_t *top, char *name) {
    node_t *p = mknode(name);
    p->next = top;
    return p;
}

void node_print(node_t *top) {
    node_t *p = top;
    fprintf(stderr, "\nBEGIN LIST PRINT\n");
    while(p != NULL){
        fprintf(stderr, "[%s]", p->name);
        p = p->next;
    }
    fprintf(stderr, "\n");
    fprintf(stderr, "END LIST PRINT\n");
}

bool node_is_typed(node_t *top) {
    assert(top != NULL);
    if (top -> type == 0) {
        return false;
    }
    return true;
}

void node_add_arg(node_t *n, node_t *arg) {
    assert(n != NULL);
    if (arg == NULL) {
        return;
    }
    n->argc++;
    n->arg_list = (node_t**)realloc(n->arg_list, n->argc*sizeof(node_t*));
    n->arg_list[(n->argc)-1] = arg;
}

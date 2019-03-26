#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "node.h"
#include "tree.h"
#include "y.tab.h"

/* Constructors */
node_t *mknode(char *s){
    node_t *p = (node_t *) malloc(sizeof(node_t));
    assert(p != NULL);
    p->name = strdup(s);
    p->next = NULL;
    return p;
}

/* Helpers */
node_t *node_search(node_t *top, char *name){
    node_t *p = top;

    while(p != NULL){
        if (strcmp(p->name, name) == 0) return p;
        p = p->next;
    }
    return NULL;
}

node_t *node_insert(node_t *top, char *name){
    node_t *p = mknode(name);
    p->next = top;
    return p;
}

void node_print(node_t *top){
    node_t *p = top;
    fprintf(stderr, "BEGIN LIST PRINT\n");
    while(p != NULL){
        fprintf(stderr, "[%s]", p->name);
        p = p->next;
    }
    fprintf(stderr, "\n");
    fprintf(stderr, "END LIST PRINT");
}

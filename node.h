#pragma once

/* Linked list */

typedef struct node_s {
    char *name;
    struct node_s *next;
    
    /* Variable type */
    int type;
    
} node_t;

/* Constructors */
node_t *mknode(char *);

/* Helpers */
node_t *node_search(node_t *, char *);
node_t *node_insert(node_t *, char *);
void node_print(node_t *);

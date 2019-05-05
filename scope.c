#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "scope.h"
#include "base_tree.h" //Needed to let y.tab.h not complain about missing tree_t type
#include "codegen.h"
#include "y.tab.h"

/* ----------------------------------------------------------------------------- 
 * hashpjw
 * Peter J. Weinberger's hash function 
 * Source: Aho, Sethi, and Ullman, "Compilers", Addison-Wesley, 1986 (page 436).
 */
#define EOS		'\0'

int hashpjw(char *s) {
	char *p; 
	unsigned h = 0, g; 
	
	for ( p = s; *p != EOS; p++ ) 
	{ 
		h = (h << 4) + (*p); 
		if ( (g = h & 0xf0000000) ) 
		{ 
			h = h ^ ( g >> 24 ); 
			h = h ^ g; 
		} 
	} 
	return h % HASH_SIZE; 
}



scope_t *mkscope() {
    scope_t *p = (scope_t *) malloc(sizeof(scope_t));
    assert(p != NULL);

    for (int i=0; i < HASH_SIZE; i++) (p->table)[i] = NULL;

    p->next = NULL;
    return p;
}

void free_scope(scope_t *top) {
    return;
}


scope_t *push_scope(scope_t *top) {
    scope_t *p = mkscope();
    p->next = top;
    return p;
}
scope_t *pop_scope(scope_t *top) {
    scope_t *p;

    if (top == NULL) return NULL;
    p = top->next;
    free_scope(top);
    return p;
}


node_t *scope_search(scope_t *top, char *name) {
    int index = hashpjw(name);
    node_t *tmp = top->table[index];
    return node_search(tmp, name);
}
node_t *scope_search_all(scope_t *top, char *name) {
    scope_t *p = top;
    node_t *tmp;
    while(p != NULL) {
        if ((tmp = scope_search(p, name)) != NULL) return tmp;
        p = p->next;
    }
    return NULL;
}
node_t *scope_insert(scope_t *top, char *name) {
    if (strcmp(name, "input") == 0) {
        int index = hashpjw("read");
        node_t *tmp = top->table[index];
        top->table[index] = node_insert(tmp, "read");
        top->table[index] -> type = PROCEDURE;
        return top->table[index];
    }
    if (strcmp(name, "output") == 0) {
        int index = hashpjw("write");
        node_t *tmp = top->table[index];
        top->table[index] = node_insert(tmp, "write");
        top->table[index] -> type = PROCEDURE;

        index = hashpjw("writeln");
        tmp = top->table[index];
        top->table[index] = node_insert(tmp, "writeln");
        top->table[index] -> type = PROCEDURE;
        return top->table[index];
    }
    int index = hashpjw(name);
    node_t *tmp = top->table[index];
    top->table[index] = node_insert(tmp, name);
    return top->table[index];
}
node_t *scope_del(scope_t *top, char *name) {
    return NULL;
}

void scope_type(scope_t *top, tree_t *type) {
    for (int i = 0; i < HASH_SIZE; i++) {
        node_t *tmp = top -> table[i];
        if (tmp != NULL) {
            do {
                if (tmp -> type == 0) {
                    if (type->array == ARRAY) {
                        tmp->array = ARRAY;
                        tmp->l_bound = type->l_bound;
                        tmp->r_bound = type->r_bound;
                    }
                    tmp -> type = type->type;
                }
                tmp = tmp -> next;
            } while (tmp != NULL);
        }
    }
}

/*void scope_type_all(scope_t *top, int type) {
    scope_t *p = top;
    while(p != NULL) {
        scope_type(p, type);
        p = p->next;
    }
}*/

node_t *scope_insert_type(scope_t *top, char *name, int type) {
    int index = hashpjw(name);
    node_t *tmp = top->table[index];
    top->table[index] = node_insert(tmp, name);
    top->table[index]->type = type;
    return top->table[index];
}

void scope_print(scope_t *top) {
    // gen_offset(top);
    fprintf(stderr, "BEGIN SCOPE PRINT\n");
    for (int i = 0; i < HASH_SIZE; i++) {
        node_t *tmp = top -> table[i];
        if (tmp != NULL) {
            do {
                fprintf(stderr, "[%s;%d | offset;%d]\n", tmp->name, tmp->type, tmp->offset);
                tmp = tmp -> next;
            } while (tmp != NULL);
        }
    }
    fprintf(stderr, "END SCOPE PRINT\n");
}

void scope_type_node(scope_t *top, char *name, int type) {
    node_t *n = scope_search_all(top, name);
    n -> type = type;
}

    
void scope_type_function(scope_t *top, char *name, int ret_type) {
    node_t *n = scope_search_all(top, name);
    n -> ret_type = ret_type;
}

int scope_get_size(scope_t *top) {
    int num = 0;
    for (int i = 0; i < HASH_SIZE; i++) {
        node_t *tmp = top -> table[i];
        if (tmp != NULL) {
            do {
                if (tmp->offset != -1) {
                    if (tmp->array == ARRAY) {
                        num += (tmp->r_bound - tmp->l_bound);
                    } else {
                        num++;
                    }
                }
                tmp = tmp -> next;
            } while (tmp != NULL);
        }
    }
    return num;
}
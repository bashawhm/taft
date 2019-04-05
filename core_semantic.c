#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "core_semantic.h"
#include "y.tab.h"

extern int line_num;

void tree_to_args(node_t *n, tree_t *args) {
    assert(n != NULL);
    if (args == NULL) {
        return;
    }

    node_add_arg(n, args->attribute.nVal);
    tree_to_args(n, args->left);
    tree_to_args(n, args->right);
}


arg_list_t *aux_tree_to_arg_list(tree_t *t, bool called) {
    if (t == NULL) {
        return NULL;
    }
    if (called) {
        if (t -> type == FUNCTION_CALL) {
            arg_list_t *al = mkarg_list(t -> left -> attribute.nVal -> ret_type);
            al -> next = NULL;
            return al;
        }
    }
    if (t -> type == INUM) {
        arg_list_t *al = mkarg_list(INUM);
        al -> next = NULL;
        return al;
    }
    if (t -> type == RNUM) {
        arg_list_t *al = mkarg_list(RNUM);
        al -> next = NULL;
        return al;
    }
    arg_list_t *al = aux_tree_to_arg_list(t -> left, called);
    if (al == NULL) {
        return aux_tree_to_arg_list(t -> right, called);
    }
    arg_list_t *tmp = al;
    while (tmp -> next != NULL) {
        tmp = tmp -> next;
    }
    tmp -> next = aux_tree_to_arg_list(t -> right, called);

    return al;
}

arg_list_t *tree_to_arg_list(tree_t *t) {
    if (t -> type == FUNCTION_CALL) {
        return aux_tree_to_arg_list(t, true);
    }
    return aux_tree_to_arg_list(t, false);
}


node_t *check_scope(node_t *n, char *name) {
    if (n == NULL) {
        fprintf(stderr, "ERROR: line %d, %s not in scope\n", line_num, name);
        exit(-2);
    }
    return n;
}

bool check_arg_type(tree_t *t) {
    if (t == NULL) {
        return true;
    }
    assert(t -> type == FUNCTION_CALL || t -> type == PROCEDURE_CALL);
    arg_list_t *al = tree_to_arg_list(t);
    // arg_list_print(al);
    arg_list_t *tmp = al;
    for (int i = 0; i < t -> left -> attribute.nVal->argc; i++) {
        if (tmp == NULL) {
            fprintf(stderr, "ERROR: line %d, not enough arguments in call to %s\n", line_num, t->left->attribute.nVal->name);
            exit(-3);
        }
        if (tmp -> type != t -> left -> attribute.nVal -> arg_list[i] -> type) {
            fprintf(stderr, "ERROR: line %d, type conflict %d != %d\n", line_num, tmp->type, t -> left -> attribute.nVal -> arg_list[i] -> type);
            exit(-4);
        }
        tmp = tmp -> next;
    }
    return true;
}

void arg_list_print(arg_list_t *al) {
    fprintf(stderr, "\nBEGIN ARG PRINT\n");
    if (al == NULL) {
        return;
    }
    fprintf(stderr, "[");
    arg_list_t *tmp = al;
    do {
        if (tmp -> type == INUM) {
            fprintf(stderr, " INUM ");
        } else {
            fprintf(stderr, " RNUM ");
        }
        tmp = tmp -> next;
    } while (tmp != NULL);
    fprintf(stderr, "]\n");
    fprintf(stderr, "\nEND ARG PRINT\n");
}
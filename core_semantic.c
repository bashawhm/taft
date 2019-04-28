#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "core_semantic.h"
#include "y.tab.h"

extern int line_num;
extern int yyerror(char*);

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
    if (t->type == ARRAY_ACCESS) {
        check_array_index(t);
        //TODO: make arg list with the array type
        arg_list_t *al = mkarg_list(t->left->attribute.nVal->type);
        al -> next = NULL;
        return al;
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
    if (t -> type == ID) {
        if (t->attribute.nVal->type == INUM || t->attribute.nVal->type == RNUM) {
            arg_list_t *al = mkarg_list(t->attribute.nVal->type);
            al -> next = NULL;
            return al;
        }
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
    fprintf(stderr, "type: %d\n", t->type);
    assert(t -> type == FUNCTION_CALL || t -> type == PROCEDURE_CALL);
    arg_list_t *al = tree_to_arg_list(t);
    // arg_list_print(al);
    arg_list_t *tmp = al;
    for (int i = 0; i < t -> left -> attribute.nVal->argc; i++) {
        if (tmp == NULL) {
            fprintf(stderr, "ERROR: line %d, not enough arguments in call to %s, needed %d\n", line_num, t->left->attribute.nVal->name, t->left->attribute.nVal->argc);
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

int check_tree_type(tree_t *t) {
    if (t == NULL) {
        return 0;
    }
    if (t->left == NULL && t->right == NULL) {
        if (t->type == ID) {
            if (t->attribute.nVal->type == FUNCTION) {
                return t->attribute.nVal->ret_type;
            }
            return t->attribute.nVal->type;
        } else {
            return t->type;
        }
    }
    int l_type = -1;
    int r_type = -2;

    if (t->left != NULL) {
        if (/*t->left->type == FUNCTION_CALL ||*/ t->left->type == FUNCTION) {
            l_type = t->left->attribute.nVal->ret_type;
        } else if (t->left->type == ID) {
            if (t->left->attribute.nVal->type == FUNCTION) {
                l_type = t->left->attribute.nVal->ret_type;
            } else {
                l_type = t->left->attribute.nVal->type;
            }
        } else if (t->left->type == ARRAY_ACCESS) {
            check_array_index(t->left);
            l_type = t->left->left->attribute.nVal->type;
        } else {
            l_type = check_tree_type(t->left);
        }
    }

    if (t->right != NULL) {
        if (/*t->right->type == FUNCTION_CALL ||*/ t->right->type == FUNCTION) {
            r_type = t->right->attribute.nVal->ret_type;
        } else if (t->right->type == ID) {
            if (t->right->attribute.nVal->type == FUNCTION) {
                r_type = t->right->attribute.nVal->ret_type;
            } else {
                r_type = t->right->attribute.nVal->type;
            }
            r_type = t->right->attribute.nVal->type;
        } else if (t->right->type == ARRAY_ACCESS) {
            check_array_index(t->right);
            r_type = t->right->left->attribute.nVal->type;
        } else {
            r_type = check_tree_type(t->right);
        }
    }

    if (t->left != NULL && t->right != NULL) {
        //compare
        if (l_type != r_type) {
            fprintf(stderr, "ERROR: line %d, type conflict on operator. left: %d, right: %d\n", line_num, l_type, r_type);
            exit(-5);
        }
    }
    if (t->left != NULL) {
        return l_type;
    }
    return r_type;
}

void check_array_index(tree_t *t) {
    if (t == NULL) {
        return;
    }
    int type = check_tree_type(t->right);
    if (type != INUM) {
        fprintf(stderr, "ERROR: line %d, must index and array with an integer\n", line_num);
        exit(-6);
    }
}

bool check_relop(tree_t *t) {
    if (t == NULL) {
        return false;
    }
    if (t->type == RELOP) {
        return true;
    }
    bool test = false;
    test = test || check_relop(t->left);
    if (test) {
        return true;
    }
    test = test || check_relop(t->right);
    if (test) {
        return true;
    }
    yyerror("No relop in condition");
    return false;
}
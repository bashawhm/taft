#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "base_tree.h"
#include "y.tab.h"


extern int yyerror(char*);

tree_t *mktree(int type, tree_t *left, tree_t *right) {
    tree_t *p = (tree_t*)malloc(sizeof(tree_t));
    assert(p != NULL);
    p->type = type;
    p->left = left;
    p->right = right;
    p->array = -1;
    p->l_bound = 0;
    p->r_bound = 0;
    p->label = 0;
    return p;
}

tree_t *mktree_array(int type, tree_t *left, tree_t *right, int l_bound, int r_bound) {
    tree_t *t = mktree(type, left, right);
    t->array = ARRAY;
    t->l_bound = l_bound;
    t->r_bound = r_bound;
    return t;
}

tree_t *mkarray(tree_t *t, int l_bound, int r_bound) {
    t->array = ARRAY;
    t->l_bound = l_bound;
    t->r_bound = r_bound;
    return t;
}

tree_t *mkid(node_t *id) {
    tree_t *t = mktree(ID, NULL, NULL);
    t->attribute.nVal = id;

    return t;
}
tree_t *mkinum(int inum) {
    tree_t *t = mktree(INUM, NULL, NULL);
    t->attribute.iVal = inum;

    return t;
}
tree_t *mkrnum(float rnum) {
    tree_t *t = mktree(RNUM, NULL, NULL);
    t->attribute.rVal = rnum;

    return t;
}

tree_t *mkop(int type, int attribute, tree_t *left, tree_t *right) {
    tree_t *t = mktree(type, left, right);
    t -> attribute.opVal = attribute;

    return t;
}

void aux_tree_print(tree_t *t, int spaces) {
    if ( t == NULL) {
        return;
    }
    for (int i = 0; i < spaces; ++i) {
        fprintf(stderr, " ");
    }
    fprintf(stderr, "[%d] ", t->label);
    switch (t->type) {
    case RELOP: {
        fprintf(stderr, "[RELOP;%d]\n", t->attribute.opVal);
        break;
    }
    case ADDOP: {
        fprintf(stderr, "[ADDOP;%d]\n", t->attribute.opVal);
        break;
    }
    case MULOP: {
        fprintf(stderr, "[MULOP;%d]\n", t->attribute.opVal);
        break;
    }
    case ID: {
        if (t->attribute.nVal != NULL) {
            if (t -> attribute.nVal->type == INUM) {
                if (t->attribute.nVal->array == ARRAY) {
                    fprintf(stderr, "[NODE ID;%s | NODE TYPE;INUM | LEFT BOUND %d; RIGHT BOUND %d]\n", t->attribute.nVal->name, t->attribute.nVal->l_bound, t->attribute.nVal->r_bound);
                } else {
                    fprintf(stderr, "[NODE ID;%s | NODE TYPE;INUM]\n", t->attribute.nVal->name);
                }
            } else if (t -> attribute.nVal->type == RNUM) {
                if (t->attribute.nVal->array == ARRAY) {
                    fprintf(stderr, "[NODE ID;%s | NODE TYPE;RNUM | LEFT BOUND %d; RIGHT BOUND %d]\n", t->attribute.nVal->name, t->attribute.nVal->l_bound, t->attribute.nVal->r_bound);
                } else {
                    fprintf(stderr, "[NODE ID;%s | NODE TYPE;RNUM]\n", t->attribute.nVal->name);
                }
            } else if (t -> attribute.nVal->type == FUNCTION) {
                if (t -> attribute.nVal->ret_type == INUM) {
                    if (t -> attribute.nVal->argc == 0) {
                        fprintf(stderr, "[NODE ID;%s | NODE TYPE;FUNCTION | RET TYPE;INUM]\n", t->attribute.nVal->name);
                        break;
                    }
                    fprintf(stderr, "[NODE ID;%s | NODE TYPE;FUNCTION | RET TYPE;INUM | ", t->attribute.nVal->name);
                    for (int i = 0; i < t -> attribute.nVal -> argc; i++) {
                        if (t -> attribute.nVal -> arg_list[i] -> type == INUM) {
                            fprintf(stderr, "ARG NAME %s;ARG TYPE INUM", t->attribute.nVal->arg_list[i]->name);
                            if (i + 1 == t -> attribute.nVal -> argc) {
                                fprintf(stderr, "]\n");
                            } else {
                                fprintf(stderr, " |");
                            }
                        } else {
                            fprintf(stderr, "ARG NAME %s;ARG TYPE RNUM", t->attribute.nVal->arg_list[i]->name);
                            if (i + 1 == t -> attribute.nVal -> argc) {
                                fprintf(stderr, "]\n");
                            } else {
                                fprintf(stderr, " |");
                            }
                        }
                    }
                } else if (t -> attribute.nVal->ret_type == RNUM) {
                    if (t -> attribute.nVal->argc == 0) {
                        fprintf(stderr, "[NODE ID;%s | NODE TYPE;FUNCTION | RET TYPE;RNUM]\n", t->attribute.nVal->name);
                        break;
                    }
                    fprintf(stderr, "[NODE ID;%s | NODE TYPE;FUNCTION | RET TYPE;RNUM]\n", t->attribute.nVal->name);
                    for (int i = 0; i < t -> attribute.nVal -> argc; i++) {
                        if (t -> attribute.nVal -> arg_list[i] -> type == INUM) {
                            fprintf(stderr, "ARG NAME %s;ARG TYPE INUM", t->attribute.nVal->arg_list[i]->name);
                            if (i + 1 == t -> attribute.nVal -> argc) {
                                fprintf(stderr, "]\n");
                            } else {
                                fprintf(stderr, " |");
                            }
                        } else {
                            fprintf(stderr, "ARG NAME %s;ARG TYPE RNUM", t->attribute.nVal->arg_list[i]->name);
                            if (i + 1 == t -> attribute.nVal -> argc) {
                                fprintf(stderr, "]\n");
                            } else {
                                fprintf(stderr, " |");
                            }
                        }
                    }
                }
            } else if (t -> attribute.nVal->type == PROCEDURE) {
                if (t -> attribute.nVal->argc == 0) {
                    fprintf(stderr, "[NODE ID;%s | NODE TYPE;PROCEDURE]\n", t->attribute.nVal->name);
                    break;
                }
                fprintf(stderr, "[NODE ID;%s | NODE TYPE;PROCEDURE | ", t->attribute.nVal->name);
                for (int i = 0; i < t -> attribute.nVal -> argc; i++) {
                    if (t -> attribute.nVal -> arg_list[i] -> type == INUM) {
                        fprintf(stderr, "ARG NAME %s;ARG TYPE INUM", t->attribute.nVal->arg_list[i]->name);
                        if (i + 1 == t -> attribute.nVal -> argc) {
                            fprintf(stderr, "]\n");
                        } else {
                            fprintf(stderr, " |");
                        }
                    } else {
                        fprintf(stderr, "ARG NAME %s;ARG TYPE RNUM", t->attribute.nVal->arg_list[i]->name);
                        if (i + 1 == t -> attribute.nVal -> argc) {
                            fprintf(stderr, "]\n");
                        } else {
                            fprintf(stderr, " |");
                        }
                    }
                }
            } else {
                fprintf(stderr, "[NODE ID;%s|NODE TYPE;%d]\n", t->attribute.nVal->name, t->attribute.nVal->type);
            }
        } else {
            fprintf(stderr, "[NOT IN SCOPE]\n");
        }
        break;
    }
    case INUM: {
        fprintf(stderr, "[INUM;%d]\n", t->attribute.iVal);
        break;
    }
    case RNUM: {
        fprintf(stderr, "[RNUM;%f]\n", t->attribute.rVal);
        break;
    }
    case NOT: {
        fprintf(stderr, "[NOT]\n");
        break;
    }
    case ARRAY_ACCESS: {
        fprintf(stderr, "[ARRAY_ACCESS]\n");
        break;
    }
    case FUNCTION_CALL: {
        fprintf(stderr, "[FUNCTION_CALL]\n");
        break;
    }
    case PROCEDURE_CALL: {
        fprintf(stderr, "[PROCEDURE_CALL]\n");
        break;
    }
    case COMMA: {
        fprintf(stderr, "[COMMA]\n");
        break;
    }
    case SEMICOLON: {
        fprintf(stderr, "[SEMICOLON]\n");
        break;
    }
    case IF: {
        fprintf(stderr, "[IF]\n");
        break;
    }
    case THEN: {
        fprintf(stderr, "[THEN]\n");
        break;
    }
    case WHILE: {
        fprintf(stderr, "[WHILE]\n");
        break;
    }
    case ASSIGNOP: {
        fprintf(stderr, "[ASSIGNOP]\n");
        break;
    }
    default: {
        yyerror("Error in tree printing");
        break;
    }
    }

    aux_tree_print(t->left, spaces+4);
    aux_tree_print(t->right, spaces+4);
}

void tree_print(tree_t * t) {
    tree_label(t);
    aux_tree_print(t, 0);
}

void tree_label(tree_t *t) {
    if (t == NULL) {
        return;
    }
    tree_label(t->right);
    tree_label(t->left);
    if (t->right != NULL) {
        //If right node is a leaf
        if (t->right->left == NULL && t->right->right == NULL) {
            t->right->label = 0;
        }
    }
    if (t->left != NULL) {
        //If left node is a leaf
        if (t->left->left == NULL && t->left->right == NULL) {
            t->left->label = 1;
        }
    }
    if (t->left == NULL && t->right != NULL) {
        t->label = t->right->label;
    }

    if (t->left != NULL && t->right == NULL) {
        t->label = t->left->label;
    }

    if (t->left != NULL && t->right != NULL) {
        if (t->left->label < t->right->label) {
            t->label = t->right->label;
        }
        if (t->left->label > t->right->label) {
            t->label = t->left->label;
        }
        if (t->left->label == t->right->label) {
            t->label = (t->left->label)+1;
        }
    }
}
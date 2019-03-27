#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "tree.h"
#include "y.tab.h"

extern int yyerror(char*);

tree_t *mktree(int type, tree_t *left, tree_t *right) {
    tree_t *p = (tree_t*)malloc(sizeof(tree_t));
    assert(p != NULL);
    p->type = type;
    p->left = left;
    p->right = right;
    return p;
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
                fprintf(stderr, "[NODE ID;%s|NODE TYPE;INUM]\n", t->attribute.nVal->name);
            } else if (t -> attribute.nVal->type == RNUM) {
                fprintf(stderr, "[NODE ID;%s|NODE TYPE;RNUM]\n", t->attribute.nVal->name);
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
    aux_tree_print(t, 0);

}

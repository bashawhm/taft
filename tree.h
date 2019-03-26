#pragma once
#include <stdlib.h>

#include "node.h"

typedef struct tree_s {
    int type;         //Type: INUM RNUM ID RELOP ADDOP MULOP NOT ..
    union {           //Token attribute
        int   iVal;   //INUM
        float rVal;   //RNUM
        node_t *nVal; //ID info
        int  opVal;   //RELOP: LT LE GT GE EQ NE
                      //ADDOP: PLUS MINUS OR
                      //MULOP: STAR SLASH AND
    } attribute;

    struct tree_s *left;
    struct tree_s *right;
} tree_t;

tree_t *mktree(int type, tree_t *left, tree_t *right);
tree_t *mkid(node_t *id);
tree_t *mkinum(int inum);
tree_t *mkrnum(float rnum);
tree_t *mkop(int type, int attribute, tree_t *left, tree_t *right);

void tree_print(tree_t *tree);

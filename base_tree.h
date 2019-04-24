#pragma once
#include <stdlib.h>
#include "node.h"

#define NUM_REGISTERS 4 // Needs to be one higher than the actual because my comparisons are weird
                        //TODO: Make comparisons not weird

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
    int array;
    int l_bound;
    int r_bound;

    struct tree_s *left;
    struct tree_s *right;
    int label;
} tree_t;

tree_t *mktree(int type, tree_t *left, tree_t *right);
tree_t *mktree_array(int type, tree_t *left, tree_t *right, int l_bound, int r_bound);
tree_t *mkarray(tree_t *t, int l_bound, int r_bound);
tree_t *mkid(node_t *id);
tree_t *mkinum(int inum);
tree_t *mkrnum(float rnum);
tree_t *mkop(int type, int attribute, tree_t *left, tree_t *right);
void tree_print(tree_t *tree);
void tree_label(tree_t *);
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "base_semantic.h"

arg_list_t *mkarg_list(int type) {
    arg_list_t *al = (arg_list_t*)malloc(sizeof(arg_list_t));
    assert(al != NULL);
    al -> type = type;
    al -> next = NULL;
    return al;
}

#pragma once

#include "common.h"

typedef struct arg_list_s {
    struct arg_list_s *next;
    int type;
} arg_list_t;

arg_list_t *mkarg_list(int type);
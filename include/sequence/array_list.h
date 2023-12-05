#ifndef _CONTAINERS_SEQUENCE_ARRAY_LIST_H_
#define _CONTAINERS_SEQUENCE_ARRAY_LIST_H_

#include <stdio.h>

typedef struct array_list{
    size_t capacity;
    size_t size;
    int * arr;
    void (*display)(struct array_list*);
} array_list;


array_list* init_array_list();
void display_list(array_list*);
#endif
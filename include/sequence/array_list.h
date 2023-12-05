#ifndef _CONTAINERS_SEQUENCE_ARRAY_LIST_H_
#define _CONTAINERS_SEQUENCE_ARRAY_LIST_H_

#include <stdio.h>
#include <common/util.h>

typedef struct array_list{
    size_t capacity;
    size_t size;
    int * arr;
    void (*display)(struct array_list*);
    void (*push)(struct array_list*, int);
    void (*insert) (struct array_list*, int, int);
    void (*replace) (struct array_list*, int, int);
    void (*pop) (struct array_list* list);
    response* (*get) (struct array_list* list, int);
} array_list;

/*
Intitialize array list with size 0
*/
array_list* init_array_list();
#endif
#ifndef _CONTAINERS_SEQUENCE_ARRAY_LIST_H_
#define _CONTAINERS_SEQUENCE_ARRAY_LIST_H_

#include <stdio.h>

typedef struct array_list{
    size_t capacity;
    size_t size;
    int * arr;
    void (*display)(struct array_list*);
    void (*push)(struct array_list*, int);
    void (*insert) (struct array_list*, int, int);
} array_list;

/*
Intitialize array list with size 0
*/
array_list* init_array_list();

/*
push item into array list at the back
*/
void push_into_array_list(array_list* list, int item);

/*
insert item into array list at specific index and increases the size 
*/
void insert_into_array_list(array_list*, int index, int item);

/*
Displays contents of array_list along with size and capacity
*/
void display_array_list(array_list* list);
#endif
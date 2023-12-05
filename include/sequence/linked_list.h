#ifndef _CONTAINERS_SEQUENCE_LINKED_LIST_H_
#define _CONTAINERS_SEQUENCE_LINKED_LIST_H_

#include <common/util.h>

typedef struct node {
    int val;
    struct node* next;
} node;

typedef struct linked_list {
    int size;
    node* head;
    node* tail;
} linked_list;

linked_list* init_linked_list();

#endif
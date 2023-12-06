#ifndef _CONTAINERS_SEQUENCE_LINKED_LIST_H_
#define _CONTAINERS_SEQUENCE_LINKED_LIST_H_

#include <common/util.h>

typedef struct node {
    int val;
    struct node* next;
} node;

typedef struct linked_list {
    size_t size;
    node* head;
    node* tail;
    void (*display)(struct linked_list*);
    void (*push)(struct linked_list*, int);
    void (*insert)(struct linked_list*, int, int);
} linked_list;

linked_list* init_linked_list();

#endif
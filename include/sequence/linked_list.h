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

    /*
    * Displays the array list in array form
    * @param this
    */
    void (*display)(struct linked_list*);

    /*
    * push an iten at the back of linked_list
    * @param this
    * @param item to be inserted
    */
    void (*push)(struct linked_list*, int);

    /*
    * insert an item into array list at specific index
    * @param this
    * @param index at which item is to be inserted
    * @param item to be inserted
    */
    void (*insert) (struct linked_list*, int, int);

    /*
    * Replaces an item at specific index
    * @param this
    * @param index at which item is to be replaced
    * @param new item that will replace old item
    */
    void (*replace) (struct linked_list*, int, int);

    /*
    * Remove an item from specified index
    * @param this
    * @param index from which item to be removed
    */
    void (*remove) (struct linked_list*, int);

    /*
    * Pop an item from the back of the array_list
    * @param this
    */
    void (*pop) (struct linked_list* list);

    /*
    * Returns an item at specified index
    * @param this
    * @param index from which item is to be returned
    * @return response{error:const char*, value:int} -> error is empty if error occured.
    */
    response* (*get) (struct linked_list* list, int);
} linked_list;

linked_list* init_linked_list();

#endif
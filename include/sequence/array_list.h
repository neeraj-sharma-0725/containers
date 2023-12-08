#ifndef _CONTAINERS_SEQUENCE_ARRAY_LIST_H_
#define _CONTAINERS_SEQUENCE_ARRAY_LIST_H_

#include <stdio.h>
#include <common/util.h>

typedef struct array_list{
    size_t capacity;
    size_t size;
    int * arr;
    /*
    * Displays the array list in array form
    * @param this
    */
    void (*display)(struct array_list*);

    /*
    * push an iten at the back of array_list
    * @param this
    * @param item to be inserted
    */
    void (*push)(struct array_list*, int);

    /*
    * insert an item into array list at specific index
    * @param this
    * @param index at which item is to be inserted
    * @param item to be inserted
    */
    void (*insert) (struct array_list*, int, int);

    /*
    * Replaces an item at specific index
    * @param this
    * @param index at which item is to be replaced
    * @param new item that will replace old item
    */
    void (*replace) (struct array_list*, int, int);

    /*
    * Remove an item from specified index
    * @param this
    * @param index from which item to be removed
    */
    void (*remove) (struct array_list*, int);

    /*
    * Pop an item from the back of the array_list
    * @param this
    */
    void (*pop) (struct array_list* list);

    /*
    * Returns an item at specified index
    * @param this
    * @param index from which item is to be returned
    * @return response{error:const char*, value:int} -> error is empty if error occured.
    */
    response* (*get) (struct array_list* list, int);
} array_list;

array_list* init_array_list();
void delete_array_list(array_list*);
#endif
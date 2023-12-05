#include <sequence/linked_list.h>

linked_list* init_linked_list(){
    linked_list* list = (linked_list*) malloc(sizeof(linked_list));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    
}
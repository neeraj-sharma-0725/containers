#include <stdio.h>
#include <sequence/linked_list.h>
#include <sequence/array_list.h>

int main(){
    linked_list* list = init_linked_list();
    list->push(list, 3);
    list->push(list, 5);
    list->insert(list, 1, 4);
    list->insert(list, 0, 1);
    list->insert(list, 4, 7);
    list->display(list);
    list->insert(list, -1, 5);
    list->insert(list, 6, 3);
    return 0;
}
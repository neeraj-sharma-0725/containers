#include <stdio.h>
#include <sequence/linked_list.h>
#include <sequence/array_list.h>

int main(){
    array_list* list = init_array_list();
    list->push(list, 2);
    list->push(list, 5);
    list->push(list, 8);
    list->push(list, 15);
    list->push(list, 21);
    list->push(list, 23);
    list->insert(list, 0, 1);
    list->insert(list, 3, 7);
    list->insert(list, 8, 25);
    list->display(list);
    list->remove(list, 0);
    list->display(list);
    return 0;
}
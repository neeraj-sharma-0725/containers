#include <stdio.h>
#include <sequence/array_list.h>

int main(){
    array_list* list = init_array_list();
    list->push(list, 3);
    list->push(list, 5);
    list->push(list, 9);
    list->push(list, 11);
    list->display(list);
    list->insert(list, 2, 7);
    list->display(list);
}
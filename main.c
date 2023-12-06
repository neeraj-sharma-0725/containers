#include <stdio.h>
#include <sequence/linked_list.h>

int main(){
    linked_list* list = init_linked_list();
    list->push(list, 5);
    list->push(list, 7);
    list->push(list, 10);
    list->display(list);
    return 0;
}
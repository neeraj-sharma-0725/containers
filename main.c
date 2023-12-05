#include <stdio.h>
#include <sequence/array_list.h>

int main(){
    array_list* list = init_array_list();
    list->display(list);
}
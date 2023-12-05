#include <sequence/array_list.h>

#include <stdlib.h>

array_list* init_array_list(){
    array_list* list = (array_list*) malloc(sizeof(array_list));
    list->capacity = 0;
    list->size = 0;
    list->display = display_list;
    return list;
}

void display_list(array_list* list){
    printf("[");
    for(size_t i = 0; i < list->size; i++){
        printf("%d", list->arr[i]);
        if(i != list->size - 1){
            printf(",");
        }
    }
    printf("]\n");
}


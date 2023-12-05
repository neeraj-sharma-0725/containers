#include <sequence/array_list.h>
#include <stdlib.h>

void expand_array_list(array_list* list){
    list->capacity = list->capacity == 0 ? 1 : list->capacity * 2;
    int* arr = (int*) malloc(list->capacity);
    for(size_t i = 0; i < list->size; i++){
        arr[i] = list->arr[i];
    }
    free(list->arr);
    list->arr = arr;
}

void shrink_array_list(array_list* list){

}

void push_into_array_list(array_list* list, int item){
    if(list->capacity <= list->size){
        expand_array_list(list);
    }
    list->arr[list->size++] = item;
}

void insert_into_array_list(array_list* list, int index, int item){
    if(index > list->size){
        fprintf(stderr, "Array index out of bounds \n");
        return;
    }
    if(list->capacity <= list->size){
        expand_array_list(list);
    }
    for(size_t i = list->size++; i > index; i--){
        list->arr[i] = list->arr[i-1];
    }
    list->arr[index] = item;
}

void display_array_list(array_list* list){
    printf("{\n");
    printf("\tcapacity: %lu,\n", list->capacity);
    printf("\tsize: %lu,\n", list->size);
    printf("\tarr:[");
    for(size_t i = 0; i < list->size; i++){
        printf("%d", list->arr[i]);
        if(i != list->size - 1){
            printf(", ");
        }
    }
    printf("]\n");
    printf("}\n");
}

void pop_from_array_list(array_list* list){
    
}

array_list* init_array_list(){
    array_list* list = (array_list*) malloc(sizeof(array_list));
    list->capacity = 0;
    list->size = 0;
    list->display = display_array_list;
    list->push = push_into_array_list;
    list->insert = insert_into_array_list;
    list->pop = pop_from_array_list;
    return list;
}

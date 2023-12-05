#include <sequence/array_list.h>
#include <stdlib.h>
#include <string.h>

void expand_array_list(array_list* list){
    list->capacity = list->capacity == 0 ? 1 : list->capacity * 2;
    int* arr = (int*) malloc(list->capacity * sizeof(int));
    for(size_t i = 0; i < list->size; i++){
        arr[i] = list->arr[i];
    }
    free(list->arr);
    list->arr = arr;
}

void shrink_array_list(array_list* list){
    if(list->size == 0) free(list->arr);
    list->capacity = list->capacity/2;
    int* arr = (int*)malloc(list->capacity * sizeof(int));
    for(int i = 0; i < list->size; i++){
        arr[i] = list->arr[i];
    }
    free(list->arr);
    list->arr = arr;
}

void push_into_array_list(array_list* list, int item){
    if(list->capacity <= list->size){
        expand_array_list(list);
    }
    list->arr[list->size++] = item;
}

void insert_into_array_list(array_list* list, int index, int item){
    if(index > list->size){
        fprintf(stderr, "array index out of bounds \n");
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

void replace_in_array_list(array_list* list, int index, int item){
    if(index >= list->size){
        fprintf(stderr, "array index out of bounds \n");
        return;
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
    if(list->size <= 0){
        fprintf(stderr, "array is empty\n");
        return;
    }
    list->size--;
    if(list->size <= list->capacity/2){
        shrink_array_list(list);
    }
}

response* get_from_array_list(array_list* list, int index){
    response* resp = (response*)malloc(sizeof(response));
    if(index >= list->size){
        resp->error = strdup("array index out of bounds\n");
    } else {
        resp->error = NULL;
        resp->value = list->arr[index];
    }
    return resp;
}

array_list* init_array_list(){
    array_list* list = (array_list*) malloc(sizeof(array_list));
    list->capacity = 0;
    list->size = 0;
    list->display = display_array_list;
    list->push = push_into_array_list;
    list->insert = insert_into_array_list;
    list->pop = pop_from_array_list;
    list->replace = replace_in_array_list;
    list->get = get_from_array_list;
    return list;
}

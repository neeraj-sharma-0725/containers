#include <sequence/linked_list.h>
#include <stdlib.h>

node* create_node(int item){
    node* nd = (node*) malloc(sizeof(node));
    nd->val = item;
    return nd;
}

void push_into_linked_list(linked_list* list, int item){
    node* nd = create_node(item);
    if(list->head){
        list->tail->next = nd;
        list->tail = list->tail->next;
    } else {
        list->tail = list->head = nd;
    }
}

void insert_into_linked_list(linked_list* list, int index, int item){
    if(index > list->size){
        fprintf(stderr, "array index out of bounds \n");
        return;
    }
    
}

void display_linked_list(linked_list* list){
    printf("{\n");
    printf("\tsize: %lu,\n", list->size);
    printf("\tlist:[");
    node* nd = list->head;
    while(nd){
        printf("(%d)", nd->val);
        nd = nd->next;
        if(nd){
            printf("->");
        }
    }
    printf("]\n");
    printf("}\n");
}

linked_list* init_linked_list(){
    linked_list* list = (linked_list*) malloc(sizeof(linked_list));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    list->display = display_linked_list;
    list->push = push_into_linked_list;
    list->insert = insert_into_linked_list;
    return list;
}
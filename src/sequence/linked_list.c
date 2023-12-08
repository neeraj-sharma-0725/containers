#include <sequence/linked_list.h>
#include <stdlib.h>

const char* INVALID_INDEX = "invalid index\n";

node* create_node(int item){
    node* nd = (node*) malloc(sizeof(node));
    nd->val = item;
    return nd;
}

void push_front(linked_list* list, int item){
    node* nd = create_node(item);
    nd->next = list->head;
    list->head = nd;
}

void push_back(linked_list* list, int item){
    list->tail->next = create_node(item);
    list->tail = list->tail->next;
}

void push_into_linked_list(linked_list* list, int item){
    if(!list->head){
        push_front(list, item);
        list->tail = list->head;
    } else {
        push_back(list, item);
    }
    list->size++;
}

void insert_into_linked_list(linked_list* list, int index, int item){
    if(index < 0 || index > list->size){
        fprintf(stderr, "%s", INVALID_INDEX);
        return;
    }
    if(index == 0){
        push_front(list, item);
    } else if(index == list->size){
        push_back(list, item);
    } else {
        node* nd = list->head;
        while(--index){
            nd = nd->next;
        }
        node* next = nd->next;
        nd->next = create_node(item);
        nd->next->next = next;
        }
    list->size++;
}

void replace_in_linked_list(linked_list* list, int index, int item){
    if(index < 0 || index >= list->size){
        fprintf(stderr, "%s", INVALID_INDEX);
        return;
    }
    node* nd = list->head;
    while(index--){
        nd = nd->next;
    }
    nd->val = item;
}

void remove_from_linked_list(linked_list* list, int index, int item){
    if(index < 0 || index >= list->size){
        fprintf(stderr, "%s", INVALID_INDEX);
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
    list->replace = replace_in_linked_list;
    list->remove = remove_from_linked_list;
    return list;
}
#include <stdio.h>
#include <stdlib.h>
struct list{
    int data;
    struct list*next;
};

void append(struct list * array, int element){
    struct list *new_place=(struct list*)malloc(sizeof(struct list));
    while(array->next!=NULL){
        array=array->next;
    }
    array->next=new_place;
    new_place->next=NULL;
    new_place->data=element;
    
}
void printList(struct list* head)
{
    while (head->next != NULL) {
        printf(" %d ", head->data);
        head = head->next;
    }
    printf(" %d ", head->data);
}

int main(){
    struct list *head=(struct list*)malloc(sizeof(struct list));
    struct list *second=(struct list*)malloc(sizeof(struct list));
    struct list *third=(struct list*)malloc(sizeof(struct list));
    head->data=1;
    second->data=2;
    third->data=3;
    head->next=second;
    second->next=third;
    third->next=NULL;
    append(head,2);
    printList(head);
    return 0;
}

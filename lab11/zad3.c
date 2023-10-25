#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


struct tnode{
    char value;
    struct tnode *next;
};

void add_end(struct tnode **head, char val){
    struct tnode *newnode=malloc(sizeof(struct tnode));
    newnode->value=val;
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
        return;
    }
    struct tnode *current = *head;
    while(current->next != NULL){
        current=current->next;
    }
    current->next=newnode;
}

void print_list(struct tnode **head){
    struct tnode *current = *head;
    while(current != NULL){
        printf("%c-> ", current->value);
        current=current->next;
    }
    printf("\n");
}

void free_list(struct tnode **head){
    struct tnode *current = *head;
    while(current!=NULL){
        struct tnode *temp = current;
        current=current->next;
        free(temp);
    }
    *head=NULL;
}

void add_front(struct tnode **head, struct tnode *elem){
    if(elem==NULL){
        return;
    }
    elem->next=*head;
    *head=elem;
}

struct tnode *delete_list(struct tnode **head, char c) {
    struct tnode *current = *head;
    struct tnode *new_head = NULL;
    struct tnode *new = NULL;

    while (current != NULL) {
        if (current->value == c) {
            struct tnode *removed = current;
            current = current->next;
            removed->next = new;
            new = removed;
        } else {
            if (new_head == NULL) {
                new_head = current;
            }
            if (current->next != NULL && current->next->value == c) {
                struct tnode *removed = current->next;
                current->next = current->next->next;
                removed->next = new;
                new = removed;
            }
            current = current->next;
        }
    }

    *head = new_head;
    return new;
}



int main(void){
    struct tnode *head=NULL;
    add_end(&head, 't');
    add_end(&head, 'a');
    add_end(&head, 'v');
    add_end(&head, 'c');
    add_end(&head, 'a');
    print_list(&head);

    struct tnode *elem1=malloc(sizeof(struct tnode));
    elem1->value='k';
    elem1->next=NULL;
    add_front(&head, elem1);
    print_list(&head);
    struct tnode *left=NULL;
    left = delete_list(&head, 'a');
    print_list(&head);
    printf("\n");
    print_list(&left);
    return 0;
}
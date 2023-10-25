#include <stdlib.h>
#include <stdio.h>

typedef struct tnode {
    int value;
    struct tnode* next;
    struct tnode* prev;
} tnode;

void printNext(tnode* head) {
    printf("next: ");
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

void printPrev(tnode* tail) {
    printf("previous: ");
    while (tail != NULL) {
        printf("%d ", tail->value);
        tail = tail->prev;
    }
    printf("\n");
}

tnode* add_first(tnode* head, tnode* val) {
    val->next = head;
    if (head != NULL) {
        head->prev = val;
    }
    return val;
}

tnode* add_last(tnode* head, tnode* val) {
    if (head == NULL) {
        return val;
    }

    tnode* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = val;
    val->prev = curr;
    val->next = NULL;
    
    return head;
}

void free_list(tnode** head) {
    tnode* curr = *head;
    while (curr != NULL) {
        tnode* next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL; 
}

int main(void) {
    tnode* head = NULL;
    tnode* tail = NULL;

    for (int i = 1; i <= 5; i++) {
        tnode* new_node = (tnode*)malloc(sizeof(tnode));
        new_node->value = i;
        new_node->next = NULL;
        new_node->prev = NULL;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    printNext(head);

    printPrev(tail);

    tnode* newh = (tnode*)malloc(sizeof(tnode));
    newh->value = 0;
    newh->next = NULL;
    newh->prev = NULL;
    head = add_first(head, newh);

    tnode* newt = (tnode*)malloc(sizeof(tnode));
    newt->value = 6;
    newt->next = NULL;
    newt->prev = NULL;
    head = add_last(head, newt);

    printNext(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
    int value;
    struct tnode *next;
}node;

//void print_list(struct tnode*){

//}

struct tnode* add_el(struct tnode* head, struct tnode* el) {
    if (head == NULL) {
        head = el;
        el->next = head;
    } else {
        struct tnode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = el;
        el->next = head;
    }
    return head;
}

void print_list(node* head) {
    if (head == NULL) {
        printf("pusta:(");
        return;
    }

    node* cur = head;
    do {
        printf("%d ", cur->value);
        cur = cur->next;
    } while (cur != head);
    printf("\n");
}

void del_el(node** head, int var) {
    if (*head == NULL) {
        printf("pusta:(");
        return;
    }

    node* cur = *head;
    node* prev = NULL;

    while (cur->next != *head) {
        if (cur->value == var) {
            if (prev == NULL) {
                node* last = *head;

                while (last->next != *head) {
                    last = last->next;
                }
                *head = cur->next;
                last->next = *head;
                
                cur = *head;
            } else {
                prev->next = cur->next;
                node* temp = cur;
                cur = cur->next;
                free(temp);
            }
        } else {
            prev = cur;
            cur = cur->next;
        }
    }
    if (cur->value == var) {
        if (prev == NULL) {
            *head = NULL;
        } else {
            prev->next = cur->next;
        }
    }
}

void freelist(node** head) {
    if (*head == NULL) {
        return;
    }

    node* cur = *head;
    node* next_node = NULL;

    while (cur->next != *head) {
        next_node = cur->next;
        free(cur);
        cur = next_node;
    }

    free(cur);
}



int main(void){
    printf("dupa\n");
    node *head = NULL;
    node *el1 = (node*)malloc(sizeof(node));
    el1->value = 7;
    node *el2 = (node*)malloc(sizeof(node));
    el2->value = 20;

    head = add_el(head,el1);
    head = add_el(head,el2);
    print_list(head);

    

    del_el(&head,20);
    print_list(head);


    freelist(&head);
    free(el1);
    free(el2);
    return 0;
}
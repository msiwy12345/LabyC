#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int value;
    struct tnode* next;
};

void print_list(struct tnode* head) {
    if (head == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    struct tnode* current = head;

    do {
        printf("%d ", current->value);
        current = current->next;
    } while (current != head);

    printf("\n");
}

struct tnode* add_el(struct tnode* head, struct tnode* el) {
    if (head == NULL) {
        head = el;
        el->next = head;
        return head;
    }

    struct tnode* current = head;

    while (current->next != head) {
        current = current->next;
    }

    current->next = el;
    el->next = head;
    return head;
}

void del_el(struct tnode** head, int var) {
    if (*head == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    struct tnode* current = *head;
    struct tnode* prev = NULL;

    while (current->next != *head) {
        if (current->value == var) {
            if (prev == NULL) {
                struct tnode* last = *head;

                while (last->next != *head) {
                    last = last->next;
                }

                *head = current->next;
                last->next = *head;
                free(current);
                current = *head;
            } else {
                prev->next = current->next;
                struct tnode* temp = current;
                current = current->next;
                free(temp);
            }
        } else {
            prev = current;
            current = current->next;
        }
    }

    if (current->value == var) {
        if (prev == NULL) {
            *head = NULL;
            free(current);
        } else {
            prev->next = current->next;
            free(current);
        }
    }
}

void free_list(struct tnode** head) {
    if (*head == NULL) {
        printf("Lista jest pusta.\n");
        return;
    }

    struct tnode* current = *head;

    while (current->next != *head) {
        struct tnode* temp = current;
        current = current->next;
        free(temp);
    }

    free(current);
    *head = NULL;
}

int main() {
    struct tnode* head = NULL;


    print_list(head);

    struct tnode* el1 = (struct tnode*)malloc(sizeof(struct tnode));
    el1->value = 2;
    el1->next = NULL;
    head = add_el(head, el1);

    print_list(head);

    struct tnode* el2 = (struct tnode*)malloc(sizeof(struct tnode));
    el2->value = 5;
    el2->next = NULL;
    head = add_el(head, el2);

    struct tnode* el3 = (struct tnode*)malloc(sizeof(struct tnode));
    el3->value = 7;
    el3->next = NULL;
    head = add_el(head, el3);

    struct tnode* el4 = (struct tnode*)malloc(sizeof(struct tnode));
    el4->value = 3;
    el4->next = NULL;
    head = add_el(head, el4);

    print_list(head);

    del_el(&head, 5);

    print_list(head);

    del_el(&head, 3);

    print_list(head);

    free_list(&head);

    print_list(head);

    return 0;
}

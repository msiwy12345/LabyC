#include <stdlib.h>
#include <stdio.h>

typedef struct tnode {
    int value;
    struct tnode* next;
} tnode;

tnode* create(int value) {
    tnode* new = (tnode*)malloc(sizeof(tnode));
    if (new == NULL) {
        return NULL;
    }

    new->value = value;
    new->next = NULL;

    return new;
}

void printList(tnode* head) {
    printf("address \t\t value \t next\n");
    while (head != NULL) {
        printf("%p\t%d\t%p\n", (void*)head, head->value, (void*)head->next);
        head = head->next;
    }
}

void sortList(tnode** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }

    tnode* parhead = NULL;
    tnode* nieparhead = NULL;
    tnode* partail = NULL;
    tnode* niepartail = NULL;

    tnode* curr = *head;
    while (curr != NULL) {
        tnode* next = curr->next;

        if (curr->value % 2 == 0) {
            if (parhead == NULL) {
                parhead = curr;
                partail = curr;
            } else {
                partail->next = curr;
                partail = curr;
            }
        } else {
            if (nieparhead == NULL) {
                nieparhead = curr;
                niepartail = curr;
            } else {
                niepartail->next = curr;
                niepartail = curr;
            }
        }

        curr->next = NULL;

        curr = next;
    }

    if (parhead == NULL) {
        *head = nieparhead;
    } else {
        *head = parhead;
        partail->next = nieparhead;
    }
}

int main(void) {
    tnode* head = NULL;
    tnode* curr = NULL;
    int values[] = {5, 5, 14, 7, 3, 3, 4, 14, 10, 4};
    int numElements = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numElements; i++) {
        if (head == NULL) {
            head = create(values[i]);
            curr = head;
        } else {
            curr->next = create(values[i]);
            curr = curr->next;
        }
    }

    printList(head);
    sortList(&head);
    printf("\n\n");
    printList(head);
    curr = head;
    while (curr != NULL) {
        tnode* next = curr->next;
        free(curr);
        curr = next;
    }

    return 0;
}

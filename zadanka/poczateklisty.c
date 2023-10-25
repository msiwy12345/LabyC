#include <stdio.h>
#include <stdlib.h>

typedef struct tnode{
    int value;
    struct tnode *next;
}node;

node *insertbeginning(node *head, int val){
    node *temp=malloc(sizeof(node)); //alokacja na jeden element
    if(!temp){
        printf("blad alokacji\n");
        return head;
    }
    temp->value=val;
    temp->next=head;
    return temp;
}

node *insertend(node *head, int val){
    node *temp=malloc(sizeof(node));
    if(!temp){
        printf("blad alokacji");
        return NULL;
    }
    temp->value=val;
    temp->next=NULL;

    if(head){
        node *ele = head;
        while(ele->next){
            ele=ele->next;
        }
        ele->next=temp;
    }
    else{
        head=temp;
    }
    return head;
}

void printList(node *elem){
   if(!elem){
    printf("lista jest pusta");
    return;
   }
   while(elem){
    printf("[%p]=%d -> %p, ",elem,elem->value,elem->next);
    elem=elem->next;
   }
   printf("\n\n");
}

int main(void){
    
    node *head = insertbeginning(NULL,5);
    head = insertbeginning(head,20);
    printList(head);
    
    head=insertend(head,15);
    printList(head);
    
    return 0;
}
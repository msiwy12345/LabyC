#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node{
    int val;
    struct node *next;
}*head;

struct node *findmax (struct node *head){
    if(head==NULL){
        printf("nie ma listy i chuj\n");
        return 0;
    }

    int max=head->val;
    struct node *pierwszy=head;
    struct node *curr=head;
    struct node *prev=NULL;
    struct node *temp=NULL;
    int l=0;
    while(curr->next != NULL){
        if(curr->next->val>max){
            max=curr->next->val;
            prev=curr;
            temp=curr->next;
            l++;
        }
        curr=curr->next;
    }  
    if(l==0){
        return pierwszy;
    }

    return temp;
}

int main(void){

    struct node node1={9,NULL};
    struct node node2={7,NULL};
    struct node node3={3,NULL};
    struct node node4={4,NULL};
    head=&node1;
    node1.next=&node2;
    node2.next=&node3;
    node3.next=&node4;
    struct node *odp=findmax(head);
    printf("to jest najwiekszy element %d\n", odp->val);




    return 0;
}

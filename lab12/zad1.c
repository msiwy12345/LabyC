#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct elem{
    char a;
    int c;
    struct elem *next;
};

struct elem *create(char val){
    struct elem *current=malloc(sizeof(struct elem));
    current->a=val;
    current->c=1;
    current->next=NULL;
    return current;
}

int main(int argc, char *argv[]){




    return 0;
}
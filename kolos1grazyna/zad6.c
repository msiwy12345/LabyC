#include <stdio.h>
#include <stdlib.h>
typedef int* (*t_1)[5];
int main(void){
    t_1 tab = malloc(20*sizeof(int *));
    int j=0;
    for(int i=0;i<20;i++){
        tab[i][j]=malloc(sizeof(int)*3);
    }



    return 0;
}
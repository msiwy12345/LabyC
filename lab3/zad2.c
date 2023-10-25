#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(void){

    int abc[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            abc[i][j]=i;
            printf("%d ",abc[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(int i=0;i<5;i++){
        for(int j=0;j<i;j++){
            swap(*(abc+i)+j,*(abc+j)+i);
            
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            printf("%d ",abc[i][j]);
        }
        printf("\n");
    }

    return 0;
}
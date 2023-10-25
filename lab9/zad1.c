#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b){
    int *x=(int*)a;
    int *y=(int*)b;
    if(*x%2==0){
        if(*y%2==0){
            return 0;
        }
        else{
            return -1;
        }
    }
    if(*y%2==0){
        if(*x%2!=0){
            return 1;
        }
    }
    if(*y%2!=0 && *x%2!=0){
        return 0;
    }
}

int main(void){
    int tab_A[3][6] = {{1,-4,1,2,11,55},{12,2,32,2},{72,1,-32,2}};
    for(int i=0;i<3;i++){
        qsort(tab_A[i], 6, sizeof(int), compare);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            printf("%d ",tab_A[i][j]);
        }
        printf("\n");
    }

    return 0;
}
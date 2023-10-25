#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define M 5
#define N 5

int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}

int main(void){
    srand(time(0));
    int tab[M][N];
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            tab[i][j]=i_rand(0,9);
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");
    int (*wsk)[N]=tab;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(j%2==0){
                (*(wsk+i))[j]=0;
            }
            printf("%d ",tab[i][j]);
        }
         printf("\n");
    }
    return 0;
}
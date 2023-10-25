#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}

int main(void){
    srand(time(0));
    int n;
    scanf("%d", &n);

    int *table=malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        table[i]=i_rand(-5,5);
    }
    for(int i=0;i<n;i++){
        printf("%d ",table[i]);
    }
    printf("\n");
    int *ap=malloc(sizeof(int));
    int *an=malloc(sizeof(int));
    int k=0;
    int l=0;
    int f=n;
    for(int i=n-1;i>=0;i--){
        if(table[i]%2==0){
            ap=realloc(ap,(++k)*sizeof(int));
            ap[k-1]=table[i];
            table=realloc(table,(--f) * sizeof(int));
            
        }
        else{
            an=realloc(an,(++l)*sizeof(int));
            an[l-1]=table[i];
            table=realloc(table,(--f) * sizeof(int));
        }
    }
    for(int i=0;i<k;i++){
        printf("%d ",ap[i]);
    }
    printf("\n");
    for(int i=0;i<l;i++){
        printf("%d ",an[i]);
    }

    printf("\n");
    free(ap);
    free(an);
    free(table);
    return 0;
}
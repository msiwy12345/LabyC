#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_tab_all(int y,int a[][y], int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}

int compare(const void *a, const void *b){
    int *x=(int *)a;
    int *y=(int *)b;
    return *x-*y;
}

int main(void){
    srand(time(0));
    int **tab_3 = malloc( 15*sizeof(int*));
    int i=0, j=0;
    for(i = 0; i < 15; i++)  
        tab_3[i] = malloc(10 * sizeof(int));

    for(i = 0; i < 15; i++)
        for(j = 0; j < 10; j++)
            tab_3[i][j]  =  rand() % 21;

    int **tab_33 = malloc( 15 * sizeof(int*));

    tab_33[0] = malloc(10 * 15 * sizeof(int));
    for(i = 1; i < 15; i++)  
        tab_33[i] = tab_33[i-1] + 10 ;

    for(i = 0; i < 15; i++)
        for(j = 0; j < 10; j++)
            tab_33[i][j]  =  rand() % 21;

    int (*tab_333)[10] = malloc(10 * 15 * sizeof(int));

    for(i = 0; i < 15  ; i++)
        for(j = 0; j < 10; j++)
            tab_333[i][j]  =  rand() % 21;

    for(int i=0;i<15;i++){
        for(int j=0;j<10;j++){
            printf("%d ",tab_3[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    for(int i=0;i<15;i++){
        for(int j=0;j<10;j++){
            printf("%d ",tab_33[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
    for(int i=0;i<15;i++){
        for(int j=0;j<10;j++){
            printf("%d ",tab_333[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<15;i++){
        qsort(tab_3[i], 10, sizeof(tab_3[0]), compare);
    }
    printf("\n\n\n-----------------------\n\n\n");
    for(int i=0;i<15;i++){
        for(int j=0;j<10;j++){
            printf("%d ",tab_3[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<15;i++){
        qsort(tab_33[i], 10, sizeof(tab_3[0]), compare);
    }
    printf("\n\n\n-----------------------\n\n\n");
    for(int i=0;i<15;i++){
        for(int j=0;j<10;j++){
            printf("%d ",tab_33[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<15;i++){
        qsort(tab_333[i], 10, sizeof(tab_3[0]), compare);
    }
    printf("\n\n\n-----------------------\n\n\n");
    for(int i=0;i<15;i++){
        for(int j=0;j<10;j++){
            printf("%d ",tab_333[i][j]);
        }
        printf("\n");
    }


    return 0;
}
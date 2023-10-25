#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_rows(int n, int (*tab)[n], int x, int y){
    for(int i=0;i<n;i++){
        swap(*(tab+x)+i, *(tab+y)+i);
    }
}


int* find_min_ind (int *T_F, int len){  //T_F - wskaznik na pierwszy element
    int min = 0;
    for (int i = 1; i < len; i++)
        if(T_F[min] > T_F[i]) min = i;
    return T_F + min;
}

void sortowanie(int n, int (*tab)[n], int x){
    int k=0;
    
    for(int i=0;i<x-1;i++){
        int *min = find_min_ind(tab[i], n);
        int indeks=i;
        for(int j=i+1;j<x;j++){
            if(*min>*find_min_ind(tab[j], n)){
                min=find_min_ind(tab[j], n);
                indeks=j;
            }
        }
        swap_rows(n, tab, i, indeks);

    }
}

int main(void){

    int tab_A[3][6] = {{1,-4,1,2,11},{12,2,32,2},{72,2,-32,2}};
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            printf("%d ", tab_A[i][j]);
        }
        printf("\n");
    }
    sortowanie(6, tab_A, 3);
    printf("\n\n\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<6;j++){
            printf("%d ", tab_A[i][j]);
        }
        printf("\n");
    }

    int tab_B[4][3] = {{1,-24,1},{9,32,2},{5,64,1},{3,32,1}};
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            printf("%d ", tab_B[i][j]);
        }
        printf("\n");
    }
    sortowanie(3, tab_B, 4);
    printf("\n\n\n");
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            printf("%d ", tab_B[i][j]);
        }
        printf("\n");
    }

    return 0;
}
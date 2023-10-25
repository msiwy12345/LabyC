#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int suma (int *p, int len) { 
    int sum = 0;
  
    for (int i = 0; i < len; i++)
        sum += p[i];
  
    return sum;
}

void print_tab_all(int y,int a[][y], int x){
    int i, j;
    for (i = 0; i < x; i++){
        for (j = 0; j < y; j++)
        printf ("%3d", a[i][j]);
        printf ("\n");   }
    return;
}
int compare(const void *x, const void *y){
    int *a = (int *)x;
    int *b = (int *)y;
    return suma(a,6)-suma(b,6);
}

int compare1(const void *x, const void *y){
    return *(int*)x-*(int*)y;
}

int check(int y, int tab[][y], int x, int s){
    qsort(tab, x, sizeof(tab[0]), compare);
    
    int t[x];
    for(int i=0;i<x;i++){
        t[i]=suma(tab[i],y);
    }
    
    
    int *find=bsearch(&s, t, x, sizeof(int), compare1);
    if(find==NULL){
        return -1;
    }
    else{
        return find-t;
    }


}

int main(void){

    int tab_A[3][6] = {{1,-4,1,2,11},{12,0,0,0},{72,2,-32,2}};
    int f=check(6,tab_A,3,12);
    printf("we wierszu %d\n",f);


    return 0;
}
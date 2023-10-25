#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#define M 5
#define N 3

double suma (int *tab, int len) { 
    double ss = 0.0;
    for (int i = 0; i < len; i++)  
        ss+= tab[i]; 
    return ss;
}

double *tab_avg(int a[M][N], int n){
    double *avg = malloc(n*sizeof(double));
    printf("\n");
    for(int i=0;i<n;i++){
        avg[i]=suma(a[i], N)/N;
        //printf("%d ",avg[i]);
    }
    printf("\n");
    return avg;
}

int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}

int row_number(int a[M][N], int n){
    double *av = tab_avg(a, M);
    int sum=0;
    for(int i=0;i<M;i++){
        sum = sum + av[i];
    }
    double srednia = sum/M;
    int min=fabs(srednia - av[0]);
    int indeks=0;
    for(int i=0;i<M;i++){
        if(fabs(srednia-av[i]) < min){
            min = srednia -av[i];
            indeks=i;
        }
    }
    return indeks;
}

int main(void){
    srand(time(0));
    int tab[M][N];
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            tab[i][j]=i_rand(-5,5);
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    double *average=tab_avg(tab,M);
    for(int i=0;i<M;i++){
        printf("%f ",average[i]);
    }
    int id=row_number(tab, M);
    printf("\nwiersz o najmniejszej roznicy wzgledem srednich to: %d \n", id);
    return 0;
}
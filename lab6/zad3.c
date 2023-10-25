#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double min(double tab[], int n){
    double min=tab[0];
    for(int i=0;i<n;i++){
        if(min>tab[i]){
            min=tab[i];
        }
    }
    return min;
}

double max(double tab[], int n){
    double max=tab[0];
    for(int i=0;i<n;i++){
        if(max<tab[i]){
            max=tab[i];
        }
    }
    return max;
}

double min_or_max(double *tab, int n, double (*f)(double *, int)){
    return (*f)(tab,n);
}

int main(void){
    double tab_A [] = {-12.0, 41.5, 3.6, 1.23, 6.15, -32.1};
    double tab_B [] = {2.0, 4.0, 6.5, -2.1};
    int a=sizeof(tab_A)/sizeof(double);
    int b=sizeof(tab_B)/sizeof(double);
    double r1=fabs(min_or_max(tab_A, a, max)-min_or_max(tab_A, a, min));
    printf("%f %d\n", r1, a);
    double r2=min_or_max(tab_B, b, max)-min_or_max(tab_B, b, min);
    printf("%f %d \n", r2, b);


    return 0;
}
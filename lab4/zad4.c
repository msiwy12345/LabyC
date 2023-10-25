#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

double *iloraz(int *a, int *b){
    double il = fabs(*a / *b);
    double *ret=malloc(sizeof(double));
    *ret=il;
    return ret;
}

int main(void){
    int a=6, b=3;
    double *dupa=iloraz(&a,&b);
    printf("%f to iloraz\n",*dupa);
    return 0;
}
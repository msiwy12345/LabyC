#include <stdio.h>
#include <stdlib.h>

void wypisz_d (double *poczatek, double *koniec) { 
    while (poczatek < koniec) 
        printf ("%6.2f", *poczatek++); 
    printf ("\n");    
    return;
}

void odwroctablice(double tab[],int start, int end){
    while(start<end){
        double temp=tab[start];
        tab[start]=tab[end];
        tab[end]=temp;
        start++;
        end--;
    }
}

void swap_pointer(double **a, double **b){
    double *temp=*a;
    *a=*b;
    *b=temp;
}

int main(void){

    printf("dupa\n");
    double tab2[]={1,2,3,4,5,6,7};
    double *tab1[]={tab2, tab2+1, tab2+2, tab2+3, tab2+4, tab2+5, tab2+6};
    double **wsk=&tab1[0];
    wypisz_d(*wsk, *wsk+7);
    for(int i=0;i<7;i++){
        printf("%p \n",&wsk[i]);
    }

    //przesuniecie cykliczne

    int p=6;
    int n=7;
    p=p%n;
    odwroctablice(*tab1, 0, n-1);
    odwroctablice(*tab1, 0, p-1);
    odwroctablice(*tab1, p, n-1);    
    wypisz_d(*wsk, *wsk+7);
/*
    int i=0, j=6;
    while(i<j){
        swap_pointer(wsk+i,wsk+j);
        i++;
        j--;
    }
    for(int i=0;i<7;i++){
        printf("%f ",*tab1[i]);
    }
    printf("\n");
    wypisz_d(*wsk-6, *wsk+1);
*/
    double **wsk1=&tab1[0];
    
    wsk1=wsk1+6;
    swap_pointer(wsk, wsk1);
    for(int i=0;i<7;i++){
        printf("%f ",*tab1[i]);
    }
    printf("\n");
    wypisz_d(*wsk-6, *wsk+1);
    return 0;
}
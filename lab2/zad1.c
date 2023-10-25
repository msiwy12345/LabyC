#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int find_min(int *t, int n){
    int min=*t;
    int indeks=0;
    for(int i=0;i<n;i++){
        if(*(t+i)<min){
            min=*(t+i);
            indeks=i;
        }
    }
    return indeks;
}

void sort(int *p, int *k){
    while(p<k){
        int ind = find_min(p,k-p);
        swap(p,p+ind);
        *p++;
    }
}

void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
    printf ("\n");    
    return;}



int main(void){

    int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,22,12,6,8,4,44,6,42,2,16,5,33,1,7,9,55,1,11,22,34,78,11,21,9,12,5,3,9};
    int n=sizeof(tab_A)/sizeof(tab_A[0]);
    int indeks = find_min(tab_A,n);
    printf("indeks: %d, liczba: %d\n",indeks,tab_A[indeks]);
    for(int i=0;i<n;i=i+10){
        wypisz_i(tab_A+i, tab_A+i+10);
        int id=find_min(tab_A+i,10);
        printf("najmniejszy element to %d, o indeksie %d, oraz adresie %p\n",tab_A[id+i],id+i, &tab_A[id+i]);
    }
    
    for(int i=0;i<n;i=i+10){
        sort(tab_A+i, tab_A+i+10);
        wypisz_i(tab_A+i, tab_A+i+10);
    }
    return 0;
}
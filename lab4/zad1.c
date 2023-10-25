#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void wypelnij(double (*A)[6], int n){
    double c=-0.4;
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            c=c+0.4;
            A[i][j]=c;
        }
    }
}

void wypisz_d (double *poczatek, double *koniec) { 
    while (poczatek < koniec) 
        printf ("%6.2f", *poczatek++); 
    printf ("\n");    
    return;
}



int main(void){

    double a1[8][6];
    double a2[10][6];
    wypelnij(a1,8);
    wypelnij(a2,10);
    wypisz_d(*a1,*(a1+8));
    printf("\n");
    for(int i=0;i<8;i++){
        wypisz_d(*(a1+i), *(a1+i)+6);
    }




    return 0;
}
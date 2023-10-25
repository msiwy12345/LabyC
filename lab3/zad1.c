#include <stdlib.h>
#include <stdio.h>
#define M 5
#define N 4
#include <time.h>

//generowanie liczb losowych calkowitych z przedziału (min, max)
int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}
    //generowanie liczb losowych rzeczywistych z przedziału (min, max)
double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
}
void wypisz_i (int *poczatek, int *koniec) { 
    while (poczatek < koniec) 
        printf ("%4d ", *poczatek++);   
        printf ("\n");    
    return;
}
void wypisz_d (double *poczatek, double *koniec) { 
    while (poczatek < koniec) 
        printf ("%6.2f", *poczatek++); 
    printf ("\n");    
    return;
}
int suma (int *tab, int len) { 
    int ss = 0.0;
    for (int i = 0; i < len; i++)  
        ss+= tab[i]; 
    return ss;
}
double suma1 (double *tab, int len) { 
    double ss = 0.0;
    for (int i = 0; i < len; i++)  
        ss+= tab[i]; 
    return ss;
}
int find_min_ind (int *T_F, int *T_L){  //poczatek i koniec (T_F - wskaznik na pierwszy element, T_L wskaznik za ostatni element) obszaru tablicy gdzie szukamy minimum
    int min = 0;
    for (int i = 1; i < T_L - T_F; i++)
        if(T_F[min] > T_F[i]) min = i;
    
    return min;
}
int main(void){
    srand(time(0));
    int tab[M][N];
    double avgabc[M];
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            tab[i][j]=i_rand(-10,10);
        }
    }
    for(int i=0;i<M;i++){
        wypisz_i(*(tab+i),*(tab+i)+N);
    }
    for(int i=0;i<M;i++){
        avgabc[i]=(double)suma(*(tab+i),N)/N;
    }
    double avg_all_1 = (double)suma(*(tab+0)+0, sizeof(tab)/sizeof(tab[0][0]))/20;
    wypisz_d(avgabc,avgabc+M);
    double avg_all_2 = suma1(avgabc, sizeof(avgabc)/sizeof(avgabc[0]))/M;
    printf("srednia calej tablicy to: %f, a rozmiar to %d elementow, albo %f\n",avg_all_1,sizeof(tab)/sizeof(tab[0][0]), avg_all_2);
    
    int id=find_min_ind(*tab,*(tab+N)+M);
    
    int j=id/4;
    int k=id%4;
    
    printf("najmniejszy indeks %d,element %d, a jego adres to %p\n",id,tab[j][k], &tab[j][k]);
    
    
    
    
    
    
    
    
    
    
    return 0;
}
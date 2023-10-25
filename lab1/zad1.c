#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

int suma(const int *p, const int *end){   //nie używaj N 
    if (p!=end)
        return *p+suma(p+1,end);
    else
        return 0;
}

int main(void){

int tab[N];
srand(time(NULL));
//deklaracja tablicy 10 liczb całkowitych, użyj N
//deklaracja wskaźnika p do liczby całkowitej, użyj NULL
//nie używaj zmiennej int  do indeksowania tablicy
//przypisz kolejnym elementom tablicy liczby pseudolosowe z przedziału od 7 do 35 i wypisz je na ekran 
int *p=NULL;
    for(p=tab; p<tab+N ; p++){
       *p=rand()%(35-7+1)+7;  // nie korzystaj z tab 
		
//oblicz wartość indeksu kolejnych elementów tablicy, wypisz wartości kolejnych elementów używając p


       printf("p[%d] = %d\n", p-tab, *p);
}

printf("\n");

 
//oblicz rekurencyjnie sumę elementów tablicy.
p=tab;
int *end=tab+sizeof(tab)/sizeof(tab[0]);
    int su = suma(p, end);   //nie używaj N
    
    printf("su=%d\n",su);
    return 0;
    

 //funkcja rekurencyjna liczaca sume elementów tablicy  


}
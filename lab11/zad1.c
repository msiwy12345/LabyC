#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}

double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
}

union unia{
    int i;
    double d;
};

struct liczba{
    char a;
    union unia dane;
};

void struct_prn(struct liczba *tab, int n){
    for(int i=0;i<n;i++){
        if(tab[i].a=='i'){
            printf("int: %d", tab[i].dane.i);
        }
        else if(tab[i].a=='d'){
            printf("double: %lf", tab[i].dane.d);
        }
        printf("\n");
    }
}

int compare(const void *x, const void *y){
    struct liczba *aa = (struct liczba *)x;
    struct liczba *bb = (struct liczba *)y;

    if(aa->a=='i' && bb->a=='d'){
        return 1;
    }
    else if(aa->a=='d' && bb->a=='i'){
        return -1;
    }
    else{
        if(aa->a=='i'){
            return aa->dane.i - bb->dane.i;
        }
        else{
            return aa->dane.d - bb->dane.d;
        }
    }
}

void posortuj(struct liczba *tab, int n){
    qsort(tab, n, sizeof(struct liczba), compare);
}

int main(int argc, char *argv[]){
    srand(time(0));
    if(argc<2){
        printf("nie podales argumentu debilu");
        return 0;
    }
    int len=i_rand(10,20);
    struct liczba num[len];
    for(int i=0;i<len;i++){
        int l=i_rand(0,1);
        if(l==0){
            num[i].a='i';
            num[i].dane.i=i_rand(-5,5);
        }
        else{
            num[i].a='d';
            num[i].dane.d=d_rand(-5,5);
        }
    }

    struct_prn(num, len);

    FILE *plik;
    plik = fopen("plik.dat", "wb");

    if(plik==NULL){
        printf("nie mozna otworzyc pliku\n");
        return 0;
    }

    fwrite(num, sizeof(struct liczba), len, plik);
    fclose(plik);


    plik = fopen("plik.dat", "rb");
    fseek(plik, 0, SEEK_END);
    long wielkosc = ftell(plik);
    fclose(plik);
    printf("wielkosc pliku to :%ld bajtow\n",wielkosc);

    int n = wielkosc/sizeof(struct liczba);
    struct liczba TAB[n];
    plik = fopen("plik.dat", "rb");
    fread(TAB, sizeof(struct liczba), n, plik);

    fclose(plik);
    struct_prn(TAB, n);

    posortuj(num, len);
    printf("\n\n\n");

    struct_prn(num ,len);   
    char s=argv[1][0];
    struct liczba szukana;
    if(s=='i'){
        szukana.dane.i = atoi(argv[2]);
        szukana.a = 'i';
    }
    else if(s=='d'){
        szukana.dane.d = atof(argv[2]);
        szukana.a = 'd';
    }
    int id=0;
    printf("\n");
    struct liczba *p = bsearch(&szukana, num, len, sizeof(struct liczba), compare);
    if(p==NULL){
        printf("nie ma elementu\n");
        
    }
    else{
        while(p=bsearch(&szukana, num+id+1, len-id-1, sizeof(struct liczba), compare)){
            id=p-num;
            printf("%d ",id);
        }
    }

    

    return 0;
}
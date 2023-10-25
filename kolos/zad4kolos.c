#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct point{
    double z,x,y;
    char label[4];
};
int compare2(const void *x, const void *y){
    double *a = (double *) x;
}
int compare(const void *x, const void *y){
    struct point *a = (struct point *)x;
    struct point *b = (struct point *)y;
    return a->z - b->z;
}

int compareString(const void *x, const void *y){
    struct point *a = (struct point *)x;
    struct point *b = (struct point *)y;
    
    return strcmp(a->label,b->label);
}

int main(void){
    struct point tab[10][7];
    double n;
    scanf("%lf",&n);
    printf("%lf\n",n);
    double k=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<7;j++){
            tab[i][j].z=k++;
            printf("%f ",tab[i][j].z);
            tab[i][j].x = 0.0;
            tab[i][j].y = 0.0; 
            strcpy(tab[i][j].label, "dupa");
        }
        printf("\n");
    }
    qsort(tab, 10*7, sizeof(struct point), compare);
    struct point key;
    key.z=n;
    struct point *result = bsearch(&key, tab, 10*7, sizeof(struct point), compare);
    if(result != NULL){
        int indeks= result-&tab[0][0];
        int row=indeks/7;
        printf("twoje szukane znajduje w %d wierszu\n",row);

    }
    //polecenie b)

    char s[4];
    scanf("%s",s);
    printf("\n%s\n",s);
    strcpy(tab[0][2].label, "krok\0");
    qsort(tab, 10*7, sizeof(struct point), compareString);
    struct point klucz;
    strcpy(klucz.label, s);
    struct point *result1=bsearch(&klucz,tab,  10*7, sizeof(struct point), compareString);
    if(result1!=NULL){
        printf("string taki sie znajduje\n");
    }
    


    return 0;
}
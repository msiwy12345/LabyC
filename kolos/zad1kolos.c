#include <stdio.h>
#include <stdlib.h>

void savetofile(char *nazwa, void *a, size_t elementSize, size_t n){
    FILE *file = fopen(nazwa, "wb");

    size_t zapis = fwrite(a,elementSize, n, file);
    if(zapis==n){
        printf("tablica zapisana, rozmiary sie zgadzaja \n");
    }


    fclose(file);
}

int main(void){
    double *tab = realloc(NULL, 17*sizeof(*tab));
    for(int i=0;i<17;i++){
        tab[i]=1;
    }
    savetofile("dupa", tab, sizeof(*tab), 17);

    struct point{
        double x,y,z;
        char label[4];
    } tab2[13]={};
    savetofile("dupa1", tab2, sizeof(struct point), 13);

    return 0;
}
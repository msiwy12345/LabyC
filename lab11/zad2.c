#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

float *va_tables(int n, ...){
    va_list args;
    va_start(args, n);
    int total=0;
    for(int i=0;i<n;i++){
        float *table = va_arg(args, float*);
        int table_size=va_arg(args, int);
        total = total + table_size;
    }

    va_end(args);
    float *tablica=malloc(total*sizeof(float));
    va_start(args, n);
    int current=0;
    for(int i=0;i<n;i++){
        float *table = va_arg(args, float *);
        int table_size = va_arg(args, int);
        for(int j=0;j<table_size;j++){
            tablica[current++] = table[j];
        }
    }
    va_end(args);
    return tablica;
}

int main(void){
    float tab_W[] = {31, 32, 33, 34, 35, 36};
    float tab_X[] = {47};
    float tab_Y[] = {52, 50, 56, 55};
    float tab_Z[] = {62, 65, 66, 65, 67, 68, 69};

    float *result = va_tables(4, tab_W, 6, tab_X, 1, tab_Y, 4, tab_Z, 7);

    printf("Rezultat 1: tablica {");
    for (int i = 0; i < 18; i++) {
        printf("%.2f", result[i]);
        if (i < 17) {
            printf(", ");
        }
    }
    printf("}\n");

    FILE *plik = fopen("plik.txt", "w");
    if(plik!=NULL){
        fprintf(plik, "Rezultat 1: tablica {");
        for (int i = 0; i < 18; i++) {
            fprintf(plik, "%.2f", result[i]);
            if (i < 17) {
                fprintf(plik, ", ");
            }
    }
    printf("}\n");
    }
    fclose(plik);
    return 0;
}
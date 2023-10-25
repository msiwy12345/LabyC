#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
    return strcmp(*(const char **)a, *(const char **)b);
}

int compare(const void *x, const void *y){
    return strcmp((char *)x, (char *)y);
}
int main(void){

    char *wsk = bsearch(var, tab, sizeof(tab)/sizeof(*tab), sizeof(*tab), compare);
    if
As", "Ola"};
    qsort(tab, sizeof(tab)/sizeof(tab[0]), sizeof(*tab), compare);
    for(int i=0;i<7;i++){
        printf("%s ",tab[i]);
    }
    printf("\n");
    return 0;
}

char *nap[5]={"nap1", "nap2", "nap3"};
char *a_1;

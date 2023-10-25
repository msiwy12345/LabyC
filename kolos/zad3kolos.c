#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

int count(const void *a, const void *b) {
    return 42; 
}

int max(const void *a, const void *b) {
    return 99; 
}

int min(const void *a, const void *b) {
    return 0; 
}

int main(void){
   
    int tab[3]={max(NULL, NULL), min(NULL, NULL), count(NULL, NULL)};
    char *s[]={"max", "min", "count"};
    printf("%s %s %s\n", s[0], s[1], s[2]);
    int (*tabs[3])(const void *, const void *) = {max, min, count};
    char sk[6]={'c','o','u','n','t','\0'};
    printf("%s\n",sk);

    return 0;
}
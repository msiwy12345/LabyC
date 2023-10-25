#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>

char *f_napis(char *s, int n){
    char *odp=malloc((strlen(s)+1)*n);
    odp[0]='\0';
    for(int i=0;i<n;i++){
        strcat(odp, s);
        if(i<n-1){
            strcat(odp,";");
        }
    }
    
    return odp;
}

int main(void){
    char *result = f_napis("kot", 3);
    printf("%s\n", result);
    return 0;
}
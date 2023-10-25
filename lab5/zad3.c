#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

char *text_edit(char *t1, char *t2, char *t3){
    int n = strlen(t1);
    int k = strlen(t2);
    int m = strlen(t3);
    int length = n - k + m;
    char *odp=malloc(length*sizeof(char));
    odp[0]='\0';
    int f=0;
    while(f<n){
        char *result = strstr(t1+f, t2); // znalezienie pierwszego wystapienia
        if(result==NULL){
            strcat(odp, t1+f);
            break;
        }
        else{
            int id = result - t1; // indeks tego wystapienia
            
            strncat(odp, t1+f , id-f);
            //odp[id]='\0';
            strcat(odp, t3);
            f = id + k;
        }
        //f++;
    }
    
    return odp;

}

int main(void){
    char *t1 = "Jak sie nie ma, co sie lubi, to sie lubi, co sie ma";
    char *t2 = "sie";
    char *t3 = "Alicja";

    printf("%s\n%s\n%s\n", t1, t2, t3);
    char *s = text_edit(t1,t2,t3);
    printf("%s\n", s);

    return 0;
}
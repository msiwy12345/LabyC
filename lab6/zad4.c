#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc<2){
        printf("nie wpisales zadnych argumentow debilu\n");
        return 0;
    }

    printf("%s ||| %s\n", argv[1], argv[2]);
    char *a=argv[1];
    char *b=argv[2];
    int da=strlen(a);
    int db=strlen(b);
    int i=0;
    int wynik1=0;
    int wynik2=0;
    while (i<da){
        if(strstr(a+i,b)!=NULL){
            char *m=strstr(a+i,b);
            printf("\n\n%s\n\n",m);
            wynik1++;
            if(m[-1]==' ' && (m[db]==' ' || m[db]=='\0')){
                wynik2++;
            }
            i=m-a+db;
            
        }
        else{
            break;
        }
        i++;
    }
    printf("wyraz 1 wystepuje w wyrazie 2: %d raz, a jako osobny wyraz: %d\n",wynik1, wynik2);



    return 0;
}
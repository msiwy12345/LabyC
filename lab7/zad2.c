#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char **podziel(char *s, int *n){
    char **k=malloc(*n*sizeof(char*));
    
    char *token=strtok(s,", .;:-");
    int i=0;
    int check=0;
    while(token!=NULL){
        check=0;
        for(int j=0;j<i;j++){
            if(strcmp(token,k[j])==0){
                check=1;
            }
        }
        if(check==0){
            k[i]=strdup(token);
            i++;
        }
        token=strtok(NULL, ", .;:-");
    }
    *n=i;
    return k;

}

void sort(char **k, int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(strcmp(k[j], k[j+1]) > 0){
                char *p = k[j];
                k[j] = k[j+1];
                k[j+1] = p;
            }
        }
    }
}

char *sklej(char **k, int n){
    char *m = malloc(n*sizeof(char));
    m[0]='\0';
    for(int i=0;i<n;i++){
        strcat(m,k[i]);
        strcat(m," ");
    }
    return m;
}

int main(int argc, char *argv[]){
    if(argc<2){
        printf("nie podales zadnych argumentow\n");
        return 0;
    }
    char *s = argv[1];
    printf("%s\n",s);
    int n=strlen(s)+1;
    char **roz=podziel(s,&n);
    printf("to lancuch z unikalnych wyrazow: ");
    for(int i=0;i<n;i++){
        printf("%s ",roz[i]);
    }
    printf("\n");
    sort(roz, n);
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%s ",roz[i]);
    }
    printf("\n");
    char *odp=sklej(roz,n);
    printf("\n\nodpowiedz to: %s\n\n", odp);

    return 0;

}
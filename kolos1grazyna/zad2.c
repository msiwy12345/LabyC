#include <stdio.h>
#include <stdlib.h>

char fun1(char s[], char c){
    for(int i=0;s[i]!='\0';i++){
        if(s[i]==c){
            return s[i];
        }
    }
    return 0;
}

char *fun2(char *s, char c){
    while(*s){
        if(*s++==c){
            return --s;
        }
        
    }
    return NULL;
}

int main(void){
    char *s="dupa\0";
    char n='p';
    printf("%c %c \n", fun1(s, n), fun2(s,n));

    return 0;
}
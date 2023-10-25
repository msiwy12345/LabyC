#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}

void swap(char *a, char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

int main(void){
    srand(time(0));
    int n=i_rand(8,20);
    char s[n];
    for(int i=0;i<n;i++){
        int l=i_rand(0,1);
        if(l==0){
            s[i]=i_rand(97,122);
        }
        else{
            s[i]=i_rand(65,90);
        }
    }
    s[n]='\0';
    printf("to lancuch: %s\n",s);
    int i=0;
    int j=n+1;
    while(i<=n){
        j=n+1;
        while(s[i]>=65 && s[i]<=90){
            if(s[j]>=97 && s[j]<=122){
                swap(&s[i], &s[j]);           
            }
            else{
                j--;
                if (j < i + 1)
                    break;
            }
        }

        i++;
    }
    printf("lancuch po zmianie: %s \n",s);

    return 0;
}
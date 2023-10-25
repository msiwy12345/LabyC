#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
}

double d_rand(double min, double max){
    double r = (double) rand()/RAND_MAX;
    return r*(max-min) + min;
}

int main(void){
    srand(time(0)); 
    int n=i_rand(5,10);
    char s[n+1];
    for(int i=0;i<n;i++){
        int los=i_rand(0,1);
        s[i]=i_rand(97,122);
    }
    s[n]='\0';
    printf("%s\n",s);
    char sam[]={"aeiouAEIOU"};
    for(int j=0;j<5;j++){
        char szukane=sam[j];
        char *result = strchr(s,szukane);
        if(result != NULL){
            s[result-s] = sam[j+5];
        }
    }

    printf("po zamianie: %s\n",s);

    return 0;
}
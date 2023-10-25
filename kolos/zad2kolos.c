#include <stdio.h>
#include <stdlib.h>

void proc(float T[][5], int rows){
    for(int i=0;i<rows;i++){
        for(int j=0;j<5;j++){
            printf("%f ", T[i][j]);
        }
        printf("\n");
    }
}



int main(void){
    int rows=3;
    float(*ar)[5];
    ar=realloc(NULL, 5*rows*sizeof(float));
    
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<5;j++){
            ar[i][j]=1;
            
        }
    }
    proc(ar, rows);

    free(ar);
    return 0;
}
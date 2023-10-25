#include <stdio.h>
#include <stdlib.h>

float suma1(float *t, int n, float *min){
    float suma=0;
    *min=*t;
    for(int i=0;i<n;i++){
        suma=suma+*(t+i);
        if(*(t+i)<*min){
            *min=*(t+i);
        }
    }
    return suma;
}

int main(void){
    float tab[] = {1, 2, 3, 4, 5};
    int n = sizeof(tab) / sizeof(tab[0]);
    float min;
    float sum = suma1(tab, n, &min);
    
    printf("suma wynosi: %f\n", sum);
    printf("a najmniejszy element to: %f", min);
    return 0;
}
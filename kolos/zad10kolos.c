#include <stdio.h>
#include <stdlib.h>

#define raz(a,b) (a)<(b)?(a):(b)
#define dwa(x) 2*x
#define trzy(x) printf("%s = %d\n", #x, x)

int main(void){
    int x=3, y=4, m= raz(x++, y++);
    printf("x=%d, y=%d, m=%d \n",x,y,m);
    double n =47/dwa(2);
    printf("n =%f\n",n);
    trzy(2*2+6);

    return 0;
}
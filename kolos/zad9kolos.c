#include <stdio.h>
#include <stdlib.h>

#define N 4
#define M 3

int main(void){

    int t[N][M]={1,3,5,8,0,2,7,12,9,4,6,10};
    printf("t[0][0]=%d &t[0][0]=%p\n", t[0][0], &t[0][0]);

    printf("t[0]+1=%p, t+2=%p, *(t+1)=%p, *(t[0]+2)=%d, *t=%p, **t+1=%d, *(t+2)+2=%p\n",
           t[0]+1, t+2, *(t+1), *(t[0]+2), *t, **t+1, *(t+2)+2);

    return 0;
}

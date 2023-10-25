#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct point{
    double x, y, z;
    char label[4];

};



int icmp (const void* x, const void *y){
    struct point *a = (struct point*) x;
    struct point *b = (struct point*) y;
    return (a->z)-(b->z);
}
int icmp2(const void *x, const void *y){
    double *a = (double *) x;
}


int main(){
    struct point TAB[10][7];
    double a, k = 0, o = 30, p = 60;
    scanf("%lf",&a);
    double key = a;
    printf("%lf\n", a);

    int  i, j;
    for(i=0;i<10;i++){
        for(j=0;j<7;j++){
            TAB[i][j].x=k++;
            TAB[i][j].y=1.0;
            TAB[i][j].z=0.0;
            strcpy(TAB[i][j].label,"siwy");
        }
        printf("%lf  ",TAB[i][j].y);
    }
    qsort(tab, 70, sizeof(tab), icmp);
    struct point *result = bsearch(&key, TAB, 70, sizeof(TAB), icmp);








    return 0;
}
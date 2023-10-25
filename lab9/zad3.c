#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float  min (float *f, float *l){
	float a = *f++;
	while (f<l){
	   if (a > *f) a = *f;
	   f++;
	}
return a;
}

float  max (float *f, float *l){
	float a = *f++;
	while (f<l){
	   if (a < *f) a = *f;
	   f++;
	}
return a;
}

float  avg (float *f, float *l){
	float sum = 0.;
	int i = l-f;
	while (f<l)
    	   sum += *f++;

return sum/i;
}

float  mid (float *f, float *l){
return *(f+(l-f)/2);
}

void print_fun(float (*f)(float *, float *), char *s, float(*tab)[8], int x){
	float y=8;
     for(int i=0;i<x;i++){
		printf("%s(%d)=%f, ", s, i, f(tab[i], tab[i]+8));
	 }
	 printf("\n");
}

int main(void){
    char* name[]={"min", "max","avg","mid"};
    float data[4][8] = { { -0.5, 1.0, 1.5, 2.0, 2.1, 3.0, 3.5, 4.0 },
                         { 2.5, 3.1, -1.5, 4.1, 2.5, 3.0, 3.5, 4.1 },
                         { 1.5, -2.0, 0.5, 2.7, 2.8, 3.0, 1.5, 2.0 },
                         { 0.5, 3.0, 0.5, 2.0, 2.3, 6.0, 3.5, -1.0 }};


    float (*tab_fun[5])(float *, float *);
    tab_fun[0] = min; 
    tab_fun[1] = max;
    tab_fun[2] = avg; 
    tab_fun[3] = mid;
    tab_fun[4] = NULL;
	float (**wsk_fun)(float *, float*);
	print_fun(min, name[0], data, 4);
	wsk_fun = tab_fun;
	char **str;
    str = name;
	for(int i=0;i<5;i++){
		print_fun(*(wsk_fun+i), *(str+i), data, 4);
	}

    return 0;
}
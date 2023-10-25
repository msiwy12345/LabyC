#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double f(double x){
    return -(x*x) + 3*x + 11;
}

int zero(double (*f)(double), double a, double b, double *mz, double eps){
    double sr=0.0;
    if(f(a)*f(b)>0){
        return 0;
    }
    else{
        
        while(fabs(b-a)>eps){
            sr=(a+b)/2;
            if(f(sr)==0.0){
                *mz=sr;
                return 1;
            }
            if(f(a)*f(sr)<0){
                b=sr;
            }
            else{
                a=sr;
            }
        }
    }
    *mz=sr;
    return 1;

}

int main(void){

    
    double eps=0.01;
    double mz;
    if(zero(f, -1, 1, &mz, eps)){
        printf("miejsce zerowe to %f\n",mz);
    }
    else{
        printf("nie ma miejsca zerowego\n");
    }
    return 0;
}
#include <stdio.h>
#include <stdio.h>

void zamiana(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void odwroc(int tab[], int n){
    int x=0;
    int y=n-1;
    while(x<y){
        zamiana(&tab[x++],&tab[y--]);
    }
}

int main(void){
    int a=5;
    int b=12;
    printf("a= %d, b= %d\n",a,b);
    zamiana(&a,&b);
    printf("a= %d, b= %d\n",a,b);

    int tab[]={1,2,3,4,5};
    int n=sizeof(tab)/sizeof(tab[0]);
    for(int i=0;i<n;i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
    odwroc(tab, n);
    for(int i=0;i<n;i++){
        printf("%d ",tab[i]);
    }
    printf("\n");
    return 0;

}
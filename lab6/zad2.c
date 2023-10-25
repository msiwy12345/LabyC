#include <stdio.h>
#include <stdlib.h>

void print_tab_all(int y,int **a, int x){
 int i, j;
  for (i = 0; i < x; i++){
    for (j = 0; j < y; j++)
       printf ("%3d", a[i][j]);
    printf ("\n");   }
   return;}

int **multi_tab(int a, int b, int c, int(*tab1)[b], int (*tab2)[c]){
    int **result=malloc(a*sizeof(int));
    for(int i=0;i<a;i++){
        result[i]=malloc(c*sizeof(int));
        for(int j=0;j<c;j++){
            result[i][j]=0;
            for(int k=0;k<b;k++){
                result[i][j]+=tab1[i][k]*tab2[k][j];
            }
        }
    }
    return result;
}

int main(void){
    int tab_A [2][3] = {{1,2,3},{4,5,6}};
    int tab_B [3][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1}};
                
    int **result_1;
                
    result_1 = multi_tab (2,3,4,tab_A,tab_B); //wywołanie dla tablic tab_A oraz tab_B
                
    print_tab_all (4,result_1,2); //wypisanie tablicy result_1

    return 0;
}

#include <stdio.h>

int file_cmp(char* f1, char* f2) {
    FILE* file1 = fopen(f1, "rb");
    FILE* file2 = fopen(f2, "rb");

    if (file1 == NULL || file2 == NULL) {
        printf("blad otwarcia\n");
        return 0;
    }

    fseek(file1, 0, SEEK_END);
    long long s1 = ftell(file1);
    fseek(file2, 0, SEEK_END);
    long long s2 = ftell(file2);

    fclose(file1);
    fclose(file2);

    if (s1 > s2) {
        return 1; 
    } else if (s1 < s2) {
        return 2; 
    } else {
        return 0; 
    }
}

#include <stdio.h>
#include <stdlib.h>

int main(){
double test[] = {1.0,2.3,2.1,5.2,1.9,2.9,4.3,4.4,5.0,5.2,3.5};	
		
FILE *ptr_txt ;	//wskaznik do pliku tekstowego
FILE *ptr_bin ; //wskaznik do pliku binarnego
int i;	
size_t test_len = sizeof(test)/sizeof(*test);

//zapis tablicy test do pliku binarnego 
ptr_bin = fopen ("b_1","wb");	
fwrite(test, 1, sizeof(test), ptr_bin);	
fclose(ptr_bin);

//zapis tablicy test do pliku tekstowego 
ptr_txt = fopen ("t_1","w");	
for (i = 0; i < test_len; i++)
   fprintf (ptr_txt, "%.1f ", test[i]);
fclose(ptr_txt);


//sprawdzenie
//wczytanie z pliku binarnego
ptr_bin = fopen ("b_1","rb");	
double *tab_1 = malloc (sizeof(test));
fread(tab_1, 1, sizeof(test), ptr_bin);	
fclose(ptr_bin);
 
puts("_______bin__________________") ;
for (i = 0; i < test_len; i++)
   printf ( " tab_1[%d]  %.1f  \n",i, tab_1[i]);
printf ("\n");   

//wczytanie z pliku tekstowego
ptr_txt = fopen ("t_1","r");	
double *tab_2 = malloc (sizeof(test));
for (int i = 0; i < test_len; i++)
   fscanf (ptr_txt, "%lf", tab_2 + i);
    
fclose(ptr_txt);
puts("_______text__________________") ;
for (i = 0; i < test_len; i++) 
  printf ( " tab_2[%d]  %.1f  \n",i, tab_2[i]);


char* f1="b_1";
char *f2="t_1";
int wynik=file_cmp(f1,f2);

if(wynik==0){
    printf("sa identyczne\n");
} else if(wynik==1){
    printf("plik 1 jest wiekszy\n");
} else if(wynik==2){
    printf("plik 2 jest wiekszy\n");
} else{
    printf("error\n");
}
return 0;

}
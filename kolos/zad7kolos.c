#include <stdio.h>

int main (void)
{
      enum fruits {APPLE, MANGO, ORANGE=4, BANANA}; //wartosc liczbowa symbolu jest o 1 wieksza od poprzedzającego a=0, m=1 o=4, b=5
      
      char *fruit_names[] = {
            [APPLE]="Apple",
            [MANGO]="Mango",
            [ORANGE]="Orange",
            [BANANA]="Banana"
      };
      size_t size = sizeof(fruit_names);
      printf("ilosc elem = %zd, size=%zd, *fruit_names=%d\n", size/sizeof(*fruit_names), size,sizeof(*fruit_names));

      for(size_t i = 0; i < (size/sizeof(*fruit_names));i++)
      {
            printf("The name of fruit is %s\n", fruit_names[i]);
      }


      return 0;
}
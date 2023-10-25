#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 150
#define MIN 100

typedef struct {
    int digits [MAX];
    int liczba;
} elastyna;

void generateNumber(elastyna *elast)
{
    elast->liczba = rand() % (MAX - MIN + 1) + MIN;
  
    for (int i = 0; i < elast->liczba; i++)
    {
        if (i == 0)
            elast->digits[i] = rand() % 9 + 1; 
        else
            elast->digits[i] = rand() % 10;
    }
}

void printNumber(elastyna *elast, int index)
{
    printf("tab[%d] liczba ", index);
  
    for (int i = 0; i < elast->liczba; i++)
    {
        printf("%d", elast->digits[i]);
    }
  
    printf("\n");
}

void printNumber2(elastyna *elast)
{
    
  
    for (int i = 0; i < elast->liczba; i++)
    {
        printf("%d", elast->digits[i]);
    }
  
    printf("\n");
}

int compare(const void *a, const void *b)
{
    const elastyna *elastA = *(const elastyna **)a;
    const elastyna *elastB = *(const elastyna **)b;

    if (elastA->liczba < elastB->liczba)
        return -1;
    else if (elastA->liczba > elastB->liczba)
        return 1;
    else
    {
        for (int i = 0; i < elastA->liczba; i++)
        {
            if (elastA->digits[i] < elastB->digits[i])
                return -1;
            else if (elastA->digits[i] > elastB->digits[i])
                return 1;
        }

        return 0;
    }
}

int main()
{
    srand(time(0));

    elastyna *tab[5];

    for (int i = 0; i < 5; i++)
    {
        tab[i] = (elastyna *)malloc(sizeof(elastyna));
      
        generateNumber(tab[i]);
      
        printNumber(tab[i], i);
    }

    qsort(tab, 5, sizeof(elastyna *), compare);

    printf("\nPo sortowaniu:\n\n");

    for (int i = 0; i < 5; i++)
    {
        printNumber2(tab[i]);
    }

    
    for (int i = 0; i < 5; i++)
    {
        free(tab[i]);
    }
    
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

void zeroSelectedElements(FILE *ptr_bin, int elementIndex)
{
    fseek(ptr_bin, (elementIndex - 1) * sizeof(double), SEEK_SET); 
    double zero = 0.0;
    fwrite(&zero, sizeof(double), 1, ptr_bin);
}

int main()
{
    double test[] = {1.0, 2.3, 2.1, 5.2, 1.9, 2.9, 4.3, 4.4, 5.0, 5.2, 3.5};

    FILE *ptr_txt;  // Wskaźnik do pliku tekstowego
    FILE *ptr_bin;  // Wskaźnik do pliku binarnego
    int i;
    size_t test_len = sizeof(test) / sizeof(*test);

    // Zapis tablicy test do pliku binarnego
    ptr_bin = fopen("b_1", "wb");
    fwrite(test, sizeof(double), test_len, ptr_bin);
    fclose(ptr_bin);

    // Zapis tablicy test do pliku tekstowego
    ptr_txt = fopen("t_1", "w");
    for (i = 0; i < test_len; i++)
        fprintf(ptr_txt, "%.1f ", test[i]);
    fclose(ptr_txt);

    
    ptr_bin = fopen("b_1", "rb");
    double *tab_1 = malloc(test_len * sizeof(double));
    fread(tab_1, sizeof(double), test_len, ptr_bin);
    fclose(ptr_bin);

    puts("_______bin__________________");
    for (i = 0; i < test_len; i++)
        printf(" tab_1[%d]  %.1f  \n", i, tab_1[i]);
    printf("\n");
    free(tab_1);

    // Wywołanie procedury do zerowania wybranych elementów w pliku binarnym
    ptr_bin = fopen("b_1", "rb+");
    int elementIndex;
    for (elementIndex = 3; elementIndex <= test_len; elementIndex += 3)
    {
        zeroSelectedElements(ptr_bin, elementIndex);
    }
    fclose(ptr_bin);

    // Sprawdzenie - wczytanie z pliku tekstowego
    ptr_txt = fopen("t_1", "r");
    double *tab_2 = malloc(test_len * sizeof(double));
    for (i = 0; i < test_len; i++)
        fscanf(ptr_txt, "%lf", tab_2 + i);

    fclose(ptr_txt);
    puts("_______text__________________");
    for (i = 0; i < test_len; i++)
        printf(" tab_2[%d]  %.1f  \n", i, tab_2[i]);
    free(tab_2);

    return 0;
}

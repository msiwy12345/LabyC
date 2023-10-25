#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define M 5
#define N 4

int i_rand(int min, int max) {
    return rand() % (max - min + 1) + min;
}

double d_rand(double min, double max) {
    double r = (double) rand() / RAND_MAX;
    return r * (max - min) + min;
}

void wypisz_i(int *poczatek, int *koniec) {
    while (poczatek < koniec)
        printf("%4d ", *poczatek++);
    printf("\n");
    return;
}

void wypisz_d(double *poczatek, double *koniec) {
    while (poczatek < koniec)
        printf("%6.2f", *poczatek++);
    printf("\n");
    return;
}

int suma(int *tab, int len) {
    int ss = 0;
    for (int i = 0; i < len; i++)
        ss += tab[i];
    return ss;
}

double suma1(double *tab, int len) {
    double ss = 0.0;
    for (int i = 0; i < len; i++)
        ss += tab[i];
    return ss;
}

int main(void) {
    srand(time(0));
    int tab[M][N];
    double avgabc[M];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            tab[i][j] = i_rand(-10, 10);
        }
    }

    for (int i = 0; i < M; i++) {
        wypisz_i(*(tab + i), *(tab + i) + N);
    }

    for (int i = 0; i < M; i++) {
        avgabc[i] = (double) suma(*(tab + i), N) / N;
    }

    double avg_all_1 = (double) suma(&tab[0][0], sizeof(tab) / sizeof(int)) / sizeof(tab[0][0]);
    wypisz_d(avgabc, avgabc + M);
    double avg_all_2 = suma1(avgabc, M) / M;

    printf("srednia calej tablicy to: %f, a rozmiar to %zu elementow, albo %f\n",
           avg_all_1, sizeof(tab) / sizeof(int), avg_all_2);

    return 0;
}

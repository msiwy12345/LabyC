#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct person {
    char f_name[MAX];
    char l_name[MAX];
    char code[MAX];
    int age;
};

struct person* create_tab(char* file_name, int* size) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Błąd otwarcia pliku\n");
        return NULL;
    }

    
    int lines = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            lines++;
        }
    }
    fseek(file, 0, SEEK_SET);

    
    struct person* tab = malloc(lines * sizeof(struct person));
    if (tab == NULL) {
        printf("Błąd alokacji pamięci\n");
        fclose(file);
        return NULL;
    }

    *size = lines;

    
    int i;
    for (i = 0; i < lines; i++) {
        fscanf(file, "%s %s %s %d", tab[i].f_name, tab[i].l_name, tab[i].code, &tab[i].age);
    }

    fclose(file);

    return tab;
}

void saveBinary(struct person* tab, int size, char* file_name) {
    FILE* file = fopen(file_name, "wb");
    if (file == NULL) {
        printf("Błąd otwarcia pliku\n");
        return;
    }

    fwrite(tab, sizeof(struct person), size, file);

    fclose(file);
}

void readBinary(struct person** dane, int* size, char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Błąd otwarcia pliku\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    *size = file_size / sizeof(struct person);

    *dane = malloc(file_size);
    if (*dane == NULL) {
        printf("Błąd alokacji pamięci\n");
        fclose(file);
        return;
    }

    fseek(file, 0, SEEK_SET);
    fread(*dane, sizeof(struct person), *size, file);

    fclose(file);
}

int main() {
    int size;
    struct person* tab = create_tab("data.txt", &size);
    if (tab == NULL) {
        return 1;
    }

    saveBinary(tab, size, "dane.dat");

    free(tab);

    
    struct person* dane;
    int dane_size;
    readBinary(&dane, &dane_size, "dane.dat");

    
    int i;
    for (i = 0; i < dane_size/4; i++) {
        printf("Person %d:\n", i + 1);
        printf("First Name: %s\n", dane[i].f_name);
        printf("Last Name: %s\n", dane[i].l_name);
        printf("Code: %s\n", dane[i].code);
        printf("Age: %d\n", dane[i].age);
        printf("\n");
    }

    free(dane);

    return 0;
}

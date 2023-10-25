    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    //generowanie liczb losowych calkowitych z przedziału (min, max)
    int i_rand(int min, int max){
    return rand() % (max-min+1) + min;
    }


    int main(void){
        srand(time(0));
        int rows1=i_rand(3,7);
        int columns1=i_rand(3,7);
        int **array_1=calloc(rows1, sizeof(int*));
        if(array_1==NULL){
            return 0;
        }
        for(int i=0;i<rows1;i++){
            array_1[i]=calloc(columns1, sizeof(int));
            if(array_1[i]==NULL){
                return 0;
            }
            for(int j=0;j<columns1;j++){
                array_1[i][j]=i_rand(1,15);
            }
        }
        for(int i=0;i<rows1;i++){
            for(int j=0;j<columns1;j++){
                printf("%d ", array_1[i][j]);
            }
            printf("\n");
        }

        int rows_new1=i_rand(3,7);

        if(rows_new1>rows1){
            array_1=realloc(array_1, rows_new1 * sizeof(int*));
            for(int i=rows1;i<rows_new1;i++){
                array_1[i]=calloc(columns1, sizeof(int));
                if(array_1[i]==NULL){
                return 0;
                }
                for(int j=0;j<columns1;j++){
                    array_1[i][j]=i_rand(-15,-1);
                }
            }
        }
        if(rows_new1<rows1){
            for(int i=rows_new1;i<rows1;i++){
                free(array_1[i]);
            }
            array_1=realloc(array_1, rows_new1 * sizeof(int*));
        }
        printf("\n");
        for(int i=0;i<rows_new1;i++){
            for(int j=0;j<columns1;j++){
                printf("%d ", array_1[i][j]);
            }
            printf("\n");
        }


        for(int i=0;i<rows_new1;i++){
            free(array_1[i]);
        }
        free(array_1);

    //metoda 2


        int **array_2=calloc(rows1, sizeof(int*));
        array_2[0]=calloc(rows1*columns1, sizeof(int));
        for(int i=1; i<rows1; i++){
            array_2[i]=array_2[i-1]+columns1;
        }
        for(int i=0;i<rows1;i++){
            for(int j=0;j<columns1;j++){
                array_2[i][j]=i_rand(1,15);
            }
        }
        printf("\n\n\n");
        for(int i=0;i<rows1;i++){
            for(int j=0;j<columns1;j++){
                printf("%d ", array_2[i][j]);
            }
            printf("\n");
        }

        if (rows_new1 > rows1) {
            array_2 = realloc(array_2, rows_new1 * sizeof(int*));
            array_2[0] = realloc(array_2[0], rows_new1 * columns1 * sizeof(int));
            for (int i = rows1; i < rows_new1; i++) {
                array_2[i] = array_2[i - 1] + columns1;
                for(int j=0;j<columns1;j++){
                    array_2[i][j]=i_rand(-15,-1);
                }
            }
        } else if (rows_new1 < rows1) {
            for (int i = rows_new1; i < rows1; i++) {
                free(array_2[i]);
            }
            array_2 = realloc(array_2, rows_new1 * sizeof(int*));
        }
        printf("\n");
        for(int i=0;i<rows_new1;i++){
            for(int j=0;j<columns1;j++){
                printf("%d ", array_2[i][j]);
            }
            printf("\n");
        }

        //metoda 3

        int (*array_3)[columns1]=calloc(rows1*columns1, sizeof(int));
        printf("\n\n\n");
        for(int i=0;i<rows1;i++){
            for(int j=0;j<columns1;j++){
                array_3[i][j]=i_rand(1,15);
                printf("%d ", array_3[i][j]);
            }
            printf("\n");
        }

        if(rows_new1>rows1){
        array_3=realloc(array_3, rows_new1*columns1*sizeof(int));
        for(int i=rows1;i<rows_new1;i++){
            for(int j=0;j<columns1;j++){
                array_3[i][j]=i_rand(-15,-1);
            }
        }
    }
    else{
        array_3=realloc(array_3, rows_new1*columns1*sizeof(int));
    }
    printf("\n");
    for(int i=0;i<rows_new1;i++){
        for(int j=0;j<columns1;j++){
            printf("%d ", array_3[i][j]);
        }
        printf("\n");
    }
    free(array_3);



        return 0;
    }
   

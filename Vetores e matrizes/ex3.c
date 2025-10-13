/*Escreva  um  programa  que  leia  duas  matrizes  quadradas  de  ordem  3  de  números 
inteiros e gere uma terceira matriz representando a soma das duas matrizes 
informadas. */

#include <stdio.h>

const int ordem = 3;

int main(){
    int i,j;

    int matriz3[ordem][ordem];
    int matriz4[ordem][ordem];
    int matrizsoma[ordem][ordem];

    printf("\n\n-----Primeira Matriz:-----\n\n");

    for(i = 0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            printf("Informe o valor: ");
            scanf("%d", &matriz3[i][j]);
        }
        printf("\n");
    }

    printf("\n\n-----Segunda Matriz:-----\n\n");

    for(i = 0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            printf("Informe o valor: ");
            scanf("%d", &matriz4[i][j]);
        }
        printf("\n");
    }

    printf("\n\n-----Matriz soma:-----\n\n");

    for(i = 0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            matrizsoma[i][j] = matriz3[i][j] + matriz4[i][j];
            printf("%d\t", matrizsoma[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    return 0;
    
}
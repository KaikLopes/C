#include <stdio.h>

const int linhas = 3, colunas = 4;


void lerMatriz(int matriz[linhas][colunas]){
    int i, j;

    for(i = 0; i < linhas; i++){
        for(j = 0;j < colunas; j++){
            printf("Informe o valor da posição a%d,%d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

}

int maiorNum(int matriz[linhas][colunas]){
    int i, j, maior = 0;

    for(i = 0; i < linhas; i++){
        for(j = 0;j < colunas; j++){
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            }
        }
        printf("O maior termo da %d linha eh: %d\n", i + 1, maior);
        maior = 0;
    }
}

int main(){
    int matriz[linhas][colunas];

    lerMatriz(matriz);

    maiorNum(matriz);
}
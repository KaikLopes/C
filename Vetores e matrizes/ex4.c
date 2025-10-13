#include <stdio.h>

int const ordem = 3;

void lerMatriz(int matriz[ordem][ordem]){
    int i, j;

    for(i = 0; i < ordem; i++){
        for(j = 0;j < ordem; j++){
            printf("Informe o valor da posição a%d,%d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

}

int matrizNula(int matriz[ordem][ordem]){
    int i, j, cont = ordem;

    for(i = 0; i < ordem; i++){
           if(matriz[i][0] != 0 || matriz[i][1] != 0 || matriz[i][2] != 0){
            cont--;
           }
        }
        return cont;
    }


int main(){
    int matriz[ordem][ordem];

    lerMatriz(matriz);

    printf("A quantidade de linhas nulas eh: %d\n\n", matrizNula(matriz));
}
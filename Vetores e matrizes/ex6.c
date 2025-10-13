#include <stdio.h>

const int ordem = 4;

void lerMatriz(int matriz[ordem][ordem]){
    int i, j;

    for(i = 0; i < ordem; i++){
        for(j = 0;j < ordem; j++){
            printf("Informe o valor da posição a%d,%d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

}

int quantVezes(int matriz[ordem][ordem], int num){
    int j, i, cont = 0;
    for(j = 0; j < ordem; j++){
        for(i = 0; i < ordem; i++){
            if(matriz[i][j] == num){
                cont++;
                break;
            }
        }
    }
    return cont;
}

int main(){
    int matriz[ordem][ordem], num;

    lerMatriz(matriz);

    printf("Informe o numero que deseja verificar: ");
    scanf("%d", &num);

    printf("A quantidade de colunas em que o numero aparece eh: %d\n\n", quantVezes(matriz, num));
}

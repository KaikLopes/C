#include <stdio.h>

const int ordem = 3;

void lerMatriz(int matriz[ordem][ordem]){
    int i, j;

    for(i = 0; i < ordem; i++){
        for(j = 0;j < ordem; j++){
            printf("Informe o valor da posição a%d,%d: ", i + 1, j + 1);
            scanf("%d", &matriz[i][j]);
        }
    }

}

int ehSimetrica(int matriz[ordem][ordem]){
    int i, j;

    for(i = 0; i < ordem; i++){
        for(j = 0;j < ordem; j++){
            if(matriz[i][j] == matriz[j][i]){
                return 1;
            }
        }
    }
    return 0;
}

int main(){
    int matriz[ordem][ordem];

    lerMatriz(matriz);

    if(ehSimetrica){
    printf("A matriz eh simetrica.\n");
    }
    else{
       printf("A matriz nao eh simetrica.\n"); 
    }
}
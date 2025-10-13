#include <stdio.h>

const int ordem = 3;

int main(){
    int num, i, j;

    int matriz[ordem][ordem];

    printf("Informe o valor a ser multiplicado: ");
    scanf("%d", &num);

    for(i = 0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            printf("Informe o numero: ");
            scanf("%d", &matriz[i][j]);
        }
    }
    
    printf("\nMatriz informada:\n");
    
    for(i =  0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }

    for(i =  0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            matriz[i][j] *= num;
        }
    }

    printf("\nMatriz multiplicada:\n");

    for(i =  0; i < ordem; i++){
        for(j = 0; j < ordem; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }



    return 0;
}
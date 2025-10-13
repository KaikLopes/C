#include <stdio.h>

int main() {
    int n, i, j;
    long int graos = 1;

    printf("Informe a quantidade de linhas/colunas do tabuleiro: ");
    scanf("%d", &n);

    long int matriz[n][n];

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            matriz[i][j] = graos;
            graos *= 2;
        }
    }

    printf("\nTabuleiro de grãos:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%li\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
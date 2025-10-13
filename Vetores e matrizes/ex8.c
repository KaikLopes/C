#include <stdio.h>

int main() {
    char matriz[6][10];
    int i, j;

    printf("Digite o gabarito (10 caracteres):\n");
    for(j = 0; j < 10; j++) {
        scanf(" %c", &matriz[0][j]);
    }

    for(i = 1; i < 6; i++) {
        printf("Digite as respostas do candidato %d (10 caracteres):\n", i);
        for(j = 0; j < 10; j++) {
            scanf(" %c", &matriz[i][j]);
        }
    }

    
    for(i = 1; i < 6; i++) {
        int acertos = 0;
        for(j = 0; j < 10; j++) {
            if(matriz[i][j] == matriz[0][j]) {
                acertos++;
            }
        }
        printf("Candidato %d acertou %d questões.\n", i, acertos);
    }

    return 0;
}
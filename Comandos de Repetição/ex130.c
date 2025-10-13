#include <stdio.h>
#include <string.h>

int main() {
    int n, bilhete, ganhador = 0;
    char nome[100], nome_ganhador[100];

    printf("Informe o número de pessoas: ");
    scanf("%d", &n);
    getchar();

    for (int i = 1; i <= n; i++) {
        printf("Nome da %d pessoa: ", i);
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = 0;

        printf("Número do bilhete: ");
        scanf("%d", &bilhete);
        getchar();

        if (bilhete == i) {
            strcpy(nome_ganhador, nome);
            ganhador = 1;
        }
    }

    if (ganhador) {
        printf("\nO ganhador é: %s\n\n", nome_ganhador);
    }

    return 0;
}
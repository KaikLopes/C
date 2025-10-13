#include <stdio.h>
#include <math.h>

const int tam = 3;

// Função recursiva para divisão inteira
int dividirRec(int soma, int divisor) {
    if (soma < divisor)
        return 0;
    return 1 + dividirRec(soma - divisor, divisor);
}

// Função recursiva para calcular casas decimais
double dividirRecDecimalAux(int resto, int divisor, int casas, int max_casas) {
    if (resto == 0 || casas == max_casas)
        return 0;
    int digito = dividirRec(resto * 10, divisor);
    int novo_resto = resto * 10 - digito * divisor;
    return digito / pow(10, casas) + dividirRecDecimalAux(novo_resto, divisor, casas + 1, max_casas);
}

double dividirRecDecimal(int soma, int divisor, int max_casas) {
    int parte_inteira = dividirRec(soma, divisor);
    int resto = soma - (parte_inteira * divisor);
    return parte_inteira + dividirRecDecimalAux(resto, divisor, 1, max_casas);
}

int main(){
    int notas[tam], soma = 0;

    printf("Informe as notas: ");
    for(int i = 0; i < tam; i++) {
        scanf("%d", &notas[i]);
        soma += notas[i];
    }

    int casas_decimais = 6; // ajuste para mais casas se quiser
    double media = dividirRecDecimal(soma, tam, casas_decimais);

    printf("A média é: %.*f\n", casas_decimais, media);

    return 0;
}
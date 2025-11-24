
#include <stdio.h>

// Variáveis globais para armazenar as dimensões
int linhas, colunas, tam;


void dimensionaMatriz(int l, int c) {
    linhas = l;
    colunas = c;
    tam = linhas * colunas;
}


void zerarMatriz(int *vet) {
    // Apenas percorre o vetor 1D do início ao fim
    for (int i = 0; i < tam; i++) {
        vet[i] = 0;
    }
}


void imprimeMatriz(int *vet) {
    printf("--- Matriz %dx%d ---\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            // Usa a fórmula de mapeamento 2D -> 1D
            printf("%d\t", vet[i * colunas + j]);
        }
        printf("\n"); // Pula linha ao final de cada linha da matriz
    }
    printf("--------------------\n\n");
}


void adicionaElemento(int *vet, int num, int l, int c) {
    // Validação para não escrever fora da memória
    if (l > 0 && l <= linhas && c > 0 && c <= colunas) {
        // Fórmula de mapeamento com correção de índice (l-1, c-1)
        int indice = ((l - 1) * colunas) + (c - 1);
        vet[indice] = num;
    } else {
        printf("Erro: Posição [%d][%d] fora dos limites da matriz!\n", l, c);
    }
}


int buscaElemento(int *vet, int l, int c) {
    // Validação para não ler fora da memória
    if (l > 0 && l <= linhas && c > 0 && c <= colunas) {
        // Fórmula de mapeamento com correção de índice (l-1, c-1)
        int indice = ((l - 1) * colunas) + (c - 1);
        return vet[indice];
    } else {
        printf("Erro: Posição [%d][%d] fora dos limites da matriz!\n", l, c);
        return -1; // Retorna um valor de erro
    }
}


int somaMatriz(int *vet) {
    int soma = 0;
    // Como é um vetor 1D, basta somar todos os seus elementos
    for (int i = 0; i < tam; i++) {
        soma += vet[i];
    }
    return soma;
}

// --- PROGRAMA CLIENTE ---
// A main() não sabe que 'vet' é um vetor,
// ela apenas usa as operações de "Matriz".
int main() {
    // 1. Define as dimensões
    dimensionaMatriz(3, 3);

    // 2. Cria o vetor (VLA - Variable Length Array)
    // Isso só funciona porque 'tam' foi calculado na linha anterior
    int vet[tam];

    // 3. Zera a Matriz
    printf("Imprimindo matriz zerada:\n");
    zerarMatriz(vet);
    imprimeMatriz(vet);

    // 4. Adiciona elementos (usando indexação base 1, ex: [1][1])
    adicionaElemento(vet, 15, 1, 1); // Linha 1, Coluna 1
    adicionaElemento(vet, 25, 2, 2); // Linha 2, Coluna 2
    adicionaElemento(vet, 35, 3, 3); // Linha 3, Coluna 3
    
    // 5. Imprime a Matriz Preenchida
    printf("Imprimindo matriz preenchida:\n");
    imprimeMatriz(vet);

    // 6. Busca um elemento
    printf("O elemento que esta na linha 2 coluna 2 eh: %d\n\n", buscaElemento(vet, 2, 2));

    // 7. Soma os elementos
    // Corrigido: A função 'somaMatriz' retorna um int,
    // então ela deve ser chamada DENTRO do printf.
    printf("Soma de todos os elementos da Matriz: %d\n", somaMatriz(vet));

    return 0;
}
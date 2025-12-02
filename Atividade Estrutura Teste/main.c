#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 15

typedef struct{
    char nome[30];
    char endereço[50];
    char telefone[15];
    char cpf[15];
    char cargo[30];
    float salario;
    char nascimento[15];
}Funcionario;


typedef struct{
    Funcionario dados[TAM];
    int quant;
}VetorFuncionario;





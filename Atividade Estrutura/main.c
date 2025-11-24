#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_CARGO 50
#define NOME_ARQUIVO "dados_funcionarios.csv"

typedef struct {
    int id;
    char nome[MAX_NOME];
    char cargo[MAX_CARGO];
    float salario;
} Funcionario;

// Protótipos
void carregar_dados(Funcionario **funcionarios, int *num_funcionarios);
void salvar_dados(Funcionario *funcionarios, int num_funcionarios);
void adicionar_funcionario(Funcionario **funcionarios, int *num_funcionarios);
void listar_funcionarios(Funcionario *funcionarios, int num_funcionarios);
void editar_funcionario(Funcionario *funcionarios, int num_funcionarios);
void excluir_funcionario(Funcionario **funcionarios, int *num_funcionarios); 

int main() {
    Funcionario *lista_funcionarios = NULL;
    int num_funcionarios = 0;
    int opcao;

    carregar_dados(&lista_funcionarios, &num_funcionarios);

    do {
        printf("\n--- Sistema de Cadastro de Funcionários ---\n");
        printf("1. Adicionar Novo Funcionário\n");
        printf("2. Listar Funcionários\n");
        printf("3. Editar Funcionário\n");
        printf("4. Excluir Funcionário\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); 

        switch (opcao) {
            case 1:
                adicionar_funcionario(&lista_funcionarios, &num_funcionarios);
                salvar_dados(lista_funcionarios, num_funcionarios);
                break;
            case 2:
                listar_funcionarios(lista_funcionarios, num_funcionarios);
                break;
            case 3:
                editar_funcionario(lista_funcionarios, num_funcionarios);
                salvar_dados(lista_funcionarios, num_funcionarios);
                break;
            case 4: // Nova Opção
                excluir_funcionario(&lista_funcionarios, &num_funcionarios);
                salvar_dados(lista_funcionarios, num_funcionarios);
                break;
            case 5:
                printf("Saindo do programa. Dados salvos em %s.\n", NOME_ARQUIVO);
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    free(lista_funcionarios);
    return 0;
}

void excluir_funcionario(Funcionario **funcionarios, int *num_funcionarios) {
    int id_busca;
    int indice_excluir = -1;
    
    if (*num_funcionarios == 0) {
        printf("\nNenhum funcionário cadastrado para excluir.\n");
        return;
    }

    printf("\n--- Excluir Funcionário ---\n");
    printf("Digite o ID do funcionário que deseja excluir: ");
    scanf("%d", &id_busca);
    while (getchar() != '\n'); 

    // 1. Procura o funcionário pelo ID e guarda o índice
    for (int i = 0; i < *num_funcionarios; i++) {
        if ((*funcionarios)[i].id == id_busca) {
            indice_excluir = i;
            break;
        }
    }

    if (indice_excluir != -1) {
        printf("❗ Confirma a exclusão de: ID %d, Nome: %s? (s/n): ", 
               (*funcionarios)[indice_excluir].id, (*funcionarios)[indice_excluir].nome);
        char confirmacao = getchar();
        while (getchar() != '\n');
        
        if (confirmacao == 's' || confirmacao == 'S') {
            // 2. Move os elementos subsequentes uma posição para trás
            for (int i = indice_excluir; i < *num_funcionarios - 1; i++) {
                (*funcionarios)[i] = (*funcionarios)[i + 1];
            }

            // 3. Reduz o contador
            (*num_funcionarios)--;

            // 4. Realoca a memória para o novo tamanho
            *funcionarios = (Funcionario *)realloc(*funcionarios, (*num_funcionarios) * sizeof(Funcionario));
            
            // Tratamento opcional para realloc falho ou lista vazia
            if (*num_funcionarios > 0 && *funcionarios == NULL) {
                perror("Erro ao realocar memória após exclusão");
                exit(EXIT_FAILURE);
            }

            printf("\nFuncionário ID %d excluído com sucesso.\n", id_busca);
        } else {
            printf("\nExclusão cancelada.\n");
        }
    } else {
        printf("\nErro: Funcionário com ID %d não encontrado.\n", id_busca);
    }
}


void carregar_dados(Funcionario **funcionarios, int *num_funcionarios) {
    FILE *arquivo = fopen(NOME_ARQUIVO, "r");
    char linha[256];
    int count = 0;

    if (arquivo == NULL) {
        printf("Arquivo %s não encontrado. Iniciando um novo cadastro.\n", NOME_ARQUIVO);
        return;
    }

    fgets(linha, sizeof(linha), arquivo);

    while (fgets(linha, sizeof(linha), arquivo)) {
        count++;
    }
    
    fseek(arquivo, 0, SEEK_SET);
    fgets(linha, sizeof(linha), arquivo);

    *funcionarios = (Funcionario *)malloc(count * sizeof(Funcionario));
    if (*funcionarios == NULL) {
        perror("Erro ao alocar memória");
        exit(EXIT_FAILURE);
    }
    *num_funcionarios = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (sscanf(linha, "%d,%[^,],%[^,],%f", 
                   &(*funcionarios)[*num_funcionarios].id,
                   (*funcionarios)[*num_funcionarios].nome,
                   (*funcionarios)[*num_funcionarios].cargo,
                   &(*funcionarios)[*num_funcionarios].salario) == 4) {
            (*num_funcionarios)++;
        } else {
            fprintf(stderr, "Erro ao ler linha no arquivo CSV: %s", linha);
        }
    }

    printf("Dados de %d funcionários carregados de %s.\n", *num_funcionarios, NOME_ARQUIVO);
    fclose(arquivo);
}

void salvar_dados(Funcionario *funcionarios, int num_funcionarios) {
    FILE *arquivo = fopen(NOME_ARQUIVO, "w");

    if (arquivo == NULL) {
        perror("Erro ao abrir/criar arquivo CSV para escrita");
        return;
    }

    fprintf(arquivo, "ID,Nome,Cargo,Salario\n");

    for (int i = 0; i < num_funcionarios; i++) {
        fprintf(arquivo, "%d,%s,%s,%.2f\n", 
                funcionarios[i].id, 
                funcionarios[i].nome, 
                funcionarios[i].cargo, 
                funcionarios[i].salario);
    }

    fclose(arquivo);
    printf("Dados salvos com sucesso em %s.\n", NOME_ARQUIVO);
}

void adicionar_funcionario(Funcionario **funcionarios, int *num_funcionarios) {
    Funcionario novo;

    printf("\n--- Adicionar Novo Funcionário ---\n");

    novo.id = *num_funcionarios + 1;
    printf("ID: %d\n", novo.id);

    printf("Nome: ");
    if (fgets(novo.nome, MAX_NOME, stdin) != NULL) {
        novo.nome[strcspn(novo.nome, "\n")] = 0;
    }

    printf("Cargo: ");
    if (fgets(novo.cargo, MAX_CARGO, stdin) != NULL) {
        novo.cargo[strcspn(novo.cargo, "\n")] = 0;
    }

    printf("Salário: ");
    scanf("%f", &novo.salario);
    while (getchar() != '\n'); 

    *funcionarios = (Funcionario *)realloc(*funcionarios, (*num_funcionarios + 1) * sizeof(Funcionario));
    if (*funcionarios == NULL) {
        perror("Erro ao realocar memória");
        exit(EXIT_FAILURE);
    }

    (*funcionarios)[*num_funcionarios] = novo;
    (*num_funcionarios)++;

    printf("Funcionário %s adicionado.\n", novo.nome);
}

void listar_funcionarios(Funcionario *funcionarios, int num_funcionarios) {
    if (num_funcionarios == 0) {
        printf("\nNenhum funcionário cadastrado.\n");
        return;
    }

    printf("\n--- Lista de Funcionários (%d total) ---\n", num_funcionarios);
    printf("ID | Nome                       | Cargo                      | Salário\n");
    printf("---|----------------------------|----------------------------|---------\n");
    for (int i = 0; i < num_funcionarios; i++) {
        printf("%-2d | %-26s | %-26s | R$ %.2f\n", 
               funcionarios[i].id, 
               funcionarios[i].nome, 
               funcionarios[i].cargo, 
               funcionarios[i].salario);
    }
}

void editar_funcionario(Funcionario *funcionarios, int num_funcionarios) {
    int id_busca;
    int encontrado = 0;
    
    if (num_funcionarios == 0) {
        printf("\nNenhum funcionário cadastrado para editar.\n");
        return;
    }

    printf("\n--- Editar Funcionário ---\n");
    printf("Digite o ID do funcionário que deseja editar: ");
    scanf("%d", &id_busca);
    while (getchar() != '\n'); 

    for (int i = 0; i < num_funcionarios; i++) {
        if (funcionarios[i].id == id_busca) {
            encontrado = 1;
            
            printf("\nFuncionário encontrado: ID %d, Nome: %s\n", 
                   funcionarios[i].id, funcionarios[i].nome);
            printf("--- Digite as novas informações (ou deixe em branco e pressione Enter para manter a atual) ---\n");

            char novo_nome[MAX_NOME];
            printf("Novo Nome (Atual: %s): ", funcionarios[i].nome);
            if (fgets(novo_nome, MAX_NOME, stdin) != NULL) {
                novo_nome[strcspn(novo_nome, "\n")] = 0;
                if (strlen(novo_nome) > 0) {
                    strcpy(funcionarios[i].nome, novo_nome);
                }
            }

            char novo_cargo[MAX_CARGO];
            printf("Novo Cargo (Atual: %s): ", funcionarios[i].cargo);
            if (fgets(novo_cargo, MAX_CARGO, stdin) != NULL) {
                novo_cargo[strcspn(novo_cargo, "\n")] = 0;
                if (strlen(novo_cargo) > 0) {
                    strcpy(funcionarios[i].cargo, novo_cargo);
                }
            }
            
            float novo_salario;
            printf("Novo Salário (Atual: R$ %.2f, digite 0 para manter): ", funcionarios[i].salario);
            if (scanf("%f", &novo_salario) == 1) {
                if (novo_salario > 0.0) {
                    funcionarios[i].salario = novo_salario;
                }
            }
            while (getchar() != '\n');

            printf("\nInformações do funcionário ID %d atualizadas com sucesso.\n", funcionarios[i].id);
            break; 
        }
    }

    if (!encontrado) {
        printf("\nErro: Funcionário com ID %d não encontrado.\n", id_busca);
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 10

// Estrutura que representa um item do inventário
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Protótipos das funções
void inserirItem(Item mochila[], int *numItens);
void removerItem(Item mochila[], int *numItens);
void listarItens(Item mochila[], int numItens);
void buscarItem(Item mochila[], int numItens);

int main() {
    Item mochila[MAX_ITENS];   // Vetor de structs
    int numItens = 0;          // Quantidade atual de itens
    int opcao;

    do {
        printf("\n==== Sistema de Inventario ====\n");
        printf("1. Cadastrar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar buffer do Enter

        switch(opcao) {
            case 1:
                inserirItem(mochila, &numItens);
                listarItens(mochila, numItens);
                break;
            case 2:
                removerItem(mochila, &numItens);
                listarItens(mochila, numItens);
                break;
            case 3:
                listarItens(mochila, numItens);
                break;
            case 4:
                buscarItem(mochila, numItens);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}

// Função para cadastrar um item no inventário
void inserirItem(Item mochila[], int *numItens) {
    if (*numItens >= MAX_ITENS) {
        printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    Item novo;
    printf("Digite o nome do item: ");
    fgets(novo.nome, sizeof(novo.nome), stdin);
    novo.nome[strcspn(novo.nome, "\n")] = '\0'; // Remove quebra de linha

    printf("Digite o tipo do item (arma, municao, cura...): ");
    fgets(novo.tipo, sizeof(novo.tipo), stdin);
    novo.tipo[strcspn(novo.tipo, "\n")] = '\0';

    printf("Digite a quantidade: ");
    scanf("%d", &novo.quantidade);
    getchar();

    mochila[*numItens] = novo;
    (*numItens)++;

    printf("Item adicionado com sucesso!\n");
}

// Função para remover um item do inventário pelo nome
void removerItem(Item mochila[], int *numItens) {
    if (*numItens == 0) {
        printf("Mochila vazia! Nao ha itens para remover.\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item a ser removido: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < *numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            encontrado = 1;
            // Desloca os itens para "fechar o buraco"
            for (int j = i; j < *numItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*numItens)--;
            printf("Item removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado!\n");
    }
}

// Função para listar todos os itens do inventário
void listarItens(Item mochila[], int numItens) {
    if (numItens == 0) {
        printf("Mochila vazia.\n");
        return;
    }

    printf("\n--- Itens na mochila ---\n");
    for (int i = 0; i < numItens; i++) {
        printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Função de busca sequencial por nome
void buscarItem(Item mochila[], int numItens) {
    if (numItens == 0) {
        printf("Mochila vazia!\n");
        return;
    }

    char nome[30];
    printf("Digite o nome do item a buscar: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    int encontrado = 0;
    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n",
                   mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado.\n");
    }
}
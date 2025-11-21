#include <stdio.h>
#include <string.h>
#define MAX_ITENS 100

typedef struct {
    int id;
    char nome[50];
    int ativo;
} Item;

Item itens[MAX_ITENS];
int total = 0;

void cadastrar() {
    if (total >= MAX_ITENS) {
        printf("Limite de itens atingido.\n");
        return;
    }

    Item novo;
    novo.id = total + 1;
    novo.ativo = 1;

    printf("Digite o nome do item: ");
    scanf(" %[^\n]", novo.nome);

    itens[total] = novo;
    total++;

    printf("Item cadastrado com sucesso!\n");
}

void consultar() {
    int id;
    printf("Digite o ID do item: ");
    scanf("%d", &id);

    if (id <= 0 || id > total || itens[id - 1].ativo == 0) {
        printf("Item nao encontrado.\n");
        return;
    }

    printf("ID: %d\nNome: %s\n", itens[id - 1].id, itens[id - 1].nome);
}

void excluir() {
    int id;
    printf("Digite o ID do item para excluir: ");
    scanf("%d", &id);

    if (id <= 0 || id > total || itens[id - 1].ativo == 0) {
        printf("Item nao encontrado.\n");
        return;
    }

    itens[id - 1].ativo = 0;
    printf("Item excluido com sucesso.\n");
}

void gerarRelatorio() {
    FILE *arquivo = fopen("relatorio.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao gerar arquivo.\n");
        return;
    }

    fprintf(arquivo, "RELATORIO DE ITENS\n\n");

    for (int i = 0; i < total; i++) {
        if (itens[i].ativo == 1) {
            fprintf(arquivo, "ID: %d - Nome: %s\n", itens[i].id, itens[i].nome);
        }
    }

    fclose(arquivo);
    printf("Relatorio gerado com sucesso (relatorio.txt).\n");
}

int main() {
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar item\n");
        printf("2 - Consultar item\n");
        printf("3 - Excluir item\n");
        printf("4 - Gerar relatorio (.txt)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrar(); break;
            case 2: consultar(); break;
            case 3: excluir(); break;
            case 4: gerarRelatorio(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}

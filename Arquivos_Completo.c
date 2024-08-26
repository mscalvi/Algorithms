#include <stdio.h>
#include <string.h>

#define MAX_ITENS 100
#define DESC_MAX 100

typedef struct {
    int codigo;
    char descricao[DESC_MAX];
    int quantidade;
    float valor_unitario;
    int removido;  // Flag para remoção lógica
} ItemEstoque;

int qtdItens = 0;
ItemEstoque estoque[MAX_ITENS];

// Função para adicionar um item ao estoque
void adicionar_item() {
    if (qtdItens >= MAX_ITENS) {
        printf("Estoque cheio!\n");
        return;
    }

    ItemEstoque item;
    printf("Digite o codigo do item: ");
    scanf("%d", &item.codigo);
    getchar();  // Limpar buffer do enter

    printf("Digite a descricao do item: ");
    fgets(item.descricao, DESC_MAX, stdin);
    item.descricao[strcspn(item.descricao, "\n")] = '\0';  // Remove o '\n'

    printf("Digite a quantidade do item: ");
    scanf("%d", &item.quantidade);

    printf("Digite o valor unitario do item: ");
    scanf("%f", &item.valor_unitario);

    item.removido = 0;  // Item não removido logicamente
    estoque[qtdItens] = item;
    qtdItens++;
    printf("Item adicionado com sucesso!\n");
}

// Função para consultar itens no estoque
void consultar_itens() {
    printf("\n--- Consulta de Itens ---\n");
    for (int i = 0; i < qtdItens; i++) {
        if (!estoque[i].removido) {
            printf("Codigo: %d\n", estoque[i].codigo);
            printf("Descricao: %s\n", estoque[i].descricao);
            printf("Quantidade: %d\n", estoque[i].quantidade);
            printf("Valor Unitario: %.2f\n\n", estoque[i].valor_unitario);
        }
    }
}

// Função para alterar um item no estoque
void alterar_item() {
    int codigo;
    printf("Digite o codigo do item a ser alterado: ");
    scanf("%d", &codigo);

    for (int i = 0; i < qtdItens; i++) {
        if (estoque[i].codigo == codigo && !estoque[i].removido) {
            printf("Digite a nova descricao: ");
            getchar();  // Limpar buffer do enter
            fgets(estoque[i].descricao, DESC_MAX, stdin);
            estoque[i].descricao[strcspn(estoque[i].descricao, "\n")] = '\0';

            printf("Digite a nova quantidade: ");
            scanf("%d", &estoque[i].quantidade);

            printf("Digite o novo valor unitario: ");
            scanf("%f", &estoque[i].valor_unitario);

            printf("Item alterado com sucesso!\n");
            return;
        }
    }
    printf("Item nao encontrado!\n");
}

// Função para remover um item logicamente do estoque
void remover_item() {
    int codigo;
    printf("Digite o codigo do item a ser removido: ");
    scanf("%d", &codigo);

    for (int i = 0; i < qtdItens; i++) {
        if (estoque[i].codigo == codigo && !estoque[i].removido) {
            estoque[i].removido = 1;  // Remoção lógica
            printf("Item removido logicamente!\n");
            return;
        }
    }
    printf("Item nao encontrado!\n");
}

// Função para remover fisicamente os itens removidos logicamente
void remover_fisicamente() {
    int i = 0;
    while (i < qtdItens) {
        if (estoque[i].removido) {
            // Remover fisicamente o item
            for (int j = i; j < qtdItens - 1; j++) {
                estoque[j] = estoque[j + 1];
            }
            qtdItens--;  // Reduz a quantidade de itens no estoque
        } else {
            i++;
        }
    }
    printf("Remocao fisica concluida!\n");
}

// Função principal
int main() {
    int opcao;

    do {
        printf("\n--- Sistema de Estoque ---\n");
        printf("1. Adicionar Item\n");
        printf("2. Consultar Itens\n");
        printf("3. Alterar Item\n");
        printf("4. Remover Item\n");
        printf("5. Sair e Remover Fisicamente\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionar_item();
                break;
            case 2:
                consultar_itens();
                break;
            case 3:
                alterar_item();
                break;
            case 4:
                remover_item();
                break;
            case 5:
                remover_fisicamente();
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 5);

    return 0;
}

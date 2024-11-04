#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista encadeada
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Função para adicionar um elemento no final da lista
void adicionar_no_final(No **lista, int valor) {
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    
    if (*lista == NULL) {
        *lista = novo;
    } else {
        No *atual = *lista;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

// Função para imprimir a lista
void imprimir_lista(No *lista) {
    No *atual = lista;
    while (atual != NULL) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para contar o número de elementos na lista
int contar_elementos(No *lista) {
    int contador = 0;
    No *atual = lista;
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }
    return contador;
}

// Função para remover um nó em uma posição específica da lista
void remover_em_posicao(No **lista, int posicao) {
    if (*lista == NULL || posicao <= 0) return; // Lista vazia ou posição inválida

    No *atual = *lista;

    // Caso a posição seja 1 (remoção do primeiro nó)
    if (posicao == 1) {
        *lista = atual->prox;
        free(atual);
        return;
    }

    // Para outras posições, percorre a lista até encontrar o nó anterior ao desejado
    for (int i = 1; atual != NULL && i < posicao - 1; i++) {
        atual = atual->prox;
    }

    // Verifica se o nó da posição existe
    if (atual == NULL || atual->prox == NULL) return;

    No *temp = atual->prox;
    atual->prox = temp->prox; // Aponta o nó atual para o próximo do nó a ser removido
    free(temp); // Libera a memória do nó removido
}

// Função para liberar a memória da lista
void liberar_lista(No *lista) {
    No *atual = lista;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    No *lista = NULL;

    // Adiciona 7 elementos à lista
    for (int i = 1; i <= 7; i++) {
        adicionar_no_final(&lista, i);
    }

    printf("Lista original: ");
    imprimir_lista(lista);

    // Remover o primeiro elemento
    remover_em_posicao(&lista, 1);

    // Contar o número de elementos após a remoção do primeiro
    int tamanho = contar_elementos(lista);

    // Remover o último elemento (posição `tamanho`)
    remover_em_posicao(&lista, tamanho);

    // Recalcula o tamanho da lista para encontrar a posição do meio
    tamanho = contar_elementos(lista);
    int posicao_meio = (tamanho / 2) + (tamanho % 2);

    // Remover o elemento do meio
    remover_em_posicao(&lista, posicao_meio);

    printf("Lista após remoções: ");
    imprimir_lista(lista);

    // Libera a memória da lista
    liberar_lista(lista);

    return 0;
}

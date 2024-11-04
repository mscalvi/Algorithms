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

// Função para buscar um elemento na lista encadeada e retornar sua posição
int buscar_elemento_com_posicao(No *lista, int valor) {
    No *atual = lista;
    int posicao = 1; // Começa da posição 1
    
    while (atual != NULL) {
        if (atual->valor == valor) {
            return posicao; // Retorna a posição do elemento encontrado
        }
        atual = atual->prox;
        posicao++; // Incrementa a posição
    }
    
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Função para liberar a memória alocada para a lista
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

    // Adiciona alguns elementos à lista
    adicionar_no_final(&lista, 10);
    adicionar_no_final(&lista, 20);
    adicionar_no_final(&lista, 30);

    // Valor que queremos buscar na lista
    int valor_procurado = 20;

    // Busca o valor na lista e obtem a posição
    int posicao = buscar_elemento_com_posicao(lista, valor_procurado);

    if (posicao != -1) {
        printf("O valor %d foi encontrado na posição %d da lista.\n", valor_procurado, posicao);
    } else {
        printf("O valor %d não foi encontrado na lista.\n", valor_procurado);
    }

    // Libera a memória da lista
    liberar_lista(lista);

    return 0;
}

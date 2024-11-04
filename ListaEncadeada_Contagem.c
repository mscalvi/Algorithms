#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da lista encadeada
typedef struct No {
    int valor;
    struct No *prox;
} No;

// Função para contar o número de elementos na lista encadeada
int contar_elementos(No *lista) {
    int contador = 0;
    No *atual = lista;
    
    while (atual != NULL) {
        contador++;
        atual = atual->prox;
    }
    
    return contador;
}

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
    
    // Conta e exibe o número de elementos na lista
    int num_elementos = contar_elementos(lista);
    printf("Número de elementos na lista: %d\n", num_elementos);
    
    // Libera a memória da lista
    liberar_lista(lista);
    
    return 0;
}

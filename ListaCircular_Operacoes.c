#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
typedef struct No {
    int dado;
    struct No* prox;
} No;

// Função para criar uma lista vazia
No* criarLista() {
    return NULL; // Lista inicialmente vazia
}

// Função para adicionar um elemento no início da lista
No* adicionarInicio(No* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;

    if (lista == NULL) {
        novoNo->prox = novoNo; // Lista circular: aponta para si mesmo
        return novoNo;
    } else {
        // Encontrar o último nó
        No* temp = lista;
        while (temp->prox != lista) {
            temp = temp->prox;
        }
        // Inserir o novo nó no início
        novoNo->prox = lista;
        temp->prox = novoNo;
        return novoNo; // Novo nó é o início da lista
    }
}

// Função para inserir um elemento no final da lista
No* inserirFinal(No* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = valor;

    if (lista == NULL) {
        novoNo->prox = novoNo; // Lista circular: aponta para si mesmo
        return novoNo;
    } else {
        No* temp = lista;
        while (temp->prox != lista) {
            temp = temp->prox;
        }
        temp->prox = novoNo;
        novoNo->prox = lista;
        return lista; // A cabeça da lista permanece a mesma
    }
}

// Função para mostrar todos os elementos da lista
void mostrarLista(No* lista) {
    if (lista == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    No* temp = lista;
    do {
        printf("%d -> ", temp->dado);
        temp = temp->prox;
    } while (temp != lista);
    printf("(volta ao início)\n");
}

// Função para remover o elemento do início da lista
No* removerInicio(No* lista) {
    if (lista == NULL) {
        printf("A lista está vazia. Nada para remover.\n");
        return NULL;
    }

    if (lista->prox == lista) {
        // Apenas um elemento na lista
        free(lista);
        return NULL;
    }

    // Encontrar o último nó
    No* temp = lista;
    while (temp->prox != lista) {
        temp = temp->prox;
    }

    // Ajustar o ponteiro para remover o primeiro elemento
    No* remover = lista;
    temp->prox = lista->prox;
    lista = lista->prox;
    free(remover);

    return lista;
}

// Função principal para testar as operações
int main() {
    No* lista = criarLista();

    // Adicionando elementos no início
    lista = adicionarInicio(lista, 10);
    lista = adicionarInicio(lista, 20);
    lista = adicionarInicio(lista, 30);

    printf("Lista após adicionar elementos no início:\n");
    mostrarLista(lista);

    // Inserindo elementos no final
    lista = inserirFinal(lista, 40);
    lista = inserirFinal(lista, 50);

    printf("Lista após inserir elementos no final:\n");
    mostrarLista(lista);

    // Removendo elemento do início
    lista = removerInicio(lista);
    printf("Lista após remover o primeiro elemento:\n");
    mostrarLista(lista);

    // Removendo elemento do início novamente
    lista = removerInicio(lista);
    printf("Lista após remover o primeiro elemento novamente:\n");
    mostrarLista(lista);

    return 0;
}

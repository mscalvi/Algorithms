#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista duplamente encadeada
typedef struct No {
    int dado;             // Dado armazenado no nó
    struct No* prox;      // Ponteiro para o próximo nó
    struct No* ant;       // Ponteiro para o nó anterior
} No;

// Função para criar um novo nó
No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo->dado = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

// Função para exibir a lista
void exibirLista(No* inicio) {
    if (inicio == NULL) {
        printf("A lista está vazia!\n");
        return;
    }
    
    No* temp = inicio;
    printf("Elementos da lista: ");
    while (temp != NULL) {
        printf("%d ", temp->dado);
        temp = temp->prox;
    }
    printf("\n");
}

// Função para inserir um nó no início da lista
void inserirNoInicio(No** inicio, int valor) {
    No* novo = criarNo(valor);
    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        novo->prox = *inicio;
        (*inicio)->ant = novo;
        *inicio = novo;
    }
}

// Função para inserir um nó no final da lista
void inserirNoFinal(No** inicio, int valor) {
    No* novo = criarNo(valor);
    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No* temp = *inicio;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
        novo->ant = temp;
    }
}

// Função para inserir um nó de forma ordenada na lista
void inserirOrdenado(No** inicio, int valor) {
    No* novo = criarNo(valor);
    if (*inicio == NULL) {
        *inicio = novo;
        return;
    }
    
    No* atual = *inicio;
    
    // Se o novo valor for menor que o primeiro elemento, insere no início
    if (valor < atual->dado) {
        novo->prox = *inicio;
        (*inicio)->ant = novo;
        *inicio = novo;
        return;
    }

    // Percorrer a lista para encontrar a posição correta
    while (atual->prox != NULL && atual->prox->dado < valor) {
        atual = atual->prox;
    }

    // Inserir no final se chegamos ao último nó
    if (atual->prox == NULL) {
        atual->prox = novo;
        novo->ant = atual;
    } else { // Inserir entre dois nós
        novo->prox = atual->prox;
        novo->ant = atual;
        atual->prox->ant = novo;
        atual->prox = novo;
    }
}

// Função para remover o nó do início da lista
void removerInicio(No** inicio) {
    if (*inicio == NULL) {
        printf("A lista está vazia, nada para remover!\n");
        return;
    }

    No* temp = *inicio;
    *inicio = (*inicio)->prox;
    
    if (*inicio != NULL) {
        (*inicio)->ant = NULL;
    }
    
    free(temp);
    printf("Elemento removido do início.\n");
}

// Função para remover o nó do final da lista
void removerFinal(No** inicio) {
    if (*inicio == NULL) {
        printf("A lista está vazia, nada para remover!\n");
        return;
    }

    No* temp = *inicio;
    
    // Se há apenas um elemento
    if (temp->prox == NULL) {
        free(temp);
        *inicio = NULL;
    } else {
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->ant->prox = NULL;
        free(temp);
    }
    printf("Elemento removido do final.\n");
}

// Função para buscar um elemento na lista
void buscarElemento(No* inicio, int valor) {
    if (inicio == NULL) {
        printf("A lista está vazia!\n");
        return;
    }
    
    No* temp = inicio;
    int posicao = 0;
    while (temp != NULL) {
        if (temp->dado == valor) {
            printf("Elemento %d encontrado na posição %d\n", valor, posicao);
            return;
        }
        temp = temp->prox;
        posicao++;
    }
    printf("Elemento %d não encontrado na lista.\n", valor);
}

// Função para limpar a lista (remover todos os elementos)
void limparLista(No** inicio) {
    No* temp;
    while (*inicio != NULL) {
        temp = *inicio;
        *inicio = (*inicio)->prox;
        free(temp);
    }
    printf("A lista foi completamente limpa.\n");
}

// Função principal
int main() {
    No* lista = NULL;

    // Inserindo elementos
    inserirNoInicio(&lista, 20);
    inserirNoInicio(&lista, 10);
    inserirNoFinal(&lista, 30);
    inserirNoFinal(&lista, 40);
    inserirOrdenado(&lista, 25);
    exibirLista(lista); // Saída esperada: 10 20 25 30 40 

    // Buscar elementos na lista
    buscarElemento(lista, 25); // Deve encontrar
    buscarElemento(lista, 50); // Não deve encontrar

    // Remover elementos
    removerInicio(&lista);
    removerFinal(&lista);
    exibirLista(lista); // Saída esperada: 20 25 30

    // Limpar a lista
    limparLista(&lista);
    exibirLista(lista); // Saída esperada: A lista está vazia!

    return 0;
}

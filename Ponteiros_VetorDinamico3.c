#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

No* criar_no(int valor) {
    No *novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->valor = valor;
        novo->prox = NULL;
    }
    return novo;
}

int contem(No *lista, int valor) {
    No *atual = lista;
    while (atual != NULL) {
        if (atual->valor == valor) {
            return 1;
        }
        atual = atual->prox;
    }
    return 0; 
}

void adicionar_no_final(No **lista, int valor) {
    No *novo = criar_no(valor);
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

No* uniao(No *x1, No *x2) {
    No *x3 = NULL; 

    No *atual = x1;
    while (atual != NULL) {
        if (!contem(x3, atual->valor)) {
            adicionar_no_final(&x3, atual->valor);
        }
        atual = atual->prox;
    }

    atual = x2;
    while (atual != NULL) {
        if (!contem(x3, atual->valor)) {
            adicionar_no_final(&x3, atual->valor);
        }
        atual = atual->prox;
    }

    return x3;
}

void imprimir_lista(No *lista) {
    No *atual = lista;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void liberar_lista(No *lista) {
    No *atual = lista;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
}

int main() {
    No *x1 = NULL;
    adicionar_no_final(&x1, 1);
    adicionar_no_final(&x1, 3);
    adicionar_no_final(&x1, 5);
    adicionar_no_final(&x1, 6);
    adicionar_no_final(&x1, 7);

    No *x2 = NULL;
    adicionar_no_final(&x2, 1);
    adicionar_no_final(&x2, 3);
    adicionar_no_final(&x2, 4);
    adicionar_no_final(&x2, 6);
    adicionar_no_final(&x2, 8);

    No *x3 = uniao(x1, x2);

    printf("Lista união (x3): ");
    imprimir_lista(x3);

    liberar_lista(x1);
    liberar_lista(x2);
    liberar_lista(x3);

    return 0;
}

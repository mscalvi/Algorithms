#include <stdio.h>
#include <stdlib.h>

int contem(int *vetor, int tamanho, int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == elemento) {
            return 1;
        }
    }
    return 0; 
}

int* uniao(int *x1, int *x2, int n1, int n2, int *qtd) {
    int tamanho_max = n1 + n2;
    int *x3 = (int *)malloc(tamanho_max * sizeof(int)); 

    if (x3 == NULL) {
        printf("Erro de alocacao de memoria!\n");
        *qtd = 0;
        return NULL;
    }

    int indice = 0;

    for (int i = 0; i < n1; i++) {
        if (!contem(x3, indice, x1[i])) { 
            x3[indice++] = x1[i];
        }
    }

    for (int i = 0; i < n2; i++) {
        if (!contem(x3, indice, x2[i])) { 
            x3[indice++] = x2[i];
        }
    }

    *qtd = indice;

    x3 = (int *)realloc(x3, (*qtd) * sizeof(int));

    return x3;
}

int main() {
    int x1[] = {1, 3, 5, 6, 7};
    int x2[] = {1, 3, 4, 6, 8};
    int n1 = 5;
    int n2 = 5;
    int qtd;

    int *x3 = uniao(x1, x2, n1, n2, &qtd);

    if (x3 != NULL) {
        printf("Vetor uniao (x3): ");
        for (int i = 0; i < qtd; i++) {
            printf("%d ", x3[i]);
        }
        printf("\n");

        free(x3);
    }

    return 0;
}

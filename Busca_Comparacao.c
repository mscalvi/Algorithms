#include <stdio.h>

// Busca Sequencial
int buscaSequencial(int vetor[], int n, int elemento, int *comparacoes) {
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (vetor[i] == elemento) {
            return i;
        }
    }
    return -1;
}

// Busca Sequencia Ordenada
int buscaSequencialOrdenada(int vetor[], int n, int elemento, int *comparacoes) {
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        if (vetor[i] == elemento) {
            return i;
        }
        if (vetor[i] > elemento) {
            break;
        }
    }
    return -1; 
}

// Busca Binária
int buscaBinaria(int vetor[], int inicio, int fim, int elemento, int *comparacoes) {
    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        (*comparacoes)++;

        if (vetor[meio] == elemento) {
            return meio;
        } else if (vetor[meio] < elemento) {
            inicio = meio + 1; 
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main() {
    int elemento;

    int vetor[10];

    printf("Digite os elementos do vetor ordenado: \n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Digite o elemento a ser buscado: ");
    scanf("%d", &elemento);

    int comparacoesSequencial = 0;
    int resultadoSequencial = buscaSequencial(vetor, 10, elemento, &comparacoesSequencial);

    int comparacoesSequencialOrdenada = 0;
    int resultadoSequencialOrdenada = buscaSequencialOrdenada(vetor, 10, elemento, &comparacoesSequencialOrdenada);

    int comparacoesBinaria = 0;
    int resultadoBinaria = buscaBinaria(vetor, 0, 9, elemento, &comparacoesBinaria);

    printf("\nResultados:\n");

    if (resultadoSequencial != -1) {
        printf("Busca Sequencial: encontrado no indice %d com %d comparacoes.\n", resultadoSequencial, comparacoesSequencial);
    } else {
        printf("Busca Sequencial: nao encontrado com %d comparacoes.\n", comparacoesSequencial);
    }

    if (resultadoSequencialOrdenada != -1) {
        printf("Busca Sequencial Ordenada: encontrado no indice %d com %d comparacoes.\n", resultadoSequencialOrdenada, comparacoesSequencialOrdenada);
    } else {
        printf("Busca Sequencial Ordenada: nao encontrado com %d comparacoes.\n", comparacoesSequencialOrdenada);
    }

    if (resultadoBinaria != -1) {
        printf("Busca Binaria: encontrado no indice %d com %d comparacoes.\n", resultadoBinaria, comparacoesBinaria);
    } else {
        printf("Busca Binaria: nao encontrado com %d comparacoes.\n", comparacoesBinaria);
    }

    return 0;
}

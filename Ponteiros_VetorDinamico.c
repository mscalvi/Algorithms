#include <stdio.h>
#include <stdlib.h>

void ler_elementos(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("Digite o elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }
}

int main() {
    int n;

    printf("Digite a quantidade de elementos: ");
    scanf("%d", &n);

    int *vetor = (int *)malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }

    ler_elementos(vetor, n);

    printf("Vetor preenchido:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    free(vetor);

    return 0;
}

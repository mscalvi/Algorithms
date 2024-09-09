#include <stdio.h>

int menorElemento(int vetor[], int n) {
    int menor;
    
    if (n == 1) {
        return vetor[0];
    }

    menor = menorElemento(vetor, n - 1);

    if (vetor[n - 1] < menor) {
        return vetor[n - 1];
    } else {
        return menor;
    }
}

int main() {
    int vetor[10];  

    printf("Digite 10 numeros inteiros:\n");
    for (int i = 0; i < 10; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    int menor = menorElemento(vetor, 10);

    printf("O menor elemento do vetor é: %d\n", menor);

    return 0;
}
#include <stdio.h>

int soma(int x, int vet[]) {
    if (x == 0){
        return 0;
    } else {
        return soma(x-1, vet) + vet[x-1];
    }
}

int main() {
    int numero;
    int vetor[10];
    
    for (int i = 0; i < 10; i++){
        printf("\nDigite um número:\n");
        scanf("%d", &vetor[i]);
    }

    printf("A soma do vetor é %d", soma(10, vetor));
    
    return 0;
}

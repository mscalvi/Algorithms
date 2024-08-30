#include <stdio.h>
#include <math.h>

int main (){
    int vetor[5], N, soma;
    soma = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite um numero inteiro\n");
        scanf ("%d", &N);
        vetor[i] = N;
    }
    for (int i = 0; i < 5; i++)
    {
        soma = soma + vetor[i];
    }

    printf("Soma = %d", soma);
    return 0;
}
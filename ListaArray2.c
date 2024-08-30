#include <stdio.h>
#include <math.h>

int main (){
    int vetor[10], N, X, soma;
    float media;
    
    soma = 0;
    X = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite um numero inteiro\n");
        scanf ("%d", &N);
        vetor[i] = N;
    }
    for (int i = 0; i < 5; i++)
    {
        if (vetor[i] % 2 == 0)
        {
            soma = soma + vetor[i];
            X++;
        }
    }

    media = soma / X;

    printf("Meida dos Pares = %.2f", media);
    return 0;
}
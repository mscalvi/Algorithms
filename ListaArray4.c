#include <stdio.h>
#include <math.h>

int main (){

    int vetor[6];
    int n, mult;

    mult = 0;

    for (int i = 0; i < 8; i++)
    {
        printf("Digite um numero inteiro\n");
        scanf ("%d", &n);
        vetor[i] = n;
        mult = mult * n;
    }

    printf("Todos esse números multiplicados dão: %d", mult);
    
    return 0;
}


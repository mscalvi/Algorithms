#include <stdio.h>
#include <math.h>

int main (){

    int vetor[5];
    int n, aux, j;

    aux = 0;
    j = 4;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite um numero inteiro\n");
        scanf ("%d", &n);
        vetor[i] = n;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]);
    }

    printf ("\n");

    for (int i = 0; i < 2; i++)
    {
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
        j--;
    }

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]);
    }
    
    return 0;
}


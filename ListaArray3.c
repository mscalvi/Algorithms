#include <stdio.h>
#include <math.h>

int main (){

    int vetor[8];
    int n, maior, menor;

    maior = 0;
    menor = 0;

    for (int i = 0; i < 8; i++)
    {
        printf("Digite um numero inteiro\n");
        scanf ("%d", &n);
        vetor[i] = n;
        if (i == 0){
            maior = n;
            menor = n;
        }
        if (n > maior)
        {
            maior = n;
        }
        if (n < menor)
        {
            menor = n;
        }
    }

    printf("O maior elemento é %d, e o menor é %d", maior, menor);
    
    return 0;
}


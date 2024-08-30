#include <stdio.h>
#include <math.h>

int main (){

    int vetor[20];
    int n, maior, posicao;

    maior = 0;
    posicao = 0;

    for (int i = 0; i < 20; i++)
    {
        scanf ("%d", &n);
        vetor[i] = n;
        if (i == 0){
            maior = n;
        }
        if (n > maior)
        {
            maior = n;
            posicao = i+1;
        }
    }

    printf("O maior elemento é %d, e sua posicao é %d", maior, posicao);
    
    return 0;
}


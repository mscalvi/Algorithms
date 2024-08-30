#include <stdio.h>
#include <math.h>

int main (){

    int vetor[7];
    int n, aux, pronto;

    aux = 0;
    pronto = 0;

    for (int i = 0; i < 7; i++)
    {
        printf("Digite um numero inteiro\n");
        scanf ("%d", &n);
        vetor[i] = n;
    }

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", vetor[i]);
    }

    do {
        for (int i = 0; i < 7; i++)
        {
            if (vetor[i] > vetor [i+1])
            {  
                aux = vetor[i+1];
                vetor[i+1] = vetor[i];
                vetor[i] = aux;
            }
        }
        if (vetor[0] <= vetor[1] && vetor[1] <= vetor[2]  && vetor[2] <= vetor[3]  && vetor[3] <= vetor[4]  && vetor[4] <= vetor[5]  && vetor[5] <= vetor[6] )
        {
            pronto = 1;
        }
    } while (pronto == 0);

    printf ("\n");

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", vetor[i]);
    }
    
    return 0;
}


#include <stdio.h>
#include <math.h>

int main (){

    int vetor[10];
    int n, proc, apar, pronto, aux;

    apar = 0;
    pronto = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite um numero inteiro\n");
        scanf ("%d", &n);
        vetor[i] = n;
    }

    printf("Seu vetor:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
    }

    do {
        for (int i = 0; i < 10; i++)
        {
            if (vetor[i] > vetor [i+1])
            {  
                aux = vetor[i+1];
                vetor[i+1] = vetor[i];
                vetor[i] = aux;
            }
        }
        if (vetor[0] <= vetor[1] && vetor[1] <= vetor[2] && vetor[2] <= vetor[3] && vetor[3] <= vetor[4] && vetor[4] <= vetor[5] && vetor[5] <= vetor[6] && vetor[6] <= vetor[7] && vetor[7] <= vetor[8] && vetor[8] <= vetor[9] && vetor[9] <= vetor[10])
        {
            pronto = 1;
        }
    } while (pronto == 0);

    for (int i = 0; i < 10; i++)
    {
        if (i != 10 && i != 0)
        {
            if (vetor[i] == vetor [i+1] && vetor[i] != vetor[i-1])
            {
                apar++;
            }
        }
    }

    printf ("\n");
    printf("Quantidade de numeros que se repetem é: %d\n", apar);
    
    return 0;
}


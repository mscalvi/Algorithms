#include <stdio.h>
#include <math.h>

int main (){
    int tam, n, soma;

    scanf ("%d", &tam);
    
    int matriz[tam][tam];

    soma = 0;

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            scanf ("%d", &n);
            matriz[i][j] = n;
        }
    }

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            printf ("%d ", matriz[i][j]);
        }
        printf ("\n");
    }

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            if (i >= j){
                soma = soma + matriz[i][j];
            }
        }
    }

    printf ("\nA soma dos elementos e: %d", soma);

    return 0;
}
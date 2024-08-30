#include <stdio.h>
#include <math.h>

int main (){
    int matriz[4][5], n, vetor[5];

    vetor[0] = 0;
    vetor[1] = 0;
    vetor[2] = 0;
    vetor[3] = 0;
    vetor[4] = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf ("%d", &n);
            matriz[i][j] = n;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            vetor[j] = vetor[j] + matriz[i][j];
            printf ("%d ", matriz[i][j]);
        }
        printf ("\n");
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf ("%d ", vetor[i]);
    }

    return 0;
}


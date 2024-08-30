#include <stdio.h>
#include <math.h>

int main (){
    int tam, n, simetrica;

    scanf ("%d", &tam);
    
    int matriz[tam][tam];

    simetrica = 0;

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
            if (matriz[i][j] != matriz[j][i]){
                simetrica = 1;
            }
        }
    }

    if (simetrica == 0){
        printf ("\nA matriz e simetrica");
    } else {
        printf ("\nA matriz nao e simetrica.");
    }

    return 0;
}
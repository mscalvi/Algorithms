#include <stdio.h>
#include <math.h>

int main (){
    int matriz[2][2], n;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            scanf ("%d", &n);
            matriz[i][j] = n;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf ("%d ", matriz[i][j]);
        }
        printf ("\n");
    }

    return 0;
}


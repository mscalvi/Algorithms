#include <stdio.h>
#include <math.h>

int main (){
    int matriz[4][5], n, somal;

    somal = 0;

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
        somal = 0;
        for (int j = 0; j < 5; j++)
        {
            somal = somal + matriz[i][j];
            printf ("%d ", matriz[i][j]);
        }
        printf (" -  %d \n", somal);
    }

    return 0;
}


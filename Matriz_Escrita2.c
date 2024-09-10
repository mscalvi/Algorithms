#include <stdio.h>
#include <math.h>

int main (){
    float matriz[3][4], n;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf ("%f", &n);
            matriz[i][j] = n;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf ("%.2f ", matriz[i][j]);
        }
        printf ("\n");
    }

    return 0;
}


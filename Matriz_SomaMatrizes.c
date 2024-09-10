#include <stdio.h>
#include <math.h>

int main (){
    int matriz1[3][4], matriz2[3][4], matrizs[3][4], n;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf ("%d", &n);
            matriz1[i][j] = n;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf ("%d", &n);
            matriz2[i][j] = n;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrizs[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf ("%d ", matrizs[i][j]);
        }
        printf ("\n");
    }

    return 0;
}


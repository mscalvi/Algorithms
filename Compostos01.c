#include <stdio.h>
#include <math.h>

int main (){
    int matriz[3][3], n;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf ("%d", &n);
            matriz[i][j] = n;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j = 2){
                printf ("%d ", matriz[i][j]);
            }
        }
        printf ("\n");
    }

    return 0;
}


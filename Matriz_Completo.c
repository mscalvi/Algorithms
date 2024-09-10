#include <stdio.h>
#include <math.h>

int main (){
    int Matriz[6][6], n, SomaP, SomaS, SomaUpP, SomaUpS, SomaDownP, SomaDownS;

    SomaP = 0;
    SomaS = 0;
    SomaUpP = 0;
    SomaUpS = 0;
    SomaDownP = 0;
    SomaDownS = 0;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            scanf ("%d", &n);
            Matriz[i][j] = n;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (i == j) //Diagonal Principal
            {
                SomaP = SomaP + Matriz[i][j];
            }
            if (i + j == 5) //Diagonal Secundaria
            {
                SomaS = SomaS + Matriz[i][j];
            }
            if (i < j) //Superior a Diagonal Principal
            {
                SomaUpP = SomaUpP + Matriz[i][j];
            }
            if (i + j < 5) //Superior a Diagonal Secundaria
            {
                SomaUpS = SomaUpS + Matriz[i][j];
            }
            if (i > j) //Inferior a Diagonal Principal
            {
                SomaDownP = SomaDownP + Matriz[i][j];
            }
            if (i + j > 5) //Inferior a Diagonal Secundaria
            {
                SomaDownS = SomaDownS + Matriz[i][j];
            }
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf ("%d ", Matriz[i][j]);
        }
        printf ("\n");
    }

    printf ("A- Soma dos elementos da Diagonal Principal: %d\n", SomaP);
    printf ("B- Soma dos elementos da Diagonal Secundaria: %d\n", SomaS);
    printf ("C- Soma dos elementos acima da Diagonal Principal: %d\n", SomaUpP);
    printf ("D- Soma dos elementos abaixo da Diagonal Principal: %d\n", SomaDownP);
    printf ("E- Soma dos elementos acima Diagonal Secundaria: %d\n", SomaUpS);
    printf ("F- Soma dos elementos abaixo Diagonal Secundaria: %d\n", SomaDownS);

    return 0;
}


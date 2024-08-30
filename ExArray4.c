#include <stdio.h>
#include <math.h>

int main (){

    int vetor1[10], vetor2[10], vetor3[10], n;

    for (int i = 0; i < 10; i++)
    {
        scanf ("%d", &n);
        vetor1[i] = n;
    }

    for (int i = 0; i < 10; i++)
    {
        scanf ("%d", &n);
        vetor2[i] = n;
    }

    for (int i = 0; i < 10; i++)
    {
        vetor3[i] = vetor1[i]* vetor2[i];
    }

    for (int i = 0; i < 10; i++)
    {
        printf ("%d ", vetor3[i]);
    }
    return 0;
}


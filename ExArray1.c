#include <stdio.h>
#include <math.h>

int main (){
    int vetor[100];

    for (int i = 0; i < 100; i++)
    {
        vetor[i] = 10;
        printf("%d  ", vetor[i]);
    }
    printf("\n");
    for (int i = 1; i <= 100; i++)
    {
        vetor[i] = i;
        printf("%d ", vetor[i]);
    }

    return 0;
}


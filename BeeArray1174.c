#include <stdio.h>
#include <math.h>

int main (){
    float vetor[10], n;

    for (int i = 0; i < 10; i++)
    {
        scanf ("%f", &n);
        vetor[i] = n;
    } //Le o vetor e calcula o próximo numero

    for (int i = 0; i < 10; i++)
    {
        if (vetor[i] <= 10)
        {
            printf("A[%d] = %.1f\n", i, vetor[i]);
        }
    } //Escreve o vetor

    return 0;
}


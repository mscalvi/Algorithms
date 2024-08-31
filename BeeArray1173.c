#include <stdio.h>
#include <math.h>

int main (){
    int vetor[10], n;

    scanf ("%d", &n);

    for (int i = 0; i < 10; i++)
    {
        vetor[i] = n * pow(2,i);
    } //Le o vetor e calcula o próximo numero

    for (int i = 0; i < 10; i++)
    {
        printf("N[%d] = %d\n", i, vetor[i]);
    } //Escreve o vetor

    return 0;
}


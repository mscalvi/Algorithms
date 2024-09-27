#include <stdio.h>
#include <math.h>

int main (){
    int vetor[1000], n, aux;

    scanf ("%d", &n);

    aux = 0;

    for (int i = 0; i < 1000; i++)
    {
        vetor[i] = aux;
        aux++;
        if (aux == n)
        {
            aux = 0;
        }
    } //Le o vetor e calcula o próximo numero

    for (int i = 0; i < 1000; i++)
    {
        printf("N[%d] = %d\n", i, vetor[i]);
    } //Escreve o vetor

    return 0;
}

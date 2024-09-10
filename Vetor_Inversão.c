#include <stdio.h>
#include <math.h>

int main (){
    float vetor[20], n;
    int aux;

    for (int i = 0; i < 20; i++)
    {
        scanf ("%f", &n);
        vetor[i] = n;
    } //Le o vetor e calcula o próximo numero

    for (int i = 0; i < 10; i++)
    {
        aux = vetor[i];
        vetor[i] = vetor[19-i];
        vetor[19-i] = aux;
    } //Inverte o vetor

    for (int i = 0; i < 20; i++)
    {
        printf("N[%d] = %.0f\n", i, vetor[i]);
    } //Escreve o vetor

    return 0;
}


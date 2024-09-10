#include <stdio.h>
#include <math.h>

int main (){
    double vetor[100], n;

    scanf ("%lf", &n);

    for (int i = 0; i < 100; i++)
    {
        vetor[i] = n;
        n = n / 2;
    } //Le o vetor e calcula o próximo numero

    for (int i = 0; i < 100; i++)
    {
        printf("N[%d] = %.4lf\n", i, vetor[i]);
    } //Escreve o vetor

    return 0;
}

#include <stdio.h>
#include <math.h>

int main (){
    int vetor[10], n;

    for (int i = 0; i < 10; i++)
    {
        scanf ("%d", &n);
        if (n <= 0)
        {
            vetor[i] = 1;
        } else {
            vetor[i] = n;
        }
    } //Le o vetor e já corrige negativos e positivos

    for (int i = 0; i < 10; i++)
    {
        printf("X [%d]= %d\n", i, vetor[i]);
    } //Escreve o vetor

    return 0;
}


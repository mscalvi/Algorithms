#include <stdio.h>
#include <math.h>

int main (){
    int n, menor, posicao, tam;

    menor = 0;
    posicao = 0;

    scanf ("%d", &tam);
    int vetor[tam];

    for (int i = 0; i < tam; i++)
    {
        scanf ("%d", &n);
        vetor[i] = n;
        if (i == 0){
            menor = n;
            posicao = i;
        }
        if(n < menor){
            menor = n;
            posicao = i;
        }
    } //Le o vetor e calcula o próximo numero

    printf("Menor valor: %d\nPosicao: %d\n", menor, posicao);

    return 0;
}


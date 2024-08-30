#include <stdio.h>

int main() {

    double vetor[20];
    
    double maior, menor;
    int cMaior, cMenor;

    //entra o vetor
    for (int i = 0; i < 20; i++) {
        scanf ("%lf", &vetor[i]);
    }

    maior = vetor [0];
    menor = vetor [0];

    //verificar numero maior e menor
    for (int i = 0; i < 20; i++) {
        if (vetor[i] > maior){
            maior = vetor[i];
        }
        if (vetor [i] < menor){
            menor = vetor[i];
        }
    }

    //conta repetiçoes
    cMaior = 0;
    cMenor = 0;

    for (int i = 0; i < 20; i++) {
        if (vetor[i] == maior){
            cMaior++;
        }
        if (vetor [i] == menor){
            cMenor++;
        }
    }

    printf("Maior numero: %f, %d vezes\nMenor numero: %f, %d vezes\n", maior, cMaior, menor, cMenor);
    return 0;
}
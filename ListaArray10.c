#include <stdio.h>
#include <math.h>

int main (){

    int vetor[10];
    int n, proc, apar;

    apar = 11;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite um numero inteiro diferente dos anteriores.\n");
        scanf ("%d", &n);
        vetor[i] = n;
    }

    printf("Qual numero deseja procurar?\n");
    scanf("%d", &proc);
  
    printf("Seu vetor:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", vetor[i]);
        if (vetor[i] == proc)
        {
            apar = i;
        }
    }

    printf ("\n");
    if (apar == 11)
    {
       printf("Seu numero não está no vetor.\n"); 
    }
    printf("Seu numero esta na posicao %d do vetor, considerando que ele inicia em 1.\n", apar+1);
    
    return 0;
}


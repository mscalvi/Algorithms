#include <stdio.h>
#include <math.h>

int main (){

    int vetor[10];
    int n, proc, apar;

    apar = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite um numero inteiro\n");
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
            apar++;
        }
    }

    printf ("\n");
    printf("Quantidade de vezes que o numero %d aparece: %d\n", proc, apar);
    
    return 0;
}


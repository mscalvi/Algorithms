#include <stdio.h>
#include <math.h>

int main () {

    long a, Fatorial;
    int x;

    x = 1;

    while (x == 1) {
        Fatorial = 1;
        printf ("Digite um número.\n");
        scanf ("%d", &a);

        if (a < 0){
            printf ("Não definido.\n");
        } else {
            for (int i = 1; i <= a; i++){
                Fatorial = Fatorial * i;
                printf ("Para o número %d o fatorial total é: %ld\n", i, Fatorial);
            }
        }

        printf ("Deseja testar outro par de números? 1 = Sim, 0 = Não.\n");
        scanf ("%d", &x);
    }
}
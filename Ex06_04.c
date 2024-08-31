/* Desenvolva um algoritmo em C que solicite ao usu ́ario um numero inteiro e,
em seguida, use um loop while para exibir a tabuada desse numero de 1 a
10. */

#include <stdio.h>
#include <math.h>

int main ()
{
    int num, tabuada, resultado;

    printf ("Digite um número.\n");

    scanf ("%d", &num);
    resultado = 0;
    tabuada = 0;

    while (tabuada <= 10) {
        resultado = num * tabuada;
        printf ("%d x %d = %d\n", num, tabuada, resultado);
        tabuada++;
    }
}

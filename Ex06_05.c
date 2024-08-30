/* Crie um programa utilizando loop do-while que solicite ao usuario que in-
sira uma serie de numeros positivos. O programa deve continuar solicitando
numeros at ́e que o usuario insira um numero negativo. Em seguida, o pro-
grama deve exibir a soma dos numeros positivos inseridos. */

#include <stdio.h>
#include <math.h>

int main ()
{
    int num, resultado;
    resultado = 0;

    do{
        printf ("\nDigite um número.\n");

        scanf ("%d", &num);

        resultado = resultado + num;

    } while (num >= 0);

    printf ("\nSoma total dos numeros: %d", resultado);
}

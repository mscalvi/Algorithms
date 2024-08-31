/* Escreva um programa que solicite ao usu ́ario um n ́umero inteiro positivo e,
em seguida, use um loop while para exibir uma contagem regressiva a partir
desse n ́umero at ́e zero. Por exemplo, se o usu ́ario inserir 5, o programa deve
exibir: 5, 4, 3, 2, 1, 0. */

#include <stdio.h>
#include <math.h>

int main ()
{
    int num;

    printf ("Digite um numero inteiro e positivo.\n");

    scanf ("%d", &num);

    if (num < 0){
        printf ("Numero invalido.\n");
    }

    while (num >= 0){
        printf ("%d\n", num);
        num--;
    }
}
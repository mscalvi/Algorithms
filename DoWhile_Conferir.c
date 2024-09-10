#include <stdio.h>
#include <math.h>

int main () {

    int a, b;

    b = 0;

    do {
        printf ("Digite um número de 1 a 4.\n");
        scanf ("%d", &a);
        if (a <= 4 && a >= 0) {
            printf ("%d", a);
            b = 1;
        } else {
            printf ("Número inválido!\n");
            b = 0;
        }
    } while (b != 1);
}
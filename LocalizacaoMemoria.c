#include <stdio.h>

int main (){
    int a, b;

    printf ("Digite o primeiro valor: ");
    scanf ("%d", &a);
    printf ("Digite o segundo valor: ");
    scanf ("%d", &b);

    printf ("\nTeste");
    printf ("\nSoma: %d ", a + b);
    printf ("\nSubtração: %d ", a - b);
    printf ("\nSubtração: %.2f ", (float)a / b);

    printf ("\nA variável A tem o valor %d, e está localizada em %p", a, &a);
    printf ("\nA variável B tem o valor %d, e está localizada em %p", b, &b);

    return 0;
}
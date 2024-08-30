#include <stdio.h>

int main (){
    float a, b, m;

    printf ("Digite o primeiro valor: ");
    scanf ("%f", &a);
    printf ("Digite o segundo valor: ");
    scanf ("%f", &b);

    m = (a+b)/2;

    printf ("\nSoma: %.f ", a + b);
    printf ("\nMédia: %.2f ", m);

    return 0;
}
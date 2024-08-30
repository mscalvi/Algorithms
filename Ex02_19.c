#include <stdio.h>
#include <math.h>

int main () {

    int Num1, Num2;
    int Soma, Sub1, Sub2, Mult, Quo1, Quo2, Res1, Res2;
    float Div1, Div2;

    printf ("Digite o primeiro número.\n");
    scanf ("%d", &Num1);

    printf ("Digite o segundo número.\n");
    scanf ("%d", &Num2);

    Soma = Num1 + Num2;
    Sub1 = Num1 - Num2;
    Sub2 = Num2 - Num1;
    Mult = Num1 * Num2;
    Div1 = (float) Num1 / Num2;
    Div2 = (float) Num2 / Num1;
    Quo1 = Num1 / Num2;
    Quo2 = Num2 / Num1;
    Res1 = Num1 % Num2;
    Res2 = Num2 % Num1;

    printf ("\nSoma: %d", Soma);
    printf ("\nSubtração A-B: %d", Sub1);
    printf ("\nSubtração B-A: %d", Sub2);
    printf ("\nMultiplicação: %d", Mult);
    printf ("\nDivisão A/B: %.2f", Div1);
    printf ("\nDivisão B/A: %.2f", Div2);
    printf ("\nQuociente A/B: %d", Quo1);
    printf ("\nQuociente B/A: %d", Quo2);
    printf ("\nResto de A/B: %d", Res1);
    printf ("\nResto de B/A: %d", Res2);

    return 0;
}

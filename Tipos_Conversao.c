#include <stdio.h>

int main ()
{
    float Num, Frac;
    int Inte, Arred;

    printf ("Insira um número.");
    scanf ("%f", &Num);

    Inte = (int)Num;
    Frac = Num - Inte;

    if (Frac < 0.5)
    {
        Arred = Inte;
    } else {
        Arred = Inte + 1;
    }

    printf ("\nA parte inteira dele é: %d", Inte);
    printf ("\nA parte fracionária dele é: %f", Frac);
    printf ("\nO valor arredondado dele é: %d", Arred);
}
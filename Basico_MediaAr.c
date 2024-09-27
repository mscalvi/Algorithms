#include <stdio.h>
#include <math.h>

int main ()
{
    float Nota1, Nota2, Peso1, Peso2, Media, NReal1, NReal2;

    printf ("\nDigite a primeira nota.\n");
    scanf ("%f", &Nota1);
    printf ("\nDigite o peso da nota, de 0 a 10.\n");
    scanf ("%f", &Peso1);

    printf ("\nDigite a segunda nota.\n");
    scanf ("%f", &Nota2);
    printf ("\nDigite o peso da nota, de 0 a 10.\n");
    scanf ("%f", &Peso2);

    NReal1 = Nota1 * (Peso1/10);
    NReal2 = Nota2 * (Peso2/10);

    Media = NReal1 + NReal2;

    printf ("\nA Média do aluno foi: %.2f", Media);
}
#include <stdio.h>
#include <math.h>

int main ()
{
    float Nota1, Nota2, Nota3, Media;

    printf ("\nDigite a primeira nota.\n");
    scanf ("%f", &Nota1);
    printf ("\nDigite a segunda nota.\n");
    scanf ("%f", &Nota2);
    printf ("\nDigite a terceira nota.\n");
    scanf ("%f", &Nota3);

    Media = (Nota1 + Nota2 + Nota3) / 3;

    printf ("\nA Média do aluno foi: %.2f", Media);
}
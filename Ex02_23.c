#include <stdio.h>
#include <math.h>

int main ()
{
    float Ang, AngRad, SenAng, CosAng, TanAng;

    printf ("Digite o valor do ângulo desejado.\n");
    scanf ("%f", &Ang);

    AngRad = Ang * 3.14 / 180;

    SenAng = sin(AngRad);
    CosAng = cos(AngRad);
    TanAng = tan(AngRad);

    printf ("\nPara o ângulo %.0f, temos um seno de %.2f, cosseno de %.2f, e tangente de %.2f.", Ang, SenAng, CosAng, TanAng);

}
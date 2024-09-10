#include <stdio.h>
#include <math.h>

int main (){
    float Raio, Result;

    printf ("Digite o raio da esfera.\n");
    scanf ("%f", &Raio);

    Result = 4/3 * pow(Raio, 3) * 3.1415;

    printf ("O volume da esfera é %.2f umc", Result);
}
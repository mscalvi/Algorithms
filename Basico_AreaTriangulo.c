#include <stdio.h>
#include <math.h>

int main (){
    float Result;
    float a, b, c, p;

    printf ("Digite o comprimento dos lados do triangulo.\n");
    scanf ("%f %f %f", &a, &b, &c);

    p = (a+b+c)/2;

    Result = sqrt(p*(p-a)*(p-b)*(p-c));

    printf ("A área do triangulo é %.2f uma", Result);
}
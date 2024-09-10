#include <stdio.h>
#include <math.h>

int main (){
    float Result, p;
    int x1, x2, y1, y2;

    printf ("Digite o primeiro ponto.\n");
    scanf ("%d %d", &x1, &y1);

    printf ("Digite o segundo ponto.\n");
    scanf ("%d %d", &x2, &y2);

    p = pow(x1-x2,2) + pow(y1-y2,2);
    Result = sqrt(p);

    printf ("A distância entre os pontos é %.2f umd", Result);
}
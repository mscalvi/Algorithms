#include <stdio.h>
#include <math.h>

int main () {
    float a, b, c;
    float delta, x1, x2, result;

    scanf ("%f %f %f", &a, &b, &c);

    delta = b*b - 4 * a * c;

    if (delta > 0){
        x1 = (-b + sqrt(delta))/(2 * a);
        x2 = (-b - sqrt(delta))/(2 * a);

        printf ("Raizes sao: %.2f e %.2f", x1, x2);
    }
    else if (delta < 0 ) {
        printf ("\n Nao existem raizes reais");

    } else {
        x1 = (-b + sqrt(delta))/(2 * a);

        printf ("So existe uma raiz, que e: %.2f", x1, x2);
    }

}
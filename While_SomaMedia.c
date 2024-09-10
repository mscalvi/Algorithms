#include <stdio.h>
#include <math.h>

int main () {

    int a, b, c;
    float d;

    b = 0;
    c = 0;
    d = 0;
    
    while (a >= 0) {
        printf ("Digite um número positivo.\n");
        scanf ("%d", &a);
        if (a > 0){
            b += a;
            c++;
            d = (float)b / c;
            printf ("Soma parcial: %d\nMedia parcial: %.1f\nNúmeros digitados: %d\n", b, d, c);
        } else {
            printf ("Soma final: %d\nMedia final: %.1f\nMedia parcial: %.1f\nNúmeros digitados: %d\n", b, d, c);
        }
    }
}
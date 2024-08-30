#include <stdio.h>
#include <math.h>

int main () {
    int a, b, c, aux;

    scanf ("%d %d %d", &a, &b, &c);

    while ( a > b || b > c){
        if (a > b){
            aux = a;
            a = b;
            b = aux;
        }
        if (b > c){
            aux = b;
            b = c;
            c = aux;
        }
    }

    printf ("A ordem crescente desses numero e: %d, %d e %d", a, b, c);
    
}
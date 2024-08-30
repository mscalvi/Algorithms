#include <stdio.h>
#include <math.h>

int main () {

    int a, b, Quo, Res, x; 
    x = 1;

    while (x == 1) {
        Quo = 0;
        Res = 0;
        
        printf ("Digite dois números.\n");
        scanf ("%d %d", &a, &b);

        while (a > 0) {
            if (a >= b){
                a -= b;
                Quo++;
            } Res = a + b;
            printf ("Quociente de %d por %d: %d\nResto: %d\n", a, b, Quo, Res);
        }

        printf ("Deseja testar outro par de números? 1 = Sim, 0 = Não.\n");
        scanf ("%d", &x);
    }
}
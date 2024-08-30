#include <stdio.h>
#include <math.h>

int main(){
    int n, dobras, teste, ant, atu;
    teste = 1;

    scanf ("%d", &n);

    while (n >= 0){
        atu = 0;
        ant = 2;
        for (int i = 1; i <= n; i++){
            atu = 2 * ant - 1;
            ant = atu;
        }
        dobras = atu * atu;
        if (n == 0){
            printf ("Teste %d\n4\n\n", teste);
        } else {
            printf ("Teste %d\n%d\n\n", teste, dobras);
        }

        teste++;
        scanf ("%d", &n);
    } 
}
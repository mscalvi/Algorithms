#include <stdio.h>
#include <math.h>

int main () {

    int a, b, c, d; 

    b = 0;
    c = 0;
    d = 0;

    do {
        printf ("Digite um número positivo.\n");
        scanf ("%d", &a);
        if (!d){ //Detecta o primeiro número de a, para referencial
            b = a;
            c = a;
            d++;
        }
        if (a > 0){ //Checa se o número é maior que o maior ou menor que o menor, se não ignora, se sim atualiza
            if (a > b){
                b = a;
            } else if (a < c){
                c = a;
            }
        } else { //Mostra o final se um número negativo for digitado
            printf ("Maior número: %d\nMenor número: %d\n", b, c);
        }
    } while (a > 0); //Quebra a sequencia se um número negativo for digitado
}
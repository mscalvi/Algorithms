#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
    FILE *arq;
    char caracter;

    arq = fopen ("teste.txt", "r");
    int cont = 0;
    do {
        cont++;
        caracter = getc(arq);
        if (caracter != EOF)
            printf ("%c",toupper(caracter));
    } while (caracter != EOF);
    printf("%d leituras\n", cont);
    
    return 0;
}
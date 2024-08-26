#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main () {
    FILE *arq;
    char caracter;
    int n, m, o, soma;

    soma = 0;

    if ((arq = fopen ("matriz.txt", "r")) == NULL){
        printf ("\n Arquivo não pode ser aberto.");
        exit(1);
    }

    while (fscanf (arq, "%d %d %d", &n, &m, &o) != EOF){
        soma += n + m + o;
    }

    printf ("soma: %d", soma);
        
    fclose (arq);

    return 0;
}
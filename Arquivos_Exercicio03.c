#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main () {

    FILE *arquivo;
    char caractere;
    int letras, digitos; 
    int moda[300];

    letras = 0;
    digitos = 0;

    if ((arquivo = fopen ("texto.txt", "r")) == NULL){
        printf ("\n Arquivo não pode ser aberto.");
        exit(1);
    }

    while ((caractere = fgetc(arquivo)) != EOF) {
        caractere = tolower(caractere);
        if (caractere >= 'a' && caractere <= 'z') {
            letras++;
        }
    }

    fclose (arquivo);

    printf("O texto contem %d vogais e %d consoantes", vogais, consoantes);
 
    return 0;
}
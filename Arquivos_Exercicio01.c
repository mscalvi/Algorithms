#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main () {

    FILE *arquivo;
    char caractere;
    int vogais, consoantes, outros;

    vogais = 0;
    consoantes = 0;
    outros = 0;

    if ((arquivo = fopen ("texto.txt", "r")) == NULL){
        printf ("\n Arquivo não pode ser aberto.");
        exit(1);
    }

    while ((caractere = fgetc(arquivo)) != EOF) {
        caractere = tolower(caractere);
        if (caractere == 'a' || caractere == 'e' || caractere == 'i' || caractere == 'o' || caractere == 'u'){
            vogais++;
        } else if (caractere > 'a' && caractere <= 'z') {
            consoantes++;
        } else {
            outros++;
        }
    }

    fclose (arquivo);

    printf("O texto contem %d vogais e %d consoantes", vogais, consoantes);
 
    return 0;
}
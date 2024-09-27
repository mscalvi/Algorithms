#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main () {

    FILE *arquivo1, *arquivo2, *arquivo3;
    char carac;

    if ((arquivo1 = fopen ("texto1.txt", "r")) == NULL){
        printf ("\n Arquivo 1 não pode ser aberto.");
        exit(1);
    }

    if ((arquivo2 = fopen ("texto2.txt", "r")) == NULL){
        printf ("\n Arquivo 2 não pode ser aberto.");
        exit(1);
    }

    arquivo3 = fopen("resultado.txt", "w");
    if (arquivo3 == NULL){
        printf("Erro ao criar o arquivo de saída.\n");
        fclose(arquivo1);
        fclose(arquivo2);
        return 1;
    }

    while ((carac = fgetc(arquivo1)) != EOF) {
        fputc(carac, arquivo3);
    }

    fprintf(arquivo3, "\n");

    while ((carac = fgetc(arquivo2)) != EOF) {
        fputc(carac, arquivo3);
    }

    fclose (arquivo1);
    fclose (arquivo2);
    fclose (arquivo3);

    return 0;
}
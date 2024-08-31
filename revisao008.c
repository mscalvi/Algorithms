#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char frase[300];
    char *menor, *palavra;
    int tamanho = 100;
    int tamanho2;

        printf("Digite uma frase:\n");
        fgets(frase, sizeof(frase), stdin);

        // Remove o caractere de nova linha do final da string, se presente
        frase[strcspn(frase, "\n")] = '\0';

        palavra = strtok(frase, " :.!,-");

        while (palavra != NULL) {
            tamanho2 = strlen(palavra);
            if (tamanho > tamanho2) {
                tamanho = tamanho2;
                menor = palavra;
            }
            palavra = strtok(NULL, " :.!,-");
        }

        printf("A menor palavra e: %s\n", menor);

    return 0;
}
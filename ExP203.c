#include <stdio.h>
#include <string.h>
#include <ctype.h>

int checaConsoante(char letra) {
    letra = tolower(letra);
    return (letra >= 'a' && letra <= 'z') && !(letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');
}

int main() {
    char frase[100];
    int cont = 1;

    while (cont == 1) {
        printf("Digite uma frase:\n");
        fgets(frase, sizeof(frase), stdin);

        // Remove o caractere de nova linha do final da string, se presente
        frase[strcspn(frase, "\n")] = '\0';

        char *palavra = strtok(frase, " :.!,-");

        printf("Palavras terminadas em consoantes:\n");
        while (palavra != NULL) {
            int tamanho = strlen(palavra);
            if (tamanho > 0 && checaConsoante(palavra[tamanho - 1])) {
                printf("%s\n", palavra);
            }
            palavra = strtok(NULL, " :.!,-");
        }

        printf("Digite 1 para continuar, 0 para sair.\n");
        scanf("%d", &cont);

        //Limpa a entrada
        while (getchar() != '\n');
    }

    return 0;
}
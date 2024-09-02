#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINHA 1024

char caractereMaisFrequente(char linha[]) {
    int frequencia[256] = {0}; 
    int maxFreq = 0;
    char caractereMaisFreq = '\0';

    for (int i = 0; linha[i] != '\0'; i++) {
        if (linha[i] != '\n' && linha[i] != ' ') {
            frequencia[(unsigned char)linha[i]]++;
            if (frequencia[(unsigned char)linha[i]] > maxFreq) {
                maxFreq = frequencia[(unsigned char)linha[i]];
                caractereMaisFreq = linha[i];
            }
        }
    }

    return caractereMaisFreq;
}

int main() {
    FILE *arquivo;
    char nomeArquivo[50];
    char linha[MAX_LINHA];
    int numLinhas = 0;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    while (fgets(linha, MAX_LINHA, arquivo) != NULL) {
        int numLetras = 0, numDigitos = 0;
        numLinhas++;

        for (int i = 0; linha[i] != '\0'; i++) {
            if (isdigit(linha[i])) {
                numDigitos++;
            } else if (isalpha(linha[i])) {
                numLetras++;
            }
        }

        char maisFrequente = caractereMaisFrequente(linha);

        printf("Linha %d:\n", numLinhas);
        printf("Quantidade de dígitos: %d\n", numDigitos);
        printf("Quantidade de letras: %d\n", numLetras);
        printf("Caractere mais frequente: %c\n\n", maisFrequente);
    }

    printf("Número total de linhas no arquivo: %d\n", numLinhas);

    // Fechar o arquivo
    fclose(arquivo);

    return 0;
}
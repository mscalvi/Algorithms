/*

Arquivos_Trabalho3.c

Esse programa faz a tradução de um arquivo utilizando uma biblioteca de sinônimos, disponível em outro arquivo

Funcionalidades
-Diferenciação de letras maiúsculas e minúsculas
-Capacidade de até 100 pares de sinônimos, podendo ser alterado pelo MAX_DICT_SIZE

Fluxo do Programa
-Carrega o dicionário
-Carrega o arquivo para ser traduzido
-Confere as palavras que estão disponíveis no dicionário
-Gera o novo arquivo

----------------------

Marcelo Fernandes Scalvi

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 50     // Tamanho máximo de uma palavra
#define MAX_LINE_LEN 1000   // Tamanho máximo de uma linha
#define MAX_DICT_SIZE 100   // Número máximo de pares de palavras no dicionário


//Estrutura dos sinônimos do dicionário
typedef struct {
    char original[MAX_WORD_LEN];
    char substituta[MAX_WORD_LEN];
} Dicionario;

//Método para carregar o dicionário de um arquivo texto
int carregarDicionario(const char *arquivoDicionario, Dicionario dicionario[], int *tamanhoDicionario) {
    FILE *arquivo = fopen(arquivoDicionario, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo do dicionario, verifique o arquivo dicionario.txt.\n");
        return 0;
    }

    char linha[MAX_LINE_LEN];
    *tamanhoDicionario = 0;

    //Carrega os pares do dicionário enquanto houver linhas no arquivo e o limite não for atingido
    while (fgets(linha, MAX_LINE_LEN, arquivo) != NULL && *tamanhoDicionario < MAX_DICT_SIZE) {
        sscanf(linha, "%s %s", dicionario[*tamanhoDicionario].original, dicionario[*tamanhoDicionario].substituta);
        (*tamanhoDicionario)++;
    }

    if (*tamanhoDicionario == MAX_DICT_SIZE) {
        printf("Dicionario atingiu a capacidade maxima de %d palavras.\n", MAX_DICT_SIZE);
    }

    fclose(arquivo);
    return 1;
}

//Método para encontrar uma palavra no dicionário e retornar a palavra substituta
const char* buscarPalavraNoDicionario(Dicionario dicionario[], int tamanhoDicionario, const char *palavra) {
    for (int i = 0; i < tamanhoDicionario; i++) {
        if (strcmp(dicionario[i].original, palavra) == 0) {
            return dicionario[i].substituta;
        }
    }
    return NULL;
}

//Método para processar o arquivo de texto original e gerar o novo arquivo de texto
void processarTexto(const char *arquivoOriginal, const char *arquivoNovo, Dicionario dicionario[], int tamanhoDicionario) {
    FILE *arquivoEntrada = fopen(arquivoOriginal, "r");
    FILE *arquivoSaida = fopen(arquivoNovo, "w");

    if (arquivoEntrada == NULL || arquivoSaida == NULL) {
        printf("Erro ao abrir os arquivos de texto, verifique o arquivo texto_original.txt.\n");
        return;
    }

    char palavra[MAX_WORD_LEN];
    char ch;
    int i = 0;

    //Lê o arquivo original e processa todas as palavras, filtrando símbolos
    while ((ch = fgetc(arquivoEntrada)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '.' || ch == ',') {
            if (i > 0) {
                palavra[i] = '\0';  
                const char *substituta = buscarPalavraNoDicionario(dicionario, tamanhoDicionario, palavra);
                if (substituta) {
                    fprintf(arquivoSaida, "%s", substituta); 
                } else {
                    fprintf(arquivoSaida, "%s", palavra); 
                }
                i = 0;
            }
            fputc(ch, arquivoSaida);  
        } else {
            palavra[i++] = ch;  
        }
    }

    fclose(arquivoEntrada);
    fclose(arquivoSaida);
}

int main() {
    Dicionario dicionario[MAX_DICT_SIZE]; 
    int tamanhoDicionario;

    //Carregar o dicionário
    if (!carregarDicionario("dicionario.txt", dicionario, &tamanhoDicionario)) {
        printf("Erro ao carregar o dicionario, verifique o arquivo dicionario.txt.\n");
        return 1;
    }

    //Processar o texto original e gerar o novo texto
    processarTexto("texto_original.txt", "novo_texto.txt", dicionario, tamanhoDicionario);

    printf("Arquivo traduzido pronto!.\n");

    return 0;
}


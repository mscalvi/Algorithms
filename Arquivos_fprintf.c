#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

int n, j, k;
n = 10;
j = 0;
k = 0;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n], vetpar[n], vetimpar[n];

    printf("Digite os elementos do vetor:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }

    FILE *arquivoPares = fopen("pares.txt", "w");
    FILE *arquivoImpares = fopen("impares.txt", "w");

    if (arquivoPares == NULL || arquivoImpares == NULL) {
        printf("Erro ao abrir arquivos.\n");
        return 1;
    }

    for (int i = 0; i < n; i++){
        if (vetor[i] % 2 == 0 ) 
        {
            vetpar[k] = vetor[i];
            k++;
        } else 
        {
            vetimpar[j] = vetor[i];
            j++;
        }
    }

    for (int i = 0; i < j; i++){
        fprintf(arquivoPares, "%d\n", vetpar[i]);
    }

    for (int i = 0; i < k; i++){
        fprintf(arquivoImpares, "%d\n", vetimpar[i]);
    }

    fclose(arquivoPares);
    fclose(arquivoImpares);

    arquivoPares = fopen("pares.txt", "r");
    arquivoImpares = fopen("impares.txt", "r");

    if (arquivoPares == NULL || arquivoImpares == NULL) {
        printf("Erro ao abrir arquivos para leitura.\n");
        return 1;
    }

    printf("\nConteúdo do arquivo pares.txt:\n");
    int num;
    while (fscanf(arquivoPares, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    printf("\n");

    printf("\nConteúdo do arquivo impares.txt:\n");
    while (fscanf(arquivoImpares, "%d", &num) != EOF) {
        printf("%d ", num);
    }
    printf("\n");

    fclose(arquivoPares);
    fclose(arquivoImpares);

return 0;
}
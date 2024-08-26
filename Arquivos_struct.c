#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura que vai armazenar os dados da pessoa
struct Pessoa {
    char nome[100];
    int idade;
    char email[100];
};

int main() {
    struct Pessoa pessoa;

    // Solicitando os dados da pessoa
    printf("Digite o nome: ");
    fgets(pessoa.nome, sizeof(pessoa.nome), stdin);
    pessoa.nome[strcspn(pessoa.nome, "\n")] = '\0'; // Remover nova linha

    printf("Digite a idade: ");
    scanf("%d", &pessoa.idade);
    getchar(); // Limpar o buffer de entrada

    printf("Digite o e-mail: ");
    fgets(pessoa.email, sizeof(pessoa.email), stdin);
    pessoa.email[strcspn(pessoa.email, "\n")] = '\0'; // Remover nova linha

    // Abrindo o arquivo para escrita
    FILE *arquivo = fopen("dados_pessoa.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita!\n");
        return 1;
    }

    // Escrevendo os dados da pessoa no arquivo
    fprintf(arquivo, "Nome: %s\n", pessoa.nome);
    fprintf(arquivo, "Idade: %d\n", pessoa.idade);
    fprintf(arquivo, "E-mail: %s\n", pessoa.email);

    // Fechando o arquivo após a escrita
    fclose(arquivo);

    // Abrindo o arquivo para leitura
    arquivo = fopen("dados_pessoa.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return 1;
    }

    // Lendo e exibindo o conteúdo do arquivo
    printf("\nConteúdo do arquivo:\n");
    char linha[150];
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }

    // Fechando o arquivo após a leitura
    fclose(arquivo);

    return 0;
}

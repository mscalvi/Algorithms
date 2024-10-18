/*

Arquivos_Trabalho2.c

Esse programa faz o registro de cartas de MTG em um arquivo binário, dando opção de consulta e manipulação desses registros, podendo excluí-los logicamente ou fisicamente.

Funcionalidades
-Cadastrar Carta: Adiciona uma nova carta à coleção, permitindo que o usuário forneça dados como nome, custo de mana, tipo, subtipo e supertipo.
-Consultar Carta: Permite a busca de uma carta na coleção por ID ou nome.
-Desativar Carta: Remove uma carta da coleção, marcando-a como desativada.
-Excluir Carta: Exclui permanentemente uma carta da coleção.
-Ajuda Criptografada: Exibe e criptografa um arquivo de ajuda para o usuário.
-Menu Interativo: Interface de texto simples que facilita a navegação entre as opções.

Fluxo do Programa
-O programa começa verificando a existência do arquivo de ajuda (help.txt). Se não existir, cria e criptografa o arquivo.
-Abre ou cria o arquivo binário que armazena as cartas (colecao.dat).
-Exibe o menu principal, onde o usuário pode escolher entre cadastrar, consultar, desativar ou excluir cartas, ou ainda acessar a ajuda.
-No menu principal, o usuário pode pressionar F1 para visualizar a ajuda criptografada.

----------------------

Marcelo Fernandes Scalvi

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAX_NOME_LEN 50
#define MAX_TIPO_LEN 20
#define MAX_SUBTIPO_LEN 20
#define MAX_SUPERTIPO_LEN 20
#define MAX_CMC_LEN 10

typedef struct {
    int id;               
    char nome[MAX_NOME_LEN];
    char cmc[MAX_CMC_LEN];
    char tipo[MAX_TIPO_LEN];
    char subtipo[MAX_SUBTIPO_LEN];
    char supertipo[MAX_SUPERTIPO_LEN];
    int colecao;            
} CartaModel;

void cadastrarCarta(FILE *arquivo) {
    CartaModel carta;
    int ultimoId = 0;
    
    rewind(arquivo); 
    while (fread(&carta, sizeof(CartaModel), 1, arquivo)) {
        if (carta.colecao) { 
            ultimoId = carta.id; 
        }
    }

    carta.id = ultimoId + 1;

    printf("\nNova Carta para a Colecao!\n");
    
    printf("Nome: ");
    scanf(" %[^\n]%*c", carta.nome);
    printf("Custo de Mana: ");
    scanf(" %[^\n]%*c", carta.cmc);
    printf("Tipo: ");
    scanf(" %[^\n]%*c", carta.tipo);
    printf("Subtipo: ");
    scanf(" %[^\n]%*c", carta.subtipo);
    printf("Supertipo: ");
    scanf(" %[^\n]%*c", carta.supertipo);

    carta.colecao = 1;

    fseek(arquivo, 0, SEEK_END); 
    fwrite(&carta, sizeof(CartaModel), 1, arquivo);
    printf("Carta adicionada a colecao, ID: %d!\n", carta.id);
}

void consultarCarta(FILE *arquivo) {
    CartaModel carta;
    char opcao;
    int id, cont;
    char nome[MAX_NOME_LEN];
    
    printf("\n1- Procurar por ID\n2- Procurar por Nome\n");
    opcao = getch();
    
    rewind(arquivo); 
    cont = 1;

    while (cont == 1) {
    if (opcao == '1') {
        printf("Digite o ID: ");
        scanf("%d", &id);
        while (fread(&carta, sizeof(CartaModel), 1, arquivo)) {
            if (carta.colecao && carta.id == id) {
                printf("\nCarta encontrada: %s, um %s, de custo %s\n", carta.nome, carta.tipo, carta.cmc);
                printf ("Aperte 0 para voltar ao menu.");
                scanf("%d", &cont);
                return;
            }
        }
    } else if (opcao == '2') {
        printf("Digite o Nome: ");
        scanf(" %[^\n]%*c", nome);
        while (fread(&carta, sizeof(CartaModel), 1, arquivo)) {
            if (carta.colecao && strcmp(carta.nome, nome) == 0) {
                printf("\nCarta encontrada: %s, um %s, de custo %s\n", carta.nome, carta.tipo, carta.cmc);
                printf ("Aperte 0 para voltar ao menu.");
                scanf("%d", &cont);
                return;
            }
        }
    }
    }
    
    printf("Carta nao esta na colecao!\n");
}

void desligarCarta(FILE *arquivo) {
    int id;
    CartaModel carta;
    
    printf("Digite o ID da carta a ser removida da colecao: ");
    scanf("%d", &id);
    
    rewind(arquivo);
    while (fread(&carta, sizeof(CartaModel), 1, arquivo)) {
        if (carta.id == id && carta.colecao == 1) {
            carta.colecao = 0;
            fseek(arquivo, sizeof(CartaModel), SEEK_CUR);
            fwrite(&carta, sizeof(CartaModel), 1, arquivo);
            printf("Carta desabilitada na colecao.\n");
            return;
        }
    }
    printf("Carta nao encontrada.\n");
}

void excluirCarta(FILE *arquivo) {
    FILE *temp = fopen("temp.dat", "wb");
    CartaModel carta;
    int id;
    
    printf("Digite o ID da carta a ser excluída permanentemente da colecao: ");
    scanf("%d", &id);

    rewind(arquivo);
    while (fread(&carta, sizeof(CartaModel), 1, arquivo)) {
        if (carta.id != id || carta.colecao == 0) {
            fwrite(&carta, sizeof(CartaModel), 1, temp);
        }
    }
    
    fclose(arquivo);
    fclose(temp);
    remove("colecao.dat");
    rename("temp.dat", "colecao.dat");
    printf("Carta excluida da colecao.\n");
}

void cripAjuda(const char *input, const char *output) {
    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");
    char ch;

    while ((ch = fgetc(in)) != EOF) {
        fputc(ch + 3, out); 
    }
    fclose(in);
    fclose(out);
    remove(input); 
}

void uncripAjuda(const char *help) {
    FILE *in = fopen(help, "r");
    char ch;

    while ((ch = fgetc(in)) != EOF) {
        putchar(ch - 3);
    }
    fclose(in);
}

void criarAjuda(const char *output) {
    FILE *out = fopen(output, "w");
    if (out == NULL) {
        printf("Erro ao criar arquivo de ajuda.\n");
        return;
    }

    fprintf(out, "Você ja esta alem da ajuda\n"); 
    fclose(out);
}

int arquivoExiste(const char *arquivo) {
    FILE *file = fopen(arquivo, "r");
    if (file) {
        fclose(file);
        return 1;
    }
    return 0;
}

void mostrarAjuda() {
    if (arquivoExiste("help.txt")) {
        printf("\nEssa e a ajuda que posso oferecer:\n");
        uncripAjuda("help.txt");
    } else {
        printf("\nArquivo de ajuda nao encontrado!\n");
    }
}

void inicializarAjuda() {
    if (arquivoExiste("help.txt")) {
        printf("Arquivo de ajuda existente. Criptografando...\n");
        cripAjuda("help.txt", "help.txt");
        printf("Arquivo de ajuda criptografado com sucesso.\n");
    } else {
        printf("Arquivo de ajuda nao encontrado. Criando arquivo...\n");
        criarAjuda("help.txt");
        cripAjuda("help.txt", "help.txt");
        printf("Arquivo de ajuda criado e criptografado com sucesso.\n");
    }
}

void menu(FILE *arquivo) {
    int tecla;

    do {
        system("cls");

        printf("\n---- MENU ----\n");
        printf("1. Cadastrar Carta\n");
        printf("2. Consultar Carta\n");
        printf("3. Desativar Carta\n");
        printf("4. Excluir Carta\n");
        printf("5. Sair\n");
        printf("F1. Ajuda\n");
        tecla = getch();

        if (tecla == 0 || tecla == 224) {  
            tecla = getch();  
            if (tecla == 59) { 
                mostrarAjuda();
            }
        } else {
            switch (tecla) {
                case '1':
                    cadastrarCarta(arquivo);
                    break;
                case '2':
                    consultarCarta(arquivo);
                    break;
                case '3':
                    desligarCarta(arquivo);
                    break;
                case '4':
                    excluirCarta(arquivo);
                    break;
                case '5':
                    printf("Desconectando da Colecao.\n");
                    break;
                default:
                    printf("Opcao invalida!\n");
            }
        }
    } while (tecla != '5');
}

int main() {

    inicializarAjuda();

    FILE *arquivo = fopen("colecao.dat", "rb+");

    if (!arquivo) {
        arquivo = fopen("colecao.dat", "wb+");
        if (!arquivo) {
            printf("Erro ao criar colecao!\n");
            return 1;
        }
    }

    menu(arquivo);

    fclose(arquivo);
    return 0;
}
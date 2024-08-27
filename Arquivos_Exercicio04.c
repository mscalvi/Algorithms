#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct aluno {
    int id;
    char nome[50];
    float nota1;
    float nota2;
    float media;
};

int main () {

    FILE *arquivo;
    int n;

    if ((arquivo = fopen ("alunos.txt", "r")) == NULL){
        printf ("\n Arquivo não pode ser aberto.");
        exit(1);
    }

    fscanf(arquivo, "%d\n", &n);

    struct aluno alunos[100];

    for (int i = 0; i < n; i++) {
        fgets(alunos[i].nome, 50, arquivo);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
        fscanf(arquivo, "%f %f\n", &alunos[i].nota1, &alunos[i].nota2);
        alunos[i].media = (alunos[i].nota1 + alunos[i].nota2) / 2;
    }

    fclose (arquivo);

    printf("Alunos com media menor que 5.0:\n");
 
    for (int i = 0; i < n; i++) {
        if (alunos[i].media < 5.0) {
            printf("%s\n", alunos[i].nome);
        }
    }

    return 0;
}
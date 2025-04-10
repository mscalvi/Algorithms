#include <stdio.h>

#define MAX_ALUNOS 1000

// Estrutura para armazenar a nota e a posição original do aluno
typedef struct {
    int nota;
    int posicao_original;
} Aluno;

// Função de ordenação usando Bubble Sort (ordem decrescente)
void bubbleSort(Aluno arr[], int n) {
    int i, j;
    Aluno temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j].nota < arr[j + 1].nota) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, M, i, alunosNoMesmoLugar;
    Aluno fila[MAX_ALUNOS], filaOrdenada[MAX_ALUNOS];

    scanf("%d", &N); // Número de casos de teste

    while (N--) {
        scanf("%d", &M); // Número de alunos

        // Lendo as notas e armazenando a posição original
        for (i = 0; i < M; i++) {
            scanf("%d", &fila[i].nota);
            fila[i].posicao_original = i; // Guarda a posição original
            filaOrdenada[i] = fila[i]; // Cópia para ordenação
        }

        // Ordenando a filaOrdenada em ordem decrescente de nota usando Bubble Sort
        bubbleSort(filaOrdenada, M);

        // Contando quantos alunos mantiveram a posição original
        alunosNoMesmoLugar = 0;
        for (i = 0; i < M; i++) {
            if (fila[i].nota == filaOrdenada[i].nota) {
                alunosNoMesmoLugar++;
            }
        }

        printf("%d\n", alunosNoMesmoLugar);
    }

    return 0;
}

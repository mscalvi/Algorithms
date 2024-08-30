#include <stdio.h>
#include <math.h>

int main (){

    int n, reprovados, aprovados;
    float x, soma, media;

    soma = 0;
    media = 0;
    reprovados = 0;
    aprovados = 0;

    printf ("Quantos alunos serao inseridos?\n");
    scanf ("%d", &n);

    float alunos[n-1];

    for (int i = 0; i < n; i++)
    {  
        printf ("Digite a nota do aluno %d\n", i+1);
        scanf ("%f", &x);
        alunos[i] = x;
        if (x >= 5){
            aprovados++;
        } else {
            reprovados++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        soma = soma + alunos[i];
    }

    media = soma / n;

    printf ("A media da sala foi %.2f\n", media);

    for (int i = 0; i < n; i++)
    {
        printf("A nota do aluno %d foi: %.2f\n", i+1, alunos[i]);
    }

    if (reprovados > 0){
        printf ("%d alunos tiraram menos de 5, e %d mais do que 5.", reprovados, aprovados);
    } else {
        printf ("Nenhum aluno tirou menos de 5, %d alunos foram aprovados.", n);
    }

    return 0;
}


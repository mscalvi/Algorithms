/* DESAFIO 1: Escreva um algoritmo para um jogo de adivinhacao. Seu pro-
grama deve conter uma frase de bem vindo (e o nome do seu jogo) em seguida,
a seguinte mensagem: Tente adivinhar o numero que estou pensando
entre 1 e 100. A cada iteracao, o programa dever ́apresentar a mensagem
Seu palpite esta muito baixo caso o n ́umero seja menor que o correto e,
Seu palpite esta muito alto, caso o valor digitado seja maior que o va-
lor correto. Quando o usu ́ario acertar o valor, o programa dever ́a retornar a
mensagem parab ́ens, vocˆe acertou o n ́umero em X tentativas
Obs: para que o computador gere o n ́umero aleat ́orio, vocˆe poder ́a fazer dessa
forma:
srand(time(NULL)); “Obriga o computador gerar um n ́umero aleat ́orio cada
1 vez que for executado”
numeroSecreto = rand() % 100 + 1; “Gera o valor aleat ́orio” */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

int main ()
{
    int num, escolhido, tentativas;
    int jogar;

    do {

    escolhido = 0;
    tentativas = 0;
    jogar = 0;
    
    srand(time(NULL));
    escolhido = rand() % 100 + 1;

    printf ("Bem-vindo ao TigrinhoSupremo, acerte o numero magico e ganhe um parabens.\n");

    do{
        printf ("\nChute um número.\n");
        scanf ("%d", &num);
        tentativas++;
        if (num < escolhido){
            printf ("Seu palpite esta muito baixo.\n");
        } else if (num > escolhido) {
            printf ("Seu palpite esta muito alto.\n");
        } else {
            printf ("Parabens! Voce acertou em %d tentativas.\n", tentativas);
        }
    } while (num != escolhido);

    printf ("\nDigite 1 para jogar novamente.\n");
    scanf ("%d", &jogar);

    } while (jogar == 1);
}

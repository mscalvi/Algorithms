/* Desenvolva um algoritmo que simule 3 op ̧c ̃oes b ́asicas de um
caixa eletrˆonico (Consulta de saldo, Deposito e Saque). O saldo deve iniciar
com o valor de R$ 1000,00 e tamb ́em deve conter a op ̧c ̃ao de SAIR quando o
usu ́ario n ̃ao quiser mais realizar transa ̧c ̃oes no caixa eletrˆonico. A cada saque,
a atualiza ̧c ̃ao do saldo deve ser apresentada na tela. */

#include <stdio.h>
#include <math.h>

int main ()
{
    float saldo, saque, deposito;
    int opcao;

    saldo = 1000.00;

    saque = 0;
    deposito = 0;
    opcao = 0;
    
    printf ("Bem-vindo! O que deseja fazer hoje?\n");

    while (opcao != 4){
        if (opcao != 0){
            printf ("\n\nNova operacao?\n");
        }
        printf ("1- Consultar Saldo\n");
        printf ("2- Sacar\n");
        printf ("3- Depositar\n");
        printf ("4- Sair\n");
        scanf ("%d", &opcao);

        switch (opcao){
            case 1:
                printf ("\nSaldo atual: %.2f.\n", saldo);
                break;
            case 2:
                printf ("Digite o valor do saque\n");
                scanf ("%f", &saque);
                if (saque > saldo){
                    printf ("\nSaldo insuficiente, operacao negada.\n");
                } else {
                    saldo = saldo - saque;
                    printf ("\nSaque realizado.\nNovo saldo: %.2f.\n", saldo);
                }
                break;
            case 3:
                printf ("Digite o valor do deposito\n");
                scanf ("%f", &deposito);
                saldo = saldo + deposito;
                printf ("\nDeposito realizado.\nNovo saldo: %.2f.\n", saldo);
                break;
            case 4:
                printf ("\nTenha um bom dia!\n");
                break;
            default:
                printf ("\nOpcao Invalida.\n");
                break;
        }
    }
}
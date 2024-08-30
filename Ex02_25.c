#include <stdio.h>
#include <math.h>

int main ()
{
    float Deposito, Taxa, Tempo;
    float Mensal, Final;
    int Juros;

    printf ("Digite o valor para depósito.\n");
    scanf ("%f", &Deposito);
    printf ("Digite a taxa de juros ao mês.\n");
    scanf ("%f", &Taxa);
    printf ("Digite a quantidade de meses total do investimento.\n");
    scanf ("%f", &Tempo);
    printf ("Digite 1 para juros simples e 2 para juros compostos.\n");
    scanf ("%d", &Juros);

    if (Juros == 1){
        Mensal = (Taxa / 100) * Deposito;
        Final = Deposito + (Mensal * Tempo);
        printf ("\nO valor final do investimento será de R$ %.2f", Final);
    } else if (Juros == 2) {
        Final = Deposito;
        for (int i = 0; i <= Tempo; i++)
        {
            Final = Final + (Final * (Taxa / 100));
        }
        printf ("\nO valor final do investimento será de R$ %.2f", Final);
    } else {
        printf ("\nValor não disponíveis.");
    }
}
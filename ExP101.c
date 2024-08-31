#include <stdio.h>
 
int main() {
 
    int Codigo;
    float Aumento, Salario, NovoSalario;

    printf ("Digite o codigo do cargo do funcionario.\n");
    scanf ("%d", &Codigo);
    printf ("Digite o salario do funcionario.\n");
    scanf ("%f", &Salario);

    switch (Codigo){
        case 10:
            Aumento = 0.1;
            NovoSalario = Aumento * Salario + Salario;
            break;
        case 25:
            Aumento = 0.2;
            NovoSalario = Aumento * Salario + Salario;
            break;
        case 35:
            Aumento = 0.3;
            NovoSalario = Aumento * Salario + Salario;
            break;
        default:
            Aumento = 0.25;
            NovoSalario = Aumento * Salario + Salario;
            break;
    }

    printf ("Salario antigo: %.2f\n", Salario);
    printf ("Salario novo: %.2f\n", NovoSalario);
    printf ("Aumento: %.0f%%\n", Aumento * 100);

}
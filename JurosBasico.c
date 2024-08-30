#include <stdio.h>
#include <math.h>

int main (){
    float PIni, PFin, Impostos, Lucro;
    
    printf ("Qual o preço de custo do produto?\n");
    scanf ("%f", &PIni);
    Impostos = 0.45 * PIni;
    Lucro = 0.5 * PIni;
    PFin = PIni + Impostos + Lucro;
    printf ("\nO Preço final do produto deve ser: R$ %.2f\n", PFin);
}
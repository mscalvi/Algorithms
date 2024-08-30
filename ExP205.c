#include <stdio.h>
#include <string.h>
#include <ctype.h>

int Fatorial(int num) {
    int Fatorial = 1;

    for (int i = num; i > 0; i--){
        Fatorial = Fatorial * i;
    }

    return (Fatorial);
}

int main() {
    int Binomio = 0;
    int numero1 = 0;

    while (numero1 <= 0){
        printf ("Entre o primeiro numero do coeficiente binomial.\n");
        scanf ("%d", &numero1);
    }

    int numero2 = numero1 + 1;

    while (numero2 >= numero1){
        printf ("Entre o segundo numero do coeficiente binomial.\n");
        scanf ("%d", &numero2);
    }

    printf ("O fatorial do numero %d e %d\n", numero1, Fatorial(numero1));
    printf ("O fatorial do numero %d e %d\n", numero2, Fatorial(numero2));

    Binomio = Fatorial(numero1)/(Fatorial(numero2)*Fatorial(numero1 - numero2));

    printf ("O coeficiente binominal de %d e %d e %d", numero1, numero2, Binomio);

    return 0;
}
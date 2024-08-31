#include <stdio.h>
#include <math.h>

int a, b, soma;

int Soma (int,int){
    soma = a + b;
    return (soma);
}

int main (){
    scanf ("%d %d", &a, &b);
    printf("Resultado: %d", Soma(a,b));
    return 0;
}


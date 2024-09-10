#include <stdio.h>
#include <math.h>

int main (){
    int n, testes;
    unsigned long long int fib[60], aux1, aux2;

    aux1 = 0;
    aux2 = 1;
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= 60; i++)
    {
        fib[i] = aux1 + aux2;
        aux1 = aux2;
        aux2 = fib[i];
        printf("Fib(%d) = %llu\n", i, fib[i]);
    } //Cria um vetor para Fibonacci

    scanf ("%d", &testes);

    for (int i = 0; i < testes; i++)
    {
        scanf ("%d", &n);
        printf("Fib(%d) = %llu\n", n, fib[n]);
    } //Escreve os valores correspondentes

    return 0;
}

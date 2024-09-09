#include <stdio.h>
#include <math.h>

int soma(int n) {
    if (n <= 0) {
        return 0;
    } else {
        return pow(n, 3) + soma(n - 1); 
    }
}

int main() {
    int numero;
    
    printf("Digite um número: ");
    scanf("%d", &numero);

    printf("a soma dos cubos dos números positivos menores a %d é %d\n", numero, soma(numero));
    
    return 0;
}

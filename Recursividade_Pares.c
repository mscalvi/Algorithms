#include <stdio.h>
#include <math.h>

int pares(int n, int atual) {
    if (n == 0) {
        return;
    } else {
        printf("%d ", atual);  
        pares(n - 1, atual + 2); 
    }
}

int main() {
    int numero;
    
    printf("Digite um numero: ");
    scanf("%d", &numero);

    pares(numero, 0);
    
    return 0;
}

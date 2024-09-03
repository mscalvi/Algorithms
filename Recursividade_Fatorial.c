#include <stdio.h>

int fat(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * fat(n - 1);
    }
}

int main() {
    int numero;
    
    printf("Digite um número: ");
    scanf("%d", &numero);

    printf("O fatorial de %d é %d\n", numero, fat(numero));
    
    return 0;
}

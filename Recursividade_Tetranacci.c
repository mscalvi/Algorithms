#include <stdio.h>

int nacci(int n) {
    if (n <= 2) {
        return 0;
    } else if (n == 3) {
        return 1;
    } else {
        return nacci(n - 1) + nacci(n - 2) + nacci(n - 3) + nacci(n - 4);
    }
}

int main() {
    int n;

    printf("Digite um numero: ");
    scanf("%d", &n);

    printf("O termo %d da sequencia de Tetranacci e: %d\n", n, nacci(n));

    return 0;
}
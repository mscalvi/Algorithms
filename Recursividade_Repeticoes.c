#include <stdio.h>

int contar(int N, int K) {
    if (N == 0) {
        return 0;
    }

    if (N % 10 == K) {
        return 1 + contar(N / 10, K);
    } else {
        return contar(N / 10, K);
    }
}

int main() {
    int N, K;

    printf("Digite um numero natural grande: ");
    scanf("%d", &N);
    printf("Qual numero quer saber as repeticoes? ");
    scanf("%d", &K);

    printf("O digito %d ocorre %d vezes em %d\n", K, contar(N, K), N);

    return 0;
}
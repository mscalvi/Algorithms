#include <stdio.h>

int inverterNumero(int num) {

    int invertido = 0;
    int ultDig;

    while (num > 0) {
        ultDig = num % 10;
        invertido = invertido * 10 + ultDig;
        num = num / 10;
    }
    return invertido;
}

int main() {
    printf("Numeros palíndromos entre 1 e 9999:\n");
    for (int i = 1; i <= 101; i++) {
        if (i == inverterNumero(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
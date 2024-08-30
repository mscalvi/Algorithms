#include <stdio.h>

int main() {

    int x, y, soma, sinal;

    scanf("%d %d", &x, &y);
    
    soma = 0;
    sinal = 0;

    if (x <= y) {
        if (x % 2 == 0) {
            x++;
            for (int i = x; i < y; i += 2) 
            {
                soma = soma + i;
            }
        } else {
            for (int i = x; i < y; i += 2) 
            {
                if (i > x){
                    soma = soma + i;
                }
            }
        }
    } else {
        if (y % 2 == 0) {
            y++;
            for (int i = y; i < x; i += 2) 
            {
                soma = soma + i;
            }
        } else {
            for (int i = y; i < x; i += 2) 
            {
                if (i > y){
                    soma = soma + i;
                }
            }
        }
    }
    
    printf("%d\n", soma);

    return 0;
}
#include <stdio.h>
#include <string.h>

void troca(char* x, char* y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}


void anagramas(char* palavra, int comeco, int final) {
    if (final == comeco) {
        printf("%s\n", palavra);
    } else {
        for (int i = comeco; i <= final; i++) {
            troca(&palavra[comeco], &palavra[i]);
            anagramas(palavra, comeco + 1, final);
            troca(&palavra[comeco], &palavra[i]);
        }
    }
}

int main() {
    char palavra[30];
    
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    int n = strlen(palavra);
    anagramas(palavra, 0, n - 1);
    
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <string.h>

int main (){

    char palavra[100];
    int tamanho, ini, fim, falha;

    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    tamanho = strlen(palavra);
    ini = 0;
    fim = tamanho - 1;

    while ( fim > ini)
    {
        if (palavra[ini] != palavra[fim])
        {
            falha = 1;
            break;
        }
        ini++;
        fim--;
        falha = 0;
    }

    if (falha == 0) {
        printf("A palavra '%s' e um palindromo.\n", palavra);
    } else {
        printf("A palavra '%s' nao e um palindromo.\n", palavra);
    }

    return 0;
}


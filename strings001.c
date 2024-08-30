#include <stdio.h>
#include <string.h>

int main () {
    
    int cont, vog;
    char str[100];

    cont = 1;
    vog = 0;

    do {
        printf ("Digite uma frase.\n");
        gets (str);
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] == "a" || str[i] == "e" || str[i] == "i" || str[i] == "o" || str[i] == "u"){
                vog++;
            }
        }
        printf ("Sua frase teve %d vogais.\n", vog);
        printf ("Digite 1 para continuar, 0 para sair.\n");
        scanf ("%d", &cont);
    } while (cont == 1);
}

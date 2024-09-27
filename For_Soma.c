#include <stdio.h>

int main (){

    int total = 0;

    for (int i = 0; i <= 50; i++){
        if (i % 2 != 0){
            if (i % 3 == 0){
                total += i;
            } else { printf ("Número %d inválido.\n", i);}
        } else { printf ("Número %d inválido.\n", i);}
    }

    printf ("\nResposta final: %d", total);
}
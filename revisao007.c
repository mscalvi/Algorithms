#include <stdio.h>
#include <math.h>
#include <string.h>

int main (){
    char string[100];


    printf ("Digite uma frase.\n");
    gets (string);

    for (int i = 0; i < strlen(string); i++){
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u'){
            string[i] = '*';
        }
    }

    printf ("Sua nova frase: %s\n", string);
    
}
#include <stdio.h>
#include <string.h>

int main () {
    
    int cont, vog, cons, i;
    char str[100];

    cont = 1;

    while (cont == 1) {
          vog = 0;
          cons = 0;
          printf ("Digite uma frase.\n");
          gets (str);
          for (i = 0; i < strlen(str); i++) {
              if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
                 vog++;
              } else if (str[i] >= 'b' && str[i] <= 'z'){
                 cons++;       
              }
          }
          printf ("A frase digitada foi: %s\n", str);
          printf ("O numero de vogais e: %d\n", vog);
          printf ("O numero de consoantes e: %d\n", cons);
          printf ("Digite 1 para continuar, 0 para sair.\n");
          scanf ("%d", &cont);
    }
}

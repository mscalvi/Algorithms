#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char Mode;
    double Matriz[15][15];
    int Cont, n;
    double Soma, Media;

    Cont = 1;

    while (Cont == 1) {

        Soma = 0;
        Media = 0;
        Cont = 0;

        printf ("Qual operação deseja realizar? Digite M para Média ou S para Soma.");
        scanf ("%c", &Mode);
        Mode = toupper(Mode);

        printf ("Entre com a matriz.");
        
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                scanf ("%d", &n);
                Matriz[i][j] = n;
            }
        }

        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                if (i < j && i + j >= 15){
                    Soma = Soma + Matriz[i][j];
                    Cont = Cont + 1;
                }
            }
        }
        
        Media = Soma / Cont;

        if (Mode == 'S'){
            printf ("A Soma dos elementos é %lf", &Soma);
        } else if (Mode == 'M'){
            printf ("A Média dos elementos é %lf", &Media);
        }

        printf ("Digite 1 para continuar, 0 para sair.");
        scanf ("%d", &Cont);
    }

    return 0;
}
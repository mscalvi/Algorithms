#include <stdio.h>
 
int main() {
 
    int Figura, Linhas, Atual, Subindo;

    printf ("Quantas linhas deseja?.\n");
    scanf ("%d", &Linhas);
    printf ("Qual figura deseja? 1- Triangulo 2- Losango.\n");
    scanf ("%d", &Figura);

    switch (Figura){
        case 1:
            Atual = Linhas;
            for (int i = 0; i < Linhas; i++){
                for (int j = Atual; j > 0; j--){
                    printf ("  ");
                }
                printf ("%%");
                if (Atual < Linhas){
                    for (int k = Atual; k < Linhas; k++){
                        printf ("%%%%");
                    }
                }
                Atual--;
                printf ("\n");
            }
            break;
        case 2:
            Atual = Linhas;
            Subindo = 1;
            if (Subindo == 1){
                for (int i = 0; i < Linhas; i++){
                    for (int j = Atual; j > 0; j--){
                        printf ("  ");
                    }
                    printf ("%%");
                    if (Atual < Linhas){
                        for (int k = Atual; k < Linhas; k++){
                            printf ("%%%%%%%%");
                        }
                    }
                    Atual--;
                    printf ("\n");
                }
                Subindo = 0;
            }
            if (Subindo == 0){
                for (int i = Linhas; i >= 0; i--){
                    for (int j = 0; j < Atual; j++){
                        printf ("  ");
                    }
                    printf ("%%");
                    if (Atual < Linhas){
                        for (int k = Atual; k < Linhas; k++){
                            printf ("%%%%%%%%");
                        }
                    }
                    Atual++;
                    printf ("\n");
                }
            }
            break;
        default:
            printf ("Figura nao conhecida.");
            break;
    }

}
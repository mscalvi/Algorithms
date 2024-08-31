/* Escreva um programa que solicite ao usu ́ario que insira uma senha. O pro-
grama deve continuar solicitando a senha at ́e que o usu ́ario insira a senha
correta. Use um loop do-while para garantir que pelo menos uma tentativa
de senha seja feita. */

#include <stdio.h>
#include <math.h>

int main ()
{
    char senha[6], esperada[6];
    int correto;

    printf ("Cadastre sua senha de cinco caracteres.\n");
    scanf ("%5s", esperada);
    printf ("Senha cadastrada.\n\n");

    do {
        correto = 0;

        printf ("Digite sua senha.\n");

        scanf ("%5s", senha);

        for (int i = 0; i < 5; i++){
            if (senha[i] == esperada[i]){
                correto++;
            } else {
                printf ("Falha no caracter %d\n", i+1);
                break;
            }
        }

        if (correto != 5){
            printf ("Senha invalida.\n\n\n");
        } else {
            printf ("Seja bem-vindo.\n");
        }
    } while (correto != 5);
}

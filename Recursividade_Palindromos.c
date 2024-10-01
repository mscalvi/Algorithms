#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função recursiva para verificar se uma palavra é um palíndromo
int verificaPalindromo(char palavra[], int inicio, int fim) {
    // Caso base: se a palavra tiver 0 ou 1 caractere, é um palíndromo
    if (inicio >= fim) {
        return 1;
    }
    
    // Ignorando letras maiúsculas e minúsculas
    if (tolower(palavra[inicio]) != tolower(palavra[fim])) {
        return 0; // Não é um palíndromo
    }
    
    // Chamando recursivamente a função para o próximo par de caracteres
    return verificaPalindromo(palavra, inicio + 1, fim - 1);
}

int main() {
    char palavra[100];
    
    // Lendo uma palavra do usuário
    printf("Digite uma palavra: ");
    scanf("%s", palavra);
    
    int tamanho = strlen(palavra);
    
    // Verificando se a palavra é um palíndromo
    if (verificaPalindromo(palavra, 0, tamanho - 1)) {
        printf("%s e um palindromo.\n", palavra);
    } else {
        printf("%s não e um palindromo.\n", palavra);
    }
    
    return 0;
}
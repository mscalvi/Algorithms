//Marcelo Fernandes Scalvi, feito no Windows.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Métodos para Conferência
int confereBin (char numero[]){
    for (int i = 0; i < strlen(numero); i++) {
        if (numero[i] == '\n') continue;
        if (numero[i] < '0' || numero[i] > '1') {
            return 1;
        }
    }
    return 0; 
}

int confereOct (char numero[]){
    for (int i = 0; i < strlen(numero); i++) {
        if (numero[i] == '\n') continue;
        if (numero[i] < '0' || numero[i] > '7') {
            return 1;
        }
    }
    return 0; 
}

int confereDec (char numero[]){
    for (int i = 0; i < strlen(numero); i++) {
        if (numero[i] == '\n') continue;
        if (numero[i] < '0' || numero[i] > '9') {
            return 1;
        }
    }
    return 0; 
}

int confereHex (char numero[]){
    for (int i = 0; i < strlen(numero); i++) {
        if (numero[i] == '\n') continue;
        numero[i] = toupper(numero[i]);
    }
    for (int i = 0; i < strlen(numero); i++) {
        if (numero[i] == '\n') continue;
        if (!((numero[i] >= '0' && numero[i] <= '9') || (numero[i] >= 'A' && numero[i] <= 'F'))) {
            return 1;
        }
    }
    return 0; 
}

//Tabela dos Binários
void TabelaBinario(char numChar, char *binStr) {
    switch (numChar) {
        case '0': strcpy(binStr, "0000"); break;
        case '1': strcpy(binStr, "0001"); break;
        case '2': strcpy(binStr, "0010"); break;
        case '3': strcpy(binStr, "0011"); break;
        case '4': strcpy(binStr, "0100"); break;
        case '5': strcpy(binStr, "0101"); break;
        case '6': strcpy(binStr, "0110"); break;
        case '7': strcpy(binStr, "0111"); break;
        case '8': strcpy(binStr, "1000"); break;
        case '9': strcpy(binStr, "1001"); break;
        case 'A': strcpy(binStr, "1010"); break;
        case 'B': strcpy(binStr, "1011"); break;
        case 'C': strcpy(binStr, "1100"); break;
        case 'D': strcpy(binStr, "1101"); break;
        case 'E': strcpy(binStr, "1110"); break;
        case 'F': strcpy(binStr, "1111"); break;
        default: strcpy(binStr, "0000"); break;
    }
}

//Métodos para 1a Conversão
//hexa pra bi
char* ConverterHxB(const char* hexStr) {
    static char binStr[1024];
    char tempBin[5];
    binStr[0] = '\0'; 

    for (int i = 0; i < strlen(hexStr); i++) {
        TabelaBinario(hexStr[i], tempBin);
        strcat(binStr, tempBin); 
    }

    return binStr;
}

//deci pra bi
char* ConverterDxB(const char* decStr) {
    static char binStr[1024];
    char tempBin[5];
    binStr[0] = '\0'; 

    for (int i = 0; i < strlen(decStr); i++) {
        TabelaBinario(decStr[i], tempBin);
        strcat(binStr, tempBin); 
    }

    return binStr;
}

//octa pra bi
char* ConverterOxB(const char* octStr) {
    static char binStr[1024];
    char tempBin[5];
    binStr[0] = '\0'; 

    for (int i = 0; i < strlen(octStr); i++) {
        TabelaBinario(octStr[i], tempBin);
        //Dropar o primeiro 0
        strcat(binStr, tempBin); 
    }

    return binStr;
}

//Métodos para 2a Conversão
//bi pra hexa
//bi pra deci
//bi pra octa

int main () {

    int i = 1;
    int InInvalida = 0;
    int baseI, baseF;
    char baseEntrada[4];
    char baseSaida[4];
    char numeroInicial[100];
    char numeroBinario[500];
    char numeroFinal[500];

    do {
        //Menu
        //Base de Entrada
        do {
            InInvalida = 0;

            printf ("Em qual base está seu número?\n1-Binário, 2-Octal, 3-Decimal, 4- Hexadecimal\n");
            scanf ("%d", &baseI);
            while ((getchar()) != '\n');

            if (baseI == 1){
                strcpy(baseEntrada, "Bin");
            }   else if (baseI == 2){
                strcpy(baseEntrada, "Oct");
            } else if (baseI ==3){
                strcpy(baseEntrada, "Dec");
            } else if (baseI == 4){
                strcpy(baseEntrada, "Hex");
            }

            if (baseI < 1 || baseI > 4){
                InInvalida = 1;
                printf("Base de entrada inválida, digite outra.\n");
            }   
        } while (InInvalida != 0);

        //Base de Saída    
        do {
            InInvalida = 0;
                
            printf ("Para qual base quer convertê-lo?\n1-Binário, 2-Octal, 3-Decimal, 4- Hexadecimal\n");
            scanf ("%d", &baseF);
            while ((getchar()) != '\n');

            if (baseF == 1){
                strcpy(baseSaida, "Bin");
            }   else if (baseF == 2){
                strcpy(baseSaida, "Oct");
            } else if (baseF ==3){
                strcpy(baseSaida, "Dec");
            } else if (baseF == 4){
                strcpy(baseSaida, "Hex");
            }

            if (baseF < 1 || baseF > 4){
                InInvalida = 1;
                printf("Base de saída inválida, digite outra.\n");
            }   
        } while (InInvalida != 0);

        //Número para Conversão
        do {
            InInvalida = 0;

            printf ("Entre com o número.\n");
            fgets (numeroInicial, sizeof(numeroInicial), stdin);

            if (baseI == 1){
                InInvalida = confereBin(numeroInicial);
            }   else if (baseI == 2){
                InInvalida = confereOct(numeroInicial);
            } else if (baseI ==3){
                InInvalida = confereDec(numeroInicial);
            } else if (baseI == 4){
                InInvalida = confereHex(numeroInicial);
            }

            if (InInvalida == 1){
                printf("Número inválido para a base de entrada inserida (%s), digite outro número.\n", baseEntrada);
            }

        } while (InInvalida != 0);
            
        //Primeira Conversão
        if (baseI != 1) {
            switch (baseI)
            {
            case 2:
                strcpy(numeroBinario, ConverterOxB(numeroInicial));
                break;

            case 3:
                strcpy(numeroBinario, ConverterDxB(numeroInicial));
                break;

            case 4:
                strcpy(numeroBinario, ConverterHxB(numeroInicial));
                break;

            default:
                break;
            }
        }

        //Segunda Conversão
        if (baseF != 1) {
            switch (baseF)
            {
            case 2:
                strcpy(numeroFinal, ConverterBxO(numeroBinario));
                break;

            case 3:
                strcpy(numeroFinal, ConverterBxD(numeroBinario));
                break;

            case 4:
                strcpy(numeroFinal, ConverterBxH(numeroBinario));
                break;

            default:
                break;
            }
        }

        //Saída
        printf ("O numero %s, convertido da base %s para a ase %s, fica %s.\n\n", numeroInicial, baseEntrada, baseSaida, numeroFinal);

        //recursão
        printf ("\nDigite 1 para entrar com outro número, 0 para sair.\n");
        scanf("%d", &i);
        while ((getchar()) != '\n');

    } while (i == 1);
    
    return 0;
}

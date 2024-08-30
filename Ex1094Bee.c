#include <stdio.h>

int main() {

    int Testes, C, S, R, Quant, Total;
    float CCent, SCent, RCent;
    char Animal;

    scanf ("%d", &Testes);

    C = 0;
    R = 0;
    S = 0;

    for (int i = 1; i <= Testes; i++){
        scanf ("%d %c", &Quant, &Animal);

        switch (Animal){
            case 'C':
                C = C + Quant;
                break;
            case 'S':
                S = S + Quant;
                break;
            case 'R':
                R = R + Quant;
                break;
            default:
                break;
        }
    }

    Total = C + R + S;
    CCent = C*100.0/Total;
    RCent = R*100.0/Total;
    SCent = S*100.0/Total;

    printf ("Total: %d cobaias\nTotal de coelhos: %d\nTotal de ratos: %d\nTotal de sapos: %d\nPercentual de coelhos: %.2f %\nPercentual de ratos: %.2f %\nPercentual de sapos: %.2f %\n", Total, C, R, S, CCent, RCent, SCent);

    return 0;
}
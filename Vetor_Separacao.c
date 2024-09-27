#include <stdio.h>
#include <math.h>

int main (){
    int n, p, m, countp, countm;
    int par[5], impar[5];

    p = 0;
    m = 0;
    countp = 0;
    countm = 0;

    for (int i = 0; i < 15; i++)
    {
        scanf ("%d", &n);
        if(n % 2 == 0){
            par[p] = n;
            p++;
            countp++;
            if (p == 5){
                for (int j = 0; j < 5; j++){
                    printf("par[%d] = %d\n", j, par[j]);
                }
                p = 0;
                countp = 0;
            }
        } else {
            impar[m] = n;
            m++;
            countm++;
            if (m == 5){
                for (int j = 0; j < 5; j++){
                    printf("impar[%d] = %d\n", j, impar[j]);
                }
                m = 0;
                countm = 0;
            }
        }
    } //Le o vetor e calcula o próximo numero


    for (int i = 0; i < countm; i++)
    {
        printf("impar[%d] = %d\n", i, impar[i]);
    } //Escreve os vetores finais
    for (int i = 0; i < countp; i++)
    {
        printf("par[%d] = %d\n", i, par[i]);
    } //Escreve os vetores finais

    return 0;
}

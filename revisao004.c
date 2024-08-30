#include <stdio.h>
#include <math.h>


int potencias (float x, int n){
    float pot;
    pot = pow(x, 2*n);
    printf ("\npot: %.2f", pot);
    return pot;
}

int fatorial (int termo){
    int fat;
    fat = 1;
    for (int i = 1; i <= 2 * termo; i++){
        fat = fat * i;
    }
    printf ("\nfat: %d", fat);
    return fat;
}

int main () {
    int nter;
    float x, cos;

    cos = 1;

    scanf ("%f %d", &x, &nter);

    for (int i = 1; i <= nter; i++){
        if (nter % 2 == 0){
            cos = cos + (potencias(x, i) / fatorial (i));
        } else {
            cos = cos - (potencias(x, i) / fatorial (i));
        }
    }

    printf ("\nO cosseno de %.2f, com %d termos, e: %.2f", x, nter, cos);
    
}
#include <stdio.h>
#include <math.h>

int main () {
    int a, fat;
    fat = 1;

    scanf ("%d", &a);

    for (int i = 1; i <= a; i++){
        fat = fat * i;
    }

    printf ("O fatorial de %d e: %d", a, fat);
    
}
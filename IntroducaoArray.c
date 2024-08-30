#include <stdio.h>
#include <math.h>

int main (){
    int i, vetor[10];

    for (i = 0; i < 10; i++)
    {
        vetor[i] = 2*i;
        printf("%d\n", vetor[i]);
    }
    return 0;
}


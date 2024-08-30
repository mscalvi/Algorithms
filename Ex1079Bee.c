#include <stdio.h>

int main() {

    int N;
    float A, B, C, Media;

    scanf ("%d", &N);

    for (int i = 0; i < N; i++){
        scanf ("%f %f %f", &A, &B, &C);
        Media = (A*2 + B*3 + C*5)/10;
        printf ("%.1f\n", Media);
    }

    return 0;
}
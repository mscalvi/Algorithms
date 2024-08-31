#include <stdio.h>
 
int main() {
 
    int N, X, Y, Soma;
    
    scanf ("%d", &N);
    
    for (int j = 0; j < N; j++){

        Soma = 0;
        scanf ("%d %d", &X, &Y);

        if (X > Y) {
            int temp = X;
            X = Y;
            Y = temp;
        }

        if (X % 2 == 0){
            X++;
        } else {
            Soma -= X;
        }

        for (int i = X; i < Y; i+=2){
            Soma += i;
        }

        if (Soma < X){
            Soma = 0;
        }

        printf ("%d\n", Soma);
    }
    
    return 0;
}
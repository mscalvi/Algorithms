#include <stdio.h>
 
int main() {
 
    int X, Y;
    int Soma;

    X = 1;
    Y = 1;
    
    while (X > 0 && Y > 0) {

        Soma = 0;
        
        scanf ("%d %d", &X, &Y);
        
        if (X > 0 && Y > 0){
            if (X > Y) {
                int temp = X;
                X = Y;
                Y = temp;
            }
        
            for (int i = X; i <= Y; i++){
                printf ("%d ", i);
                Soma+=i;
            }
        
            printf ("Sum=%d\n", Soma);
        }
    }
    
    return 0;
}
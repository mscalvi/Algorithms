#include <stdio.h>
 
int main() {

    float j = 0;

    for (float i = 0; i <= 2.1; i+= 0.2){
        for (int c = 1; c <= 3; c++){
            j = c + i;
            if (i == 0 || i == 1 || i >= 2){
                printf ("I=%.0f J=%.0f\n", i, j);
            } else {
                printf ("I=%.1f J=%.1f\n", i, j);
            }
        }
    }
 
    return 0;
}
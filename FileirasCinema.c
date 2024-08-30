#include <stdio.h>

int main (){

    for (int i = 1; i <= 20; i++){
        for (int j = 1; j <= 30; j++){
            printf (" %d-%d ", i, j);
        }
        printf ("\n");
    }
}
#include <stdio.h>
 
int main() {
 
    int x, y, a;
    
    scanf ("%d %d", &x, &y);
    
    if (x > y) {
        int temp = x;
        x = y;
        y = temp;
    }
    
    if (x < 0){
        a = 0;
    } else {
        a = x + 1;
    }

    for (int i = a; i < y; i++){
        if (i % 5 == 2 || i % 5 == 3){
            printf ("%d\n", i);
        }
    }
 
    return 0;
}
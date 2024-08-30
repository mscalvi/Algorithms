#include <stdio.h>

int main() {

    int Num, MNum, MPos;

    MPos = 0;
    MNum = 0;

    for (int i = 1; i <= 100; i++){
        scanf ("%d", &Num);

        if (Num > MNum){
            MNum = Num;
            MPos = i;
        }

    }

    printf ("%d\n%d\n", MNum, MPos);

    return 0;
}
#include <stdio.h>
#include <math.h>

int main ()
{
    int Num, Tabu, Result;

    printf ("Digite o número cuja tabuada deseja conhecer.\n");
    scanf ("%d", &Num);

    printf ("Até qual valor deseja ver a tabuada?\n");
    scanf ("%d", &Tabu);

    for (int i = 0; i <= Tabu; i++)
    {
        Result = i * Num;
        printf ("%d x %d = %d\n", Num, i, Result);
    }
}
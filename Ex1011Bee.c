#include <stdio.h>
#include <math.h>
 
int main() {
 
    double R, volume;
    
    scanf ("%lf", &R);
    
    volume = (4/3.0) * 3.14159 * pow (R,3);

    printf ("VOLUME = %.3lf\n", volume);
 
    return 0;
}
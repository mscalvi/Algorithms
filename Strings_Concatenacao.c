#include <stdio.h>
#include <string.h>

int main () {
    char str1[40], str2[20];
    strcpy (str1, "Queijos");
    strcat (str1, " e ");
    strcpy (str2, "Vinhos");
    strcat (str1, str2);
    printf("%s", str1);
}
#include <stdio.h>

int main(void)
{
    int i, p;
    float f;
    char s[50];

    printf("Key-in an integer, float and a string\n");
    // Each space is a new value using scanf function
    p = scanf("%d%f%s", &i, &f, s);

    printf("p = %i, i = %i, f = %f, s = %s\n", p, i, f, s);

    return 0;
}


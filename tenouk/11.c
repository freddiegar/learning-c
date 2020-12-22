#include <stdio.h>
#include "11.h"

int main(void)
{
    int a, b;

    printf("Type two numbers separate by spaces: ");
    scanf("%i%i", &a, &b);

    printf("%i + %i = %i\n", a, b, sum(a, b));
    printf("%i - %i = %i\n", a, b, sub(a, b));

    return 0;
}


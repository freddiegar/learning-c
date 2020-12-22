#include <stdio.h>
#define AVG(x, y) (x + y) / 2

int main(void)
{
    int a = 2;
    int b = 4;

    printf("(%i + %i) / 2 = %i", a, b, AVG(a, b));


    return 0;
}

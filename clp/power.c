#include <stdio.h>

int power(int, int);

int main(void)
{
    int a, b;

//    printf("Set a value:\n");
//    a = getchar();
//
//    printf("Set b value:\n");
//    b = getchar();
    a = 2;
    b = 9;

    printf("%d ** %d = %d\n", a, b, power(a, b));
}

int power(int a, int b)
{
    int r = a * a;

    for (int i = 0; i < (b - 2); ++i) {
        r *= a;
    }

    return r;
}


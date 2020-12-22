#include <stdio.h>

int main(void)
{
    int i, j;

    i = j = 5;

    printf("Initial values for i and j are: i = %i, j = %i\n", i, j);
    printf("--i = %i, j-- = %i\n", --i, j++);
    printf("--i = %i, j-- = %i\n", --i, j++);
    printf("--i = %i, j-- = %i\n", --i, j++);
    printf("--i = %i, j-- = %i\n", --i, j++);
    printf("--i = %i, j-- = %i\n", --i, j++);

    i = j = 0;

    printf("Initial values for i and j are: i = %i, j = %i\n", i, j);
    printf("++i = %i, j++ = %i\n", ++i, j++);
    printf("++i = %i, j++ = %i\n", ++i, j++);
    printf("++i = %i, j++ = %i\n", ++i, j++);
    printf("++i = %i, j++ = %i\n", ++i, j++);
    printf("++i = %i, j++ = %i\n", ++i, j++);

    i = j = 10;
    printf("Initial values for i and j are: i = %i, j = %i\n", i, j);
    i = j = 10;
    i = ++j;
    printf("(i = ++j) i = %i j = %i\n", i, j);

    i = j = 10;
    i = j++;
    printf("(i = j++) i = %i j = %i\n", i, j);

    i = j = 10;
    i = --j;
    printf("(i = --j) i = %i j = %i\n", i, j);

    i = j = 10;
    i = j--;
    printf("(i = j--) i = %i j = %i\n", i, j);

    float r = 0.0;
    i = 5;
    j = 4;
    printf("Initial values for i and j are: i = %i, j = %i\n", i, j);
    r = (float)(i + j);
    printf("i + j = %f\n", r);
    r = (float)(i - j);
    printf("i - j = %f\n", r);
    r = (float)(i * j);
    printf("i * j = %f\n", r);
    r = (float)(i / j);
    printf("i / j = %f\n", r);
    r = (float)(i % j);
    printf("i %% j = %f\n", r);

    return 0;
}


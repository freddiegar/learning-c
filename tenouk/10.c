#include <stdarg.h>
#include <stdio.h>

void echo(int words, ...)
{
    va_list ap;

    va_start(ap, words);

    for (int i = 0; i < words; ++i) {
        printf("%s ", va_arg(ap, char*));
    }

    va_end(ap);

    return;
}

int sum(int numbers, ...)
{
    va_list ap;
    int sum = 0;

    va_start(ap, numbers);

    for (int i = 0; i < numbers; ++i) {
        sum += va_arg(ap, int);
    }

    va_end(ap);

    return sum;
}

int main(void)
{
    echo(3, "Hello", "World", "\n");
    // echo(3, "Hello", "World", '\n');

    printf("Sum is: %i\n", sum(2, 4, 5));

    return 0;
}


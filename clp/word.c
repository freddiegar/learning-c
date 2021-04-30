#include <stdio.h>
#define SP ' '
#define TAB '\t'
#define LF '\n'
#define NUL '\0'
#define TRUE 1
#define FALSE 0

int isBlank(char);

int main(void)
{
    int c;
    int lastCharIsBlank = FALSE;

    printf("Word Per Line Program\n");

    while ((c = getchar()) != EOF) {
        if (lastCharIsBlank && isBlank(c)) {
            continue;
        }

        if (isBlank(c)) {
            putchar(LF);
            lastCharIsBlank = TRUE;

            continue;
        }

        putchar(c);
        lastCharIsBlank = FALSE;
    }

    return 0;
}

int isBlank(char c)
{
    return c == SP || c == TAB || c == LF;
}


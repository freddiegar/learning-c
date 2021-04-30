#include <stdio.h>
#define SP ' '
#define TAB '\t'
#define LF '\n'
#define NUL '\0'
#define TRUE 1
#define FALSE 0
#define INIT_CHAR 33
#define LAST_CHAR 127
#define COUNT_CHAR LAST_CHAR - INIT_CHAR

int isBlank(char);

int main(void)
{
    int c;
    int ndigits[COUNT_CHAR];
    int nBlanks = 0;

    printf("Counter Letters Program\n");
    printf("Letters: %d\n\n", LAST_CHAR - INIT_CHAR);

    for (int i = 0; i < COUNT_CHAR; ++i) {
        ndigits[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (isBlank(c)) {
            ++nBlanks;
            continue;
        }

        if (c < INIT_CHAR || c > LAST_CHAR) {
            continue;
        }

        ++ndigits[c - INIT_CHAR];
    }

    printf("Char <Blank>: %d times\n", nBlanks);

    for (int i = 0; i < COUNT_CHAR; ++i) {
        if (ndigits[i] == 0) {
            continue;
        }

        printf("Char %c was: %d times\n", i + INIT_CHAR, ndigits[i]);
    }

    return 0;
}

int isBlank(char c)
{
    return c == SP || c == TAB || c == LF;
}


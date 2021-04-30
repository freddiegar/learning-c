#include <stdio.h>
#include <string.h>
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
    int word[10];
    int cwords = 0;
    int nletters = 0;
    int times;

    while ((c = getchar()) != EOF) {
        if (isBlank(c)) {
            ++cwords;
            nletters = 0;

            continue;
        }

        ++nletters;
        word[cwords] = nletters;
    }

    for(int i = 0; i < cwords; ++i) {
        times = word[i];

        printf("%d:\t", i);

        for (int j = 0; j < times; ++j) {
            putchar('*');
        }

        printf("\n");
    }
}

int isBlank(char c)
{
    return c == SP || c == TAB || c == LF;
}


#include <stdio.h>
#define MAXCHARS 1000

int getcontent(char []);
char * reverse(char [], int, char []);

int main(void)
{
    int linelen = 0;
    char line[MAXCHARS];
    char lreverse[MAXCHARS];

    while ((linelen = getcontent(line)) > 0) {
        printf("> |%s|\n", reverse(line, linelen, lreverse));
    }

    return 0;
}

int getcontent(char line[])
{
    int c, i;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

char * reverse(char line[], int length, char lreverse[])
{
    int i;
    int counter = 0;

    for (i = length - 1; i >= 0; --i) {
        if (line[i] == '\n') {
            continue;
        }

        lreverse[counter] = line[i];
        ++counter;
    }

    lreverse[counter] = '\0';

    return lreverse;
}


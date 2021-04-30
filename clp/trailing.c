#include <stdio.h>
#define MAXCHARS 1000

int getcontent(char []);
char * rtrim(char [], int);

int main(void)
{
    int linelen = 0;
    char line[MAXCHARS];

    while ((linelen = getcontent(line)) > 0) {
        printf("> |%s|\n", rtrim(line, linelen));
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

char * rtrim(char line[], int length)
{
    for (int i = length; i >= 0; --i) {
        if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n' || line[i] == '\0') {
            line[i] = '\0';

            continue;
        }

        break;
    }

    return line;
}


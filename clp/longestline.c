#include <stdio.h>
#define MAX 1000

int main(void)
{
    int c;
    int nlongest = 0;
    int nletters = 0;
    char line[MAX];
    char longest[MAX];

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            if (nlongest < nletters) {
                nlongest = nletters;

                for (int i = 0; i < nletters; ++i) {
                    longest[i] = line[i];
                    line[i] = '\0';
                }
            }

            nletters = 0;
        }

        line[nletters] = c;
        ++nletters;
    }

    printf("Longest has %d: %s\n", nlongest, longest);
}


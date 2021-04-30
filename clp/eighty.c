#include <stdio.h>
#define MAXCHARS 1000

int main(void)
{
    int c;
    int nc = 0;
    char line[MAXCHARS];

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            if (nc >= 8) {
                line[nc] = '\0';
                printf("%s\n", line);
            }

            nc = 0;

            continue;
        }

        line[nc++] = c;
    }

    return 0;
}

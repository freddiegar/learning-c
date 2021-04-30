#include <stdio.h>
#define SP ' '
#define TAB '\t'
#define LF '\n'
#define NUL '\0'
#define FALSE '0'
#define TRUE '1'
#define OUT FALSE
#define IN TRUE

// OEF
//    Unix    = Ctrl + D
//    Windows = Ctrl + Z

int main(void)
{
    int c;
    long nc = 0;
    long nl = 0;
    long nt = 0;
    long ns = 0;
    long nw = 0;
    char yet = FALSE;
    char state = OUT;
    char lastChar = NUL;


    printf("Counter Char Program\n\n");
    printf("End program using\n");
    printf("\tWindows\tCtrl + Z\n");
    printf("\tUnix   \tCtrl + D\n\n");
    printf("EOF = %d\n", EOF);

    while ((c = getchar()) != EOF) {
        if (lastChar == SP && c == SP) {
            continue;
        }

        lastChar = c;

        switch (c) {
            case LF:
                ++nl;
                break;
            case SP:
                ++ns;
                break;
            case TAB:
                ++nt;
                putchar('\\');
                putchar('t');
                yet = TRUE;
                break;
        }

        if (c == LF || c == SP || c == TAB) {
            state = OUT;
        } else if (state == OUT) {
            ++nw;
            state = IN;
        }

        if (yet == FALSE) {
            putchar(c);
        }

        ++nc;
        yet = FALSE;
    }

    printf("\nSummary Characters\n");
    printf("Number of char(s) is: %ld\n", nc);
    printf("Number of space(s) is: %ld\n", ns);
    printf("Number of tab(s) is: %ld\n", nt);
    printf("Number of newline(s) is: %ld\n", nl);
    printf("Number of word(s) is: %ld\n", nw);

    return 0;
}


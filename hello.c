#include <stdio.h>
#include <string.h>
#define MAX_INPUT 20
char* clean(char *input);

int main(void)
{
    char input[MAX_INPUT];
    char *name;

    printf("Please give me your name: ");
    fgets(input, MAX_INPUT, stdin);

    printf("\nVar input\n");
    printf("Value   : %s\n", input);
    printf("Address : %p\n", &input);

    printf("\nVar name (Before)\n");
    printf("Value   : %s\n", name);
    printf("Address : %p\n", &name);

    /* Using by value: New address in memory */
    name = clean(input);

    if (name != NULL) {
        printf("\nVar name (After)\n");
        printf("Value   : %s\n", name);
        printf("Address : %p\n", &name);
    } else {
        name = "World";
    }

    printf("\n\nHello %s!\n", name);

    return 0;
}

char* clean(char *input)
{
    printf("\nCleaning var\n");
    printf("Value   : %s\n", input);
    printf("Address : %p\n", &input);

    return strtok(input, "\n");
}


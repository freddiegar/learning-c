#include <stdio.h>
#include <string.h>
#define MAX_INPUT 20
char* clean(char* input);

int main(void)
{
    char* name;

    printf("Please give me your name: ");
    fgets(name, MAX_INPUT, stdin);

    printf("\nVar name (Before)\n");
    printf("Value   : %s\n", name);
    printf("Address : %p\n", &name);

    name = clean(name);

    if (name == NULL) {
        name = "World";
    }

    printf("\n\nHello %s!\n", name);

    return 0;
}

/**
 * Return a string (aka multiple address char)
 */
char* clean(char* input)
{
    printf("\nCleaning var\n");
    printf("Value   : %s\n", input);
    printf("Address : %p\n", &input);

    return strtok(input, "\n");
}


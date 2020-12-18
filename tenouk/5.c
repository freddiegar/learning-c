#include <stdio.h>

int main(void)
{
    const char *NAME = "Freddie";
    const int NAME_LENGTH = (sizeof(NAME) / sizeof(char)) - 1;

    printf("My name is %s\n\n", NAME);

    for (int i = 0; i < NAME_LENGTH; ++i) {
        printf("%c\n", NAME[i]);
    }

    return 0;
}


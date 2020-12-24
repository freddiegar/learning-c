#include <stdio.h>

int main(void)
{
    char letter[2];

    printf("Give me a letter: \n");

    fgets(letter, 2, stdin);

    printf("The letter is: %s", letter);
}


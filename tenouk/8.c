#include <stdio.h>
#include <stdlib.h>

char* dec2bin(unsigned int n)
{
    int c, d, t;
    char *p;

    t = 0;
    p = (char*)malloc(32+1);

    if (p == NULL) {
        exit(EXIT_FAILURE);
    }

    for (c = 31 ; c >= 0 ; c--)
    {
        d = n >> c;

        if (d & 1)
            *(p+t) = 1 + '0';
        else
            *(p+t) = 0 + '0';

        t++;
    }
    *(p+t) = '\0';

    return  p;
}

void option1()
{
    int bit;

    printf("Type a interger to get it in binary (1|0): ");
    scanf("%i", &bit);

    printf("\nBinary: \t %s\n", dec2bin(bit));

    return;
}

void option2()
{
    int number1, number2;

    printf("Number 1: ");
    scanf("%i", &number1);

    printf("Number 2: ");
    scanf("%i", &number2);

    printf("(n1)     : \t %s\n", dec2bin(number1));
    printf("(n2)     : \t %s\n", dec2bin(number2));
    printf("(n1 >> 1): \t %s\n", dec2bin(number1 >> 1));
    printf("(n1 << 2): \t %s\n", dec2bin(number1 << 1));
    printf("(n1 & n2): \t %s\n", dec2bin(number1 & number2));
    printf("(n1 | n2): \t %s\n", dec2bin(number1 | number2));
    printf("(~ n1)   : \t %s\n", dec2bin(~ number1));
    printf("(n1 ^ n2): \t %s\n", dec2bin(number1 ^ number2));

    return;
}

int main(void)
{
    int option;

    do {
        printf("Select one option please:\n\n");
        printf("1. Show in binary\n");
        printf("2. Show bitwise functions between tow numbers\n");
        printf("0. Exit\n");

        printf("Option: ");
        scanf("%i", &option);

        switch(option) {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 0:
            default:
                return 0;
                break;
        }
    } while (option != '0');

    return 0;
}


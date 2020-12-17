#include <stdio.h>

int main(void)
{
    int price;
    int quantity;

    printf("Hello world\n");
    printf("A price: \n");
    scanf("%d", &price);

    printf("A quantity: \n");
    scanf("%d", &quantity);

    printf("Total is:\t %d\n", price * quantity);

    return 0;
}


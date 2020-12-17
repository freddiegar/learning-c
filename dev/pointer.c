#include <stdio.h>

int main(void)
{
    // Initial value
    int var = 30;
    // Pointer is a variable with address from another variable
    int* pointer = &var;

    // Current status
    printf("Value of var is %d\n", var);
    printf("Address of var is %p\n", &var);
    printf("Value of pointer is %p\n", pointer);
    printf("Address of pointer is %p\n", &pointer);
    printf("Value of address of pointer is %d\n", *pointer);

    // Change value using "label"
    var = 60;
    printf("Value of var is %d\n", var);
    printf("Address of var is %p\n", &var);
    printf("Value of pointer is %p\n", pointer);
    printf("Address of pointer is %p\n", &pointer);
    printf("Value of address of pointer is %d\n", *pointer);

    // Change value using "address"
    *pointer = 90;
    printf("Value of var is %d\n", var);
    printf("Address of var is %p\n", &var);
    printf("Value of pointer is %p\n", pointer);
    printf("Address of pointer is %p\n", &pointer);
    printf("Value of address of pointer is %d\n", *pointer);
    printf("\n\n");

    int bar[3] = {2, 4, 6};
    int barSize = sizeof(bar) / sizeof(bar[0]);
    printf("Value of barSize is %d\n", barSize);
    printf("\n\n");

    for (int i = 0; i < barSize; ++i) {
        printf("Value of bar in %d is %d\n", i, bar[i]);
        printf("Address of bar in %d is %p\n", i, &bar[i]);
    }

    return 0;
}


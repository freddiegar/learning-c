// C program for clearing console and
// comparing two different methods
// @see https://www.geeksforgeeks.org/clear-console-c-language/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LOOP_COUNTER 1000
int main()
{
    int i = 0;
    clock_t t1, t2;

    // a loop for showing geeks for geeks
    // repeating by clearing console using
    // system("clear")

    // Noting start time
    t1 = clock();
    for (i; i < LOOP_COUNTER; i++) 
    {
        system("clear");
        printf("geeks for geeks %d\n", i);
    }

    // Calculating total time taken by
    // system("clear")
    t1 = clock() - t1;

    i = 0;
    // Noting start time of regex
    t2 = clock();
    for (i; i < LOOP_COUNTER; i++) 
    {
        printf("\e[1;1H\e[2J");
        printf("geeks for geeks %d\n", i);
    }

    // calculating total time taken by regex
    t2 = clock() - t2;

    // printing taken by both
    printf("Time taken by system\(\"clear\")\t %f\n",
           ((double)t1) / CLOCKS_PER_SEC);
    printf("Time taken by regex expr \t %f\n",
           ((double)t2) / CLOCKS_PER_SEC);

    return 0;
}


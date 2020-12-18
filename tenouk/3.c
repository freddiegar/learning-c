#include <stdio.h>

int main(void)
{
    printf("%%#x:\t%#x\n", 141);
    printf("%%g:\t%g\n", 5.1234567);
    printf("%%07d:\t%07d\n", 123);
    printf("%%+d:\t%+d\n", 456);
    printf("%%-7d:\t%-7d,%%-5d:\t%-5d,\n", 33, 44);
    printf("%%7s:\t%7s\n", "123456");
    printf("%%s:\t%s\n", "my name");
    printf("%%4f:\t%4f\n", 41.1234);
    printf("%%8.5f:\t%8.5f\n", 1323.2346);
    printf("%%.3f:\t%.3f\n", 15.4321);
    printf("%%hd:\t%hd\n", 7);
    printf("%%ld:\t%ld\n", 9999999999);

    return 0;
}


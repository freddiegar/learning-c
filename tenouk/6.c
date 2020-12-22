#include <stdio.h>

int main(void)
{
    short s = 3;
    int i = 3;
    float f = 3.0;
    double d = 3;
    char c = 'F';
    char *cc = "Freddie";
    char ccc[] = "Hello world!";
    char *p = &c;

    printf("Short \t (hi)\t %hi\n", s);
    printf("Integer\t (i) %i\n", i);
    printf("Integer\t (d) %d\n", i);
    printf("Float\t (f) %f\n", f);
    printf("Float\t (e) %e\n", f);
    printf("Float\t (E) %E\n", f);
    printf("Double\t (F) %F\n", d);

    printf("Octal\t (o) %o\n", i);
    printf("Hexa\t (x) %x\n", i);
    printf("Hexa\t (X) %X\n", i);
    printf("Pointer\t (p) %p\n", p);

    printf("Char\t (c) %c\n", c);
    printf("Char\t (c) %c\n", *cc);
    printf("Char*\t (s) %s\n", cc);
    printf("Char*\t (s) %s\n", ccc);

    printf("sizeof(char)\t  %lu\n", sizeof(char));
    printf("sizeof(short)\t  %lu\n", sizeof(short));
    printf("sizeof(int)\t  %lu\n", sizeof(int));
    printf("sizeof(float)\t  %lu\n", sizeof(float));
    printf("sizeof(double)\t  %lu\n", sizeof(double));
    printf("sizeof(long)\t  %lu\n", sizeof(long));
}


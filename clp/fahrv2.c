#include <stdio.h>

int main(void)
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("Celsius\tFarenheit\n");

    while (fahr <= upper) {
        celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%7.0f\t%7.1f\n", fahr, celsius);
        fahr += step;
    }

    celsius = lower;

    printf("Farenheit\tCelsius\n\n");

    while (celsius <= 300) {
        fahr = (celsius / (5.0 / 9.0)) + 32;
        printf("%7.1f\t%7.0f\n", fahr, celsius);
        celsius += step;
    }

    return 0;
}


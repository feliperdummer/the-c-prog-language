#include <stdio.h>

int main(void) {

    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("FAHRENHEIT TO CELSIUS TABLE:\n\n");
    printf("FAHR: \t CELSIUS:\n");
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f %10.1f\n", fahr, celsius);
        fahr += step;
    }

    return 0;
}

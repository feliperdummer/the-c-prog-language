/*
    Exercício 1-4: Escreva um programa para imprimir a tabela correspondente de Celsius para Fahrenheit
*/

#include <stdio.h>

int main(void) {

    float fahr, celsius;
    float upper, lower, step;

    lower = 0;
    upper = 100;
    step = 10;

    celsius = lower;

    printf("CELSIUS TO FAHRENHEIT TABLE:\n\n");
    printf("CELSIUS: \t FAHR:\n");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32;
        printf("%3.0f %15.0f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}

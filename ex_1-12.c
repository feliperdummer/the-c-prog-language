/*
    Exercicio 1-12: Escreva um programa que imprima seu input em uma palavra por linha
*/

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            putchar('\n');
        else
            putchar(c);
    }

    return 0;
}


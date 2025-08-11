/*
    Exercicio 1-9: Escreva um programa para copiar seu input para o output, substituindo toda sequência de 1
    ou mais espaços em branco por apenas um espaço em branco
*/

#include <stdio.h>

int main(void) {

    int c, ls;

    while ((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
        else
            if (ls != c)
                putchar(c);
        ls = c;
    }

    return 0;
}

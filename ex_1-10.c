/*
    Exercicio 1-10: Escreva um programa para copiar seu input para o output, substituindo cada tab por um '\t',
    cada backspace por '\b' e cada contrabarra por '\\'. Isso faz com que tabs e backspaces sejam visiveis
    sem ser de uma forma não ambígua
*/

#include <stdio.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\\') {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }

    return 0;
}

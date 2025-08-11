/*
    Exercicio 1-8: Escreva um programa que conte espaços em branco, tabs e novas linhas
*/

#include <stdio.h>

int main(void) {

    int c;
    int t = 0, b = 0, nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            b++;
        if (c == '\t')
            t++;
        if (c == '\n')
            nl++;
    }

    printf("\nEspacos em branco = %d", b);
    printf("\nTabs = %d", t);
    printf("\nNovas linhas = %d", nl);

    return 0;
}

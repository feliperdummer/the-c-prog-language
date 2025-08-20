/*
    Exercicio 1-13: Escreva um programa para imprimir um histograma do tamanho das palavras do input. É fácil desenhar o histograma horizontalmente;
    um histograma vertical é mais desafiador
*/

#include <stdio.h>

#define MAXLEN 15

int main(void)
{
    int wlengths[MAXLEN];
    int c, i, j;
    int wl = 0;
    int maior;

    for (i = 0; i < MAXLEN; i++)
        wlengths[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == ' ' || c == '\t') {
            if (wl > 0 && wl < MAXLEN)
                wlengths[wl]++;
            wl = 0;
        }
        else
            wl++;
    }

    maior = 0;
    for (i = 1; i < MAXLEN; i++)
        if (wlengths[i] > maior)
            maior = wlengths[i];

    printf("\nHistograma das palavras do input:\n\n");

    for (i = maior; i > 0; i--) {
        printf("%d", i);
        for (j = 1; j < MAXLEN; j++) {
            if (wlengths[j] >= i)
                printf(" | ");
            else
                printf("   ");
        }
        putchar('\n');
    }
    putchar(' ');
    for (i = 1; i < MAXLEN; i++) {
        if (i < 10)
            printf(" %d ", i);
        else
            printf(" %d", i);
    }

    return 0;
}

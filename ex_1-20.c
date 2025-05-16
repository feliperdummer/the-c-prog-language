#include <stdio.h>

#define TABSTOP 8

int main()
{
    int c;
    int col = 0, space = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            space = TABSTOP - (col % TABSTOP);
            while (space-- > 0) {
                putchar(' ');
                col++;
            }
        }
        else {
            putchar(c);
            if (c == '\n')
                col = 0;
            else
                col++;
        }
    }

    return 0;
}

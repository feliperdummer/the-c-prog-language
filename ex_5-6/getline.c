#include "functions.h"
#include <stdio.h>

int getline(char *s, int lim)
{
    int c, i = 0;

    while (i < lim - 1 && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
        ++i;
    }
    if (c == '\n') {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
}

#include "functions.h"
#include <stdio.h>

int getline(char *s, int lim)
{
    int c;
    char *s_mem = s;

    while ((s - s_mem) < lim - 1 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return (s - s_mem);
}

#include "functions.h"
#include <stdio.h>
#include <string.h>

int strindex(char *s, char *t)
{
    int i;
    char *s_mem = s;
    char *t_mem = t;

    while (*s++) {
        if (*s == *t) {
            for (i = 0; *(s + i) == *t && *t != '\0'; i++)
                t++;
            if (*t == '\0')
                return (s - s_mem);
        }
        t = t_mem;
    }
    return -1;
}

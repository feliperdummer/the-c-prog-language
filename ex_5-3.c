/*
    Write a pointer version of the function strcat that we showed in Chapter 2: strcat(s, t) copies the string t to the end of s
*/

/*
    For those with the book in reach, the function strcat is first presented in the page 48
*/

#include <stdio.h>

void Strcat(char *s, char *t);

int main(void)
{
    char s1[20] = "Hello";
    char s2[] = " World";

    Strcat(s1, s2);

    printf("%s\n", s1);

    return 0;
}

void Strcat(char *s, char *t)
{
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}

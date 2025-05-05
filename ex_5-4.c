/*
    Write the function strend(s, t), which returns 1 if the string t occurs
    at the end of the string s, and zero otherwise.
*/

#include <stdio.h>
#include <string.h>

_Bool strend(char *s, char *t);

int main(void)
{
    char s1[] = "Hello";
    char s2[] = "llo";
    int test = strend(s1, s2);

    printf("%d\n", test);

    return 0;
}

_Bool strend(char *s, char *t)
{
    int tlen = strlen(t);
    int slen = strlen(s);
    char *tmem = t;

    t += tlen;
    s += slen;

    while ((*s == *t) && (t != tmem)) {
        --s;
        --t;
    }
    return (t == tmem);
}

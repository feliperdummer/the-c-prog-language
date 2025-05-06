/*
    Write versions of the library function strncpy, strncat and
    strncmp, which operate on at most the first n characters of
    their argument strings. For example, strncpy(s, t, n) copies
    at most n characters of t to s. Full descriptions are in Appendix B.
*/

#include <stdio.h>

char *Strncpy(char *s, char *t, size_t n);
char *Strncat(char *s, char *t, size_t n);
int Strncmp(const char *s, const char *t, size_t n);

int main(void)
{
    char s1[] = "ABCD";
    char s2[] = "ADCD";

    int result = Strncmp(s1, s2, 2);

    printf("%d\n", result);

    return 0;
}

/*
    Pay attention, the function strncpy does not add a finishing '\0', so you'll need to add manually
    depending on the context you're using it.
*/
char *Strncpy(char *s, char *ct, size_t n)
{
    char *s_mem = s;
    int i;

    for (i = 0; i < n && *ct != '\0'; i++)
        *s++ = *ct++; // Copies ct to s before incrementing both
    while (i < n)
        *s++ = '\0'; // Pad with '\0's if n is greater than the number of characters of ct;
    return s_mem;
}

/*
    In this case below, the null character of t is not copied to the end of s
    when the value of n is smaller than or equal to the size of t because the
    condition that checks the value of i is valued false before t reaches
    its null character;

    For the null character to be automatically added do the end of string s,
    the value of n needs to be higher than the size of t. That is the reason
    for the test before the return expression;
*/
char *Strncat(char *s, char *t, size_t n)
{
    char *s_mem = s;
    int i = 0;

    while(*s)
        s++;
    while ((i++ < n) && (*s++ = *t++))
        ;
    if (*(s - 1) != '\0')
        *s = '\0';
    return s_mem;
}

int Strncmp(const char *s, const char *t, size_t n)
{
    int i;

    for (i = 0; (i < n) && (*s == *t) && (*s && *t); i++)  {
        s++;
        t++;
    }
    if (i == n)
        return 0;
    return (*s - *t);
}

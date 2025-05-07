#include "functions.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    Blame my laziness. This file includes all the variants of atoi;

    This file also includes the string reversing function: srev;
*/

int atoi(char *s)
{
    int sign, n = 0;

    while (isspace(*s))
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    while (isdigit(*s))
        n = 10 * n + (*s++ - '0');
    return sign * n;
}

void itoa(int n, char *s)
{
    int sign;
    char *s_mem = s;

    if ((sign = n) < 0)
        n = -n;
    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';

    srev(s_mem);
}

void itob(int n, char *s, int b)
{
    char symbol[] = "0123456789ABCDEF";
    int sign;
    char *s_mem = s;

    if ((sign = n) < 0)
        n = -n;
    do {
        *s++ = *(symbol + (n % b));
    }while ((n /= b) > 0);

    if (sign < 0)
        *s++ = '-';
    *s = '\0';

    srev(s_mem);
}

double atof(char *s)
{
    double int_part = 0.0, dec_part = 1.0;
    int sign = 0;

    while (isspace(*s))
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-')
        s++;
    while (isdigit(*s))
        int_part = 10.0 * int_part + (*s++ - '0');
    if (*s == '.')
        s++;
    while (isdigit(*s)) {
        int_part = 10.0 * int_part + (*s++ - '0');
        dec_part *= 10.0;
    }

    return (sign * int_part / dec_part);
}

void srev(char *s)
{
    int q = strlen(s) - 1;
    int lim = q / 2;
    int i = 0;
    char temp;

    while (q > lim) {
        temp = *(s + i);
        *(s + i) = *(s + q);
        *(s + q) = temp;
        q--;
        i++;
    }
}

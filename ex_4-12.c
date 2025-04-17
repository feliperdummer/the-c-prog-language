/*
    Adapt the ideas of printd to write a recursive version of itoa; that is, convert an integer into a string by calling
    a recursive routine
*/

/*
    itoa algorithm:

    void itoa(int n, char s[])
    {
        int i, sign;

        if ((sign = n) < 0)
            n = -n;

        i = 0;
        do {
            s[i++] = n % 10 + '0';
        } while ((n /= 10) > 0);

        if (sign < 0)
            s[i++] = '-';

        s[i] = '\0';

        reverse(s);
*/

#include <stdio.h>

void itoa(int n, char s[]);

int main()
{
    int n = -123;
    char s[10];

    itoa(n, s);

    printf("%s\n", s);

    return 0;
}

int ind = 0;

void itoa(int n, char s[]) // n is the number, s is the string the number will be copied to, i is the index of the array
{
    if (n < 0) {
        s[ind++] = '-';
        n = -n;
    }

    if ((n / 10)) {
        itoa((n/10), s);
    }
    s[ind++] = n % 10 + '0';
}

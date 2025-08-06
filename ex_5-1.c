/*
    As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character
    back on the input;
*/

#include <stdio.h>
#include <ctype.h>

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        int temp = getch();
        if (!isdigit(temp)) {
            ungetch(temp);
            ungetch(c);
            return 0;
        }
        c = temp;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

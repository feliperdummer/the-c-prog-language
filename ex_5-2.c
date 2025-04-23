/*
    Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value ?
*/

#include <stdio.h>
#include <ctype.h>

int getfloat(double *pn)
{
    int c, sign, count = 1;
    double dec = 0;

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
            return -1;
        }
        c = temp;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.') {
        double frac = 0, div = 10;
        while (isdigit(c = getch())) {
            frac += (c - '0') / 10;
            div *= 10;
        }
        dec = frac;
    }
    *pn += dec;
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

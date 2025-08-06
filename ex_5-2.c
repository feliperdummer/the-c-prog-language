/*
    As written, getint treats a + or - not followed by a digit as a valid representation of zero. Fix it to push such a character
    back on the input;
*/

#include <stdio.h>
#include <ctype.h>

int getfloat(float *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != '+' && c != '-' && c != EOF) {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '-' || c == '+') {
        int temp = getch();
        if (!isdigit(temp)) {
            ungetch(c);
            ungetch(temp);
            return 0;
        }
        c = temp;
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    if (c == '.') {
        float dec = 0, power = 10.0;
        int temp = c;
        while (isdigit(c = getch())) {
            dec += (c - '0') / power;
            power *= 10;
        }
        if (dec == 0) {
            ungetch(temp);
            if (c != EOF)
                ungetch(c);
        }
        else
            *pn += dec;
    }
    else
        ungetch(c);
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

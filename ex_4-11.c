/*
    Modify getop so that it doesn't need to use ungetch. Hint: use an internal static variable
*/

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'
#define BUFSIZE 100

int getop(char []);
int getch(int buf[], int bufp);

int main(void)
{


    return 0;
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c, negative=0;
    static int buf[BUFSIZE];
    static int bufp = 0;

    while ((s[0] = c = getch(buf, bufp)) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c; /* not a number */
    }
    i = 0;
    if (c == '-') {
        if (!isdigit(s[++i] = c = getch(buf, bufp))) {
            if (bufp >= BUFSIZE) {
                printf("ungetch:  too many characters\n");
            }
            else buf[bufp++];
            return '-';
        }
    }
    if (isdigit(c)) { /* collect integer part */
        while (isdigit(s[++i] = c = getch(buf, bufp))) {
            ;
        }
    }
    if (c == '.') { /* collect fraction part */
        while (isdigit(s[++i] = c = getch(buf, bufp))) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        if (bufp >= BUFSIZE) {
            printf("ungetch:  too many characters\n");
        }
        else buf[bufp++];
    }
    return NUMBER;
}

int getch(int buf[], int bufp) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

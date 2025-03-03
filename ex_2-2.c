#include <stdio.h>

#define MAXLINE 1000

int main()
{
    int i, c;
    char s[MAXLINE];

    for (i=0; i < MAXLINE-1; ++i) {
        if ((c=getchar()) != '\n') {
            if (c != EOF) {
                s[i] = c;
            }
            else
                break;
        }
    }

    return 0;
}

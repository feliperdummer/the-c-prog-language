#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int lim);

int main()
{
    int len;
    char line[MAXLINE];
    char print_line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0) {
        if (len > 80) {
            printf("\n%s", line);
        }
    }

    return 0;
}

int getline(char s[], int lim)
{
    int i, c;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c!= '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}


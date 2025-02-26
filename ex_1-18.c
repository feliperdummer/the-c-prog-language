#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int lim);
void copy(char to[], char from[]);
int remove_tblanks(char s[], int length);
void remove_tabs(char s[], int length);

int main()
{
    char line[MAXLINE];
    int length=0;
    int new_length=0;

    while ((length = getline(line, MAXLINE)) > 0) {
        new_length = remove_tblanks(line, length);
        remove_tabs(line, length);

        printf("%s", line);
    }

    return 0;
}

int getline(char s[], int lim)
{
    int i, c;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

int remove_tblanks(char s[], int length)
{
    int i, new_length;
    i = length;
    while (s[i-2] == ' ') {
        s[i-2] = s[i-1];
        s[i-1] = s[i];
        --i;
    }
    new_length = i;

    return new_length;
}

void remove_tabs(char s[], int length)
{
    int i=0;
    while (i < length) {
        if (s[i] == '\t') {
            s[i] = ' ';
        }
        ++i;
    }
}

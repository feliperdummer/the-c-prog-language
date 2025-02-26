#include <stdio.h>

#define MAXLINE 1000

int getline(char s[], int lim);
void reverse(char s[]);
int remove_tblanks(char s[], int length);
void remove_tabs(char s[], int length);

int main()
{
    char line[MAXLINE]; // current line
    char rev[MAXLINE]; // reversed current line
    int len=0; // current line length
    int new_length=0;

    int i;
    while ((len = getline(line, MAXLINE)) > 0) {
        new_length = remove_tblanks(line, len);
        remove_tabs(line, new_length);
        reverse(line);
    }

    return 0;
}

int getline(char s[], int lim)
{
    int i, c;

    for (i=0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i; // i in this case will return the length of the line
}

// Reverse 'from' into 'to'. Getting the length of 'from' as a parameter
void reverse(char s[])
{
    char temp;
    int i;

    for (i=0; s[i] != '\0'; i++) {
        ;
    }

    int len = i; // len contains the length of the line to be reversed
    for (i=0; i < len/2; i++) {
        temp = s[i];
        s[i] = s[(len-1)-i];
        s[(len-1)-i] = temp;
    }

    printf("%s", s);
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

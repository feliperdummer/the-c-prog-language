/*
    Write a function scape(s, t) that converts characters like newline and tab into visible scape sequences
    like \n and \t as it copies the string t to s. Use a switch. Write a function for the other direction as
    well, converting scape sequences into real characters.
*/

#include <stdio.h>

void escape(char s2[], char s1[]);
void unescape(char s3[], char s2[]);

int main()
{
    char s1[] = "Hello\tWorld\tGood\tMorning";
    char s2[100];

    printf(" S1 before the escape function: %s\n", s1);

    escape(s2, s1);

    printf("\n S1 after copy from S1: %s\n", s2);

    unescape(s1, s2);

    printf("\n S2 after unescape function: %s\n", s1);

    return 0;
}

void escape(char s2[], char s1[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0';++i) {
        switch(s1[i]) {
        case '\t':
            s2[j++] = '\\';
            s2[j++] = 't';
            break;
        case '\n':
            s2[j++] = '\\';
            s2[j++] = 'n';
            break;
        default:
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

void unescape(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s2[i] != '\0'; ++i) {
        switch (s2[i]) {
        case ('\\'):
            switch (s2[++i]) {
            case ('t'):
                s1[j++] = '\t';
                break;
            case ('n'):
                s1[j++] = '\n';
                break;
            }
            break;
        default:
            s1[j++] = s2[i];
        }
    }
    s1[j] = '\0';
}

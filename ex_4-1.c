/*
    Write the function strrindex(s, t), which returns the position of the rightmost occurrence of t in s, or -1 if there is none
*/

#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]);

int main()
{
    char s[] = "abcaabc";
    char t[] = "abc";

    int i = strrindex(s, t);

    printf("\n\n%d", i);

    return 0;
}

int strrindex(char s[], char t[])
{
    int i, j, k, length;

    length = strlen(s);

    for (i=length-1; s[i] >= 0; i--) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            return i;
        }
    }
    return -1;
}

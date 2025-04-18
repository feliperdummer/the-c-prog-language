/*
    Write a recursive version of the function reverse(s), which reverses the string s in place
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

int main(void)
{
    char s[] = "Hello";

    reverse(s);

    printf("%s\n", s);

    return 0;
}

int ind = 0;

void reverse(char s[])
{
    int q = strlen(s);
    char temp;

    if (ind < (q/2)) {
        temp = s[ind];
        s[ind] = s[q-(ind+1)];
        s[q-(ind+1)] = temp;
        ind++;
        reverse(s);
    }
}

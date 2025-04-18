/*
    Write a recursive version of the function reverse(s), which reverses the string s in place
*/

#include <stdio.h>
#include <string.h>

void reverse(char s[], int ind);

int main(void)
{
    char s[] = "Hello";
    int ind = 0;

    reverse(s, ind);

    printf("%s\n", s);

    return 0;
}

void reverse(char s[], int ind)
{
    int q = strlen(s);
    char temp;

    if (ind < (q/2)) {
        temp = s[ind];
        s[ind] = s[q-(ind+1)];
        s[q-(ind+1)] = temp;
        reverse(s, ind+1);
    }
}

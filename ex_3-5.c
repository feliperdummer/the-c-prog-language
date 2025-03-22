/*
    Write a function itob(n, s, b) that converts the integer n into a base b character representation in the string s.
    In particular, itob(n, s, 16) formats n as a hexadecimal integer in s
*/

#include <stdio.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    int x = 15;
    char arr[500];

    itob(x, arr, 2);

    printf("%s", arr);

    return 0;
}

void itob(int n, char s[], int b)
{
    char symbol[] = "0123456789ABCDEF";

    int sign;

    if ((sign = n) < 0) {
        n = -n;
    }    

    int i = 0;
    do {
        s[i++] = symbol[(n % b)];
    } while((n /= b) > 0);

    if (sign < 0) {
        s[i++] = '-';
    }

    reverse(s);

    s[i] = '\0'
}

void reverse(char s[])
{
    int q;
    for (q=0; s[q] != '\0'; q++) {
        ;
    }
    --q;

    int i;
    char temp;

    for (i=0; i <= (q/2); i++) {
        temp = s[i];
        s[i] = s[q-i];
        s[q-i] = temp;
    }
}

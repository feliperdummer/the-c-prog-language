/*
    Write a version of itoa that accepts three arguments instead of two. The third argument is a minimum field width; the converted number
    must be padded with blanks on the left if necessary to make it wide enough.
*/

#include <stdio.h>

void itoa(int n, char s[], int min);
void reverse(char s[]);

int main()
{
    int x = -123;
    char arr[128];

    itoa(x, arr, 10);

    printf("\n%s", arr);

    return 0;
}

void itoa(int n, char s[], int min)
{
    int i, j, sign;

    char digit[] = "0123456789";

    if ((sign = n) < 0) {
        n = -n;
    }

    i = j = 0;
    do {
        if (((n / 10) > 0) || (n == 1)) {
            s[i++] = digit[n % 10];
            j++;
        }
        else
            s[i++] = ' ';
    }while((n /= 10) > 0 || i < min);

    if (sign < 0) {
        s[j] = '-';
    }

    reverse(s);

    s[i] = '\0';
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

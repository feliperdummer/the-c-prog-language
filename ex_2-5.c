/* EX 2-5
    Write the function any(s1, s2), which returns the first location in the string s1 where any character from the string
    s2 occurs, or -1 if s1 contains no character from s2.
*/

#include <stdio.h>

int any(const char s1[], const char s2[]);

int main()
{
    char str1[] = "Joao";
    char str2[] = "Pedro";

    int location = any(str1, str2);

    if (location != -1) {
        printf(" Location = %d \n", location);
    }
    else
        printf(" There is no equal characters \n");
}

int any(const char s1[], const char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    if (s1[i] == '\0') {
        return -1;
    }
}

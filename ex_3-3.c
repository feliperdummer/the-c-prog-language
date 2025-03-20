/*
    Write a function expand(s1, s2) that expands shorthand notations like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
    Allow for letters of either case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing
    - is taken literally
*/

/*
    This algorithm was highly inspired by stack overflow user "Fazer" algorithm, and all the other people that contributed on his question.
    Link to his question: https://stackoverflow.com/questions/38228079/kr-programming-in-c-ex-3-3
*/

#include <stdio.h>
#include <ctype.h>

void expand(char s1[], char s2[]);

int main()
{
    char s1[] = "Hello a-z good -a-z morning a-z- world -a-z- ! a-b-z";
    char s2[500];

    expand(s1, s2);

    printf("\n%s\n", s2);

    return 0;
}

void expand(char s1[], char s2[])
{

    int i, j, k;
    char temp;

    for (i=j=0; s1[i] != '\0'; i++) {
        /* The first two condition are there to check if you're in the beginning of a shorthand notation. */
        /* The third checks if there is a hyphen at the end of the shorthand notation */
        if (isalnum(s1[i]) && s1[i+1] == '-' && s1[i+2] != ' ') {
            temp = s1[i];
            /* Check if the the character 2 positions ahead (Which will be an alphanumeric) is bigger or equal than the current character */
            for (;temp <= s1[i+2];) {
                s2[j++] = temp++;
            }
            ++i; /* Increment i by 1 so it skips the '-' and the last alphanumeric character of the shorthand notation in s1 */
            --j; /* Decrement j by 1 so it does not copy the last alphanumeric to s2 twice */
        }
        else {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}

/*
    Rewrite the lower function, which converts upper case letters to lower case, with a conditional
    expression instead of if-else.

    Condtional expression: (?:)

    It works as a substitute for if-else. For example:
    if (a > b) {
        z = a;
    }
    else
        z = b;

    Could be written as: z = (a > b) ? a : b;
    You read as: (a > b) is evaluated, if its non-zero (true), a is evaluated and becomes the value of the cond. expression.
    Otherwise, b is evaluated and becomes the value of the conditional expression.

    In a general explanation: expr1 ? expr2 : expr3. expr1 is evaluated, is its non-zero (true), expr2 is evaluated and that
    is the value of the conditional epxression. Otherwie, expr3 is evaluated and that is the value of the expression.
*/

#include <stdio.h>

int lower(int c);

int main()
{
    int upper_to_lower = lower('d');

    printf("%c", upper_to_lower);

    return 0;
}

int lower(int c)
{
    return c = (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}

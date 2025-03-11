/*
    Basically, x &= (x-1) deletes the most right 1 bit in two's complement because, for context, -1 is represented as all ones
    in two's complement (independent of the bit size representation), so x - 1 is the same thing as x + (-1), by doing this sum,
    the right-most 1 bit will be deleted. This sum is the equivalent of x &= (x-1). The difference on the number value will
    depend on the most-right bit value, so if the right most bit value is 4, the result on x will be x - 4.
*/

#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    int num;
    printf(" Type a random integer: ");
    scanf("%d", &num);

    int count = bitcount(num);

    printf("\n Quantity of 1 bits in %d: %d\n", num, count);

    return 0;
}

int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x-1))
        b++;

    return b;
}

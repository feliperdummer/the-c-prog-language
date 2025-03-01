#include <stdio.h>
#include <limits.h>

int main()
{
    printf(" CHAR TYPE: \n");
    printf(" MIN = %d \t\t MAX = %d \n", CHAR_MIN, CHAR_MAX);
    printf(" MIN SIGNED = %d \t MAX SIGNED = %d \n", SCHAR_MIN, SCHAR_MAX);
    printf(" \t\t\t MAX UNSIGNED = %u \n\n", UCHAR_MAX);

    printf(" SHORT TYPE: \n");
    printf(" MIN = %d \t\t MAX = %d \n", SHRT_MIN, SHRT_MAX);
    printf(" \t\t\t MAX UNSIGNED = %u \n\n", USHRT_MAX);

    printf(" INT TYPE: \n");
    printf(" MIN = %d \t MAX = %d \n", INT_MIN, INT_MAX);
    printf(" \t\t\t MAX UNSIGNED = %u \n\n", UINT_MAX);

    printf(" LONG TYPE: \n");
    printf(" MIN = %d \t MAX = %d \n", LONG_MIN, LONG_MAX);
    printf(" \t\t\t MAX UNSIGNED = %u \n\n", ULONG_MAX);


    return 0;
}

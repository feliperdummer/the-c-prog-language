/*
    Define a macro swap(t, x, y) that interchanges two arguments of type t. (Block structure will help.)
*/

#include <stdio.h>

#define swap(t, x, y)                     \
    do {                                  \
            t temp##__LINE__;             \
            temp##__LINE__ = x;           \
            x = y;                        \
            y = temp##__LINE__;           \
    }while(0);

/*
    Use of do {...}while:
        By using this loop, we assure that the macro body is executed as only one block of code,
        this is crucial in situations where this would be used in a if written as: if(condition)
                                                                                       swap(t, x, y);

        Without the do{...}while, only the first line of the macro would be executed, the reason
        has already been told before in the book;

        The condition (0) assures that the loop will be only executed once.
*/

/*
    Use of macro __LINE__:
        This is a predefined macro in C that has the line number where it is being called as a token,
        by concatenating (##) this with the temporary variable name, the temporary variable name is
        actually temp5. This is helpful in cases where you may have other variables with the same name
        being used in the code, which would cause confusion and unexpected behavior.
*/

int main(void)
{
    int x = 12;
    int y = 13;

    printf(" Value of x before the swap = %d\n", x);
    printf(" Value of y before the swap = %d\n", y);

    swap(int, x, y);

    printf("\n Value of x after the swap = %d\n", x);
    printf(" Value of y after the swap = %d\n", y);


    return 0;
}

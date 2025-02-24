#include <stdio.h>

int main()
{
    int c;

    while ((c=getchar())!=EOF) {
        if (c!=' ') {
            putchar(c);
        }
        else
            printf("\n");
    }

    return 0;
}

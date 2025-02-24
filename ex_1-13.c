#include <stdio.h>

int main()
{
    int c, count=0, i;

    while ((c=getchar())!=EOF && c!='\n') {
        if (c!= ' ') {
            printf("|");
        }
        else if (c==' ') {
            printf("\n");
        }
    }

    return 0;
}

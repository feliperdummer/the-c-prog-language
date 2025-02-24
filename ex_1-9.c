#include <stdio.h>

int main()
{
    int c, last_seen;

    while ((c=getchar())!=EOF) {
        if (c!=' ') {
            putchar(c);
        }
        else if (c==' ')  {
            if (last_seen!=c) {
                putchar(c);
            }
        }
        last_seen=c;
    }

    return 0;
}

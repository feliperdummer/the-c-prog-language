#include "functions.h"
#include <stdio.h>

int main(void)
{
    char s[] = "bbcabc";
    char t[] = "abc";

    int i = strindex(s, t);

    printf("%d\n", i);

    return 0;
}

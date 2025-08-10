/*
    Verifique se a expressão getchar() != EOF é 0 ou 1
*/

#include <stdio.h>

int main(void) {

    printf("\n%d\n\n", getchar() != EOF);
    getchar();

    printf("\n%d", getchar() != EOF);

    return 0;
}

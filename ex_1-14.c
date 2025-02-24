#include <stdio.h>

#define TAM 127

int main()
{
    int c, i, j;
    int carac[TAM];

    for (i=33; i < TAM; ++i) {
        carac[i] = 0;
    }

    while ((c=getchar())!=EOF) {
        ++carac[c];
    }

    for (i=33; i < TAM; i++) {
        if (carac[i] > 0) {
            printf("\n Caractere %c: ", i);
            for (j=0; j < carac[i]; j++) {
                printf("| ");
            }
            printf("\n");
        }
    }

    return 0;
}


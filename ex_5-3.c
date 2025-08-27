/*
    Escreva uma versão de ponteiros da função strcat que mostramos no capítulo 2: strcat(s, t) copia a string t pro fim da string s
*/

/*
    Pra quem tiver o livro em mãos, a função aparece pela primeira vez na página 48
*/

#include <stdio.h>

void Strcat(char*, char*);

int main(void)
{
    char s1[20] = "Hello";
    char s2[] = " World";

    Strcat(s1, s2);

    printf("%s\n", s1);

    return 0;
}

void Strcat(char *s, char *t) {
    while (*s)
        s++;
    while (*s++ = *t++)
        ;
}


/*
    Exerc�cio 1-5: Modifique o programa de convers�o de temperatura para imprimir a tabela na ordem reversa, isto �, de 300 graus at� 0
*/

#include <stdio.h>

int main(void) {

    float fahr;

    printf("FAHR: \t CELSIUS:\n");
    for (fahr = 300; fahr >= 0; fahr -= 20) {
        printf("%3.0f %10.1f\n", fahr, (5.0/9.0)*(fahr - 32.0));
    }

    return 0;
}

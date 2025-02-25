#include <stdio.h>

// C = (5.0/9.0) * (F-32)

float conversion(float F);

int main()
{
    int upper=300, lower=0, step=20;
    float C, F=0;

    while(F <= upper) {
        C = conversion(F);
        printf(" %3.0f %6.1f \n", F, C);
        F += step;
    }

    return 0;
}

float conversion(float F)
 {
     float C = (5.0/9.0) * (F-32);

     return C;
 }

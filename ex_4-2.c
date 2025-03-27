/*
    Extend atof to handle scientific notation of the form 123.45e-6 where a floating point number may be followed by e or E and
    an optionally signed exponent
*/

#include <stdio.h>
#include <ctype.h>

double atof(char s[]);
double pow_of(long int base, int power);

int main(void)
{
    char s[] = "1234.56";

    printf("\n%.7f", atof(s));

    return 0;
}

double atof(char s[])
{
    double val;
    double decimal; // Decimal part of the number
    double def; // Final value of the number (val / decimal)
    int i, sign;

    for (i=0; isspace(s[i]); ++i){
        ;
    }
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-') {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (decimal = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        decimal *= 10.0;
    }
    def = sign * val / decimal;

    if (s[i] == 'e' || s[i] == 'E') {
        ++i;
        double power;
        if (s[i] == '-') {
            ++i;
            power = 1 / pow_of(10, (s[i] - '0'));
            return def * power;
        }
        else {
            power = pow_of(10, (s[i] - '0'));
            return def * power;
        }
    }

    return def;
}

// Power function
double pow_of(long int base, int power)
{
    int i, sign = 0;
    double num = 1.0;

    if (base == 0 && power > 0) {
        return 0;
    }
    else if (power <= 0) {
        return -1; // 0 to the power of 0 is indeterminate and 0 to the power of a negative number does not exists
    }
    if (power == 0) {
        return 1;
    }
    if (power < 0) {
        sign = 1; // Means that the power is negative
        power = -power; // Turn the power to positive
    }
    for (i=0; i < power; i++) {
        num *= base;
    }
    if (sign) {
        num = 1 / num;
    }

    return num;
}

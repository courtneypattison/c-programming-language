#include <stdio.h>

int fahr_to_celsius(int fahr);

/* print Farenheit-Celsius table
    for fahr = 0, 20, ..., 300; floating-point version */
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Farenheit    Celsius\n");
    printf("--------------------\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = fahr_to_celsius(fahr);
        printf("%9.0f    %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}

/* convert farenheit to celsius */
int fahr_to_celsius(int fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}


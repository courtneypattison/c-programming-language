#include <stdio.h>

/* print Celsius-Farenheit table
    for Celsius = -20, ..., 160; floating-point version */

main()
{
    float celsius, fahr;
    int lower, upper, step;

    lower = -20;    /* lower limit of temperature table */
    upper = 160;    /* upper limit */
    step = 10;      /* step size */

    printf("Celsius    Farenheit\n");
    printf("--------------------\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius / (5.0 / 9.0)) + 32;
        printf("%7.0f    %9.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}


#include <stdio.h>

#define CAPITAL_MIN 65
#define CAPTIAL_MAX 90
#define LOWER_MIN 97

/* lower: converts upper case letters to lower case */
int lower(int c)
{
    c = (c >= CAPITAL_MIN && c <+ CAPTIAL_MAX) ? c + (LOWER_MIN - CAPITAL_MIN): c; 

    return c;
}

int main()
{
    int c;

    while ((c = getchar()) != EOF) {
        printf("%c", lower(c));
    }

    return 0;
}

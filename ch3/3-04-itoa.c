#include <limits.h>
#include <stdio.h>
#include <string.h>


void reverse(char *str)
{
    int i,
        j,
        end = strlen(str) - 1,
        mid = end / 2;

    for (i = 0, j = end; i <= mid; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    return;
}


/* itoa: convert n to characters in s */
void itoa(int n, char *str)
{
    int i, sign;

    /* making the largest negative number positive will make it one greater */
    /* than the largest positive number because of zero */
    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    do {
        str[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if (sign < 0) {
        str[i++] = '-';
    }
    str[i] = '\0';

    reverse(str);

    return;
}


int main(void)
{
    char str[10] = "";

    itoa(-20, str);
    /* reverse(str); */
    printf("%s\n", str);

    return 0;
}

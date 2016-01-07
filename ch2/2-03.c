#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int htoi(char s[]);
void rm0x(char s[], int s_len);

int main()
{
    char s[6] = "4F"; /* sample string of hexadecimal digits */

    printf("decimal: %d\n", htoi(s));

    return 0;
}

/* converts a string of hexadecimal digits into its equivalent integer value */
int htoi(char s[])
{
    int i, j, k;
    int s_int, pow_sixteen;
    int decimal = 0;

    rm0x(s, strlen(s));

    k = strlen(s) - 1;
    for (i = 0; i < strlen(s); i++) {
        /* convert hex digits to decimals using ASCII values: asciitable.com */
        if ((s[i] >= 48) && (s[i] <= 57)) {
            s[i] -= 48;
        }
        if ((s[i] >= 65) && (s[i] <= 70)) {
            s[i] -= 65 - 10;
        }
        if ((s[i] >= 97) && (s[i] <= 102)) {
            s[i] -= 97 - 10;
        }

        s_int = s[i]; 

        pow_sixteen = 1;
        for (j = k; j > 0; j--) {
            pow_sixteen = pow_sixteen * 16; 
        }
        s_int = s_int * pow_sixteen;
        decimal = decimal + s_int;

        k--;
    }

    return decimal;
}

/* remove 0x or 0X from the beginning of a string */
void rm0x(char s[], int s_len)
{
    int i, j;

    if ((s[0] == '0') && ((s[1] == 'x') || (s[1] == 'X'))) {
        i = 0;
        for (j = 2; j < s_len; j++) {
            s[i] = s[j];
            i++;     
        }
        s[i] = '\0';
    }

    return;
}


#include <stdio.h>

/* When x is odd, x & x - 1 = x -1 e.g., x = 3, 11 & 10 = 10
 * When x is even, the rightmost 0 becomes a 1, and then anding it with x - 1
 * clears the rightmost 1 e.g., x = 2, 10 & 01 = 00 */

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= x - 1) {
        b++;
    }

    return b;
}

int main()
{
    printf("%d\n", bitcount(80));

    return 0;
}

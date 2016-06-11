#include <stdio.h>
#include <string.h>

/* set n bits from position p to the rightmost n bits of y */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    x = (x >> (p + 1 - n)) & ~(~0 << n);
    y = y >> n;
    y = y << n;
    x = x | y;

    return x;
}

int main()
{
    printf("%d\n", setbits(60, 4, 3, 80));

    return 0;
}

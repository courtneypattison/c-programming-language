#include <stdio.h>

unsigned getInvertedbits(unsigned x, int p, int n)
{
    return ((~x >> (p + 1 - n)) & ~(~0 << n)) << (p + 1 - n);
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned inverted, mask, x_mask;

	mask = 0;
    mask = (~mask << n) << (p + 1 - n) | ~(~0 << (p + 1 - n));

	x_mask = x & mask;

    inverted = getInvertedbits(x, p, n);
	inverted |= x_mask;

    return inverted;
}

int main()
{
    printf("%d\n", invert(80, 4, 3));

    return 0;
}

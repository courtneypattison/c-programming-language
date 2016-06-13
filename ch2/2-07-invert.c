#include <stdio.h>

unsigned getbits(unsigned x, int p, int n)
{
    return (~x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned invert(unsigned x, int p, int n)
{
    x = getbits(x, p, n);

    x = x << (p + 1 - n);
    

    return x;
}

int main()
{
    printf("%d\n", invert(80, 4, 3));

    return 0;
}

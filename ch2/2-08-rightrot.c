#include <stdio.h>
#include <limits.h>

void print_bits(unsigned int x)
{
    int i;
    for(i=8*sizeof(x)-1; i>=0; i--) {
        (x & (1 << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

unsigned rightrot(unsigned x, int n)
{
    unsigned to_rotate, x_shifted, to_rotate_shifted, x_rotated;

    x_shifted = x >> n;
    to_rotate = x_shifted & ~(~0 << n);
    to_rotate_shifted = x << ((CHAR_BIT * sizeof x) - n);
    x_rotated = x_shifted | to_rotate_shifted; 

    return x_rotated;
}

int main()
{
    printf("%d\n", rightrot(60, 4));

    return 0;
}

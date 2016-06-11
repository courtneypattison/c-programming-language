#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

long smin(int num_bits);
long smax(int num_bits);
unsigned long umax(int num_bits);

/* determines the ranges of char, short, int, and long variable, both signed and
 * unsigned, as well as ranges for various floating-point types */
int main()
{
    const int UMIN = 0;
    const int CBITS = 8;
    const int SBITS = 16;
    const int IBITS = 32;
    const int LBITS = 64;

    printf("-----------------------------------------------------------\n");
    printf("Type limits                      min - max\n");
    printf("-----------------------------------------------------------\n");
    printf("Values from standard headers\n");
    printf("-----------------------------------------------------------\n");
    printf("char:           %20d - %-20d\n", CHAR_MIN, CHAR_MAX);
    printf("signed char:    %20d - %-20d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char:  %20d - %-20u\n", UMIN, UCHAR_MAX);
    printf("short:          %20d - %-20d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: %20d - %-20u\n", UMIN, USHRT_MAX);
    printf("int:            %20d - %-20d\n", INT_MIN, INT_MAX);
    printf("unsigned int:   %20d - %-20u\n", UMIN, UINT_MAX);
    printf("long:           %20ld - %-20ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long:  %20d - %-20lu\n", UMIN, ULONG_MAX);
    printf("\n");
    printf("float:          %20E - %-20E\n", FLT_MIN, FLT_MAX);
    printf("float exp:      %20d - %-20d\n", FLT_MIN_EXP, FLT_MAX_EXP);
    printf("double:         %20E - %-20E\n", DBL_MIN, DBL_MAX);
    printf("double exp:     %20d - %-20d\n", DBL_MIN_EXP, DBL_MAX_EXP);
    printf("-----------------------------------------------------------\n");
    printf("Values by direct computation\n");
    printf("-----------------------------------------------------------\n");
    printf("char:           %20ld - %-20ld\n", smin(CBITS), smax(CBITS));
    printf("signed char:    %20ld - %-20ld\n", smin(CBITS), smax(CBITS));
    printf("unsigned char:  %20d - %-20lu\n", UMIN, umax(CBITS));
    printf("short:          %20ld - %-20ld\n", smin(SBITS), smax(SBITS));
    printf("unsigned short: %20d - %-20lu\n", UMIN, umax(SBITS));
    printf("int:            %20ld - %-20ld\n", smin(IBITS), smax(IBITS));
    printf("unsigned int:   %20d - %-20lu\n", UMIN, umax(IBITS));
    printf("long:           %20ld - %-20ld\n", smin(LBITS), smax(LBITS));
    printf("unsigned long:  %20d - %-20lu\n", UMIN, umax(LBITS));

    return 0;
}

/* return the minimum of a signed type */
long smin(int num_bits)
{
    int i;
    long smin = 1l;

    for (i = 0; i < num_bits - 1; i++) {
        smin = smin * 2l * -1;
    }

    return smin;
}

/* return the maximum of a signed type */
long smax(int num_bits)
{
    int i;
    long smax = 1l;

    for (i = 0; i < num_bits - 1; i++) {
        smax = smax * 2l;
    }

    return smax - 1l;
}

/* return the maximum of an unsigned type */
unsigned long umax(int num_bits)
{
    int i;
    unsigned long umax = 1ul;

    for (i = 0; i < num_bits; i++) {
        umax = umax * 2ul;
    }

    return umax - 1ul;
}


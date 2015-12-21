#include <stdio.h>

/* Counts blanks, tabs, and newlines */
main()
{
    int c, nb, nt, nn;

    nb = 0;
    nt = 0;
    nn = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nn;
    }
    printf("No. blanks: %d\n", nb);
    printf("No. tabs: %d\n", nt);
    printf("No. newlines: %d\n", nn);
}


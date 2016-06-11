#include <stdio.h>

/* prints input one word per line */
main()
{
    int c;
    int prev_c = 0;

    while ((c = getchar()) != EOF) {
        if ((prev_c == ' ' || prev_c == '\n' || prev_c == '\t') &&
            (c == ' ' || c == '\n' || c == '\t')) {
        } else if (c == ' ' || c == '\n' || c == '\t') {
            putchar('\n');
        } else {
            putchar(c);
        }
        prev_c = c;
    }
    putchar('\n');
}


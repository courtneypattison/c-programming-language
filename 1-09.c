#include <stdio.h>

main()
{
    int c, prev_c;

    while((c = getchar()) != 'EOF') {
        if (prev_c == ' ') {
            prev_c = c;
            continue;
        }
        putchar(c);
        prev_c = c;
    }
    printf("\n");
}


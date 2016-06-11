#include <stdio.h>

int main()
{
    int i, c;
    int lim = 1000;
    char [lim];

    for (i = 0; i < lim - 1; i++) {
        if ((c = getchar()) == '\n') break;
        if (c == EOF) break;
        s[i] = c;
    }

    return 0;
}


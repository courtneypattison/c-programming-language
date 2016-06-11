#include <stdio.h>

/* replaces tabs in the input with the proper number of blanks to space to the
 * next tab stop */
int main()
{
    int c, i;
    const int tab_width = 3; /* number of spaces per tab in my terminal */  

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i = 0; i < tab_width; i++) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }

    return 0;
}


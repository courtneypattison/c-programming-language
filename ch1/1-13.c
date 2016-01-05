#include <stdio.h>
#include <string.h>

main()
{
    char c;
    int i, str_len;

    str_len = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            putchar('\n');
            for (i = 0; i < str_len; i++) {
                putchar('-');
            }
            str_len = 0;
        } else {
            str_len++;
        }
    }
    putchar('\n');
}

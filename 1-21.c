#include <stdio.h>

/* replaces strings of blanks by the minimum number of tabs and blanks to
 * achieve the same spacing */
int main()
{
    int c, i, j;
    int num_spaces, num_tabs, remaining_spaces;
    const int TAB_WIDTH = 3; /* number of spaces per tab in my terminal */  

    num_spaces = num_tabs = remaining_spaces = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            num_spaces++;
        } else {
            num_tabs = num_spaces / TAB_WIDTH;
            remaining_spaces = num_spaces % TAB_WIDTH;
            for (i = 0; i < num_tabs; i++) {
                printf("ttt");
            }
            for (j = 0; j < remaining_spaces; j++) {
                putchar('s'); 
            }
            putchar(c);
            num_spaces = num_tabs = remaining_spaces = 0;
        }
    }

    return 0;
}


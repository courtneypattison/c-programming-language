#include <stdio.h>

/* removes all comments from a C program */
int main()
{
    int c, prev_c;
    const int TRUE = 2;
    const int END = 1;
    const int FALSE = 0;
    int in_string = FALSE;
    int in_comment = FALSE;

    prev_c = '\0';
    while ((c = getchar()) != EOF) {
        if ((prev_c == '"') && (in_string == FALSE)) {
            in_string = TRUE;
        } else if ((prev_c == '"') && (in_string == TRUE)) {
            in_string = FALSE;
        }

        if ((prev_c == '/') && (c == '*') && (in_comment == FALSE) &&
            (in_string == FALSE)) {
            in_comment = TRUE; 
        } else if ((prev_c == '*') && (c == '/') && (in_comment == TRUE)) {
            in_comment = END;
            continue;
        }

        if ((in_comment == FALSE) && (prev_c != '\0')) {
            putchar(prev_c);
        } 
        if (in_comment == END) {
            in_comment = FALSE;
        }

        prev_c = c;
    }   
    printf("%c\n", prev_c);

    return 0;
}


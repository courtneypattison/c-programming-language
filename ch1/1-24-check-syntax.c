#include <stdio.h>

int check_balanced(int c, char begin_c, char end_c, int count);
int print_unbalanced(int count, char name[]);

/* check a C program for rudimentary syntax errors like unbalanced parentheses,
 * brackets, and braces */
int main()
{
    int c, prev_c;
    int paren, bracket, brace, s_quote, d_quote, comment;

    const int TRUE = 2;
    const int END = 1;
    const int FALSE = 0;
    int in_quote = FALSE;
    int in_comment = FALSE;

    prev_c = '\0';
    paren = bracket = brace = s_quote = d_quote = comment = 0;

    while ((c = getchar()) != EOF) {
        if (((prev_c == '"') || (prev_c == '\'')) && (in_quote == FALSE)) {
            in_quote = TRUE;
        } else if (((prev_c == '"') || (prev_c == '\'')) && (in_quote == TRUE)) {
            in_quote = FALSE;
        }

        if ((prev_c == '/') && (c == '*') && (in_comment == FALSE) &&
            (in_quote == FALSE)) {
            in_comment = TRUE; 
            comment++;
        } else if ((prev_c == '*') && (c == '/') && (in_comment == TRUE)) {
            in_comment = END;
            comment--;
            continue;
        }
        if (comment < 0) {
            comment++;
        }

        if ((in_quote == FALSE) && (in_comment == FALSE) && (prev_c != '\0')) {
            paren = check_balanced(c, '(', ')', paren);
            bracket = check_balanced(c, '[', ']', bracket);
            brace = check_balanced(c, '{', '}', brace);
            s_quote = check_balanced(c, '\'', '\'', s_quote);
            d_quote = check_balanced(c, '"', '"', d_quote);
        } 

        if (in_comment == END) {
            in_comment = FALSE;
        }
        
        prev_c = c;
    }

    print_unbalanced(paren, "Parentheses");
    print_unbalanced(bracket, "Brackets");
    print_unbalanced(brace, "Braces");
    print_unbalanced(s_quote, "Single quotation marks");
    print_unbalanced(d_quote, "Double quotation marks");
    print_unbalanced(comment, "Comments");

    return 0;
}

int check_balanced(int c, char begin_c, char end_c, int count)
{
    if (c == begin_c) {
        count++;
    } else if (c == end_c) {
        count--;
    }

    if (count < 0) {
        count++;
    }

    return count;
}

int print_unbalanced(int count, char name[])
{
    if (count) {
        printf("%s are unbalanced.\n", name);
    }

    return count;
}


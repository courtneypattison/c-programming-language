#include <stdio.h>

/* "fold" long input lines into two or more shorter lines after the last
 * non-blank character */
int main()
{
    int c, i;
    int c_count = 0;
    const int TEXT_WIDTH = 80; /* max width of text being printed per line */
    const int MAX_LEN = 128; /* longest word in a major dictionary is 45 chars */
    char word[MAX_LEN];

    i = 0;
    while ((c = getchar())) {
        if ((c != ' ') && (c != '\t') && (c != '\n')) {
            word[i] = c;
            i++;
        } else {
            if (c_count > TEXT_WIDTH) {
                c_count = 0 + i;
                printf("\n");
            }
            word[i] = '\0';
            printf("%s%c", word, c);
            i = 0;
        }

        if (i == TEXT_WIDTH) {
            word[i] = '\0';
            printf("%s-\n", word);
            i = 0;
        }

        if (c == EOF) {
            if (c_count > TEXT_WIDTH) {
                printf("\n");
            }
            word[i - 1] = '\0';
            printf("%s\n", word);
            break;
        }

        c_count++;
    }

    return 0;
}


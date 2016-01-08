#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    int match_loc;
    char s1[] = "Hello";
    char s2[] = "yo";

    match_loc = any(s1, s2);
    printf("%d\n", match_loc);

    return 0;
}

/* returns the first location in the string s1 where any character from the
 * string s2 occurs, or -1 if s1 contains no characters from s2 */
int any(char s1[], char s2[])
{
    int i, j, k;
    const int TRUE = 1;
    const int FALSE = 0;
    int match = FALSE;
    int match_loc = -1;

    for (i = j = 0; s1[i] != '\0'; i++) {
        match = FALSE;
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                match = TRUE;
                match_loc = i;
            }
        }
        if (match == TRUE) {
            break;
        }
    }

    return match_loc;
}


#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main()
{
    char s1[] = "Hello";
    char s2[] = "yo";

    squeeze(s1, s2);
    printf("%s\n", s1);

    return 0;
}

/* delete each character in s1 that matches any character from s2 */
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    const int TRUE = 1;
    const int FALSE = 0;
    int match = FALSE;

    for (i = j = 0; s1[i] != '\0'; i++) {
        match = FALSE;
        for (k = 0; s2[k] != '\0'; k++) {
            if (s1[i] == s2[k]) {
                match = TRUE;
            }
        }
        if (match == FALSE) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';

    return;
}


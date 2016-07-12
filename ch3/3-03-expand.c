#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[])
{
    int i, j, s1len;

    s1len = strlen(s1);
    for (i = j = 0; i < s1len; i++) {
        if (s1[i] == '-') {
            if (i == 0 || i == s1len - 1) {
                s2[j] = '-';
                j++;
            } else {
                int k;

                for (k = s1[i - 1] + 1; k < s1[i + 1]; k++, j++) {
                    s2[j] = k;
                }
            }
        } else {
            s2[j] = s1[i];
            j++;
        }
    }
    s2[j] = '\0';

    return;
}

int main()
{
    char s1[10] = "a-z0-9";
    char s2[100];

    expand(s1, s2);
    printf("%s\n", s2);

    return 0;
}

#include <stdio.h>

/* Print histogram of the frequencies of different characters in input */
int main()
{
    int c;
    char arr_c[100];
    int tot_num_c = 0;

    while ((c = getchar()) != EOF) {
        arr_c[tot_num_c] = c;
        tot_num_c++;
    }

    int i, j, k;
    int freq_c, not_first;

    for (i = 0; i < tot_num_c; i++) {
        freq_c = 0;
        not_first = 0;

        for (j = 0; j < tot_num_c; j++) {
            if (arr_c[i] == arr_c[j]) {
                freq_c++;
                if (i > j) {
                    not_first = 1;
                }
            }
        }

        if (not_first) {
            continue;
        } else {
            printf("%c", arr_c[i]);
            for (k = 0; k < freq_c; k++) {
                printf("-");
            }
            printf("\n");
        }
    }
}


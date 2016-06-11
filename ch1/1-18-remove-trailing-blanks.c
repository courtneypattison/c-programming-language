#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int get_line(char line[], int maxline);

/* remove trailing blanks and tabs from each line of input, and delete entirely 
   blank lines */
int main()
{
	int i;
    int len;    /* current line length */
    char line[MAXLINE];     /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
		for (i = len; i >= 0; i--) {
			if (((line[i] == ' ') || (line[i] == '\t') || (line[i] == '\n')) &&
				(line[i + 1] == '\0')) {
				len--;
				line[len] = '\0';
			}
		}
    	printf("%s", line);
    }

    return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}


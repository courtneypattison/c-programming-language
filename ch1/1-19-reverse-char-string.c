#include <stdio.h>
#define MAXLINE 1000    /* maximum input line size */

int get_line(char line[], int maxline);
void reverse_line(char line[], char reversed_line[], int line_len);

/* reverses input a line at a time */
int main()
{
	int i;
    int len;    /* current line length */
    char line[MAXLINE];     /* current input line */
    char reversed_line[MAXLINE];

    while ((len = get_line(line, MAXLINE)) > 0) {
        reverse_line(line, reversed_line, len); 
    	printf("%s", reversed_line);
    }

    return 0;
}

/* get_line: read a line into s, return length */
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

/* reverse_line: reverses the character string s */
void reverse_line(char s[], char reversed_s[], int len)
{
    int i, j;

    j = len - 1;
    for (i = 0; i < len; i++) {
        reversed_s[i] = s[j];        
        j--;
    }
    reversed_s[len] = '\0';

    return;
}


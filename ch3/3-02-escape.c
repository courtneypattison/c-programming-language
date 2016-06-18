#include <stdio.h>

/* escape: converts characters like newline and tab into visible escape
 * sequences like \n and \t as it copies the string t to s */
void escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[j] != '\0'; i++) {
        switch (t[j]) {
        case '\a':
            s[i++] = '\\';
            s[i] = 'a';
            break;
        case '\b':
            s[i++] = '\\';
            s[i] = 'b';
            break;
        case '\f':
            s[i++] = '\\';
            s[i] = 'f';
            break;
        case '\n':
            s[i++] = '\\';
            s[i] = 'n';
            break;
        case '\r':
            s[i++] = '\\';
            s[i] = 'r';
            break;
        case '\t':
            s[i++] = '\\';
            s[i] = 't';
            break;
        case '\v':
            s[i++] = '\\';
            s[i] = 'v';
            break;
        default:
            s[i] = t[j];
            break;
        }
        j++;
    }
    s[i] = t[j];

    return;
}

/* dont_escape: converts visible escape sequences like \n and \t to real
 * real characters as it copies the string t to s */
void dont_escape(char s[], char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; i++) {
        if (t[i] == '\\') {
            switch (t[i + 1]) {
            case 'a':
                s[j] = '\a';
                break;
            case 'b':
                s[j] = '\b';
                break;
            case 'f':
                s[j] = '\f';
                break;
            case 'n':
                s[j] = '\n';
                break;
            case 'r':
                s[j] = '\r';
                break;
            case 't':
                s[j] = '\t';
                break;
            case 'v':
                s[j] = '\v';
                break;
            default:
                s[j] = t[i];
                break;
            }
            i++;
        } else {
            s[j] = t[i];
        }
        j++;
    }
    s[j] = t[i];

    return;
}

int main()
{
    char s[20];
    char t[20] = "1:\tYo\ffoo\n";

    char s2[20];
    char t2[20] = "1:\\tYo\\ffoo\\n";

    escape(s, t);
    printf("%s\n", s);

    dont_escape(s2, t2);
    printf("%s\n", s2);

    return 0;
}

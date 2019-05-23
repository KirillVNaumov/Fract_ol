#include "calc.h"

char        *clear_spaces(char *str)
{
    int     i;
    int     j;
    char    *new;

    j = 0;
    i = -1;
    while (str[++i])
        if (str[i] != ' ')
            ++j;
    new = (char *)malloc(sizeof(char) * (j + 1));
    i = -1;
    j = 0;
    while (str[++i])
        if (str[i] != ' ')
            new[j++] = str[i];
    new[j] = '\0';
    free(str);
    return new;
}
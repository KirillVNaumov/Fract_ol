#include "fractol.h"

char       *str_to_low(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        ++i;
    }
    return (str);
}

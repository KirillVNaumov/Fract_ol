#include "fractol.h"

char       *str_to_header(char *str)
{
    str = str_to_low(str);
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    return (str);
}

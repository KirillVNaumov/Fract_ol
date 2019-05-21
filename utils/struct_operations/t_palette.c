#include "fractol.h"

t_palette   *new_palette(void)
{
    t_palette   *new;

    new = (t_palette *)malloc(sizeof(t_palette));
    new->color = (t_color *)malloc(sizeof(t_color));
    new->color->red = 0;
    new->color->green = 0;
    new->color->blue = 0;        
    new->next = NULL;
    return (new);
}
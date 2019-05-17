#include "fractol.h"

t_palette   *new_palette(void)
{
    t_palette   *new;
    int         index;

    new = (t_palette *)malloc(sizeof(t_palette));
    new->color = (t_color **)malloc(sizeof(t_color *) * 16);
    index = 0;
    while (index < 15)
    {
        new->color[index] = (t_color *)malloc(sizeof(t_color));
        new->color[index]->red = 0;
        new->color[index]->green = 0;
        new->color[index]->blue = 0;        
        ++index;
    }
    new->color[index] = NULL;
    new->next = NULL;
    return (new);
}
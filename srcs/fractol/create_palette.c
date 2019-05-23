#include "fractol.h"

void        create_psychedelic(t_fractol *fractol)
{
    int     i;

    i = 0;
    fractol->psychedelic_palette = (t_color **)malloc(sizeof(t_color *) * 11);
    fractol->psychedelic_palette[10] = NULL;
    while (i < 10)
        fractol->psychedelic_palette[i++] = (t_color *)malloc(sizeof(t_color));
    fractol->psychedelic_palette[0]->red = 41;
    fractol->psychedelic_palette[0]->green = 44;
    fractol->psychedelic_palette[0]->blue = 232;

    fractol->psychedelic_palette[1]->red = 242;
    fractol->psychedelic_palette[1]->green = 187;
    fractol->psychedelic_palette[1]->blue = 7;

    fractol->psychedelic_palette[2]->red = 175;
    fractol->psychedelic_palette[2]->green = 7;
    fractol->psychedelic_palette[2]->blue = 242;

    fractol->psychedelic_palette[3]->red = 52;
    fractol->psychedelic_palette[3]->green = 242;
    fractol->psychedelic_palette[3]->blue = 7;

    fractol->psychedelic_palette[4]->red = 242;
    fractol->psychedelic_palette[4]->green = 7;
    fractol->psychedelic_palette[4]->blue = 7;

    fractol->psychedelic_palette[5]->red = 33;
    fractol->psychedelic_palette[5]->green = 6;
    fractol->psychedelic_palette[5]->blue = 165;

    fractol->psychedelic_palette[6]->red = 244;
    fractol->psychedelic_palette[6]->green = 239;
    fractol->psychedelic_palette[6]->blue = 100;
    
    fractol->psychedelic_palette[7]->red = 174;
    fractol->psychedelic_palette[7]->green = 95;
    fractol->psychedelic_palette[7]->blue = 175;
    
    fractol->psychedelic_palette[8]->red = 21;
    fractol->psychedelic_palette[8]->green = 124;
    fractol->psychedelic_palette[8]->blue = 77;
        
    fractol->psychedelic_palette[9]->red = 219;
    fractol->psychedelic_palette[9]->green = 139;
    fractol->psychedelic_palette[9]->blue = 10;
}

void        create_palette(t_fractol *fractol)
{
    fractol->palette = new_palette();
    fractol->palette->color->green = 100;
    fractol->palette->color->blue = 180;
    fractol->palette->next = new_palette();
    fractol->palette->next->color->red = 150;
    fractol->palette->next->color->blue = 150;
    fractol->palette->next->color->green = 150;
    fractol->palette->next->next = new_palette();
    fractol->palette->next->next->color->green = 100;
    fractol->palette->next->next->color->red = 130;
    fractol->palette->next->next->next = new_palette();
    fractol->palette->next->next->next->color->blue = 180;
    fractol->palette->next->next->next->color->red = 20;
    fractol->palette->next->next->next->next = fractol->palette;
    create_psychedelic(fractol);
}
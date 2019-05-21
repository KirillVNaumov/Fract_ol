#include "fractol.h"

void        create_palette(t_fractol *fractol)
{
    fractol->palette = new_palette();
    fractol->palette->color->red = 150;
    fractol->palette->color->blue = 150;
    fractol->palette->color->green = 150;
    fractol->palette->next = new_palette();
    fractol->palette->next->color->green = 100;
    fractol->palette->next->color->blue = 180;
    fractol->palette->next->next = new_palette();
    fractol->palette->next->next->color->green = 100;
    fractol->palette->next->next->color->red = 130;
    fractol->palette->next->next->next = new_palette();
    fractol->palette->next->next->next->color->blue = 180;
    fractol->palette->next->next->next->color->red = 20;
    fractol->palette->next->next->next->next = fractol->palette;
}
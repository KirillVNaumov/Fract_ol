#include "fractol.h"

void        create_palette(t_fractol *fractol)
{
    fractol->palette = new_palette();
    fractol->palette->color[0]->red = 255; //WHITE
    fractol->palette->color[0]->green = 255;
    fractol->palette->color[0]->blue = 255;
    fractol->palette->color[1]->red = 255; //RED
    fractol->palette->color[1]->green = 0;
    fractol->palette->color[1]->blue = 0;
    fractol->palette->color[2]->red = 255; //ORANGE
    fractol->palette->color[2]->green = 127;
    fractol->palette->color[2]->blue = 0;
    fractol->palette->color[3]->red = 255; //YELLOW
    fractol->palette->color[3]->green = 255;
    fractol->palette->color[3]->blue = 0;
    fractol->palette->color[4]->red = 0; //GREEN
    fractol->palette->color[4]->green = 255;
    fractol->palette->color[4]->blue = 0;
    fractol->palette->color[5]->red = 0; //BLUE
    fractol->palette->color[5]->green = 0;
    fractol->palette->color[5]->blue = 255;
    fractol->palette->color[6]->red = 75; //INDIGO
    fractol->palette->color[6]->green = 0;
    fractol->palette->color[6]->blue = 130;
    fractol->palette->color[7]->red = 148; //VIOLET
    fractol->palette->color[7]->green = 0;
    fractol->palette->color[7]->blue = 211;
    fractol->palette->next = new_palette();
    fractol->palette->next->next = new_palette();
    fractol->palette->next->next->next = new_palette();
    fractol->palette->next->next->next->next = new_palette();
    fractol->palette->next->next->next->next->next = fractol->palette;
}
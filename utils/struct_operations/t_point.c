#include "fractol.h"

void        to_relative(t_point **absolute, t_fractol *fractol)
{
    (*absolute)->x += fractol->offset.x;
    (*absolute)->y += fractol->offset.y;
}

void        to_absolute(t_point **relative, t_fractol *fractol)
{
    (*relative)->x -= fractol->offset.x;
    (*relative)->y -= fractol->offset.y;
}
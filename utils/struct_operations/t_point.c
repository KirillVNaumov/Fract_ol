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

double			find_double_radius(t_point *pixel)
{
	return (pixel->x * pixel->x + pixel->y * pixel->y);
}
#include "fractol.h"

double			find_double_radius(t_point *pixel/*, int zoom*/)
{
	// double		x;
	// double		y;

	// x = (double)(pixel->x - WIN_WIDTH / 2) / zoom;
	// y = (double)(pixel->y - WIN_HEIGHT / 2) / zoom;
	// return (x * x + y * y);
	return (pixel->x * pixel->x + pixel->y * pixel->y);
}

t_color			*define_color(t_point *pixel, t_fractol *fractol)
{
	// t_fractol *tmp1;
	// t_point		*tmp2;
	// t_color		*ret;
	// tmp1 = fractol;
	// tmp2 = pixel;
	// ret = (t_color *)malloc(sizeof(t_color));
	// ret->red = (char)0;
	// ret->green = (char)0;
	// ret->blue = (char)0;
	// if (find_double_radius(pixel, fractol->zoom) >= 4)
	// 	return (fractol->palette->color[0]);
	// return ret;

	t_point		result_of_iteration;
	t_point		doppelganger;
	t_point		z_from_formula;
	t_color		*color;
	int			i;

	// ft_bzero(color, sizeof(t_color);
	color = (t_color *)malloc(sizeof(t_color));
	color->red = (char)0;
	color->green = (char)0;
	color->blue = (char)0;
	i = 0;
	z_from_formula.x = 0;
	z_from_formula.y = 0;
	doppelganger.x = (double)(pixel->x - WIN_WIDTH / 2) / fractol->zoom;
	doppelganger.y = (double)(pixel->y - WIN_HEIGHT / 2) / fractol->zoom;
	// pixel->x = (double)(pixel->x - WIN_WIDTH / 2) / fractol->zoom;
	// pixel->y = (double)(pixel->y - WIN_HEIGHT / 2) / fractol->zoom;
	while (i < fractol->iterations)
	{
		result_of_iteration.x = (z_from_formula.x * z_from_formula.x - z_from_formula.y * z_from_formula.y + doppelganger.x);
		result_of_iteration.y = (2 * z_from_formula.x * z_from_formula.y + doppelganger.y);
		if (find_double_radius(&result_of_iteration/*, fractol->zoom*/) >= 4)
			break ;
		z_from_formula.x = result_of_iteration.x;
		z_from_formula.y = result_of_iteration.y;
		++i;
	}
	if (i == fractol->iterations)
		return (color);
	while (i >= 16)
		i -= 16;
	return (fractol->palette->color[i]);
}

void			mandelbrot(t_fractol *fractol)
{
	t_point		*pixel;
	t_color		*pixel_color;
	int			pos;

	pixel = (t_point *)malloc(sizeof(t_point));
	pixel_color = (t_color *)malloc(sizeof(t_color));
	pixel->y = 0;
	while (pixel->y < WIN_HEIGHT)
	{
		pixel->x = 0;
		while (pixel->x < WIN_WIDTH)
		{
			// printf("x = %f y = %f\n", pixel->x, pixel->y);
			to_absolute(&pixel, fractol);
			pixel_color = define_color(pixel, fractol);
			to_relative(&pixel, fractol);
			pos = pixel->x * 4 + 4 * WIN_WIDTH * pixel->y;
			fractol->image.data[pos] = pixel_color->red;
			fractol->image.data[pos + 1] = pixel_color->green;
			fractol->image.data[pos + 2] = pixel_color->blue;			
			++pixel->x;
		}
		++pixel->y;
	}
	// free(pixel);
}
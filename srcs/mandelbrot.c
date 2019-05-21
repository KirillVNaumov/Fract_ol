#include "fractol.h"

int 			mandelbrot(t_point *pixel, t_fractol *fractol)
{
	t_point		result_of_iteration;
	t_point		doppelganger;
	t_point		z_from_formula;
	t_color		*color;
	int			i;

	color = (t_color *)malloc(sizeof(t_color));
	color->red = (char)0;
	color->green = (char)0;
	color->blue = (char)0;
	i = 0;
	z_from_formula.x = 0;
	z_from_formula.y = 0;
	doppelganger.x = (double)(pixel->x - WIN_WIDTH / 2) / fractol->zoom;
	doppelganger.y = (double)(pixel->y - WIN_HEIGHT / 2) / fractol->zoom;
	while (i < fractol->iterations)
	{
		result_of_iteration.x = (z_from_formula.x * z_from_formula.x - z_from_formula.y * z_from_formula.y + doppelganger.x);
		result_of_iteration.y = (2 * z_from_formula.x * z_from_formula.y + doppelganger.y);
		if (find_double_radius(&result_of_iteration) >= 4)
			break ;
		z_from_formula.x = result_of_iteration.x;
		z_from_formula.y = result_of_iteration.y;
		++i;
	}
	return (i);
}
#include "fractol.h"

int				julia(t_point pixel, t_fractol *fractol)
{
	t_point		result;
	t_point		constant;
	t_point		previous_result;
	int			i;

	i = 0;
	previous_result.x = (double)(pixel.x - WIN_WIDTH / 2) / fractol->zoom;
	previous_result.y = (double)(pixel.y - WIN_HEIGHT / 2) / fractol->zoom;
	constant.x = (double)(fractol->mouse.pos.x - WIN_WIDTH / 2) / fractol->zoom;
	constant.y = (double)(fractol->mouse.pos.y - WIN_HEIGHT / 2) / fractol->zoom;
	while (i < fractol->iterations)
	{
		result.x = (previous_result.x * previous_result.x - previous_result.y * previous_result.y + constant.x);
		result.y = (2 * previous_result.x * previous_result.y + constant.y);
		if (find_double_radius(&result) >= 4)
			break ;
		previous_result.x = result.x;
		previous_result.y = result.y;
		++i;
	}
	return (i);
}
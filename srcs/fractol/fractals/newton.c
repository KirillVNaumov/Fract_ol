#include "fractol.h"

double              find_distance(int x, int y)
{
    return (x * x + y * y);
}

int				newton(t_point pixel, t_fractol *fractol)
{
	double complex		result;
	double complex		previous_result;
    double              margin_error;
	int			i;

    margin_error = 0.01;
	i = 0;
    previous_result = ((double)(pixel.x - WIN_WIDTH / 2) / fractol->zoom) + ((double)(pixel.y - WIN_HEIGHT / 2) / fractol->zoom) * I;
	while (i < fractol->iterations)
	{
		result = function(previous_result) / derivative(previous_result);
        result = previous_result - result;
		if (find_distance(creal(result - previous_result), cimag(result - previous_result)) <= margin_error * margin_error)
			break ;
		previous_result = result;
		++i;
	}
	return (i);
}
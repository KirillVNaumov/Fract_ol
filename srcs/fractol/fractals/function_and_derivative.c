#include "fractol.h"

double complex		function(double complex z)
{
	return (1 * z * z * z + 1 * z * z - 1);
}
double complex		derivative(double complex z)
{
	return (3 * z * z + 2 * z);
}

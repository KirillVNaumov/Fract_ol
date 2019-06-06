#include "fractol.h"

double complex		function(double complex z)
{
	return (8 * z * z * z + 3 * z * z - 4);
}
double complex		derivative(double complex z)
{
	return (24 * z * z + 6 * z);
}

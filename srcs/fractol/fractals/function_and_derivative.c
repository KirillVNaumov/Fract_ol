#include "fractol.h"

double complex		function(double complex z)
{
	return (2 * z * z * z + 5 * z * z - 6 * z + 5);
}
double complex		derivative(double complex z)
{
	return (6 * z * z + 10 * z - 6);
}

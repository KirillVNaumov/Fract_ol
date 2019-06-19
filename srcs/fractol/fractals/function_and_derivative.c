#include "fractol.h"

COMPLEX		function(COMPLEX z)
{
	return (5 * z * z * z - 1);
}
COMPLEX		derivative(COMPLEX z)
{
	return (15 * z * z);
}

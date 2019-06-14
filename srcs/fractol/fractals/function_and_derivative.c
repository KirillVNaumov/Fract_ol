#include "fractol.h"

COMPLEX		function(COMPLEX z)
{
	return (4 * z * z * z * z * z * z * z * z + 42 * z * z - 3);
}
COMPLEX		derivative(COMPLEX z)
{
	return (32 * z * z * z * z * z * z * z + 84 * z);
}

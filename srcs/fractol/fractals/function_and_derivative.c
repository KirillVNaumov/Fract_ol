#include "fractol.h"

double complex      function(double complex z)
{
    return (3 * z * z * z + 2 * z * z + 10 * z - 3);
}

double complex      derivative(double complex z)
{
    return (9 * z * z + 4 * z + 10);
}
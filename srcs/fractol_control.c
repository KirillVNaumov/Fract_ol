#include "fractol.h"

int		keyboard_read(int key, t_fractol *fractol)
{
    if (key == 53)
		exit(0);
    fractol->type = 1;
	return (0);
}
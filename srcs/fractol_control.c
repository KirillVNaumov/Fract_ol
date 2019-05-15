#include "fractol.h"

int		keyboard_read(int key, t_fractol *fractol)
{
  if (key == KEY_ESCAPE)
	  exit(0);
  update_fractol(fractol);
	return (0);
}
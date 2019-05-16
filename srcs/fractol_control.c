#include "fractol.h"

int				mouse_read(int mousecode, int x, int y, t_fractol *fractol)
{
	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		if (mousecode == MOUSE_UP_SCRLL)
			fractol->zoom += 5;
		else if (mousecode == MOUSE_DOWN_SCRLL && fractol->zoom > 10)
			fractol->zoom -= 5;
    // else if (mousecode == MOUSE_LEFT_CLK)
		// 	fractol->mouse.state = (fractol->mouse.state == 1) ? 0 : 1;
		update_fractol(fractol);
	}
	return (0);
}

int		    keyboard_read(int key, t_fractol *fractol)
{
  if (key == KEY_ESCAPE)
	  exit(0);
  update_fractol(fractol);
	return (0);
}

// int				mouse_movement(int x, int y, t_fractol *fractol)
// {
// 	if (fractol->mouse.state == 1 && (x > 0 && y > 0) \
// 			&& (x < WIN_WIDTH && y < WIN_HEIGHT))
// 	{
// 		fractol->mouse.pos_x = x;
// 		fractol->mouse.pos_y = y;
// 	}
// 	return (0);
// }
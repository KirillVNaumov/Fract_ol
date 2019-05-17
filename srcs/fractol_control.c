#include "fractol.h"

int				mouse_press_hook(int mousecode, int x, int y, t_fractol *fractol)
{
	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		if (mousecode == MOUSE_UP_SCRLL)
			fractol->zoom += 5;
		else if (mousecode == MOUSE_DOWN_SCRLL && fractol->zoom > 10)
			fractol->zoom -= 5;
    else if (mousecode == MOUSE_LEFT_CLK)
    {
			fractol->mouse.state = 1;
      fractol->mouse.start.x = x;
      fractol->mouse.start.y = y;
    }
		update_fractol(fractol);
	}
	return (0);
}

int		    key_press_hook(int key, t_fractol *fractol)
{
  if (key == KEY_ESCAPE)
	  exit(0);
	if (key == KEY_SPACE)
		fractol->palette = fractol->palette->next;
	if (key == KEY_UPARROW)
		++fractol->iterations;
	if (key == KEY_DOWNARROW && fractol->iterations > 0)
		--fractol->iterations;
  update_fractol(fractol);
	return (0);
}

int				mouse_release_hook(int mousecode, int x, int y, t_fractol *fractol)
{
    if (mousecode == MOUSE_LEFT_CLK)
			fractol->mouse.state = 0;
		fractol->mouse.pos.x = x;
		fractol->mouse.pos.y = y;
		return (0);
}

int				motion_hook(int x, int y, t_fractol *fractol)
{
	if (fractol->mouse.state == 1 && (x > 0 && y > 0) \
			&& (x < WIN_WIDTH && y < WIN_HEIGHT))
	{
		fractol->offset.x = fractol->offset.x - (fractol->mouse.start.x - x) / 15;
		fractol->offset.y = fractol->offset.y - (fractol->mouse.start.y - y) / 15;
	}
  update_fractol(fractol);
	return (0);
}
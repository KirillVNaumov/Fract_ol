#include "fractol.h"

int				mouse_press_hook(int mousecode, int x, int y, t_fractol *fractol)
{
  ft_printf("In mouse_press_hook\n");
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
			ft_printf("start.x = %d\nstart.y = %d\n\n", fractol->mouse.start.x, fractol->mouse.start.y);      
    }
		update_fractol(fractol);
	}
	return (0);
}

int		    key_press_hook(int key, t_fractol *fractol)
{
  if (key == KEY_ESCAPE)
	  exit(0);
  update_fractol(fractol);
	return (0);
}

int				mouse_release_hook(int mousecode, int x, int y, t_fractol *fractol)
{
  // ft_printf("In mouse_release_hook\n");
	// if (fractol->mouse.state == 1 && (x > 0 && y > 0) \
	// 		&& (x < WIN_WIDTH && y < WIN_HEIGHT))
	// {
    if (mousecode == MOUSE_LEFT_CLK)
			fractol->mouse.state = 0;
		fractol->mouse.pos.x = x;
		fractol->mouse.pos.y = y;
	// }
  // ft_printf("mouse state = %d\n", fractol->mouse.state);
	return (0);
}

int				motion_hook(int x, int y, t_fractol *fractol)
{
  // ft_printf("In motion_hook\n");
	if (fractol->mouse.state == 1 && (x > 0 && y > 0) \
			&& (x < WIN_WIDTH && y < WIN_HEIGHT))
	{
		fractol->offset.x = fractol->offset.x - (fractol->mouse.start.x - x) / 15;
		fractol->offset.y = fractol->offset.y - (fractol->mouse.start.y - y) / 15;
	}
  update_fractol(fractol);
	// ft_printf("offset.x = %d\noffset.y = %d\n\n", fractol->offset.x, fractol->offset.y);
	return (0);
}
#include "fractol.h"

void        add_axis(t_fractol *fractol)
{
    int     i;
    int     pos;

    i = 0;
    while (i < WIN_HEIGHT)
    {
        pos = WIN_WIDTH / 2 * 4 + 4 * WIN_WIDTH * i;
        fractol->image.data[pos] = (char)255;
        fractol->image.data[pos + 1] = (char)255;
        fractol->image.data[pos + 2] = (char)255;
        ++i;
    }
    i = 0;
    while (i < WIN_WIDTH)
    {
        pos = i * 4 + 4 * WIN_WIDTH * WIN_HEIGHT / 2;
        fractol->image.data[pos] = (char)255;
        fractol->image.data[pos + 1] = (char)255;
        fractol->image.data[pos + 2] = (char)255;
        ++i;
    }
}

void        update_fractol(t_fractol *fractol)
{

    add_axis(fractol);

    mlx_put_image_to_window(fractol->mlx.init, fractol->mlx.win, \
								fractol->mlx.img, 0, 0);
    mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 5, 0xFFFFFF, \
                        ft_strjoin("Number of iterations : ", ft_itoa(fractol->iterations)));
    mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 35, 0xFFFFFF, \
                        ft_strjoin("Zoom level: ", ft_itoa(fractol->zoom)));
}
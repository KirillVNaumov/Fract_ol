#include "fractol.h"

void        draw_vertical_dash(int x, int y, t_fractol *fractol)
{
    int     i;
    int     pos;
    int     init_pos;
    int     actual_size;

    if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
        return ;
    i = -10;
    init_pos = x * 4 + 4 * WIN_WIDTH * y;
    actual_size = WIN_WIDTH * 4 + 4 * WIN_WIDTH * WIN_HEIGHT;
    while (i < 10)
    {
        pos = init_pos + 4 * WIN_WIDTH * i;
        ++i;
        if (pos < 0 || pos > /*fractol->image.size*/actual_size)
            continue ;
        fractol->image.data[pos] = (char)255;
        fractol->image.data[pos + 1] = (char)255;
        fractol->image.data[pos + 2] = (char)255;
    }
}

void        draw_horizontal_dash(int x, int y, t_fractol *fractol)
{
    int     i;
    int     pos;
    int     init_pos;
    int     actual_size;

    i = -10;
    init_pos = x * 4 + 4 * WIN_WIDTH * y;
    actual_size = WIN_WIDTH * 4 + 4 * WIN_WIDTH * WIN_HEIGHT;
    while (i < 10)
    {
        pos = init_pos + 4 * i;
        ++i;
        if (x + i < 0 || x + i > WIN_WIDTH)
            continue ;
        fractol->image.data[pos] = (char)255;
        fractol->image.data[pos + 1] = (char)255;
        fractol->image.data[pos + 2] = (char)255;
    }
}


void        add_units(t_fractol *fractol)
{
    int     i;

    if (fractol->origin.x + fractol->offset.x > 0 && fractol->origin.x + fractol->offset.x < WIN_WIDTH)
    {
          i = fractol->origin.y + fractol->offset.y;
          if (i > WIN_HEIGHT)
          {
            while (i > WIN_HEIGHT)
                i -= fractol->zoom;
            while (i > 0)
            {
                draw_horizontal_dash(fractol->origin.x + fractol->offset.x, i, fractol);
                i -= fractol->zoom;
            }
          }
          else if (i < 0)
          {
            while (i < 0)
                i += fractol->zoom;
            while (i < WIN_HEIGHT)
            {
                draw_horizontal_dash(fractol->origin.x + fractol->offset.x, i, fractol);
                i += fractol->zoom;
            }
          }
          else
          {
            while (i > 0)
            {
                draw_horizontal_dash(fractol->origin.x + fractol->offset.x, i, fractol);
                i -= fractol->zoom;
            }
            i = fractol->origin.y + fractol->offset.y;
            while (i < WIN_HEIGHT)
            {
                draw_horizontal_dash(fractol->origin.x + fractol->offset.x, i, fractol);
                i += fractol->zoom;
            }
          }
    }
    if (fractol->origin.y + fractol->offset.y > 0 && fractol->origin.y + fractol->offset.y < WIN_HEIGHT)
    {
          i = fractol->origin.x + fractol->offset.x;
          if (i > WIN_WIDTH)
          {
            while (i > WIN_WIDTH)
                i -= fractol->zoom;
            while (i > 0)
            {
                draw_vertical_dash(i, fractol->origin.y + fractol->offset.y, fractol);
                i -= fractol->zoom;
            }
          }
          else if (i < 0)
          {
            while (i < 0)
                i += fractol->zoom;
            while (i < WIN_WIDTH)
            {
                draw_vertical_dash(i, fractol->origin.y + fractol->offset.y, fractol);
                i += fractol->zoom;
            }
          }
          else
          {
            while (i > 0)
            {
                draw_vertical_dash(i, fractol->origin.y + fractol->offset.y, fractol);
                i -= fractol->zoom;
            }
            i = fractol->origin.x + fractol->offset.x;
            while (i < WIN_WIDTH)
            {
                draw_vertical_dash(i, fractol->origin.y + fractol->offset.y, fractol);
                i += fractol->zoom;
            }
          }
    }
}

void        add_axis(t_fractol *fractol)
{
    int     i;
    int     pos;

    i = 0;
    if (fractol->origin.x + fractol->offset.x > 0 && fractol->origin.x + fractol->offset.x < WIN_WIDTH)
        while (i < WIN_HEIGHT)
        {
            pos = (fractol->origin.x + fractol->offset.x) * 4 + 4 * WIN_WIDTH * i;
            fractol->image.data[pos] = (char)255;
            fractol->image.data[pos + 1] = (char)255;
            fractol->image.data[pos + 2] = (char)255;
            ++i;
        }
    i = 0;
    if (fractol->origin.y + fractol->offset.y > 0 && fractol->origin.y + fractol->offset.y < WIN_HEIGHT)
        while (i < WIN_WIDTH)
        {
            pos = i * 4 + 4 * WIN_WIDTH * (fractol->origin.y + fractol->offset.y);
            fractol->image.data[pos] = (char)255;
            fractol->image.data[pos + 1] = (char)255;
            fractol->image.data[pos + 2] = (char)255;
            ++i;
        }
    add_units(fractol);
}

void        clear_image(t_fractol *fractol)
{
    int     i;
    int     j;
    int     pos;

    i = 0;
    while (i < WIN_HEIGHT)
    {
        j = 0;
        while (j < WIN_WIDTH)
        {
            pos = j * 4 + 4 * WIN_WIDTH * i;
            fractol->image.data[pos] = (char)0;
            fractol->image.data[pos + 1] = (char)0;
            fractol->image.data[pos + 2] = (char)0;
            ++j;
        }
        ++i;
    }
}

void        load_fractal(t_fractol *fractol)
{
    if (fractol->type == 1)
        mandelbrot(fractol);
    else if (fractol->type == 2)
        julia(fractol);
}

void        update_fractol(t_fractol *fractol)
{

    clear_image(fractol);
    load_fractal(fractol);
    // add_axis(fractol);

    mlx_put_image_to_window(fractol->mlx.init, fractol->mlx.win, \
								fractol->mlx.img, 0, 0);
    mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 5, 0xFFFFFF, \
                        ft_strjoin("Number of iterations : ", ft_itoa(fractol->iterations)));
    mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 35, 0xFFFFFF, \
                        ft_strjoin("Zoom level: ", ft_itoa(fractol->zoom)));
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:29:41 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/21 13:39:19 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		clear_image(t_fractol *fractol)
{
	int	i;
	int	j;
	int	pos;

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

t_color		define_color(int depth, t_fractol *fractol)
{
	t_color	color;

	if (fractol->psychedelic == 1)
	{
		color.blue = fractol->psychedelic_palette[depth % 10]->blue;
		color.green = fractol->psychedelic_palette[depth % 10]->green;
		color.red = fractol->psychedelic_palette[depth % 10]->red;
	}
	else
	{
		color.blue = fractol->palette->color->blue + (depth * 2.62);
		color.green = fractol->palette->color->green + (depth * 2.62);
		color.red = fractol->palette->color->red + (depth * 2.62);
	}
	return (color);
}

void		draw_fractal(t_fractol *fractol, int FUNCTION)
{
	t_point		pixel;
	t_color		color;
	int			depth;
	int			pos;

	pixel.y = 0;
	while (pixel.y < WIN_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIN_WIDTH)
		{
			pixel.x += fractol->offset.x;
			pixel.y += fractol->offset.y;
			depth = define_fractal_pixel(pixel, fractol);
			pixel.x -= fractol->offset.x;
			pixel.y -= fractol->offset.y;
			pos = pixel.x * 4 + 4 * WIN_WIDTH * pixel.y;
			color = define_color(depth, fractol);
			fractol->image.data[pos] = color.blue;
			fractol->image.data[pos + 1] = color.green;
			fractol->image.data[pos + 2] = color.red;
			++pixel.x;
		}
		++pixel.y;
	}
}

void		load_fractal(t_fractol *fractol)
{
	if (fractol->type == 1)
		draw_fractal(fractol, mandelbrot);
	else if (fractol->type == 2)
		draw_fractal(fractol, julia);
	else if (fractol->type == 3)
		draw_fractal(fractol, newton);
}

void		update_fractol(t_fractol *fractol)
{
	clear_image(fractol);
	load_fractal(fractol);
	if (fractol->axis == 1)
		add_axis(fractol);
	mlx_put_image_to_window(fractol->mlx.init, fractol->mlx.win, \
								fractol->mlx.img, 0, 0);
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 5, 0xFFFFFF, \
						ft_strjoin("Number of iterations : ",\
						ft_itoa(fractol->iterations)));
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 35, 0xFFFFFF, \
						ft_strjoin("Zoom level: ", ft_itoa(fractol->zoom)));
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 65, 0xFFFFFF, \
						"'Space' - Change color");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 95, 0xFFFFFF, \
					"'F' - To freeze fractal");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 125, 0xFFFFFF, \
					"'A' - To add axis");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 155, 0xFFFFFF, \
					"'R' - Redraw the fractal");
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 185, 0xFFFFFF, \
					"'P' - Psychedelic effect");
}

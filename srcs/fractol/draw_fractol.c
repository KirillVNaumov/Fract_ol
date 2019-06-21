/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 14:01:09 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/21 14:02:29 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_axis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:42:23 by knaumov           #+#    #+#             */
/*   Updated: 2019/06/05 21:42:24 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_vertical_dash(int x, int y, t_fractol *fractol)
{
	int		i;
	int		pos;
	int		init_pos;
	int		actual_size;

	if (x < 0 || y < 0 || x > WIN_WIDTH || y > WIN_HEIGHT)
		return ;
	i = -10;
	init_pos = x * 4 + 4 * WIN_WIDTH * y;
	actual_size = WIN_WIDTH * 4 + 4 * WIN_WIDTH * WIN_HEIGHT;
	while (i < 10)
	{
		pos = init_pos + 4 * WIN_WIDTH * i;
		++i;
		if (pos < 0 || pos > actual_size)
			continue ;
		fractol->image.data[pos] = (char)255;
		fractol->image.data[pos + 1] = (char)255;
		fractol->image.data[pos + 2] = (char)255;
	}
}

void		draw_horizontal_dash(int x, int y, t_fractol *fractol)
{
	int		i;
	int		pos;
	int		init_pos;
	int		actual_size;

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

void		add_vertical_units(t_fractol *fractol)
{
	int		i;

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

void		add_horizontal_units(t_fractol *fractol)
{
	int		i;

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

void		add_axis(t_fractol *fractol)
{
	int		i;
	int		pos;

	i = 0;
	if (fractol->origin.x + fractol->offset.x > 0 && fractol->origin.x + fractol->offset.x < WIN_WIDTH)
	{
		while (i < WIN_HEIGHT)
		{
			pos = (fractol->origin.x + fractol->offset.x) * 4 + 4 * WIN_WIDTH * i;
			fractol->image.data[pos] = (char)255;
			fractol->image.data[pos + 1] = (char)255;
			fractol->image.data[pos + 2] = (char)255;
			++i;
		}
		add_horizontal_units(fractol);
	}
	i = 0;
	if (fractol->origin.y + fractol->offset.y > 0 && fractol->origin.y + fractol->offset.y < WIN_HEIGHT)
	{
		while (i < WIN_WIDTH)
		{
			pos = i * 4 + 4 * WIN_WIDTH * (fractol->origin.y + fractol->offset.y);
			fractol->image.data[pos] = (char)255;
			fractol->image.data[pos + 1] = (char)255;
			fractol->image.data[pos + 2] = (char)255;
			++i;
		}
		add_vertical_units(fractol);
	}
}

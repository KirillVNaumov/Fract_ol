/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_axis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:42:23 by knaumov           #+#    #+#             */
/*   Updated: 2019/06/21 13:42:22 by amelikia         ###   ########.fr       */
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

void		add_axis_less_height(int *i, int *pos, t_fractol *fractol)
{
	while (*i < WIN_HEIGHT)
	{
		*pos = (fractol->origin.x + fractol->offset.x) * 4 + 4 * WIN_WIDTH * *i;
		fractol->image.data[*pos] = (char)255;
		fractol->image.data[(*pos) + 1] = (char)255;
		fractol->image.data[(*pos) + 2] = (char)255;
		(*i)++;
	}
	add_horizontal_units(fractol);
}

void		add_axis(t_fractol *fractol)
{
	int		i;
	int		pos;

	i = 0;
	if (fractol->origin.x + fractol->offset.x > 0 &&\
	fractol->origin.x + fractol->offset.x < WIN_WIDTH)
		add_axis_less_height(&i, &pos, fractol);
	i = 0;
	if (fractol->origin.y + fractol->offset.y > 0 &&\
	fractol->origin.y + fractol->offset.y < WIN_HEIGHT)
	{
		while (i < WIN_WIDTH)
		{
			pos = i * 4 + 4 * WIN_WIDTH *\
			(fractol->origin.y + fractol->offset.y);
			fractol->image.data[pos] = (char)255;
			fractol->image.data[pos + 1] = (char)255;
			fractol->image.data[pos + 2] = (char)255;
			++i;
		}
		add_vertical_units(fractol);
	}
}

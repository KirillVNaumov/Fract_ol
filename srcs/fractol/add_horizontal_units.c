/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_horizontal_units.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:40:39 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/21 13:44:05 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		add_horizontal_units_i_g_width(int *i, t_fractol *fractol)
{
	while (*i > WIN_HEIGHT)
		*i -= fractol->zoom;
	while (*i > 0)
	{
		draw_horizontal_dash(fractol->origin.x +\
		fractol->offset.x, *i, fractol);
		*i -= fractol->zoom;
	}
}

void		add_horizontal_units_i_l_zero(int *i, t_fractol *fractol)
{
	while (*i < 0)
		*i += fractol->zoom;
	while (*i < WIN_HEIGHT)
	{
		draw_horizontal_dash(fractol->origin.x +
		fractol->offset.x, *i, fractol);
		*i += fractol->zoom;
	}
}

void		add_horizontal_units(t_fractol *fractol)
{
	int		i;

	i = fractol->origin.y + fractol->offset.y;
	if (i > WIN_HEIGHT)
		add_horizontal_units_i_g_width(&i, fractol);
	else if (i < 0)
		add_horizontal_units_i_l_zero(&i, fractol);
	else
	{
		while (i > 0)
		{
			draw_horizontal_dash(fractol->origin.x +\
			fractol->offset.x, i, fractol);
			i -= fractol->zoom;
		}
		i = fractol->origin.y + fractol->offset.y;
		while (i < WIN_HEIGHT)
		{
			draw_horizontal_dash(fractol->origin.x +\
			fractol->offset.x, i, fractol);
			i += fractol->zoom;
		}
	}
}

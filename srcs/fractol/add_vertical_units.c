/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertical_units.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:42:51 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/21 13:44:02 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		add_vertical_units_i_g_width(int *i, t_fractol *fractol)
{
	while (*i > WIN_WIDTH)
		*i -= fractol->zoom;
	while (*i > 0)
	{
		draw_vertical_dash(*i, fractol->origin.y + fractol->offset.y, fractol);
		*i -= fractol->zoom;
	}
}

void		add_vertical_units_i_l_zero(int *i, t_fractol *fractol)
{
	while (*i < 0)
		*i += fractol->zoom;
	while (*i < WIN_WIDTH)
	{
		draw_vertical_dash(*i, fractol->origin.y + fractol->offset.y, fractol);
		*i += fractol->zoom;
	}
}

void		add_vertical_units(t_fractol *fractol)
{
	int		i;

	i = fractol->origin.x + fractol->offset.x;
	if (i > WIN_WIDTH)
		add_vertical_units_i_g_width(&i, fractol);
	else if (i < 0)
		add_vertical_units_i_l_zero(&i, fractol);
	else
	{
		while (i > 0)
		{
			draw_vertical_dash(i, fractol->origin.y +\
				fractol->offset.y, fractol);
			i -= fractol->zoom;
		}
		i = fractol->origin.x + fractol->offset.x;
		while (i < WIN_WIDTH)
		{
			draw_vertical_dash(i, fractol->origin.y +\
				fractol->offset.y, fractol);
			i += fractol->zoom;
		}
	}
}

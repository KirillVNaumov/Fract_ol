/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:28:30 by knaumov           #+#    #+#             */
/*   Updated: 2019/06/05 21:28:32 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mandelbrot(t_point pixel, t_fractol *fractol)
{
	t_point		result;
	t_point		constant;
	t_point		previous_result;
	int			i;

	i = 0;
	previous_result.x = 0;
	previous_result.y = 0;
	constant.x = (double)(pixel.x - WIN_WIDTH / 2) / fractol->zoom;
	constant.y = (double)(pixel.y - WIN_HEIGHT / 2) / fractol->zoom;
	while (i < fractol->iterations)
	{
		result.x = (previous_result.x * previous_result.x - \
					previous_result.y * previous_result.y + constant.x);
		result.y = (2 * previous_result.x * previous_result.y + constant.y);
		if (find_double_radius(&result) >= 4)
			break ;
		previous_result.x = result.x;
		previous_result.y = result.y;
		++i;
	}
	return (i);
}

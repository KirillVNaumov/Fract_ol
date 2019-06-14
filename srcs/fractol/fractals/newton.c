/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:37:01 by knaumov           #+#    #+#             */
/*   Updated: 2019/06/05 21:37:02 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double			find_distance(COMPLEX z)
{
	return (creal(z) * creal(z) + cimag(z) * cimag(z));
}

int				newton(t_point pixel, t_fractol *fractol)
{
	COMPLEX				result;
	COMPLEX				previous_result;
	double				margin_error;
	int					i;

	margin_error = 0.00001;
	i = 0;
	previous_result = ((double)(pixel.x - WIN_WIDTH / 2) / fractol->zoom) + \
					((double)(pixel.y - WIN_HEIGHT / 2) / fractol->zoom) * I;
	while (i < fractol->iterations)
	{
		result = previous_result - function(previous_result) / \
									derivative(previous_result);
		if (find_distance(result - previous_result) < \
							margin_error * margin_error)
			break ;
		previous_result = result;
		++i;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:29:41 by amelikia          #+#    #+#             */
/*   Updated: 2019/06/21 14:02:25 by amelikia         ###   ########.fr       */
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

void		display_intructions(t_fractol *fractol)
{
	char	*str;

	str = ft_itoa(fractol->iterations);
	str = ft_update(str, ft_strjoin("Number of iterations : ", str));
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 5, 0xFFFFFF, str);
	str = ft_update(str, ft_itoa(fractol->zoom));
	str = ft_update(str, ft_strjoin("Zoom level: ", str));
	mlx_string_put(fractol->mlx.init, fractol->mlx.win, 10, 35, 0xFFFFFF, str);
	free(str);
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

void		update_fractol(t_fractol *fractol)
{
	clear_image(fractol);
	load_fractal(fractol);
	if (fractol->axis == 1)
		add_axis(fractol);
	mlx_put_image_to_window(fractol->mlx.init, fractol->mlx.win, \
								fractol->mlx.img, 0, 0);
	display_intructions(fractol);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:18:27 by knaumov           #+#    #+#             */
/*   Updated: 2019/06/21 14:05:20 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			identify_fractol(char *str, t_fractol *fractol)
{
	if (!ft_strcmp(str_to_low(str), "mandelbrot"))
		fractol->type = 1;
	else if (!ft_strcmp(str_to_low(str), "julia"))
		fractol->type = 2;
	else if (!ft_strcmp(str_to_low(str), "newton"))
		fractol->type = 3;
	else
		return (-1);
	return (1);
}

void		init(t_fractol *fractol, char *name)
{
	fractol->mlx.init = mlx_init();
	fractol->mlx.win = mlx_new_window(fractol->mlx.init, WIN_WIDTH, \
		WIN_HEIGHT, str_to_header(name));
	fractol->mlx.img = mlx_new_image(fractol->mlx.init, WIN_WIDTH, \
		WIN_HEIGHT);
	fractol->image.data = mlx_get_data_addr(fractol->mlx.img, \
		&fractol->image.bpp, &fractol->image.size, &fractol->image.endian);
	fractol->zoom = 200;
	fractol->iterations = 45;
	fractol->offset.x = 0;
	fractol->offset.y = 0;
	fractol->origin.x = WIN_WIDTH / 2;
	fractol->origin.y = WIN_HEIGHT / 2;
	fractol->mouse.state = 0;
	fractol->mouse.pos.x = WIN_WIDTH / 2;
	fractol->mouse.pos.y = WIN_HEIGHT / 2;
	fractol->freeze = 0;
	fractol->psychedelic = (fractol->type == 3) ? 1 : 0;
	create_palette(fractol);
}

int			main(int argc, char **argv)
{
	t_fractol		fractol;

	if (argc == 2)
	{
		if (identify_fractol(argv[1], &fractol) == -1)
			error("Listed fractal doesn't exist. Try './fractol' for usage.");
		init(&fractol, argv[1]);
		update_fractol(&fractol);
		mlx_hook(fractol.mlx.win, 2, 3, key_press_hook, &fractol);
		mlx_hook(fractol.mlx.win, 4, 3, mouse_press_hook, &fractol);
		mlx_hook(fractol.mlx.win, 5, 3, mouse_release_hook, &fractol);
		mlx_hook(fractol.mlx.win, 6, 3, motion_hook, &fractol);
		mlx_loop(fractol.mlx.init);
	}
	else
		ft_printf("Usage: ./fractol [mandelbrot/julia/newton]\n");
	return (0);
}

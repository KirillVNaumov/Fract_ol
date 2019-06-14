/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knaumov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:15:32 by knaumov           #+#    #+#             */
/*   Updated: 2019/06/05 21:15:33 by knaumov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_press_hook(int mousecode, int x, int y, \
									t_fractol *fractol)
{
	int			zoom;

	if (x > 0 && y > 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
	{
		zoom = 5 * (fractol->zoom / 100 + 1);
		if (mousecode == MOUSE_UP_SCRLL)
			fractol->zoom += zoom;
		else if (mousecode == MOUSE_DOWN_SCRLL && fractol->zoom > zoom)
			fractol->zoom -= zoom;
		else if (mousecode == MOUSE_LEFT_CLK)
		{
			fractol->mouse.state = 1;
			fractol->mouse.start.x = x;
			fractol->mouse.start.y = y;
		}
		update_fractol(fractol);
	}
	return (0);
}

int				key_press_hook(int key, t_fractol *fractol)
{
	if (key == KEY_ESCAPE)
		exit(0);
	if (key == KEY_ANSI_F)
		fractol->freeze = (fractol->freeze == 0) ? 1 : 0;
	if (key == KEY_ANSI_A)
		fractol->axis = (fractol->axis == 0) ? 1 : 0;
	if (key == KEY_ANSI_P)
		fractol->psychedelic = (fractol->psychedelic == 0) ? 1 : 0;
	if (key == KEY_SPACE)
		fractol->palette = fractol->palette->next;
	if (key == KEY_UPARROW)
		++fractol->iterations;
	if (key == KEY_DOWNARROW && fractol->iterations > 0)
		--fractol->iterations;
	update_fractol(fractol);
	return (0);
}

int				mouse_release_hook(int mousecode, int x, int y, \
									t_fractol *fractol)
{
	if (mousecode == MOUSE_LEFT_CLK)
		fractol->mouse.state = 0;
	x = 0;
	y = 0;
	return (0);
}

int				motion_hook(int x, int y, t_fractol *fractol)
{
	if (fractol->mouse.state == 1 && (x > 0 && y > 0) \
			&& (x < WIN_WIDTH && y < WIN_HEIGHT) && fractol->type == 1)
	{
		fractol->offset.x = fractol->offset.x - \
							(fractol->mouse.start.x - x) / 15;
		fractol->offset.y = fractol->offset.y - \
							(fractol->mouse.start.y - y) / 15;
		update_fractol(fractol);
	}
	if (fractol->mouse.state == 0 && (x > 0 && y > 0) \
			&& (x < WIN_WIDTH && y < WIN_HEIGHT) \
			&& fractol->type == 2 && fractol->freeze == 0)
	{
		fractol->mouse.pos.x = x;
		fractol->mouse.pos.y = y;
		update_fractol(fractol);
	}
	return (0);
}

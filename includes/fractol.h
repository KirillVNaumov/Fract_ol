/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelikia <amelikia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:32:58 by knaumov           #+#    #+#             */
/*   Updated: 2019/06/21 14:01:34 by amelikia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define THREADS 8
# define COMPLEX double complex
# define FUNCTION (*define_fractal_pixel)(t_point, t_fractol *)

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "keys.h"
# include <fcntl.h>
# include <math.h>
# include <complex.h>

typedef struct			s_mlx
{
	void				*init;
	void				*win;
	void				*img;
}						t_mlx;

typedef struct			s_point
{
	double				x;
	double				y;
}						t_point;

typedef struct			s_image
{
	char				*data;
	int					size;
	int					endian;
	int					bpp;
}						t_image;

typedef struct			s_color
{
	int					red;
	int					green;
	int					blue;
}						t_color;

typedef struct			s_palette
{
	t_color				*color;
	struct s_palette	*next;
}						t_palette;

typedef struct			s_mouse
{
	int					state;
	t_point				pos;
	t_point				start;
}						t_mouse;

typedef struct			s_fractol
{
	t_mlx				mlx;
	t_mouse				mouse;
	t_image				image;
	t_point				offset;
	t_point				origin;
	int					type;
	int					freeze;
	int					axis;
	int					iterations;
	int					zoom;
	int					psychedelic;
	t_color				**psychedelic_palette;
	t_palette			*palette;
}						t_fractol;

int						motion_hook(int x, int y, t_fractol *fractol);
int						key_press_hook(int key, t_fractol *fractol);
int						mouse_press_hook(int mousecode, int x, int y, \
											t_fractol *fractol);
int						mouse_release_hook(int mousecode, int x, int y, \
											t_fractol *fractol);
int						mouse_movement(int x, int y, t_fractol *fractol);
void					add_axis(t_fractol *fractol);
void					update_fractol(t_fractol *fractol);
void					create_palette(t_fractol *fractol);
void					add_axis(t_fractol *fractol);
void					load_fractal(t_fractol *fractol);
void					add_vertical_units(t_fractol *fractol);
void					add_horizontal_units(t_fractol *fractol);
void					draw_vertical_dash(int x, int y, t_fractol *fractol);
void					draw_horizontal_dash(int x, int y, t_fractol *fractol);
void					load_fractal(t_fractol *fractol);

/*
**	Fractals
*/

int						julia(t_point pixel, t_fractol *fractol);
int						newton(t_point pixel, t_fractol *fractol);
int						mandelbrot(t_point pixel, t_fractol *fractol);
COMPLEX					function(COMPLEX z);
COMPLEX					derivative(COMPLEX z);

/*
**  Utils
*/

char					*str_to_low(char *str);
char					*str_to_header(char *str);
void					to_absolute(t_point **relative, t_fractol *fractol);
void					to_relative(t_point **absolute, t_fractol *fractol);
double					find_double_radius(t_point *pixel);
t_palette				*new_palette(void);

#endif

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# include "../minilibx_macos/mlx.h"
# include "../libft/libft.h"
# include "keys.h"
# include <fcntl.h>
# include <math.h>

typedef struct	s_mlx
{
	void	*init;
	void	*win;
	void	*img;
}				t_mlx;

// typedef struct	s_mouse
// {
// 	int		state;
// 	int		pos_x;
// 	int		pos_y;
// }				t_mouse;

typedef struct	s_image
{
	char	*data;
	int		size;
	int		endian;
	int		bpp;
}				t_image;

typedef struct	s_color
{
	int		red;
	int		green;
	int		blue;
}				t_color;

typedef struct	s_point
{
	int		x;
	int		y;
}				t_point;

typedef struct  s_fractol
{
    t_mlx       mlx;
	// t_mouse		mouse;
    t_image     image;
	t_point		offset;
	t_point		origin;
    int         type;
	int			iterations;
	int			zoom;
}               t_fractol;

int	            keyboard_read(int key, t_fractol *fractol);
int				mouse_read(int mousecode, int x, int y, t_fractol *fractol);
int				mouse_movement(int x, int y, t_fractol *fractol);
void        	add_axis(t_fractol *fractol);
void        	update_fractol(t_fractol *fractol);

/*
**  Utils
*/

char            *str_to_low(char *str);
char            *str_to_header(char *str);

#endif
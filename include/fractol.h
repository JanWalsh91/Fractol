/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:03:26 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 12:43:40 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "../Libft/libft.h"
# include "../Libmathft/libmathft.h"
# include "keycode_mac.h"
# include "colors.h"
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <pthread.h>

# define USAGE "usage: ./fractol Julia Madelbrot ..."
# define THREAD_COUNT 10
# define WIN_COUNT 4
# define MAX_ARG 4
# define IMG_SIZE 201
# define ZOOM 1
# define ZOOM_POW 1.1

/*
** Mandelbrot
*/

# define MANDELBROT_I 50
# define MANDELBROT_C_I 0
# define MANDELBROT_C_R 0
# define MANDELBROT_XMIN -2.1
# define MANDELBROT_XMAX 0.6
# define MANDELBROT_YMIN -1.2
# define MANDELBROT_YMAX 1.2
# define MANDELBROT_W (MANDELBROT_XMAX - MANDELBROT_XMIN)
# define MANDELBROT_H (MANDELBROT_YMAX - MANDELBROT_YMIN)
# define MANDELBROT_COLOR_SET_COUNT 3

/*
** Julia
*/

# define JULIA_I 50
# define JULIA_C_I 0.04110
# define JULIA_C_R -0.25
# define JULIA_COLOR_SET_COUNT 2

/*
** Sierpinsky's Carpet
*/

# define SIERPINSKY_CARPET_I 2
# define SIERPINSKY_COLOR_SET_COUNT 3

/*
** Newton
*/

# define NEWTON_XMIN -2.0
# define NEWTON_YMIN -2.0
# define NEWTON_XMAX 2.0
# define NEWTON_YMAX 2.0
# define NEWTON_DIM 400
# define NEWTON_I 20
# define EPSILON 0.01
# define NEWTON_COLOR_SET_COUNT 3

/*
** Instructions
*/

# define INSTRUCTIONS_H 512
# define INSTRUCTIONS_W 600
# define LINE_0 "Fract'ol instructions:"
# define LINE_1 "Zoom in:               left mouse button / scroll up"
# define LINE_2 "Zoom out:              right mouse button / scroll down"
# define LINE_3 "Change color set:      C"
# define LINE_4 "Increase iterations:   +"
# define LINE_5 "Decrease iterations:   -"
# define LINE_6 "Reset:                 space"
# define LINE_7 "Exit:                  esc"
# define LINE_8 "Julia:"
# define LINE_JUJU "Turn mouse on / off    J"
# define INSTRUCT_COLOR MISTY_ROSE

typedef enum		e_names
{
	MANDELBROT = 1,
	JULIA = 2,
	SIERPINSKY_CARPET = 3,
	NEWTON = 4,
	BURNING_SHIP = 5,
	OTHER = 6
}					t_names;

typedef struct		s_incr
{
	float			steps;
	float			x;
	float			y;
	float			r;
	float			g;
	float			b;
}					t_incr;

typedef struct		s_seirpinsky_tools
{
	int				i;
	int				w;
	int				h;
}					t_sierpinsky_tools;

typedef struct		s_draw_tools
{
	int				bpp;
	int				size_line;
	int				endian;
	char			*image;
}					t_draw_tools;

typedef struct		s_env
{
	t_draw_tools	draw;
	void			*mlx;
	void			*win_mlx;
	void			*img_mlx;
	int				h;
	int				w;
}					t_env;

typedef struct		s_fractal
{
	t_env			e;
	t_names			name;
	char			*title;
	int				(*f)(t_pt2 i, struct s_fractal *f);
	int				i;
	t_complex		c;
	double			zoom;
	t_pt2			win_size;
	t_dpt2			max;
	t_dpt2			min;
	int				mouse_on;
	int				**colors;
	int				color_set;
	int				color_set_count;
	int				(*(*get_color))(int i, int i_max);
}					t_fractal;

typedef struct		s_th
{
	t_fractal		*f;
	int				i;
}					t_th;

typedef struct		s_win_manager
{
	t_fractal		*f;
	int				nb_frac;
}					t_win_manager;

/*
** Main
*/

int					fractol(t_names *names, int nb_frac);
int					display_usage(void);
int					init_names(t_names **names);
int					init_fractal(t_fractal *f, void *mlx, int y);
int					init_win(t_fractal *f);
int					init_instructions(void *mlx);
void				reset_bounds(t_fractal *f);
int					calc_colors(t_fractal *f);
int					draw(t_fractal *f);
void				display_colors(int **tab, int xmax, int ymax);

/*
** Fracal algorithms
*/

int					mandelbrot(t_pt2 j, t_fractal *f);
int					julia(t_pt2 j, t_fractal *f);
int					sierpinsky_carpet(t_pt2 j, t_fractal *f);
int					newton(t_pt2 j, t_fractal *f);
int					burning_ship(t_pt2 j, t_fractal *f);

/*
** MLX functions
*/

int					key_released(int keycode, t_fractal *f);
int					exit_prog(int keycode, void *mlx);
int					mouse_event(int button, int x, int y, t_fractal *f);
int					mouse_motion(int x, int y, t_fractal *f);
int					red_button_exit(int *nb_frac);
int					zoom(t_fractal *f, int button, int y, int x);
int					update_iteration(t_fractal *f, int button);
int					update_color_set(t_fractal *f);
int					switch_julia_constant(t_fractal *f);

/*
** Multithreading
*/

void				*calc_colors_sections(void *v);

/*
** Functions for different color sets.
** First number refers to the fractal's index.
** Second number refers to the color set's index.
*/

int		col_0_0(int i, int i_max);
int		col_0_1(int i, int i_max);
int		col_0_2(int i, int i_max);
int		col_1_0(int i, int i_max);
int		col_1_1(int i, int i_max);
//int		col_1_2(int i, int i_max);
int		col_2_0(int i, int i_max);
int		col_2_1(int i, int i_max);
int		col_2_2(int i, int i_max);
//int		col_3_0(int i, int i_max);
//int		col_3_1(int i, int i_max);
//int		col_3_2(int i, int i_max);
int		col_4_0(int i, int i_max);
int		col_4_1(int i, int i_max);
int		col_4_2(int i, int i_max);
int		col_5_0(int i, int i_max);

#endif

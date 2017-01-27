/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:03:26 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/27 15:40:41 by jwalsh           ###   ########.fr       */
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

/*
** General settings
*/

# define THREAD_COUNT 10
# define WIN_COUNT 4
# define MAX_ARG 4
# define IMG_SIZE 100
# define ZOOM 1
# define ZOOM_POW 1.1
# define COLORS_PER_SET 4
# define COLOR_SET_COUNT 3

/*
** Mandelbrot
*/

# define MANDELBROT_I 40
# define MANDELBROT_C_I 0
# define MANDELBROT_C_R 0
# define MANDELBROT_XMIN -2.1
# define MANDELBROT_XMAX 0.6
# define MANDELBROT_YMIN -1.2
# define MANDELBROT_YMAX 1.2
# define MANDELBROT_W (MANDELBROT_XMAX - MANDELBROT_XMIN)
# define MANDELBROT_H (MANDELBROT_YMAX - MANDELBROT_YMIN)

/*
** Julia
*/

# define JULIA_I 40
# define JULIA_C_R -0.835
# define JULIA_C_I -0.2321

/*
** Sierpinsky's Carpet
*/

# define SIERPINSKY_CARPET_I 1
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
** Burning Ship
*/

# define BURNING_SHIP_I 30
# define BURNING_SHIP_COLOR_SET_COUNT 3

/*
** Color sets
*/

# define COL_00 GOLDEN_ROD
# define COL_01 GOLD
# define COL_02 CRIMSON
# define COL_03 SILVER
# define COL_10 AQUA_MARINE
# define COL_11 INDIGO
# define COL_12 SEA_GREEN
# define COL_13 SILVER
# define COL_20 SILVER
# define COL_21 SKY_BLUE
# define COL_22 HOT_PINK
# define COL_23 BLACK

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
# define INSTRUCT_COLOR AZURE

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
	int				c_1;
	int				c_2;
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
	t_incr			**incr;
	int				color_set;
	int				color_set_count;
	int				(*(*get_color))(int i, struct s_fractal *f);
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

void				fractol(t_names *names, int nb_frac, int instr);
int					display_usage(void);
int					init_names(t_names **names);
int					init_fractal(t_fractal *f, void *mlx, int y);
int					init_mandelbrot(t_fractal *f);
int					init_julia(t_fractal *f);
int					init_sierpinsky_carpet(t_fractal *f);
int					init_newton(t_fractal *f);
int					init_burning_ship(t_fractal *f);
int					init_colors(t_fractal *f);
int					init_win(t_fractal *f);
int					init_instructions(t_win_manager *f);
void				reset_bounds(t_fractal *f);
int					calc_colors(t_fractal *f);
int					draw(t_fractal *f);
int					reset_color_sets(t_fractal *f);

/*
** Fractal algorithms
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
int					key_free_fractals(int keycode, t_win_manager *f);
int					exit_prog(int keycode, void *mlx);
int					mouse_event(int button, int x, int y, t_fractal *f);
int					mouse_motion(int x, int y, t_fractal *f);
int					red_button_exit(t_win_manager *nb_frac);
int					zoom(t_fractal *f, int button, int y, int x);
int					update_iteration(t_fractal *f, int button);
int					update_color_set(t_fractal *f);
int					switch_julia_constant(t_fractal *f);

/*
** Free functions
*/

int					free_fractals(t_win_manager *f);

/*
** Functions for different color sets.
** First number refers to the fractal's index.
** Second number refers to the color set's index.
*/

int					col_0_0(int i, t_fractal *f);
int					col_0_1(int i, t_fractal *f);
int					col_0_2(int i, t_fractal *f);
int					col_1_0(int i, t_fractal *f);
int					col_1_1(int i, t_fractal *f);
int					col_1_2(int i, t_fractal *f);
int					col_2_0(int i, t_fractal *f);
int					col_2_1(int i, t_fractal *f);
int					col_2_2(int i, t_fractal *f);
int					col_3_0(int i, t_fractal *f);
int					col_3_1(int i, t_fractal *f);
int					col_3_2(int i, t_fractal *f);
int					col_4_0(int i, t_fractal *f);
int					col_4_1(int i, t_fractal *f);
int					col_4_2(int i, t_fractal *f);
int					col_5_0(int i, t_fractal *f);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:03:26 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/23 16:21:38 by jwalsh           ###   ########.fr       */
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
# define THREAD_COUNT 20
# define WIN_COUNT 4
# define MAX_ARG 4
# define WIN_WIDTH
# define WIN_HEIGHT
# define DEFAULT_I   //default amount of iterations to do
# define ZOOM_POW 2

/*
** Mandelbrot
*/

# define MANDELBROT_I 30
# define MANDELBROT_C_I 0
# define MANDELBROT_C_R 0
//# define MANDELBROT_ZOOM 100
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

# define JULIA_I 20
# define JULIA_C_I 0.04110
# define JULIA_C_R -0.25
# define JULIA_COLOR_SET_COUNT 2

/*
** Sierpinsky's Carpet
*/

# define SIERPINSKY_CARPET_H 1
# define SIERPINSKY_CARPET_W 1
# define SIERPINSKY_CARPET_I 1
# define SIERPINSKY_COLOR_SET_COUNT 1

/*
** Instructions
*/

# define INSTRUCTIONS_H 512
# define INSTRUCTIONS_W 512

# define IMG_SIZE 300
//# define IMG_SIZE_W IMG_SIZE * 2.7
//# define IMG_SIZE_H IMG_SIZE * 2.4
# define ZOOM 1


/*
** Colors for 4 sets.
*/

# define P0C0 DARK_GREEN
# define P0C1 GREEN
# define P0C2 SADDLEBROWN
# define P0C3 GAINSBORO

# define P1C0 STEEL_BLUE
# define P1C1 0xAAAAFF
# define P1C2 DEEP_PINK
# define P1C3 HOT_PINK

# define P2C0 MAROON
# define P2C1 INDIAN_RED
# define P2C2 SALMON
# define P2C3 GOLD

# define P3C0 GOLDEN_ROD
# define P3C1 LIGHT_SEA_GREEN
# define P3C2 TEAL
# define P3C3 HOT_PINK

/*
** Instructions
*/

# define HEADER
# define LINE1 
# define LINE2
# define LINE3
# define LINE4
# define LINE5
# define LINE6
# define LINE7
# define LINE8
# define LINE9
# define LINE10

typedef enum		e_names
{
	MANDELBROT = 1,
	JULIA = 2,
	SIERPINSKY_CARPET = 3,
	NEWTON = 4,
	OTHER = 5
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

//typedef struct		s_image
//{
//	void			*mlx;
//	int				h;
//	int				w;
//	//t_pt2			pos; //position of image. Probaly useless since always (0, 0)
//}					t_image;

typedef struct		s_seirpinsky_tools
{
	int	i;
	int	w;
	int	h;
}					t_sierpinsky_tools;

typedef struct		s_draw_tools //values used for get_data_address
{
	int				bpp;
	int				size_line;
	int				endian;
	char			*image;
}					t_draw_tools;

typedef struct		s_env // one win, img and draw tools per fractal
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
	char			*title; //fractal name
	int				(*f)(t_pt2 i, struct s_fractal *f); //returns color for a point bases on its coords
	int				i; //number of iteratioms 
	t_complex		c; // complex constant
	double			zoom; //float?
	t_pt2			win_size;// also image size;
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

/*
** MLX functions
*/

int					key_released(int keycode, t_fractal *f);
int					exit_prog(int keycode, void *mlx);
int					mouse_event(int button, int x, int y, t_fractal *f);
int					mouse_motion(int x, int y, t_fractal *f);
int					zoom(t_fractal *f, int button, int y, int x);
int					update_iteration(t_fractal *f, int button);
int					update_color_set(t_fractal *f);
int					switch_julia_constant(t_fractal *f);

/*
** new functions with multithreading (check which file is in use and update)
*/

void				*calc_colors_sections(void *v);
//void				*draw_section(void *v);
//

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
//int		col_2_1(int i, int i_max);
//int		col_2_2(int i, int i_max);
//int		col_3_0(int i, int i_max);
//int		col_3_1(int i, int i_max);
//int		col_3_2(int i, int i_max);

#endif

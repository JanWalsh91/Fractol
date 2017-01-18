/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:03:26 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/18 10:25:00 by tgros            ###   ########.fr       */
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

# define USAGE "usage: ./fractol Julia Madelbrot ..."
# define MAX_ARG 4
# define WIN_WIDTH
# define WIN_HEIGHT
# define DEFAULT_I   //default amount of iterations to do

/*
** Mandelbrot
*/

# define MANDELBROT_I 50
# define MANDELBROT_C_I 0
# define MANDELBROT_C_R 0
# define MANDELBROT_ZOOM 100
# define MANDELBROT_XMIN -2.1
# define MANDELBROT_XMAX 0.6
# define MANDELBROT_YMIN -1.2
# define MANDELBROT_YMAX 1.2


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
	OTHER = 3
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
	void			*win_mlx;
	void			*img_mlx;
	int				h;
	int				w;

}					t_env;

typedef struct		s_fractal
{
	t_env			e;
	char			*name; //fractal name
	int				(*f)(t_pt2 i, struct s_fractal *f); //returns color for a point bases on its coords
	int				i; //number of iteratioms 
	t_complex		c; // complex constant
	int				zoom; //float?
	t_pt2			win_size;// also image size;
	int				**colors;
}					t_fractal;

/*
** Main
*/

int					fractol(t_names *names, int nb_frac);
int					display_usage(void);
int					init_names(t_names **names);
int					init_fractal(t_fractal *f, int y);
int					init_win(t_fractal *f, void *mlx);
int					calc_colors(t_fractal *f);
int					draw(t_fractal *f, void *mlx);
int					mandelbrot(t_pt2 j, t_fractal *f);
int					key_released(int keycode, t_fractal *f);
void				display_colors(int **tab, int xmax, int ymax);

#endif

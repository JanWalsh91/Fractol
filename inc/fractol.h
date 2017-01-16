/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:03:26 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/16 17:12:03 by jwalsh           ###   ########.fr       */
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

# define USAGE "usage: ./fractol Julia Madelbrot ..."
# define MAX_ARG 4
# define WIN_WIDTH
# define WIN_HEIGHT
# define DEFAULT_I   //default amount of iterations to do

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

typedef struct		s_incr
{
	float			steps;
	float			x;
	float			y;
	float			r;
	float			g;
	float			b;
}					t_incr;

typedef struct		s_image
{
	void			*mlx;
	int				h;
	int				w;
	t_pt2			pos; //position of image. Probaly useless since always (0, 0)
}					t_image;

typedef struct		s_window
{
	void			*mlx;
	int				h;
	int				w;
}					t_window;

typedef struct		s_draw_tools
{
	int				bpp;
	int				size_line;
	int				endian;
	char			*image;
}					t_draw_tools;

typedef struct		s_data
{

}					t_data;

typedef struct		s_env
{
	void			*mlx;
	t_window		win;
	t_image			img;
	t_draw_tools	draw;
}					t_env;

typedef struct		s_all
{
	t_data			d;
	t_env			e;
}					t_all;

/*
** Main
*/

int					fractol(int file_count, char **file_names);
int					display_usage(void);

#endif

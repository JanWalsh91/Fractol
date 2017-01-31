/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:46:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 13:18:27 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Functions for initalizing individual fractals.
*/

int	init_mandelbrot(t_fractal *f)
{
	f->i = MANDELBROT_I;
	f->e.h = IMG_SIZE * MANDELBROT_H;
	f->e.w = IMG_SIZE * MANDELBROT_W;
	f->name = MANDELBROT;
	f->color_set_count = COLOR_SET_COUNT;
	if (!(f->title = ft_strdup("Mandelbrot")) || !init_colors(f))
		ft_error_exit("Malloc error");
	f->f = &mandelbrot;
	f->get_color[0] = &col_0_0;
	f->get_color[1] = &col_0_1;
	f->get_color[2] = &col_0_2;
	f->c.r = MANDELBROT_C_R;
	f->c.i = MANDELBROT_C_I;
	reset_bounds(f);
	f->color_set = 2;
	return (1);
}

int	init_julia(t_fractal *f)
{
	f->i = JULIA_I;
	f->e.h = IMG_SIZE * MANDELBROT_H;
	f->e.w = IMG_SIZE * MANDELBROT_W;
	f->name = JULIA;
	f->color_set_count = COLOR_SET_COUNT;
	if (!(f->title = ft_strdup("Julia")) || !init_colors(f))
		ft_error_exit("Malloc error");
	f->f = &julia;
	f->get_color[0] = &col_1_0;
	f->get_color[1] = &col_1_1;
	f->get_color[2] = &col_1_2;
	f->c.r = JULIA_C_R;
	f->c.i = JULIA_C_I;
	reset_bounds(f);
	f->color_set = 1;
	return (1);
}

int	init_sierpinsky_carpet(t_fractal *f)
{
	f->e.h = 729;
	f->e.w = 729;
	f->i = SIERPINSKY_CARPET_I;
	f->name = SIERPINSKY_CARPET;
	f->color_set_count = SIERPINSKY_COLOR_SET_COUNT;
	if (!(f->title = ft_strdup("Sierpinsky Capret")) || !init_colors(f))
		ft_error_exit("Malloc error");
	f->f = &sierpinsky_carpet;
	f->get_color[0] = &col_2_0;
	f->get_color[1] = &col_2_1;
	f->get_color[2] = &col_2_2;
	return (1);
}

int	init_newton(t_fractal *f)
{
	f->img_size = 100;
	f->e.h = NEWTON_DIM;
	f->e.w = NEWTON_DIM;
	f->i = NEWTON_I;
	f->name = NEWTON;
	f->zoom = ZOOM;
	f->color_set_count = NEWTON_COLOR_SET_COUNT;
	if (!(f->title = ft_strdup("Newton")) || !init_colors(f))
		ft_error_exit("Malloc error");
	f->get_color[0] = &col_4_0;
	f->get_color[1] = &col_4_1;
	f->get_color[2] = &col_4_2;
	f->f = &newton;
	reset_bounds(f);
	return (1);
}

int	init_burning_ship(t_fractal *f)
{
	f->i = BURNING_SHIP_I;
	f->e.h = IMG_SIZE * MANDELBROT_H;
	f->e.w = IMG_SIZE * MANDELBROT_W;
	f->name = BURNING_SHIP;
	f->color_set_count = BURNING_SHIP_COLOR_SET_COUNT;
	if (!(f->title = ft_strdup("Burning Ship")) || !init_colors(f))
		ft_error_exit("Malloc error");
	f->f = &burning_ship;
	f->get_color[0] = &col_3_0;
	f->get_color[1] = &col_3_1;
	f->get_color[2] = &col_3_2;
	f->c.r = MANDELBROT_C_R;
	f->c.i = MANDELBROT_C_I;
	reset_bounds(f);
	f->color_set = 0;
	return (1);
}

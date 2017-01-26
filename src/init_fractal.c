/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:46:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 12:17:26 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_mandelbrot(t_fractal *f);
static int	init_julia(t_fractal *f);
static int	init_sierpinsky_carpet(t_fractal *f);
static int	init_newton(t_fractal *f);
static int	init_burning_ship(t_fractal *f);
static int	init_colors(t_fractal *f);

/*
** Initalizes a fractal stucture based on the parameter y.
** Sets the function
*/

int			init_fractal(t_fractal *f, void *mlx, int y)
{
	f->e.mlx = mlx;
	f->color_set = 0;
	f->mouse_on = 1;
	f->zoom = ZOOM;
	if (y == JULIA)
		init_julia(f);
	else if (y == MANDELBROT)
		init_mandelbrot(f);
	else if (y == SIERPINSKY_CARPET)
		init_sierpinsky_carpet(f);
	else if (y == NEWTON)
		init_newton(f);
	else if (y == BURNING_SHIP)
		init_burning_ship(f);

	return (1);
}

static int	init_mandelbrot(t_fractal *f)
{
	//printf("init_fractol\n");
	f->e.h = IMG_SIZE * MANDELBROT_H;
	f->e.w = IMG_SIZE * MANDELBROT_W;
	f->name = MANDELBROT;
	f->color_set_count = MANDELBROT_COLOR_SET_COUNT;
	if (!(f->title = ft_strdup("Mandelbrot")) || !init_colors(f))
		return (0);
	f->f = &mandelbrot;
	f->get_color[0] = &col_0_0;
	f->get_color[1] = &col_0_1;
	f->get_color[2] = &col_0_2;
	f->i = MANDELBROT_I;
	f->c.r = MANDELBROT_C_R;
	f->c.i = MANDELBROT_C_I;
	reset_bounds(f);
	//printf("init_fractol end. (h, w) (%i, %d)\n", f->e.h, f->e.w);
	return (1);
}

static int	init_julia(t_fractal *f)
{
	f->e.h = IMG_SIZE * MANDELBROT_H;
	f->e.w = IMG_SIZE * MANDELBROT_W;
	f->name = JULIA;
	f->color_set_count = JULIA_COLOR_SET_COUNT;
	if (!(f->title = ft_strdup("Julia")) || !init_colors(f))
		return (0);
	f->f = &julia;
	f->get_color[0] = &col_1_0;
	f->get_color[1] = &col_1_1;
	f->i = JULIA_I;
	f->c.r = JULIA_C_R;
	f->c.i = JULIA_C_I;
	reset_bounds(f);
	return (1);
}

static int	init_sierpinsky_carpet(t_fractal *f)
{
	IMG_SIZE > 0 ? f->e.h = 27 : 0;
	IMG_SIZE >= 10 ? f->e.h = 81 : 0;
	IMG_SIZE >= 50 ? f->e.h = 243 : 0;
	IMG_SIZE >= 150 ? f->e.h = 729 : 0;
	f->e.w = f->e.h;
	//printf("(h, w): ([%i][%i])\n", f->e.h, f->e.w);
	f->i = SIERPINSKY_CARPET_I;
	f->name = SIERPINSKY_CARPET;
	f->color_set_count = SIERPINSKY_COLOR_SET_COUNT;
	if (!(f->title = ft_strdup("Sierpinsky Capret")) || !init_colors(f))
		return (0);
	f->f = &sierpinsky_carpet;
	f->get_color[0] = &col_2_0;
	f->get_color[1] = &col_2_1;
	f->get_color[2] = &col_2_2;
	f->max.x = f->e.h;
	f->max.y = f->e.h;
	f->min.x = 0;
	f->min.y = 0;
	return (1);
}

static int	init_newton(t_fractal *f)
{
	f->e.h = 100 * (NEWTON_XMAX - NEWTON_XMIN);
	f->e.w = 100 * (NEWTON_YMAX - NEWTON_YMIN);
	f->i = NEWTON_I;
	f->name = NEWTON;
	f->zoom = ZOOM;
	f->min.x = NEWTON_XMIN;
	f->min.y = NEWTON_XMIN;
	f->color_set_count = NEWTON_COLOR_SET_COUNT;
	if (!(f->title = ft_strdup("Newton")) || !init_colors(f))
		return (0);
	f->get_color[0] = &col_4_0;
	f->get_color[1] = &col_4_1;
	f->get_color[2] = &col_4_2;
	f->f = &newton;
	return (1);
}

static int	init_burning_ship(t_fractal *f)
{
	printf("init_fractol\n");
	f->e.h = IMG_SIZE * MANDELBROT_H;
	f->e.w = IMG_SIZE * MANDELBROT_W;
	f->name = MANDELBROT;
	f->color_set_count = MANDELBROT_COLOR_SET_COUNT;
	if (!(f->title = ft_strdup("Burning sheep")) || !init_colors(f))
		return (0);
	f->f = &burning_ship;
	f->get_color[0] = &col_0_0;
	f->get_color[1] = &col_0_1;
	f->get_color[2] = &col_0_2;
	f->i = MANDELBROT_I;
	f->c.r = MANDELBROT_C_R;
	f->c.i = MANDELBROT_C_I;
	reset_bounds(f);
	//printf("init_fractol end. (h, w) (%i, %d)\n", f->e.h, f->e.w);
	return (1);
}


static int	init_colors(t_fractal *f)
{
	int	i;

	if (!(f->colors = ft_memalloc(sizeof(int *) * f->e.h)))
		return (0);
	i = -1;
	while (++i < f->e.h)
		if (!(f->colors[i] = ft_memalloc(sizeof(int) * f->e.w)))
			return (0);
	if (!(f->get_color = ft_memalloc(sizeof(*(f->get_color)) *
					f->color_set_count)))
		return (0);
	return (1);
}

void	reset_bounds(t_fractal *f)
{
	if (f->name == MANDELBROT)
	{
		f->max.x = MANDELBROT_XMAX;
		f->max.y = MANDELBROT_YMAX;
		f->min.x = MANDELBROT_XMIN;
		f->min.y = MANDELBROT_YMIN;
	}
	else if (f->name == JULIA)
	{
		f->min.x = 0;
		f->min.y = 0;
	}
	else if (f->name == NEWTON)
	{
		f->min.x = NEWTON_XMIN;
		f->min.y = NEWTON_YMIN;
	}
}

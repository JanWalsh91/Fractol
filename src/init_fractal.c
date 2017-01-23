/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:46:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/23 11:24:41 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_mandelbrot(t_fractal *f);
static int	init_julia(t_fractal *f);
static int init_sierpinsky_carpet(t_fractal *f);
static int	init_colors(t_fractal *f);
/*
** Initalizes a fractal stucture based on the parameter y.
** Sets the function
*/

int	init_fractal(t_fractal *f, void *mlx, int y) //y is fractal index
{
	f->e.mlx = mlx;
	if (y == JULIA)
		init_julia(f);	
	else if (y == MANDELBROT)
		init_mandelbrot(f);
	else if (y == SIERPINSKY_CARPET)
		init_sierpinsky_carpet(f);
	return (1);
}


static int	init_mandelbrot(t_fractal *f)
{
	printf("init_fractol\n");
	f->e.h = IMG_SIZE * MANDELBROT_H;
	f->e.w = IMG_SIZE * MANDELBROT_W;
	f->name = MANDELBROT;
	if (!(f->title = ft_strdup("Mandelbrot")) || !init_colors(f))
		return (0);
	f->f = &mandelbrot;
	f->i = MANDELBROT_I;
	f->c.r = MANDELBROT_C_R;
	f->c.i = MANDELBROT_C_I;
	f->zoom = ZOOM;
	reset_bounds(f);
	printf("init_fractol end. (h, w) (%i, %d)\n", f->e.h, f->e.w);
	return (1);
}

static int	init_julia(t_fractal *f)
{
	f->e.h = IMG_SIZE * MANDELBROT_H;
	f->e.w = IMG_SIZE * MANDELBROT_W;
	f->name = JULIA;
	if (!(f->title = ft_strdup("Julia")) || !init_colors(f))
		return (0);
	f->f = &julia;
	f->i = JULIA_I; 
	f->c.r = JULIA_C_R;
	f->c.i = JULIA_C_I;
	f->zoom = ZOOM;
	return (1);

}

static int	init_sierpinsky_carpet(t_fractal *f)
{
	f->e.h = SIERPINSKY_CARPET_H * pow(3, IMG_SIZE / 50);
	f->e.w = SIERPINSKY_CARPET_W * pow(3, IMG_SIZE / 50);
	f->i = SIERPINSKY_CARPET_I;
	f->name = SIERPINSKY_CARPET;
	if (!(f->title = ft_strdup("Sierpinsky Capret")) || !init_colors(f))
		return (0);
	f->f = &sierpinsky_carpet;
	f->max.x = 2;
	f->max.y = 2;
	f->min.x = 0;
	f->min.y = 0;
	return (1);
}

static int	init_colors(t_fractal *f)
{
	int	i;

	if(!(f->colors = ft_memalloc(sizeof(int *) * f->e.h)))
		return (0);
	i = -1;
	while (++i < f->e.h)
		if(!(f->colors[i] = ft_memalloc(sizeof(int) * f->e.w)))
			return (0);
	return (1);
}

void	reset_bounds(t_fractal *f)
{
	f->max.x = MANDELBROT_XMAX;
	f->max.y = MANDELBROT_YMAX;
	f->min.x = MANDELBROT_XMIN;
	f->min.y = MANDELBROT_YMIN;
}

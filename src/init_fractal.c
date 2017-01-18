/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:46:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/18 19:11:34 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_mandelbrot(t_fractal *f);
static int	init_julia(t_fractal *f);

/*
** Initalizes a fractal stucture based on the parameter y.
** Sets the function
*/

int	init_fractal(t_fractal *f, void *mlx, int y) //y is fractal index
{
	f->e.mlx = mlx;
	if (y == JULIA)
		init_julia(f);	
	if (y == MANDELBROT)
		init_mandelbrot(f);
	return (1);
}


static int	init_mandelbrot(t_fractal *f)
{
	int i;

	printf("init_fractol\n");
	if (!(f->name = ft_strdup("Mandelbrot")))
		return (0);
	f->f = &mandelbrot;
	f->i = MANDELBROT_I;
	f->c.r = MANDELBROT_C_R;
	f->c.i = MANDELBROT_C_I;
	f->zoom = ZOOM;
	f->e.h = IMG_SIZE_H;
	f->e.w = IMG_SIZE_W;
	f->max.x = MANDELBROT_XMAX;
	f->max.y = MANDELBROT_YMAX;
	f->min.x = MANDELBROT_XMIN;
	f->min.y = MANDELBROT_YMIN;
	if(!(f->colors = ft_memalloc(sizeof(int *) * f->e.h)))
		return (0);
	i = -1;
	while (++i < f->e.h)
		if(!(f->colors[i] = ft_memalloc(sizeof(int) * f->e.w)))
			return (0);
	printf("init_fractol end. (h, w) (%i, %d)\n", f->e.h, f->e.w);
	return (1);
}

static int	init_julia(t_fractal *f)
{
	int i;

	if (!(f->name = ft_strdup("Julia")))
		return (0);
	f->f = &julia;
	f->i = 50; 
	f->c.r = -0.25;
	f->c.i = 0.04110;
	f->zoom = 1;
	f->e.h = 300;	
	f->e.w = 400;
	if(!(f->colors = ft_memalloc(sizeof(int *) * f->e.h)))
		return (0);
	i = -1;
	while (++i < f->e.h)
		if(!(f->colors[i] = ft_memalloc(sizeof(int) * f->e.w)))
			return (0);
	return (1);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:46:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/18 12:00:24 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	init_mandelbrot(t_fractal *f);
static int	init_julia(t_fractal *f);

/*
** Initalizes a fractal stucture based on the parameter y.
** Sets the function
*/

int	init_fractal(t_fractal *f, int y) //y is fractal index
{
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
	f->zoom = MANDELBROT_ZOOM;
	f->e.h = (MANDELBROT_YMAX - MANDELBROT_YMIN) * f->zoom;
	f->e.w = (MANDELBROT_XMAX - MANDELBROT_XMIN) * f->zoom;
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
	f->i = 300; 
	f->c.r = -0;
	f->c.i = 0.000;
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

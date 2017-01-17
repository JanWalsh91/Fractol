/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:46:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/17 15:10:38 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static int	init_mandelbrot(t_fractal *f);

/*
** Initalizes a fractal stucture based on the parameter y.
** Sets the function
*/

int	init_fractal(t_fractal *f, int y) //y is fractal index
{
	//if (y == JULIA)
	//	init_julia(*f);
	
	if (y == MANDELBROT)
		init_mandelbrot(f);
	return (1);
}


static int	init_mandelbrot(t_fractal *f)
{
	if (!(f->name = ft_strdup("Mandelbrot")))
		return (0);
	f->f = &mandelbrot;
	f->i = MANDELBROT_I;
	f->c.r = MANDELBROT_C_R;
	f->c.i = MANDELBROT_C_I;
	f->zoom = MANDELBROT_ZOOM;
	f->e.win.h = (0.6 - -2.1) * f->zoom;
	f->e.win.w = (1.2 - -1.2) * f->zoom;
	return (1);
}

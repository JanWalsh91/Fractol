/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:47:37 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/27 15:09:32 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initalizes a fractal stucture based on the parameter y.
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_bounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:53:07 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 12:54:32 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Resets bounds for Mandelbrot, Burning Ship, Julia and Newton fractals.
*/

void	reset_bounds(t_fractal *f)
{
	if (f->name == MANDELBROT || f->name == BURNING_SHIP)
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

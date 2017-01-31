/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_bounds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 12:53:07 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 14:45:25 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

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
		f->max.x = MANDELBROT_W;
		f->max.y = MANDELBROT_H;
	}
	else if (f->name == NEWTON)
	{
		f->min.x = NEWTON_XMIN;
		f->min.y = NEWTON_YMIN;
		f->max.x = NEWTON_XMAX;
		f->max.y = NEWTON_YMAX;
	}
}

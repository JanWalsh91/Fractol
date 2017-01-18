/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:03:58 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/18 17:17:32 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_bound(double *m, double zoom, int x, int i);

int	zoom(t_fractal *f, int button, int y, int x)
{
	//check max min zoom
	//check time ?
	//moidyf zoom
	if (button == MOUSE_UP || button == MOUSE_LMB)
		f->zoom = f->zoom * ZOOM_POW;
	else if (button == MOUSE_DOWN || button == MOUSE_RMB)
		f->zoom = f->zoom / ZOOM_POW;
	(f->zoom < 1) ? f->zoom = 1 : 0;
	//check zoom coord valididty
	x = (x - f->e.w / (2 * f->zoom) > 0) ? x : f->e.w / (2 * f->zoom);
	y = (y - f->e.h / (2 * f->zoom) > 0) ? y : f->e.h / (2 * f->zoom);
	x = (x - f->e.w / (2 * f->zoom) < f->e.w) ? x : f->e.w - f->e.w / (2 * f->zoom);
	y = (y - f->e.h / (2 * f->zoom) < f->e.h) ? y : f->e.h - f->e.h / (2 * f->zoom);
	//recalculate min max xy 
	update_bound(&f->min.x, f->zoom, x, 1);
	update_bound(&f->max.x, f->zoom, x, -1);
	update_bound(&f->min.y, f->zoom, x, 1);
	update_bound(&f->max.y, f->zoom, x, -1);
	//redisplay image
	calc_colors(f);
	draw(f);
	return (1);
}

static void update_bound(double *m, double zoom, int x, int i)
{
	double	y;

	y = 2;
	if (zoom == 1)
		return ;
	while (zoom != 1)
	{
		*m = *m + i * y;
		y /= 2;
		--zoom;
	}
	*m += ((double)x / IMG_SIZE + MANDELBROT_XMIN) / zoom;
}

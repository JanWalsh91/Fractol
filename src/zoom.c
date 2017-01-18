/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:03:58 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/18 17:54:40 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_bounds(t_fractal *f, int y, int x);

int	zoom(t_fractal *f, int button, int y, int x)
{
	//check if out of window
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

	printf("min = [%f;%f]\tmax = [%f;%f]\n", f->min.x, f->min.y, f->max.x, f->max.y);

	update_bounds(f, y, x);
	
	printf("min = [%f;%f]\tmax = [%f;%f]\n", f->min.x, f->min.y, f->max.x, f->max.y);
	//redisplay image
	calc_colors(f);
	draw(f);
	return (1);
}

static void update_bounds(t_fractal *f, int y, int x)
{
	/*double	y;

	y = 2 * i;
	if (zoom == 1)
		return ;
	while (zoom != 1)
	{
		*m = *m + y;
		y /= 2;
		--zoom;
	}*/
	f->max.x = MANDELBROT_XMAX * -pow((1 / f->e.w), f->zoom);
	f->max.x += ((double)x / IMG_SIZE + MANDELBROT_XMIN) / f->zoom;
	
	f->max.y = MANDELBROT_YMAX * -pow((1 / f->e.h), f->zoom);
	f->max.y += ((double)y / IMG_SIZE + MANDELBROT_XMIN) / f->zoom;
	
	f->min.x = MANDELBROT_XMIN * pow((1 / f->e.w), f->zoom);
	f->min.x += ((double)x / IMG_SIZE + MANDELBROT_XMIN) / f->zoom;
	
	f->min.y = MANDELBROT_YMIN * pow((1 / f->e.h), f->zoom);
	f->min.y += ((double)y / IMG_SIZE + MANDELBROT_XMIN) / f->zoom;

}

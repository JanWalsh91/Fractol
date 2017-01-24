/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:03:58 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/24 18:14:09 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_bounds(t_fractal *f, int y, int x, int is_zoom);
//static void	limit_mouse_coord(int *x, int *y, t_fractal *f);
static void	reset(t_fractal *f);

int	zoom(t_fractal *f, int button, int y, int x)
{
	//printf("zoom: button: %i, xy = [%d ; %d]\n", button, x, y);
	printf("minxy = [%f;%f]\tmax = [%f;%f]\n", f->min.x, f->min.y, f->max.x, f->max.y);
	if (button == MOUSE_UP || button == MOUSE_LMB)
	{
		f->zoom = f->zoom * ZOOM_POW;
		f->name != SIERPINSKY_CARPET ? f->i += 2 : 0;
		//limit_mouse_coord(&x, &y, f);
		update_bounds(f, y, x, 1);
	}
	else if ((button == MOUSE_DOWN || button == MOUSE_RMB) && f->zoom > 1)
	{
		f->name != SIERPINSKY_CARPET ? f->i -= 2 : 0;
		f->zoom = f->zoom / ZOOM_POW;
		(f->zoom < 1) ? f->zoom = 1 : 0;
		x = f->e.w / 2.0;
		y = f->e.h / 2.0;
		update_bounds(f, y, x, 0);
	}
	else if (button == KEY_SPACE)
		reset(f);
	printf("minxy = [%f;%f]\tmax = [%f;%f]\n", f->min.x, f->min.y, f->max.x, f->max.y);
	//redisplay image
	calc_colors(f);
	draw(f);
	return (1);
}

// limits may not be needed
/*
static void	limit_mouse_coord(int *x, int *y, t_fractal *f)
{
	*x = (*x - f->e.w / (2 * f->zoom) > 0) ? *x : f->e.w / (2 * f->zoom);
	*y = (*y - f->e.h / (2 * f->zoom) > 0) ? *y : f->e.h / (2 * f->zoom);
	*x = (*x + f->e.w / (2 * f->zoom) < f->e.w) ? *x : f->e.w - f->e.w / (2 * f->zoom);
	*y = (*y + f->e.h / (2 * f->zoom) < f->e.h) ? *y : f->e.h - f->e.h / (2 * f->zoom);
	//printf("limit mouse coords: xy = [%d ; %d]\n", *x, *y);
}
*/

static void update_bounds(t_fractal *f, int y, int x, int is_zoom)
{
	double	width;
	double	height;
	double zoomx, zoomy, jx, jy;

	if (f->zoom == 1)
		reset_bounds(f);
	else 
	{
		if (is_zoom)
		{
			printf("input: y: [%i] x: [%i] zoompow: [%i] zoom: [%f]\n", y, x, ZOOM_POW, f->zoom);
			printf("jx pre: [%f]\n", jx = (double)x / IMG_SIZE / f->zoom * ZOOM_POW +
					f->min.x);
			printf("jy pre: [%f]\n", jy = (double)y / IMG_SIZE / f->zoom * ZOOM_POW +
					f->min.y);

			width = (f->max.x - f->min.x) / 2;
			height = (f->max.y - f->min.y) / 2;
			printf("width: [%f] height: [%f]\n", width, height);
			zoomx = width * (((float)ZOOM_POW - 1) / ZOOM_POW);
			zoomy = height * (((float)ZOOM_POW - 1) / ZOOM_POW);
			//jx = -( (((double)jx * ZOOM_POW / (f->zoom)) + f->min.x + (width)));
			//jy = -( (((double)jy * ZOOM_POW / (f->zoom)) + f->min.y + (height)));
			jx = ((width - jx) + f->min.x) / 2;
			jy = ((height - jy) + f->min.y) / 2;
			//jy = jy * ZOOM_POW / (f->zoom) + f->min.y + height;
			f->min.x += zoomx - jx;
			f->min.y += zoomy - jy;


			printf("zoomx = [%f]\n", zoomx);
			printf("zoomy = [%f]\n", zoomy);
			printf("jx = [%f]\n",jx);
			printf("jy = [%f]\n", jy);
			printf("width = [%f]\n", width);
			printf("height = [%f]\n\n", height);


			//jx = -( (((double)jx * ZOOM_POW / (f->zoom)) + f->max.x + (width)));
			//jy = -( (((double)jy * ZOOM_POW / (f->zoom)) + f->max.y + (height)));
			f->max.x += -zoomx - jx;
			f->max.y += -zoomy - jy;
		}
		//else
		//{
			
		//}
	}
}

/*
static void update_bounds(t_fractal *f, int y, int x, int is_zoom)
{
	if (f->zoom == 1)
		reset_bounds(f);
	else
	{
		if (is_zoom)
		{
			f->min.x += (float)x / (IMG_SIZE * (f->zoom / 2)) - (float)f->e.w / (2 * f->zoom * IMG_SIZE);
			f->min.y += (float)y / (IMG_SIZE * (f->zoom / 2)) - (float)f->e.h / (2 * f->zoom * IMG_SIZE);
		}
		else
		{
			f->min.x -= (float)f->e.w / (2 * f->zoom * ZOOM_POW * IMG_SIZE);
			f->min.y -= (float)f->e.h / (2 * f->zoom * ZOOM_POW * IMG_SIZE);
		}
	}
}
*/

static void	reset(t_fractal *f)
{
	reset_bounds(f);
	f->zoom = ZOOM;
	f->name == MANDELBROT ? f->i = MANDELBROT_I : 0;
	f->name == JULIA ? f->i = JULIA_I : 0;
	f->name == SIERPINSKY_CARPET ? f->i = SIERPINSKY_CARPET_I : 0;
	//f->name == NEWTON ? f->i = NEWTON_I : 0;
}

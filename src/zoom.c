/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:03:58 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/25 12:52:23 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_bounds(t_fractal *f, int y, int x, int is_zoom);
static int	reset(t_fractal *f);

int	zoom(t_fractal *f, int button, int y, int x)
{
	//printf("zoom: button: %i, xy = [%d ; %d]\n", button, x, y);
	//printf("minxy = [%f;%f]\tmax = [%f;%f]\n",
	//	f->min.x, f->min.y, f->max.x, f->max.y);
	if (button == MOUSE_UP || button == MOUSE_LMB)
	{
		f->zoom = f->zoom * ZOOM_POW;
		f->name != SIERPINSKY_CARPET ? f->i += 2 : 0;
		//limit_mouse_coord(&x, &y, f);
		update_bounds(f, y, x, 1);
		//update_bounds(f, 120, 135, 1);
	}
	else if ((button == MOUSE_DOWN || button == MOUSE_RMB) && f->zoom > 1)
	{
		f->name != SIERPINSKY_CARPET ? f->i -= 2 : 0;
		f->zoom = f->zoom / ZOOM_POW;
		(f->zoom < 1) ? f->zoom = 1 : 0;
		update_bounds(f, y, x, 0);
	}
	else if (button == KEY_SPACE)
		reset(f);
	//printf("minxy = [%f;%f]\tmax = [%f;%f]\n",
	//		f->min.x, f->min.y, f->max.x, f->max.y);
	calc_colors(f);
	draw(f);
	return (1);
}

static void update_bounds(t_fractal *f, int y, int x, int is_zoom)
{
	double	width;
	double	height;
	double	zoomx, zoomy, jx = 0, jy = 0;

	if (f->zoom == 1)
		return (reset_bounds(f));

	//printf("input: y: [%i] x: [%i] zoompow: [%f] zoom: [%f]\n", 
	//		y, x, ZOOM_POW, f->zoom);
	width = (f->max.x - f->min.x) / 2.0;
	height = (f->max.y - f->min.y) / 2.0;
	//printf("j(yx) converted: [%f][%f]\n", jy, jx);
	if (is_zoom)
	{
		jx = (double)x / IMG_SIZE / f->zoom * (float)ZOOM_POW + f->min.x;
		jy = (double)y / IMG_SIZE / f->zoom * (float)ZOOM_POW + f->min.y;
		//printf("width: [%f] height: [%f]\n", width, height);
		zoomx = width * (((float)ZOOM_POW - 1) / (float)ZOOM_POW);
		zoomy = height * (((float)ZOOM_POW - 1) / (float)ZOOM_POW);
		jx = (width - (jx - f->min.x)) * (ZOOM_POW - 1) / (ZOOM_POW);
		jy = (height - (jy - f->min.y)) * (ZOOM_POW - 1) / (ZOOM_POW);
		f->min.x += zoomx - jx;
		f->min.y += zoomy - jy; //simplify with zom pow
		f->max.x += -zoomx - jx;
		f->max.y += -zoomy - jy;
	}

	else
	{
		jx = (double)x / IMG_SIZE / f->zoom / (float)ZOOM_POW + f->min.x;
		jy = (double)y / IMG_SIZE / f->zoom / (float)ZOOM_POW + f->min.y;
		zoomx = width * (ZOOM_POW - 1);
		zoomy = height * (ZOOM_POW - 1);
		jx = ((width - jx) + f->min.x) * (ZOOM_POW - 1) / (ZOOM_POW);
		jy = ((height - jy) + f->min.y) * (ZOOM_POW - 1) / (ZOOM_POW);
		f->min.x += -zoomx - jx;
		f->min.y += -zoomy - jy; //simplify with zom pow
		f->max.x += zoomx - jx;
		f->max.y += zoomy - jy;
	}
	/*
	printf("zoomx = [%f]\n", zoomx);
	printf("zoomy = [%f]\n", zoomy);
	printf("jx = [%f]\n",jx);
	printf("jy = [%f]\n", jy);
	printf("width = [%f]\n", width);
	printf("height = [%f]\n\n", height);
	*/
}

static int	reset(t_fractal *f)
{
	reset_bounds(f);
	f->zoom = ZOOM;
	f->name == MANDELBROT ? f->i = MANDELBROT_I : 0;
	f->name == JULIA ? f->i = JULIA_I : 0;
	f->name == SIERPINSKY_CARPET ? f->i = SIERPINSKY_CARPET_I : 0;
	//f->name == NEWTON ? f->i = NEWTON_I : 0;
	return (1);
}

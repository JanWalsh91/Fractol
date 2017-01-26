/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:03:58 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 11:52:06 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_bounds(t_fractal *f, int *y, int *x, int is_zoom);
static void	zoom_in(t_fractal *f, int *y, int *x, t_vec2 *dim);
static void	zoom_out(t_fractal *f, int *y, int *x, t_vec2 *dim);
static int	reset(t_fractal *f);

int	zoom(t_fractal *f, int button, int y, int x)
{
	//printf("zoom: button: %i, xy = [%d ; %d]\n", button, x, y);
	//printf("minxy = [%f;%f]\tmax = [%f;%f]\n",
	//	f->min.x, f->min.y, f->max.x, f->max.y);
	if (f->name == SIERPINSKY_CARPET)
		return (1);
	if (button == MOUSE_UP || button == MOUSE_LMB)
	{
		f->zoom = f->zoom * ZOOM_POW;
		update_bounds(f, &y, &x, 1);
	}
	else if ((button == MOUSE_DOWN || button == MOUSE_RMB) && f->zoom > 1)
	{
		f->zoom = f->zoom / ZOOM_POW;
		(f->zoom < 1) ? f->zoom = 1 : 0;
		update_bounds(f, &y, &x, 0);
	}
	else if (button == KEY_SPACE)
		reset(f);
	printf("minxy = [%f;%f]\tmax = [%f;%f]\n",
			f->min.x, f->min.y, f->max.x, f->max.y);
	calc_colors(f);
	draw(f);
	return (1);
}

static void update_bounds(t_fractal *f, int *y, int *x, int is_zoom)
{
	t_vec2	dim;

	if (f->zoom == 1)
		return (reset_bounds(f));

	//printf("input: y: [%i] x: [%i] zoompow: [%f] zoom: [%f]\n", 
	//		y, x, ZOOM_POW, f->zoom);
	dim.x = (f->max.x - f->min.x) / 2.0;
	dim.y = (f->max.y - f->min.y) / 2.0;
	//printf("j(yx) converted: [%f][%f]\n", jy, jx);
	is_zoom ? zoom_in(f, y, x, &dim) : zoom_out(f, y, x, &dim);
	/*
	printf("zoomx = [%f]\n", zoomx);
	printf("zoomy = [%f]\n", zoomy);
	printf("jx = [%f]\n",jx);
	printf("jy = [%f]\n", jy);
	printf("width = [%f]\n", width);
	printf("height = [%f]\n\n", height);
	*/
}

static void	zoom_in(t_fractal *f, int *y, int *x, t_vec2 *dim)
{
	t_vec2	j;
	t_vec2	zoom;

	j.x = (double)*x / IMG_SIZE / f->zoom * (float)ZOOM_POW + f->min.x;
	j.y = (double)*y / IMG_SIZE / f->zoom * (float)ZOOM_POW + f->min.y;
	//printf("width: [%f] height: [%f]\n", width, height);
	zoom.x = dim->x * (((float)ZOOM_POW - 1) / (float)ZOOM_POW);
	zoom.y = dim->y * (((float)ZOOM_POW - 1) / (float)ZOOM_POW);
	j.x = (dim->x - (j.x - f->min.x)) * (ZOOM_POW - 1) / (ZOOM_POW);
	j.y = (dim->y - (j.y - f->min.y)) * (ZOOM_POW - 1) / (ZOOM_POW);
	f->min.x += zoom.x - j.x;
	f->min.y += zoom.y - j.y; //simplify with zom pow
	f->max.x += -zoom.x - j.x;
	f->max.y += -zoom.y - j.y;
}

static void	zoom_out(t_fractal *f, int *y, int *x, t_vec2 *dim)
{
	t_vec2	j;
	t_vec2	zoom;

	j.x = (double)*x / IMG_SIZE / f->zoom / (float)ZOOM_POW + f->min.x;
	j.y = (double)*y / IMG_SIZE / f->zoom / (float)ZOOM_POW + f->min.y;
	zoom.x = dim->x * (ZOOM_POW - 1);
	zoom.y = dim->y * (ZOOM_POW - 1);
	j.x = ((dim->x - j.x) + f->min.x) * (ZOOM_POW - 1) / (ZOOM_POW);
	j.y = ((dim->y - j.y) + f->min.y) * (ZOOM_POW - 1) / (ZOOM_POW);
	f->min.x += -zoom.x - j.x;
	f->min.y += -zoom.y - j.y; //simplify with zom pow
	f->max.x += zoom.x - j.x;
	f->max.y += zoom.y - j.y;
}

static int	reset(t_fractal *f)
{
	reset_bounds(f);
	f->zoom = ZOOM;
	f->name == MANDELBROT ? f->i = MANDELBROT_I : 0;
	f->name == JULIA ? f->i = JULIA_I : 0;
	// conflict: sierpinsky & newton f->i deleted
	f->name == SIERPINSKY_CARPET ? f->i = SIERPINSKY_CARPET_I : 0;
	f->name == NEWTON ? f->i = NEWTON_I : 0;
	//f->name == NEWTON ? f->i = NEWTON_I : 0;
	return (1);
}

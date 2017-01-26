/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:03:58 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 17:52:26 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_bounds(t_fractal *f, int *y, int *x, int is_zoom);
static void	zoom_in(t_fractal *f, int *y, int *x, t_vec2 *dim);
static void	zoom_out(t_fractal *f, int *y, int *x, t_vec2 *dim);
static int	reset(t_fractal *f);

/*
** Updates the min / max values for the given fractal depending on the
** mouse position. Reset the value to default if Space is pressed
*/

int			zoom(t_fractal *f, int button, int y, int x)
{
	if (button == KEY_SPACE)
		reset(f);
	else if (f->name == SIERPINSKY_CARPET)
		return (1);
	else if (button == MOUSE_UP || button == MOUSE_LMB)
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
	calc_colors(f);
	draw(f);
	return (1);
}

/*
** Calls the appropriate function depending on the event
*/

static void	update_bounds(t_fractal *f, int *y, int *x, int is_zoom)
{
	t_vec2	dim;

	if (f->zoom == 1)
		return (reset_bounds(f));
	dim.x = (f->max.x - f->min.x) / 2.0;
	dim.y = (f->max.y - f->min.y) / 2.0;
	is_zoom ? zoom_in(f, y, x, &dim) : zoom_out(f, y, x, &dim);
}

/*
** Calculates the new min and max values when a zoom in event is triggered
*/

static void	zoom_in(t_fractal *f, int *y, int *x, t_vec2 *dim)
{
	t_vec2	j;
	t_vec2	zoom;

	j.x = (double)*x / IMG_SIZE / f->zoom * (float)ZOOM_POW + f->min.x;
	j.y = (double)*y / IMG_SIZE / f->zoom * (float)ZOOM_POW + f->min.y;
	zoom.x = dim->x * (((float)ZOOM_POW - 1) / (float)ZOOM_POW);
	zoom.y = dim->y * (((float)ZOOM_POW - 1) / (float)ZOOM_POW);
	j.x = (dim->x - (j.x - f->min.x)) * (ZOOM_POW - 1) / (ZOOM_POW);
	j.y = (dim->y - (j.y - f->min.y)) * (ZOOM_POW - 1) / (ZOOM_POW);
	f->min.x += zoom.x - j.x;
	f->min.y += zoom.y - j.y;
	f->max.x += -zoom.x - j.x;
	f->max.y += -zoom.y - j.y;
}

/*
** Calculates the new min and max values when a zoom out event is triggered
*/

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
	f->min.y += -zoom.y - j.y;
	f->max.x += zoom.x - j.x;
	f->max.y += zoom.y - j.y;
}

/*
** Reset the boundaries to default
*/

static int	reset(t_fractal *f)
{
	reset_bounds(f);
	f->zoom = ZOOM;
	return (1);
}

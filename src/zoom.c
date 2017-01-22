/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:03:58 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/22 14:08:52 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	update_bounds(t_fractal *f, int y, int x, int is_zoom);
static void	limit_mouse_coord(int *x, int *y, t_fractal *f);
static void	reset(t_fractal *f);

int	zoom(t_fractal *f, int button, int y, int x)
{
	//check if out of window
	//check max min zoom
	//check time ?
	//moidyf zoom
	printf("zoom: button: %i, xy = [%d ; %d]\n", button, x, y);
	printf("minxy = [%f;%f]\tmax = [%f;%f]\n", f->min.x, f->min.y, f->max.x, f->max.y);

	if (button == MOUSE_UP || button == MOUSE_LMB)
	{
		f->zoom = f->zoom * ZOOM_POW;
		f->i += 2;
		limit_mouse_coord(&x, &y, f);
		update_bounds(f, y, x, 1);
	}
	else if ((button == MOUSE_DOWN || button == MOUSE_RMB) && f->zoom > 1)
	{
		f->i -= 2;
		f->zoom = f->zoom / ZOOM_POW;
		(f->zoom < 1) ? f->zoom = 1 : 0;
		x = f->e.w / 2.0;
		y = f->e.h / 2.0;
		update_bounds(f, y, x, 0);
	}
	else if (button == KEY_SPACE)
		reset(f);
	//check zoom coord valididty

	//recalculate min max xy 


	
	printf("minxy = [%f;%f]\tmax = [%f;%f]\n", f->min.x, f->min.y, f->max.x, f->max.y);
	//redisplay image
	calc_colors(f);
	draw(f);
	return (1);
}

static void	limit_mouse_coord(int *x, int *y, t_fractal *f)
{
	*x = (*x - f->e.w / (2 * f->zoom) > 0) ? *x : f->e.w / (2 * f->zoom);
	*y = (*y - f->e.h / (2 * f->zoom) > 0) ? *y : f->e.h / (2 * f->zoom);
	*x = (*x + f->e.w / (2 * f->zoom) < f->e.w) ? *x : f->e.w - f->e.w / (2 * f->zoom);
	*y = (*y + f->e.h / (2 * f->zoom) < f->e.h) ? *y : f->e.h - f->e.h / (2 * f->zoom);
	printf("limit mouse coords: xy = [%d ; %d]\n", *x, *y);
}

static void update_bounds(t_fractal *f, int y, int x, int is_zoom)
{
	if (f->zoom == 1)
		reset_bounds(f);
	else
	{
		if (is_zoom)
		{
			f->min.x += ((float)x / (IMG_SIZE * 0.5 * f->zoom)) - (float)f->e.w / (2 * f->zoom * IMG_SIZE);
			f->min.y += ((float)y / (IMG_SIZE * 0.5 * f->zoom)) - (float)f->e.h / (2 * f->zoom * IMG_SIZE);
		}
		else
		{
			f->min.x -= (float)f->e.w / (2 * f->zoom * ZOOM_POW * IMG_SIZE);
			f->min.y -= (float)f->e.h / (2 * f->zoom * ZOOM_POW * IMG_SIZE);
		}
	}
}

static void	reset(t_fractal *f)
{
	reset_bounds(f);
	f->zoom = ZOOM;
	f->i = 20;
}

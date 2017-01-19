/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:54:38 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/19 10:15:10 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_event(int button, int x, int y, t_fractal *f)
{
	(void)f;
	if (button == MOUSE_UP || button == MOUSE_LMB ||
			button == MOUSE_DOWN || button == MOUSE_RMB)
		zoom(f, button, y, x);
	printf("button: %i (y, x): (%i, %i)\n", button, y, x);
	return (0);
}

int		mouse_motion(int x, int y, t_fractal *f)
{
	if (x < 0 || y < 0 || x > f->e.w || y > f->e.h)
		return (1);
	f->c.r = (double)x / 100 + MANDELBROT_XMIN;
	f->c.i = (double)y / 100 + MANDELBROT_YMIN;
	calc_colors(f);
	draw(f);
	(void)f;

	return (0);
}

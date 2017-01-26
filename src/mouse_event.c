/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:54:38 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 11:21:22 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_event(int button, int x, int y, t_fractal *f)
{
	if (x < 0 || y < 0 || x > f->e.w || y > f->e.h)
		return (1);
	//printf("button: %i (x, y): (%i, %i)\n", button, x, y);
	if (button == MOUSE_UP || button == MOUSE_LMB ||
			button == MOUSE_DOWN || button == MOUSE_RMB)
		zoom(f, button, y, x);
	return (0);
}

int		mouse_motion(int x, int y, t_fractal *f)
{
	if (!f->mouse_on || x < 0 || y < 0 || x > f->e.w || y > f->e.h)
		return (1);
	f->c.r = (double)x / IMG_SIZE + MANDELBROT_XMIN;
	f->c.i = (double)y / IMG_SIZE + MANDELBROT_YMIN;
	calc_colors(f);
	draw(f);
	(void)f;

	return (0);
}

/*
** Switches updating the julia fractal based on mouse position on or off.
*/

int		switch_julia_constant(t_fractal *f)
{
	f->mouse_on = f->mouse_on ? 0 : 1;
		return (1);
}

int		red_button_exit(int *frac)
{
	static int nb = -1;

	if (nb == -1)
		nb = *frac;
	if (--nb == 0)
		exit(0);
	// TODO: free stuff
	return (0);
}

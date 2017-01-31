/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:54:38 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 13:17:54 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Definition of the window mouse listener. Acts only if the mouse cursor
** hovers over the window.
*/

int		mouse_event(int button, int x, int y, t_fractal *f)
{
	if (x < 0 || y < 0 || x > f->e.w || y > f->e.h)
		return (1);
	if (button == MOUSE_UP || button == MOUSE_LMB ||
			button == MOUSE_DOWN || button == MOUSE_RMB)
		zoom(f, button, y, x);
	return (0);
}

/*
** Julia's mouse listener. When the mouse hovers the window and the cursor
** is moving, the function updates the complex constant C.
*/

int		mouse_motion(int x, int y, t_fractal *f)
{
	if (!f->mouse_on || x < 0 || y < 0 || x > f->e.w || y > f->e.h)
		return (1);
	f->c.r = (double)x / f->img_size + MANDELBROT_XMIN;
	f->c.i = (double)y / f->img_size + MANDELBROT_YMIN;
	calc_colors(f);
	draw(f);
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

/*
** Close the current window, and exit the programm if all of them are closed.
*/

int		red_button_exit(t_win_manager *f_list)
{
	static int nb = -1;

	if (nb == -1)
		nb = f_list->nb_frac;
	if (--nb == 0)
	{
		free_fractals(f_list);
		exit(0);
	}
	return (0);
}

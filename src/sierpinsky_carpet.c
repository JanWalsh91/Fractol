/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 14:33:46 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 14:59:06 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Determines if a point is in the sierpinsky set and returns a color.
*/

static int	sierpinsky_carpet_iterations(t_pt2 *j, t_sierpinsky_tools *t,
		t_fractal *f);

int			sierpinsky_carpet(t_pt2 j, t_fractal *f)
{
	t_sierpinsky_tools	t;
	t_pt2				cp;

	t.i = f->i;
	cp.x = j.x;
	cp.y = j.y;
	t.w = f->e.w;
	t.h = f->e.h;
	return (sierpinsky_carpet_iterations(&cp, &t, f));
}

static int	sierpinsky_carpet_iterations(t_pt2 *j, t_sierpinsky_tools *t,
		t_fractal *f)
{
	t->w /= 3;
	t->h /= 3;
	if ( ((j->y / t->h) % 3 == 1 && (j->x / t->w) % 3 == 1))
	{
		f->mouse_on = 1;
		return (f->get_color[f->color_set](t->i, f));
	}
	--t->i;
	if (!t->i || (t->w < 3) || t->h < 3)
	{
		f->mouse_on = 0;
		return (f->get_color[f->color_set](t->i, f));
	}
	else
		return (sierpinsky_carpet_iterations(j, t, f));
	return (0);
}

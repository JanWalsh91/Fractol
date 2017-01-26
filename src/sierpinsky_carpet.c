/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 14:33:46 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/25 17:02:46 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int	sierpinsky_carpet_iterations(t_pt2 *j, t_sierpinsky_tools *t);

int	sierpinsky_carpet(t_pt2 j, t_fractal *f)
{
	t_sierpinsky_tools	t;
	t_pt2				cp;

	t.i = f->i;
	cp.x = j.x / f->zoom + f->min.x;
	cp.y = j.y / f->zoom + f->min.y;
	//t.w = f->e.w / f->zoom + f->min.x;
	//t.h = f->e.h / f->zoom + f->min.y;
	t.w = f->max.x - f->min.x;
	t.h = f->max.y - f->min.y;
	return (sierpinsky_carpet_iterations(&cp, &t));
}

static int	sierpinsky_carpet_iterations(t_pt2 *j, t_sierpinsky_tools *t)
{
	t->w /= 3;
	t->h /= 3;
	if (t->w < 3 || t->h < 3)
		return (STEEL_BLUE);
	if ( ((j->y / t->h) % 3 == 1 && (j->x / t->w) % 3 == 1))
		return (t->i % 2 ? GOLDEN_ROD : CRIMSON);
	--t->i;
	if (!t->i || (t->w < 3) || t->h < 3)
		return (STEEL_BLUE);
	else
		return (sierpinsky_carpet_iterations(j, t));
	return (0);
}

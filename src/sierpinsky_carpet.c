/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_carpet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 14:33:46 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/22 16:22:26 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static int	sierpinsky_carpet_iterations(t_pt2 *j, t_sierpinsky_tools *t);

int	sierpinsky_carpet(t_pt2 j, t_fractal *f)
{
	t_sierpinsky_tools	t;
	t_pt2				cp;

	cp = j;
	t.i = f->i;
	t.w = f->e.w;
	t.h = f->e.h;
	return (sierpinsky_carpet_iterations(&cp, &t));
}
/*
int	sierpinsky_carpet(t_pt2 j, t_fractal *f)
{
	t_sierpinsky_tools t;

	t.w = f->e.w;
	t.h = f->e.h;
	t.i = f->i;
	if (t.i > 0)
		return (sierpinsky_carpet_iterations(j, &t));
	else
		return (BLACK);
}
*/
/*
static int	sierpinsky_carpet_iterations(t_pt2 j, t_sierpinsky_tools *t)
{
	if (t->i > 0)
	{
		return (sierpinsky_carpet_iterations(j, t);
	}
	else if (t->w / 3 < j.x && j.x < 2 * t->w / 3 &&
		t->h / 3 < j.y && j.y < 2 * t->h / 3)
		return (HOT_PINK);
	--t->i;
	return (LAVENDER);
}
*/

static int	sierpinsky_carpet_iterations(t_pt2 *j, t_sierpinsky_tools *t)
{
	t->w /= 3;
	t->h /= 3;
	if (((j->y / t->h) % 3 == 1 && (j->x / t->w) % 3 == 1))
		return (t->i % 2 ? GOLDEN_ROD : CRIMSON);
	--t->i;
	if (!t->i || (t->w < 3) || t->h < 3)
		return (STEEL_BLUE);
	else
		return (sierpinsky_carpet_iterations(j, t));
	return (0);
}

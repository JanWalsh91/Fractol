/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:49:47 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 15:08:45 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
** Moves the fractal around.
*/

int	move(t_fractal *f, int keycode)
{
	double	translation;

	if (f->name == SIERPINSKY_CARPET)
		return (1);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
	{
		translation = (f->max.y - f->min.y) / 10;
		f->max.y += (keycode == KEY_DOWN) ? translation : -translation;
		f->min.y += (keycode == KEY_DOWN) ? translation : -translation;
	}
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
	{
		translation = (f->max.x - f->min.x) / 10;
		f->max.x += (keycode == KEY_RIGHT ? translation : -translation);
		f->min.x += (keycode == KEY_RIGHT ? translation : -translation);
	}
	calc_colors(f);
	draw(f);
	return (1);
}

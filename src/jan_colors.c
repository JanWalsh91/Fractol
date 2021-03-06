/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jan_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 17:49:09 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 15:37:59 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This file includes functions for different color sets for the jan
** fractal.
*/

static int	get_color(t_incr incr, int i);

int			col_6_0(int i, t_fractal *f)
{
	int	color;
	int	y;

	color = 0;
	y = -1;
	while (++y < COLORS_PER_SET - 1)
	{
		if (i < f->i * (y + 1) / (COLORS_PER_SET - 1))
			return (get_color(f->incr[0][y], i - (float)f->i * y /
				(COLORS_PER_SET - 1)));
	}
	return (color);
}

int			col_6_1(int i, t_fractal *f)
{
	int	color;
	int	y;

	color = 0;
	y = -1;
	while (++y < COLORS_PER_SET - 1)
	{
		if (i < f->i * (y + 1) / (COLORS_PER_SET - 1))
			return (get_color(f->incr[1][y], i - (float)f->i * y /
				(COLORS_PER_SET - 1)));
	}
	return (color);
}

int			col_6_2(int i, t_fractal *f)
{
	int	color;
	int	y;

	color = 0;
	y = -1;
	while (++y < COLORS_PER_SET - 1)
	{
		if (i < f->i * (y + 1) / (COLORS_PER_SET - 1))
			return (get_color(f->incr[2][y], i - (float)f->i * y /
				(COLORS_PER_SET - 1)));
	}
	return (color);
}

static int	get_color(t_incr incr, int i)
{
	return (incr.c_1 + ft_round((i * incr.r)) * 0x10000 +
		ft_round((i * incr.g)) * 0x100 +
		ft_round((i * incr.b)));
}

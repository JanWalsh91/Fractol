/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_colors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 14:53:05 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 14:57:04 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This file inclues functions for different color sets for the Burning Ship
** fractal.
*/

int	col_3_0(int i, t_fractal *f)
{
	int		color;
	int		index;
	int		channels[4];

	index = i + 1 - (log(2) / abs(f->i) / log (2));
	channels[0] = (unsigned char)(sin(0.017 * index + 4) * 230);
	channels[1] = (unsigned char)(sin(0.013 * index + 2) * 230);
	channels[2] = (unsigned char)(sin(0.01 * index + 1) * 230);
	channels[3] = 200;
	color = channels[0] + (channels[1] << 2) + (channels[2] << 4) +
		(channels[3] << 6);
	return (color);
}

int	col_3_1(int i, t_fractal *f)
{
	int color;
	int mod;

	color = 0;
	mod = ((i % f->i) % 5);
	(mod == 0) ? color = GOLDEN_ROD : 0;
	(mod == 1) ? color = LAVENDER : 0;
	(mod == 2) ? color = STEEL_BLUE : 0;
	(mod == 3) ? color = INDIAN_RED : 0;
	(mod == 4) ? color = LAWN_GREEN : 0;
	return (color);
}

int	col_3_2(int i, t_fractal *f)
{
	int color;

	(void)f->i;
	color = i * 3.12;
	return (color);
}

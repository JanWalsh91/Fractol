/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:49:57 by tgros             #+#    #+#             */
/*   Updated: 2017/01/26 15:00:06 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This file includes functions for the r g and b values of the Newton fracal.
*/


int	col_4_0(int i, t_fractal *f)
{
	int color;
	int mod;

	color = 0;
	mod = ((i % f->i) % 5);
	(mod == 0) ? color = 0xFE0000 : 0;
	(mod == 1) ? color = 0xEE0000 : 0;
	(mod == 2) ? color = 0xDD0000 : 0;
	(mod == 3) ? color = 0xCC0000 : 0;
	(mod == 4) ? color = 0xBB0000 : 0;
	return (color);
}

int	col_4_1(int i, t_fractal *f)
{
	int color;
	int mod;

	color = 0;
	mod = ((i % f->i) % 5);
	(mod == 0) ? color = 0x00FE00 : 0;
	(mod == 1) ? color = 0x00EE00 : 0;
	(mod == 2) ? color = 0x00DD00 : 0;
	(mod == 3) ? color = 0x00CC00 : 0;
	(mod == 4) ? color = 0x00BB00 : 0;
	return (color);
}

int	col_4_2(int i, t_fractal *f)
{
	int color;
	int mod;

	color = 0;
	mod = ((i % f->i) % 5);
	(mod == 0) ? color = 0x0000FE : 0;
	(mod == 1) ? color = 0x0000EE : 0;
	(mod == 2) ? color = 0x0000DD : 0;
	(mod == 3) ? color = 0x0000CC : 0;
	(mod == 4) ? color = 0x0000BB : 0;
	return (color);
}

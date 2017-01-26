/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:56:46 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 13:18:05 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This file inclues functions for different color sets for the Julia
** fractal.
*/

int	col_1_0(int i, int i_max)
{
	int color;

	(void)i_max;
	color = i * 100;
	return (color);
}

int	col_1_1(int i, int i_max)
{
	int color;
	int mod;

	color = 0;
	mod = (i % i_max) % 5;
	(mod == 0) ? color = OLIVE : 0;
	(mod == 1) ? color = AQUA_MARINE : 0;
	(mod == 2) ? color = BEIGE : 0;
	(mod == 3) ? color = PALE_GREEN : 0;
	(mod == 4) ? color = GOLD : 0;
	return (color);
}

int	col_1_2(int i, int i_max)
{
	int color;
	(void)i_max;

	color = (int)(log(i) * 0xCC0044) ;
	color = (color & 0xFF0044);
	return (color);
}


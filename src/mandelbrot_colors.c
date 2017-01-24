/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_colors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:54:48 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/23 16:27:48 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This file inclues functions for different color sets for the Mandelbrot
** fractal.
*/

int	col_0_0(int i, int i_max)
{
	int color;

	color = ((i % i_max) * 0x70102) % 0xAFFFFF;
	return (color);
}

int	col_0_1(int i, int i_max)
{
	int color;
	int mod;

	color = 0;
	mod = ((i % i_max) % 5);
	(mod == 0) ? color = GOLDEN_ROD : 0;
	(mod == 1) ? color = LAVENDER : 0;
	(mod == 2) ? color = STEEL_BLUE : 0;
	(mod == 3) ? color = INDIAN_RED : 0;
	(mod == 4) ? color = LAWN_GREEN : 0;
	return (color);
}

int	col_0_2(int i, int i_max)
{
	int color;

	(void)i_max;
	color = i * 3.12;
	return (color);
}

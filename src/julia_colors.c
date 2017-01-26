/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:56:46 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 15:01:04 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This file inclues functions for different color sets for the Julia
** fractal.
*/

int	col_1_0(int i, t_fractal *f)
{
	int color;

	(void)f;
	color = i * 100;
	return (color);
}

int	col_1_1(int i, t_fractal *f)
{
	int color;
	int mod;

	(void)f;
	color = 0;
	mod = (i % f->i) % 5;
	(mod == 0) ? color = OLIVE : 0;
	(mod == 1) ? color = AQUA_MARINE : 0;
	(mod == 2) ? color = BEIGE : 0;
	(mod == 3) ? color = PALE_GREEN : 0;
	(mod == 4) ? color = GOLD : 0;
	return (color);
}

int	col_1_2(int i, t_fractal *f)
{
	int color;

	(void)f;
	color = (int)(log(i) * 0xCC0044) ;
	color = (color & 0xFF0044);
	return (color);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_carpet_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:57:48 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/27 11:43:35 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This file includes functions for different color sets for the Sierpinsky
** Carpet fractal.
*/

int	col_2_0(int i, t_fractal *f)
{
	(void)f;
	if (!i)
		return (STEEL_BLUE);
	return (FOREST_GREEN);
}

int	col_2_1(int i, t_fractal *f)
{
	(void)f;
	if (!i)
		return (GOLDEN_ROD);
	return (SILVER);
}

int	col_2_2(int i, t_fractal *f)
{
	(void)f;
	if (!i)
		return (INDIGO);
	return (ORCHID);
}

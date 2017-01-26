/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_carpet_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:57:48 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 14:45:40 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This file inclues functions for different color sets for the Sierpinsky
** Carpet fractal.
*/

int	col_2_0(int i, t_fractal *f)
{
	(void)i;
	if (!f->i)
		return (STEEL_BLUE);
	return (FOREST_GREEN);
}

int	col_2_1(int i, t_fractal *f)
{
	(void)i;
	if (!f->i)
		return (GOLDEN_ROD);
	return (SILVER);
}

int	col_2_2(int i, t_fractal *f)
{
	(void)i;
	if (!f->i)
		return (INDIGO);
	return (ORCHID);
}

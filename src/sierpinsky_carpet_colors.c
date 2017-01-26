/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_carpet_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:57:48 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 12:22:59 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This file inclues functions for different color sets for the Sierpinsky
** Carpet fractal.
*/

int	col_2_0(int i, int i_max)
{
	(void)i;
	if (!i_max)
		return (STEEL_BLUE);
	return (FOREST_GREEN);
}

int	col_2_1(int i, int i_max)
{
	(void)i;
	if (!i_max)
		return (GOLDEN_ROD);
	return (SILVER);
}

int	col_2_2(int i, int i_max)
{
	(void)i;
	if (!i_max)
		return (INDIGO);
	return (ORCHID);
}

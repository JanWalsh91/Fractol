/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinsky_carpet_colors.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:57:48 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/23 13:17:47 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** This file inclues functions for different color sets for the Sierpinsky
** Carpet fractal.
*/

int	col_2_0(int i, int i_max)
{
	int color;
	(void)i_max;

	color = i * 1000;
	return (color);
}

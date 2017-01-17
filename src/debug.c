/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:00:56 by tgros             #+#    #+#             */
/*   Updated: 2017/01/17 17:47:12 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	display_colors(int **tab, int xmax, int ymax)
{
	int i;
	int j;

	j = -1;
	while (++j < ymax)
	{
		i = -1;
		while (++i < xmax)
			printf("(y: %d; x: %d; color: %#x)\n", j, i, tab[j][i]);
		printf("\n");
	}
}

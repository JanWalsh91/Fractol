/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:44:40 by tgros             #+#    #+#             */
/*   Updated: 2017/01/17 19:26:32 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
** Draws fractal of index y to the image.
*/

int			calc_colors(t_fractal *f) //y is the fractal index
{
	t_pt2	i;

	printf("calc_colors\n");
	i.y = 0;
	i.x = 0;
	while (i.y < f->e.h)
	{
		f->colors[i.y][i.x] = f->f(i, f);
		ft_increment_index(&i.y, &i.x, f->e.w);
	}
	//display_colors(f->colors, f->e.w, f->e.h);
	return (1);
}

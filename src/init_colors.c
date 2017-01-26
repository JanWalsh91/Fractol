/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:46:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 13:02:19 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initializes f->colors and f->get_color for each fractal.
*/

int	init_colors(t_fractal *f)
{
	int	i;

	if (!(f->colors = ft_memalloc(sizeof(int *) * f->e.h)))
		return (0);
	i = -1;
	while (++i < f->e.h)
		if (!(f->colors[i] = ft_memalloc(sizeof(int) * f->e.w)))
			return (0);
	if (!(f->get_color = ft_memalloc(sizeof(*(f->get_color)) *
					f->color_set_count)))
		return (0);
	return (1);
}

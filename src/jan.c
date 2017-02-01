/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jan.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:12:14 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/01 11:18:57 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

/*
** Determines if a point is in the jan set and returns a color.
*/

int	jan(t_pt2 j, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			i;

	c.r = (float)j.x / f->img_size / f->zoom + f->min.x;
	c.i = (float)j.y / f->img_size / f->zoom + f->min.y;
	i = -1;
	z = c_horseshoe(c);
	while (c_modulus(z) < 2 && ++i < f->i)
	{
		z = c_add(c_product(c_swirl(z), c_swirl(z)), c_swirl(c));
		z = c_swirl(z);
	}
	if (i == f->i)
		i = i * c_modulus(z);
	return (f->get_color[f->color_set](i, f));
}

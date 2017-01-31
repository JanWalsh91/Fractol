/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:12:43 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 13:18:39 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Determines if a point is in the burning ship set and returns a color.
*/

int	burning_ship(t_pt2 j, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			i;

	c.r = (float)j.x / f->img_size / f->zoom + f->min.x;
	c.i = (float)j.y / f->img_size / f->zoom + f->min.y;
	z.r = MANDELBROT_C_I;
	z.i = MANDELBROT_C_R;
	i = -1;
	while (c_modulus(z) < 2 && ++i < f->i)
	{
		z = c_abs(z);
		z = c_add(c_product(z, z), c);
	}
	return (f->get_color[f->color_set](i, f));
}

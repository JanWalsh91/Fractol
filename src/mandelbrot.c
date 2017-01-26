/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:12:14 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 17:46:59 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Determines if a point is in the mandelbrot set and returns a color.
*/

int	mandelbrot(t_pt2 j, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			i;

	c.r = (float)j.x / IMG_SIZE / f->zoom + f->min.x;
	c.i = (float)j.y / IMG_SIZE / f->zoom + f->min.y;
	z.r = MANDELBROT_C_I;
	z.i = MANDELBROT_C_R;
	i = -1;
	while (c_modulus(z) < 2 && ++i < f->i)
		z = c_add(c_product(z, z), c);
	return (f->get_color[f->color_set](i, f));
}

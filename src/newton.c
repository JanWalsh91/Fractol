/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:42:26 by tgros             #+#    #+#             */
/*   Updated: 2017/01/25 10:37:41 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_roots(t_complex *r1, t_complex *r2, t_complex *r3);

int			newton(t_pt2 j, t_fractal *f)
{
	t_complex	z;
	t_complex	r1;
	t_complex	r2;
	t_complex	r3;
	int			i;

	init_roots(&r1, &r2, &r3);
	z.r = (double)j.x / 100 / f->zoom + f->min.x;
	z.i = (double)j.y / 100 / f->zoom + f->min.y;
	i = -1;
	while (++i < f->i && c_modulus(c_minus(z, r1)) >= EPSILON &&
		c_modulus(c_minus(z, r2)) >= EPSILON &&
		c_modulus(c_minus(z, r3)) >= EPSILON)
	{
		if (c_modulus(z) > 0)
			z = c_minus(z, c_divide(c_minus_double(c_product(c_product(z, z),
						z), 1.0), (c_product_double(c_product(z, z), 3))));
	}
	if (c_modulus(c_minus(z, r1)) < EPSILON)
		return (0xFF0000 - (i << 16) * 10);
	if (c_modulus(c_minus(z, r2)) <= EPSILON)
		return (0x00FF00 - (i << 8) * 10);
	if (c_modulus(c_minus(z, r3)) <= EPSILON)
		return (0x0000FF - i * 10);
	return (0x0F0F0F);
}

static void	init_roots(t_complex *r1, t_complex *r2, t_complex *r3)
{
	(*r1).r = 1.0;
	(*r1).i = 0.0;
	(*r2).r = -0.5;
	(*r2).i = sqrt(3.0) / 2.0;
	(*r3).r = -0.5;
	(*r3).i = -sqrt(3.0) / 2.0;
}

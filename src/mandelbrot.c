/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:12:14 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/18 11:50:20 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_pt2 j, t_fractal *f)
{
	t_complex	z;
	t_complex	c;
	int			i;

	c.r = j.x / f->zoom + MANDELBROT_XMIN;
	c.i = j.y / f->zoom + MANDELBROT_YMIN;
	z.r = MANDELBROT_C_I;
	z.i = MANDELBROT_C_R;
	i = 0;
	while (c_modulus(z) < 2000 && i < MANDELBROT_I)
	{
		z = c_add(c_product(z, z), c);
		++i;
	}
	return (i == MANDELBROT_I ? BLACK : i * 1002);
}

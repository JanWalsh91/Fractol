/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:12:43 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 12:27:16 by jwalsh           ###   ########.fr       */
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

	//printf("(j.y, j.y)(%i, %i) -> ", j.y, j.x);
	c.r = (float)j.x / IMG_SIZE / f->zoom + f->min.x;
	c.i = (float)j.y / IMG_SIZE / f->zoom + f->min.y;
	//printf("(c.i, c.r)(%f, %f)\n", c.i, c.r);
	//pr = 1.5 * (x - w / 2) / (0.5 * zoom * w) + moveX;
	//pi = (y - h / 2) / (0.5 * zoom * h) + moveY;
	z.r = MANDELBROT_C_I;
	z.i = MANDELBROT_C_R;
	i = -1;
	while (c_modulus(z) < 2 && ++i < f->i)
	{
		z = c_abs(z);
		z = c_add(c_product(z, z), c);
	}
	//return (i == MANDELBROT_I ? HOT_PINK : WHITE);
	return (f->get_color[f->color_set](i, f->i));
}

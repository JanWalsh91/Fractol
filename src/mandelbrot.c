/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:12:14 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/17 15:21:49 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mandelbrot(t_pt2 j)
{
	t_complex	z;
	t_complex	c;
	int			i;

	c.r = j.x / 100 + -2.1;
	c.i = j.y / 100 + -1.2;
	z.r = 0;
	z.i = 0;
	i = 0;
	while (c_modulus(z) < 2 && i < 50)
	{
		z = c_add(c_product(z, z), c);
		++i;
	}
	return (i == 50 ? WHITE : BLACK);
}

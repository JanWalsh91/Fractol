/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:34:30 by tgros             #+#    #+#             */
/*   Updated: 2017/01/25 10:22:25 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_pt2 j, t_fractal *f)
{
	t_complex	z;
	int			i;

	z.r = (float)j.x / IMG_SIZE / f->zoom - MANDELBROT_W / 2 + f->min.x;
	z.i = (float)j.y / IMG_SIZE / f->zoom - MANDELBROT_H / 2 + f->min.y;
	i = -1;
	while (++i < f->i && c_modulus(z) < 2)
		z = c_add(c_product(z, z), f->c);
	return (f->get_color[f->color_set](i, f->i));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:34:30 by tgros             #+#    #+#             */
/*   Updated: 2017/01/18 11:45:03 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_pt2 j, t_fractal *f)
{
	t_complex old;
	t_complex new;
	int i;

	new.r = 1.5 * (j.x - f->e.w / 2) / (0.5 * 1 * f->e.w);
	new.i = (j.y - f->e.h / 2) / (0.5 * 1 * f->e.h);
	i = 0;
	while (i < 300 && c_modulus(new) < 2)
	{
		old.r = new.r;
		old.i = new.i;
		new.r = old.r * old.r - old.i * old.i + f->c.r;
		new.i = 2 * old.r * old.i + f->c.i;
		i++;
	}
	return (i == 300 ? BLACK : WHITE);
}

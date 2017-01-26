/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_color_set.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:18:38 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 13:37:18 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	update_color_set(t_fractal *f)
{
	if (++f->color_set == f->color_set_count)
		f->color_set = 0;
	calc_colors(f);
	draw(f);
	return (1);
}

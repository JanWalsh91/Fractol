/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_jan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:33:43 by jwalsh            #+#    #+#             */
/*   Updated: 2017/02/01 11:14:58 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	init_jan(t_fractal *f)
{
	f->i = JAN_I;
	f->img_size = IMG_SIZE * 2;
	f->e.h = f->img_size * (JAN_YMAX - JAN_YMIN);
	f->e.w = f->img_size * (JAN_XMAX - JAN_XMIN);
	f->name = JAN;
	f->color_set_count = COLOR_SET_COUNT;
	if (!(f->title = ft_strdup("Jan")) || !init_colors(f))
		ft_error_exit("Malloc error");
	f->f = &jan;
	f->get_color[0] = &col_6_0;
	f->get_color[1] = &col_6_1;
	f->get_color[2] = &col_6_2;
	f->c.r = JAN_C_R;
	f->c.i = JAN_C_I;
	reset_bounds(f);
	f->color_set = 1;
	return (1);
}

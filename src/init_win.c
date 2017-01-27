/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:20:31 by tgros             #+#    #+#             */
/*   Updated: 2017/01/27 12:28:44 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initializes a window and an image.
*/

int		init_win(t_fractal *f)
{
	if (!(f->e.win_mlx = mlx_new_window(f->e.mlx, f->e.w, f->e.h,
		f->title)))
		ft_error_exit("Malloc error");
	f->e.img_mlx = mlx_new_image(f->e.mlx, f->e.w, f->e.h);
	f->e.draw.image = mlx_get_data_addr(f->e.img_mlx,
			&(f->e.draw.bpp), &(f->e.draw.size_line), &(f->e.draw.endian));
	return (1);
}

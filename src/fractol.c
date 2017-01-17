/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:21:15 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/17 15:24:13 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	fractol(t_fractal **f, int y)
{
	t_data d;

	d.f = *f;
	d.mlx = mlx_init();
	draw(&d, y);
	d.f[y].e.win.win_mlx = mlx_new_window(d.mlx, d.f[y].e.win.h, d.f[y].e.win.w, "test");
	mlx_put_image_to_window(d.mlx, d.f[y].e.win.win_mlx, d.f[y].e.win.img_mlx, 0, 0);
	mlx_loop(d.mlx);
	return (1);
}

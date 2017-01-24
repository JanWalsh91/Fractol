/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 10:22:53 by tgros             #+#    #+#             */
/*   Updated: 2017/01/23 16:28:01 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_released(int keycode, t_fractal *f)
{
	if (keycode == KEY_ESCAPE)
		exit(1);
	else if (keycode == KEY_MINUS || keycode == KEY_PAD_SUB ||
			(keycode == KEY_EQUAL || keycode == KEY_PAD_ADD))
		update_iteration(f, keycode);
	else if (keycode == KEY_SPACE)
		zoom(f, KEY_SPACE, 0, 0);
	else if (keycode == KEY_C)
		update_color_set(f);
	else if (keycode == KEY_J && f->name == 2)
		switch_julia_constant(f);
	return (0);
}

int		exit_prog(int keycode, void *mlx)
{
	(void)mlx;
	if (keycode == KEY_ESCAPE)
		exit (1);
	return (0);
}

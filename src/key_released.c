/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <jwalsh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 11:50:13 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/31 14:56:42 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** MLX functions for responding to user keyboard input.
*/

int		key_released(int keycode, t_fractal *f)
{
	if (keycode == KEY_MINUS || keycode == KEY_PAD_SUB ||
			(keycode == KEY_EQUAL || keycode == KEY_PAD_ADD))
		update_iteration(f, keycode);
	else if (keycode == KEY_SPACE)
		zoom(f, KEY_SPACE, 0, 0);
	else if (keycode == KEY_C)
		update_color_set(f);
	else if (keycode == KEY_J && f->name == 2)
		switch_julia_constant(f);
	else if (keycode == KEY_UP || keycode == KEY_DOWN ||
			keycode == KEY_RIGHT || keycode == KEY_LEFT)
		move(f, keycode);
	return (0);
}

/*
** Exit the program when the escape key is hit.
*/

int		exit_prog(int keycode, void *mlx)
{
	(void)mlx;
	if (keycode == KEY_ESCAPE)
		exit(0);
	return (0);
}

int		key_free_fractals(int keycode, t_win_manager *f)
{
	if (keycode == KEY_ESCAPE)
	{
		free_fractals(f);
		exit(0);
	}
	return (1);
}

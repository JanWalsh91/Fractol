/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_released.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 10:22:53 by tgros             #+#    #+#             */
/*   Updated: 2017/01/22 14:39:12 by jwalsh           ###   ########.fr       */
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
	return (0);
}

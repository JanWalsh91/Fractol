/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 15:54:38 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/18 17:11:06 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_event(int button, int x, int y, t_fractal *f)
{
	(void)f;
	if (button == MOUSE_UP || button == MOUSE_LMB ||
			button == MOUSE_DOWN || button == MOUSE_RMB)
		zoom(f, button, y, x);
	printf("button: %i (y, x): (%i, %i)\n", button, y, x);
	return (0);
}

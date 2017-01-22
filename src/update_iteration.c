/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_iteration.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 14:05:10 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/22 14:17:12 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Updates the number of iterations based on user input and updates the image.
*/

int	update_iteration(t_fractal *f, int button)
{
	if (f->i > 1 && (button == KEY_MINUS || button == KEY_PAD_SUB))
		--f->i;
	else if (button == KEY_EQUAL || button == KEY_PAD_ADD)
		++f->i;
	calc_colors(f);
	draw(f);
	return (1);
}

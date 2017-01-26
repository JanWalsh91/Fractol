/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:40:37 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/26 15:28:13 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Calculates the incrementation of x, y and the color for the line between
** two points.
*/

t_incr	get_incr(t_vec2 p1, t_vec2 p2, int c1, int c2)
{
	t_incr	incr;
	t_vec2	diff;

	diff.x = p1.x - p2.x;
	diff.y = p1.y - p2.y;
	incr.steps = (fabs(diff.x) > fabs(diff.y)) ? fabs(diff.x) : fabs(diff.y);
	(!incr.steps) ? incr.steps = 1 : 0;
	incr.x = -diff.x / incr.steps;
	incr.y = -diff.y / incr.steps;
	get_color_incr(&incr, c1, c2, incr.steps);
	return (incr);
}

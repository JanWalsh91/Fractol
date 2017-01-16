/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_matrix4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:06:27 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/23 17:08:24 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Creates a new 4 by 4 matrix and sets its values to 0;
*/

t_matrix4	new_matrix4(void)
{
	int			x;
	int			y;
	t_matrix4	m;

	if (!(m = (t_matrix4)malloc(sizeof(float *) * 4)))
		return (m);
	y = -1;
	while (++y < 4)
	{
		if (!(m[y] = (float *)malloc(sizeof(float) * 4)))
			return (m);
		x = -1;
		while (++x < 4)
			m[y][x] = 0;
	}
	return (m);
}

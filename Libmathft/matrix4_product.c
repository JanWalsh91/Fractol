/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_product.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:11:32 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/27 14:55:17 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Combines two matrices.
*/

t_matrix4	matrix4_product(t_matrix4 m1, t_matrix4 m2)
{
	int			x;
	int			y;
	t_matrix4	m;

	m = new_matrix4();
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			m[y][x] = m1[y][0] * m2[0][x] +
				m1[y][1] * m2[1][x] +
				m1[y][2] * m2[2][x] +
				m1[y][3] * m2[3][x];
		}
	}
	return (m);
}

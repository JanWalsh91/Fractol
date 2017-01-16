/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_scaling_matrix4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:10:07 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/23 17:10:56 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Creates a new scaling matrix which will scale a matrix or vector of all
** coordinates by i.
*/

t_matrix4	new_scaling_matrix4(float i)
{
	t_matrix4	m;

	m = new_matrix4();
	m[0][0] = i;
	m[1][1] = i;
	m[2][2] = i;
	return (m);
}

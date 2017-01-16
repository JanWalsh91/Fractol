/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix4_translation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:18:13 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/23 17:18:32 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Combines a matrix and a translation vector.
*/

t_matrix4	matrix4_translation(t_matrix4 m, t_vec3 v)
{
	m[0][3] += v.x;
	m[1][3] += v.y;
	m[2][3] += v.z;
	return (m);
}

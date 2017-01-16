/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_cross_product.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:28:32 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/23 17:29:54 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Returns the cross product of two vectors.
** The cross product of two vectors results in a vector orthognoal to the
** plane produced by those two vectors.
** This is useful to create a Cartesian Coordinate system.
*/

t_vec3	vec_cross_product(t_vec3 vec1, t_vec3 vec2)
{
	t_vec3 vec;

	vec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	vec.y = vec1.z * vec2.x - vec1.x * vec2.z;
	vec.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return (vec);
}

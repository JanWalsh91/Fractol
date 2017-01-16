/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:25:38 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/27 14:57:03 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Converts the vector to a unit vector.
*/

t_vec3	vec_normalize(t_vec3 vec)
{
	float len;

	len = vec3_length(vec);
	if (len > 0)
	{
		vec.x *= 1 / len;
		vec.y *= 1 / len;
		vec.z *= 1 / len;
	}
	return (vec);
}

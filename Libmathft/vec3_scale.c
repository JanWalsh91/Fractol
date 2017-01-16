/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_scale.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:41:01 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/23 17:44:43 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Scales a vector by the vector/point i.
*/

t_vec3	vec_scale(t_vec3 vec, t_vec3 i)
{
	vec.x *= i.x;
	vec.y *= i.y;
	vec.z *= i.z;
	return (vec);
}

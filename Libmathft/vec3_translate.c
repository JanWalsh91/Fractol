/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:40:13 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/27 14:58:24 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Translates a vector or point by vector i.
*/

t_vec3	vec3_translate(t_vec3 vec, t_vec3 i)
{
	vec.x *= i.x;
	vec.y *= i.y;
	vec.z *= i.z;
	return (vec);
}

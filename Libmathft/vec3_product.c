/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_product.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:38:13 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/23 17:38:51 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Scales a vector by i.
*/

t_vec3	vec3_product(t_vec3 vec1, float i)
{
	t_vec3	vec;

	vec.x = vec1.x * i;
	vec.y = vec1.y * i;
	vec.z = vec1.z * i;
	return (vec);
}

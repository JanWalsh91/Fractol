/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_matrix4_product.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:13:32 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/27 14:56:47 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

/*
** Returns the product of  matrix m and vector v.
*/

t_vec3	vec3_matrix4_product(t_vec3 v, t_matrix4 m)
{
	t_vec3	new;

	new.x = v.x * m[0][0] + v.y * m[1][0] + v.z * m[2][0] + m[3][0];
	new.y = v.x * m[0][1] + v.y * m[1][1] + v.z * m[2][1] + m[3][1];
	new.z = v.x * m[0][2] + v.y * m[1][2] + v.z * m[2][2] + m[3][2];
	return (new);
}

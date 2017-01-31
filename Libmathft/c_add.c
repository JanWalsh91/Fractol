/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 12:00:37 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/29 12:00:38 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

t_complex	c_add(t_complex x, t_complex y)
{
	t_complex res;

	res.r = x.r + y.r;
	res.i = x.i + y.i;
	return (res);
}

t_complex	c_add_float(t_complex x, double y, double z)
{
	t_complex res;

	res.r = x.r + y;
	res.i = x.i + z;
	return (res);
}

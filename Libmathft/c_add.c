/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:02:10 by tgros             #+#    #+#             */
/*   Updated: 2017/01/26 15:10:50 by tgros            ###   ########.fr       */
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

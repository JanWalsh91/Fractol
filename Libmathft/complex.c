/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:38:52 by tgros             #+#    #+#             */
/*   Updated: 2017/01/17 18:58:59 by tgros            ###   ########.fr       */
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

t_complex c_add_float(t_complex x, double y, double z)
{
	t_complex res;
	
	res.r = x.r + y;
	res.i = x.i + z;
	return (res);
}

t_complex c_product(t_complex x, t_complex y)
{
	t_complex res;

	res.r = (x.r * y.r) - (x.i * y.i);
	res.i = (x.r * y.i) + (x.i * y.r);
	return (res);
}

double	c_modulus(t_complex x)
{
	return (sqrt(pow(x.r, 2) + pow(x.i, 2)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_product.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:03:41 by tgros             #+#    #+#             */
/*   Updated: 2017/01/26 15:11:22 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

t_complex	c_product(t_complex x, t_complex y)
{
	t_complex res;

	res.r = (x.r * y.r) - (x.i * y.i);
	res.i = (x.r * y.i) + (x.i * y.r);
	return (res);
}

t_complex	c_product_double(t_complex x, double y)
{
	t_complex res;

	res.r = x.r * y;
	res.i = x.i * y;
	return (res);
}

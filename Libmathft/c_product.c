/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_product.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 12:00:21 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/29 12:00:23 by jwalsh           ###   ########.fr       */
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

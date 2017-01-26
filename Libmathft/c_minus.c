/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_minus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:03:13 by tgros             #+#    #+#             */
/*   Updated: 2017/01/26 15:03:29 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

t_complex	c_minus(t_complex x, t_complex y)
{
	t_complex res;

	res.r = x.r - y.r;
	res.i = x.i - y.i;
	return (res);
}

t_complex	c_minus_double(t_complex x, double y)
{
	t_complex res;

	res.r = x.r - y;
	res.i = x.i;
	return (res);
}

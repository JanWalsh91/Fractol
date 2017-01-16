/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 15:38:52 by tgros             #+#    #+#             */
/*   Updated: 2017/01/16 16:52:22 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

t_complex	cadd(t_complex x, t_complex y)
{
	t_complex res;

	res.real = x.real + y.real;
	res.imag = x.imag + y.imag;
	return (res);
}

t_complex cadd_float(t_complex x, double y, double z)
{
	t_complex res;
	
	res.real = x.real + y;
	res.imag = x.imag + z;
	return (res);
}

t_complex cproduct(t_complex x, t_complex y)
{
	t_complex res;

	res.real = (x.real * y.real) - (x.imag * y.imag);
	res.imag = (x.real * y.imag) + (x.imag * y.real);
	return (res);
}

double	modulus(t_complex x)
{
	return (sqrt(pow(x.real, 2) + pow(x.imag, 2)));
}

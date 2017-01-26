/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_divide.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:04:02 by tgros             #+#    #+#             */
/*   Updated: 2017/01/26 15:11:10 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmathft.h"

t_complex	c_divide(t_complex x, t_complex y)
{
	t_complex res;

	res.r = (x.r * y.r + x.i * y.i) / (y.r * y.r + y.i * y.i);
	res.i = (x.i * y.r - x.r * y.i) / (y.r * y.r + y.i * y.i);
	return (res);
}

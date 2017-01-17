/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increment_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:04:04 by tgros             #+#    #+#             */
/*   Updated: 2017/01/17 15:20:40 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Increment x and y. If x equals xmax, then the function increases y and
**	set x to 0.
*/

void	ft_increment_index(int *y, int *x, int xmax)
{
	(*x)++;
	if (*x == xmax)
	{
		*x = 0;
		(*y)++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increment_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:53:24 by tgros             #+#    #+#             */
/*   Updated: 2017/01/23 12:53:33 by tgros            ###   ########.fr       */
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

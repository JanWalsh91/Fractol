/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_increment_index.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 12:01:01 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/29 12:01:03 by jwalsh           ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:58:52 by jwalsh            #+#    #+#             */
/*   Updated: 2016/12/27 14:51:58 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** UNTESTED
** Returns the absolute value of int n.
*/

#include "libft.h"

int	ft_abs(int n)
{
	n = (n == -2147483648) ? 0 : n;
	n = (n < 0) ? -n : n;
	return (n);
}

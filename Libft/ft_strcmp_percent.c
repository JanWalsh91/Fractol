/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 12:01:11 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/29 12:01:12 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Compare src and cmp. If the difference between src and cmp is less than
**	percent, the function returns 1. Otherwise, it returns 0.
**	@percent: float between 0 and 1
*/

int		ft_strcmp_percent(char *src, char *cmp, float percent)
{
	int	cmp_len;
	int	res;

	res = 0;
	if (!src || !cmp || percent < 0.0 || percent > 1.0)
		return (-1);
	cmp_len = ft_strlen(cmp);
	while (*src == *cmp && *cmp++ && *src++)
		res++;
	return (res >= (int)(percent * cmp_len));
}

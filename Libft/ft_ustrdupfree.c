/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrdupfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:59:23 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/16 13:01:23 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Frees a char pointer and creates a new string from src with ft_strdup
** and assignes dst to the result.
*/

unsigned char	*ft_ustrdupfree(unsigned char *dst, unsigned char *src)
{
	dst ? free(dst) : 0;
	dst = ft_ustrdup(src);
	return (dst);
}

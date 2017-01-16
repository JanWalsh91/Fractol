/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ustrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:57:02 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/10 13:52:39 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Allocated sufficient memory for a copy of the string s1, does the copy,
** and returns a pointer to it. The pointer may subsequendly be used as an
** argument to the function free(3).
*/

#include "libft.h"

unsigned char	*ft_ustrdup(unsigned char *src)
{
	unsigned char	*new;

	if (!src)
		return (NULL);
	if (!(new = (unsigned char*)malloc(ft_strlen((char *)src) + 1)))
		return (NULL);
	return (ft_ustrcpy(new, src));
}

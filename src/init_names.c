/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_names.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:10:58 by tgros             #+#    #+#             */
/*   Updated: 2017/01/27 14:43:08 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initilizes the names table.
*/

int	init_names(t_names **names)
{
	if (!(*names = ft_memalloc(sizeof(t_names) * WIN_COUNT)))
		ft_error_exit("Malloc error");
	return (1);
}

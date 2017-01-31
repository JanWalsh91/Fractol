/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_names.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 11:49:44 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/29 11:49:46 by jwalsh           ###   ########.fr       */
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

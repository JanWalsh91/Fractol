/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_names.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:10:58 by tgros             #+#    #+#             */
/*   Updated: 2017/01/18 11:50:30 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_names(t_names **names)
{
	if (!(*names = ft_memalloc(sizeof(t_names) * 4)))
		return (0);
	return (1);
}

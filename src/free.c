/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:22:05 by tgros             #+#    #+#             */
/*   Updated: 2017/01/26 14:47:14 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	free_fractals(t_win_manager *f)
{
	int	i;
	int	h;

	i = -1;
	if (!f)
		return (-1);
	printf("Coucou\n");
	while (++i < f->nb_frac)
	{
		h = -1;
		free(f->f[i].title);
		while (++h < f->f[i].e.h)
			free(f->f[i].colors[h]);
		free(f->f[i].colors);
		mlx_destroy_image(f->f[i].e.mlx, f->f[i].e.img_mlx);
	}
	return (0);
}

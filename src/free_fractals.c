/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 11:53:22 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/29 11:49:29 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Frees all fractals when all windows are closed or when the program exits.
*/

static void	free_incr(t_win_manager *f, int i);

int			free_fractals(t_win_manager *f)
{
	int	i;
	int	h;

	i = -1;
	if (!f)
		return (-1);
	while (++i < f->nb_frac)
	{
		h = -1;
		if (f->f[i].name == JULIA && f->f[i].mouse_on)
		{
			f->f[i].mouse_on = 0;
			usleep(50);
		}
		free(f->f[i].title);
		while (++h < f->f[i].e.h)
			free(f->f[i].colors[h]);
		free(f->f[i].colors);
		mlx_destroy_image(f->f[i].e.mlx, f->f[i].e.img_mlx);
		if (f->f[i].name != SIERPINSKY_CARPET && f->f[i].name != NEWTON)
			free_incr(f, i);
	}
	return (0);
}

static void	free_incr(t_win_manager *f, int i)
{
	int	h;

	h = -1;
	while (++h < 3)
		free(f->f[i].incr[h]);
	free(f->f[i].incr);
}

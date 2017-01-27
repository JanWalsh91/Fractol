/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:21:15 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/27 11:08:51 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initializes fractals based on the names provided.
** Opens windows and handles events.
*/

int	fractol(t_names *names, int nb_frac, int instr)
{
	int				i;
	void			*mlx;
	t_fractal		*f;
	t_win_manager	f_list;

	mlx = mlx_init();
	if (!(f = ft_memalloc(sizeof(t_fractal) * nb_frac)))
		return (0);
	i = -1;
	f_list.f = f;
	f_list.nb_frac = nb_frac;
	while (++i < nb_frac && names[i])
	{
		if (!init_fractal(&f[i], mlx, names[i]) || !calc_colors(&f[i]) ||
				!init_win(&f[i]) || !draw(&f[i]))
			return (0);
		if (names[i] == JULIA)
			mlx_hook(f[i].e.win_mlx, MOTION, MOUSE_MASK, &mouse_motion, &f[i]);
		mlx_key_hook(f[i].e.win_mlx, &key_released, &f[i]);
		mlx_mouse_hook(f[i].e.win_mlx, &mouse_event, &f[i]);
		mlx_hook(f[i].e.win_mlx, DESTROY_EVENT, 0, &red_button_exit, &f_list);
	}
	instr ? init_instructions(mlx) : 0;
	mlx_loop(mlx);
	return (1);
}

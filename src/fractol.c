/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:21:15 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/19 12:44:48 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol(t_names *names, int nb_frac)
{
	int			i;
	void		*mlx;
	t_fractal	*f;

	printf("fractol: nb: %i\n", nb_frac);
	mlx = mlx_init();
	if (!(f = ft_memalloc(sizeof(t_fractal) * nb_frac)))
		return (0);
	i = -1;
	printf("check: names[i]: %u\n", names[0]);
	// print instructions
	while (++i < nb_frac && names[i])
	{
		printf("check2\n");
		if (!init_fractal(&f[i], mlx, names[i]) ||
				!calc_colors(&f[i]) ||
				!init_win(&f[i]) ||
				!draw(&f[i]))
			return (0);
		if (names[i] == JULIA) // if julia, tracking mouse position
			mlx_hook(f[i].e.win_mlx, MOTION, MOUSE_MASK, &mouse_motion, &f[i]);	
		mlx_key_hook(f[i].e.win_mlx, &key_released, f);
		mlx_mouse_hook(f[i].e.win_mlx, &mouse_event, f);
		// mlx hook
	}
	printf("check3\n");
	mlx_loop(mlx);
	return (1);
}

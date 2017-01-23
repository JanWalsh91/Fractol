/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:01:04 by tgros             #+#    #+#             */
/*   Updated: 2017/01/23 12:28:20 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	init_instructions(void *mlx)
{
	void	*win;

	if (!(win = mlx_new_window(mlx, INSTRUCTIONS_W, INSTRUCTIONS_H,
				"Instructions")))
		return (0);
	mlx_string_put(mlx, win, 10, 10, 0xFFFFFF, "INSTRUCTIONS");
	//mlx_key_hook(mlx, &exit_prog, &init_instructions);
	return (1);
}

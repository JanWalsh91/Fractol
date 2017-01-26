/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:01:04 by tgros             #+#    #+#             */
/*   Updated: 2017/01/26 13:04:19 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initializes and opens the instructions window.
*/

int	init_instructions(void *mlx)
{
	void	*win;
	int		i;
	int		h;

	if (!(win = mlx_new_window(mlx, INSTRUCTIONS_W, INSTRUCTIONS_H,
		"Instructions")))
		return (0);
	i = 0;
	h = 19;
	mlx_string_put(mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_0);
	mlx_string_put(mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_1);
	mlx_string_put(mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_2);
	mlx_string_put(mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_3);
	mlx_string_put(mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_4);
	mlx_string_put(mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_5);
	mlx_string_put(mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_6);
	mlx_string_put(mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_7);
	mlx_string_put(mlx, win, 10, h * (i += 2), INSTRUCT_COLOR, LINE_8);
	mlx_string_put(mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_JUJU);
	mlx_key_hook(win, &exit_prog, &i);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 12:01:04 by tgros             #+#    #+#             */
/*   Updated: 2017/01/27 14:51:52 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initializes and opens the instructions window.
*/

int	init_instructions(t_win_manager *f)
{
	void	*win;
	int		i;
	int		h;

	if (!(win = mlx_new_window(f->f[0].e.mlx, INSTRUCTIONS_W, INSTRUCTIONS_H,
		"Instructions")))
		ft_error_exit("Malloc error");
	i = 0;
	h = 19;
	mlx_string_put(f->f[0].e.mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_0);
	mlx_string_put(f->f[0].e.mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_1);
	mlx_string_put(f->f[0].e.mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_2);
	mlx_string_put(f->f[0].e.mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_3);
	mlx_string_put(f->f[0].e.mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_4);
	mlx_string_put(f->f[0].e.mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_5);
	mlx_string_put(f->f[0].e.mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_6);
	mlx_string_put(f->f[0].e.mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_7);
	mlx_string_put(f->f[0].e.mlx, win, 10, h * (i += 2),
			INSTRUCT_COLOR, LINE_8);
	mlx_string_put(f->f[0].e.mlx, win, 10, h * ++i, INSTRUCT_COLOR, LINE_JUJU);
	mlx_hook(win, KEY_PRESSED, 0, &key_free_fractals, f);
	return (1);
}

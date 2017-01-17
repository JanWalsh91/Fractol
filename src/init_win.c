/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:20:31 by tgros             #+#    #+#             */
/*   Updated: 2017/01/17 19:27:03 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int		init_win(t_fractal *f, void *mlx)
{
	printf("init_win\n");
	if (!(f->e.win_mlx = mlx_new_window(mlx, f->e.w, f->e.h, f->name)))
		return (0);	
	printf("init_win end\n");
	return (1);
}

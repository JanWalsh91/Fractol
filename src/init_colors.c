/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:46:20 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/27 14:47:01 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Initializes f->colors and f->get_color for each fractal.
*/

static void	get_incr(t_incr *incr, float i);
static int	set_limit_colors(t_incr **incr);
static void	set(t_incr *incr, int c1, int c2);

int			init_colors(t_fractal *f)
{
	int	i;

	if (!(f->colors = ft_memalloc(sizeof(int *) * f->e.h)))
		ft_error_exit("Malloc error");
	i = -1;
	while (++i < f->e.h)
		if (!(f->colors[i] = ft_memalloc(sizeof(int) * f->e.w)))
			ft_error_exit("Malloc error");
	if (!(f->get_color = ft_memalloc(sizeof(*(f->get_color)) *
					f->color_set_count)))
		ft_error_exit("Malloc error");
	if (f->name != SIERPINSKY_CARPET && f->name != NEWTON)
	{
		if (!(f->incr = (t_incr **)ft_memalloc(sizeof(t_incr *) *
			COLOR_SET_COUNT)))
			ft_error_exit("Malloc error");
		i = -1;
		while (++i < COLOR_SET_COUNT)
			if (!(f->incr[i] = (t_incr *)ft_memalloc(sizeof(t_incr) *
				COLORS_PER_SET)))
				ft_error_exit("Malloc error");
		reset_color_sets(f);
	}
	return (1);
}

int			reset_color_sets(t_fractal *f)
{
	int steps;

	steps = f->i / (COLORS_PER_SET - 1);
	set_limit_colors(f->incr);
	get_incr(&(f->incr[0][0]), steps);
	get_incr(&(f->incr[0][1]), steps);
	get_incr(&(f->incr[0][2]), steps);
	get_incr(&(f->incr[1][0]), steps);
	get_incr(&(f->incr[1][1]), steps);
	get_incr(&(f->incr[1][2]), steps);
	get_incr(&(f->incr[2][0]), steps);
	get_incr(&(f->incr[2][1]), steps);
	get_incr(&(f->incr[2][2]), steps);
	return (1);
}

static void	get_incr(t_incr *incr, float i)
{
	int	mask;

	mask = 0xFF;
	incr->b = ((incr->c_2 & mask) - (incr->c_1 & mask)) / i;
	mask = mask << 8;
	incr->g = (((incr->c_2 & mask) - (incr->c_1 & mask)) / i) / 0x100;
	mask = mask << 8;
	incr->r = (((incr->c_2 & mask) - (incr->c_1 & mask)) / i) / 0x10000;
}

static int	set_limit_colors(t_incr **incr)
{
	set(&incr[0][0], COL_00, COL_01);
	set(&incr[0][1], COL_01, COL_02);
	set(&incr[0][2], COL_02, COL_03);
	set(&incr[1][0], COL_10, COL_11);
	set(&incr[1][1], COL_11, COL_12);
	set(&incr[1][2], COL_12, COL_13);
	set(&incr[2][0], COL_20, COL_21);
	set(&incr[2][1], COL_21, COL_22);
	set(&incr[2][2], COL_22, COL_23);
	return (1);
}

static void	set(t_incr *incr, int c1, int c2)
{
	incr->c_1 = c1;
	incr->c_2 = c2;
}

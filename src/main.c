/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:20:07 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/27 14:49:27 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	check_arg(char *arg, t_names *names, int *y, int *instr);
static void	usage_error(void);

int			main(int argc, char *argv[])
{
	int		i;
	int		y;
	int		instr;
	t_names	*names;

	instr = 0;
	if (argc < 2)
		usage_error();
	init_names(&names);
	i = 1;
	y = 0;
	while (i < argc && y < MAX_ARG)
	{
		ft_strtoupper(argv[i]);
		check_arg(argv[i], names, &y, &instr);
		++i;
	}
	y == 0 ? usage_error() : fractol(names, y, instr);
	return (0);
}

/*
** Checks the argument validity and updates the fractal list.
*/

static void	check_arg(char *arg, t_names *names, int *y, int *instr)
{
	if (ft_strcmp_percent(arg, "MANDELBROT", 0.2))
		names[(*y)++] = MANDELBROT;
	else if (ft_strcmp_percent(arg, "JULIA", 0.3))
		names[(*y)++] = JULIA;
	else if (ft_strcmp_percent(arg, "SIERPINSKY", 0.2))
		names[(*y)++] = SIERPINSKY_CARPET;
	else if (ft_strcmp_percent(arg, "NEWTON", 0.2))
		names[(*y)++] = NEWTON;
	else if (ft_strcmp_percent(arg, "BURNING", 0.2))
		names[(*y)++] = BURNING_SHIP;
	else if (ft_strcmp_percent(arg, "CARPET", 0.2) && ++(*y))
		--(*y);
	else if (ft_strcmp_percent(arg, "SHIP", 0.5) && ++(*y))
		--(*y);
	else if (ft_strcmp_percent(arg, "-I", 1.0))
		*instr == 0 ? *instr = 1 : 0;
	else
		usage_error();
}

/*
** Displays an error message in stderr, and quits the programm.
*/

static void	usage_error(void)
{
	ft_putendl_fd("usage: ./fractol <julia, mandelbrot, burning ship, \
newton, sierpinsky carpet> [...] [-i]", 2);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:20:07 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/23 12:59:29 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage_error(void)
{
	ft_putendl("usage: ./fractol <julia, mandelbrot, ?> [...]");
	exit(1);
}

int		main(int argc, char *argv[])
{
	int 	i;
	int		y;
	t_names	*names;

	if (argc > MAX_ARG || argc < 2)
		usage_error();
	init_names(&names);
	i = 1;
	y = 0;
	while (i < argc && y < MAX_ARG)
	{
		ft_strtoupper(argv[i]);
		if (ft_strcmp_percent(argv[i], "MANDELBROT", 0.2))
			names[y++] = MANDELBROT;
		else if (ft_strcmp_percent(argv[i], "JULIA", 0.3))
			names[y++] = JULIA;
		else if (ft_strcmp_percent(argv[i], "SIERPINSKY", 0.2))
			names[y++] = SIERPINSKY_CARPET;
		else if (ft_strcmp_percent(argv[i], "NEWTON", 0.2))
			names[y++] = NEWTON;
		else if (ft_strcmp_percent(argv[i], "CARPET", 0.1) && ++y)
			--y;
		else
			usage_error();
		++i;
	}
	printf("main: nb_frac: %i\n", y);
	fractol(names, y);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:20:07 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/17 15:23:55 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	usage_error(void)
{
	ft_putendl("usage: ./fractol <julia, mandelbrot, ?> [...]");
	exit(1);
}

int		main(int argc, char *argv[])
{
	int i;
	t_fractal	*f;

	init_fractals(&f);
	if (argc > MAX_ARG || argc < 2)
		usage_error();
	i = 1;
	while (i < argc && i < 5)
	{
		ft_strtoupper(argv[i]);
		if (ft_strcmp_percent(argv[i], "JULIA", 0.5))
			init_fractal(&(f[i]), JULIA);
		else if (ft_strcmp_percent(argv[i], "MANDELBROT", 0.5))
			init_fractal(&(f[i]), MANDELBROT);
		else if (ft_strcmp_percent(argv[i], "?", 1))
			ft_putendl("?");
		else	
			usage_error();
		++i;
	}
	i = 0;
	while (i + 1 < argc)
		fractol(&f, i++);
	return (0);
}

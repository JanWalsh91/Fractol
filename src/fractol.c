/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:02:05 by tgros             #+#    #+#             */
/*   Updated: 2017/01/17 11:24:58 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fractol.h"



#include <stdlib.h> // TODO
#include "../Libft/libft.h" // TODO
#include <stdio.h> // TODO

# define MAX_ARG 4 // TODO

void	usage_error(void)
{
	ft_putendl("usage: ./fractol <julia, mandelbrot, ?> [...]");
	exit(1);
}

int		main(int argc, char *argv[])
{
	int i;

	if (argc > MAX_ARG || argc < 2)
		usage_error();
	i = 0;
	while (++i < argc)
	{
		ft_strtoupper(argv[i]);
		if (ft_strcmp_percent(argv[i], "JULIA", 0.5))
			ft_putendl("julia");
		else if (ft_strcmp_percent(argv[i], "MANDELBROT", 0.5))
			ft_putendl("mandelbrot");
		else if (ft_strcmp_percent(argv[i], "?", 1))
			ft_putendl("?");
		else	
			usage_error();
	}
	return (0);
}

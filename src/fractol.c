/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:02:05 by tgros             #+#    #+#             */
/*   Updated: 2017/01/16 17:12:19 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "fractol.h"



#include <stdlib.h>
#include "../Libft/libft.h"

# define MAX_ARG 4

int	main(int argc, char *argv[])
{
	int i;

	(void)argv;

	if (argc > MAX_ARG || argc < 2)
	{
		ft_putendl("usage: ./fractol <julia, mandelbrot, ?> [...]");
		exit(1);
	}
	i = 0;
	while (++i < argc)
	{
		ft_strtoupper(argv[i]);
		if (ft_strcmp(argv[i] != "JULIA")
				|| ft_strcmp(argv[i] != "JULIA")
	}

	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:24:32 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/27 12:06:48 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_pixel(t_draw_tools *t, int x, int y, int color);

/*
** Draws fractal of index y to the image.
*/

int			draw(t_fractal *f)
{
	t_pt2	i;
	int		color;

	ft_memset(f->e.draw.image, 0, f->e.h * f->e.draw.size_line);
	i.y = 0;
	i.x = 0;
	while (i.y < f->e.h)
	{
		color = f->colors[i.y][i.x];
		draw_pixel(&f->e.draw, i.y, i.x, color);
		ft_increment_index(&i.y, &i.x, f->e.w);
	}
	if (!(mlx_put_image_to_window(f->e.mlx, f->e.win_mlx, f->e.img_mlx, 0, 0)))
		ft_error_exit("mlx_put_image_to_window error");
	return (1);
}

/*
** Draws a pixel to the image in draw_tools at coordinates (y, x) of color
** color.
*/

static void	draw_pixel(t_draw_tools *t, int y, int x, int color)
{
	unsigned int	*tmp;

	tmp = (unsigned int *)(t->image + y * t->size_line +
		x * t->bpp / 8);
	*tmp = color;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:24:32 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/18 11:21:04 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_pixel(t_draw_tools *t, int x, int y, int color);

/*
** Draws fractal of index y to the image.
*/

int			draw(t_fractal *f, void *mlx) //y is the fractal index
{
	t_pt2	i;
	
	f->e.img_mlx = mlx_new_image(mlx, f->e.h, f->e.w);
	f->e.draw.image = mlx_get_data_addr(f->e.img_mlx, 
			&(f->e.draw.bpp), &(f->e.draw.size_line), &(f->e.draw.endian));
	i.y = 0;
	i.x = 0;
	while (i.y < f->e.h)
	{
		draw_pixel(&f->e.draw, i.y, i.x, f->colors[i.y][i.x]);
		ft_increment_index(&i.y, &i.x, f->e.w);
	}
	mlx_put_image_to_window(mlx, f->e.win_mlx, f->e.img_mlx, 0, 0);
	return (1);
}

/*
** Draws a pixel to the image in draw_tools at coordinates (y, x) of color
** color.
*/

// Maybe will be used in other functions (gradient color change)
// Will need to store point colors to save on speed.

static void	draw_pixel(t_draw_tools *t, int x, int y, int color)
{
	unsigned int	*tmp;

	tmp = (unsigned int *)(t->image + y * t->size_line +
		x * t->bpp / 8);
	*tmp = color;
}

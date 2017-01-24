/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:24:32 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/23 15:37:46 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_pixel(t_draw_tools *t, int x, int y, int color);

/*
** Draws fractal of index y to the image.
*/

int			draw(t_fractal *f) //y is the fractal index
{
	t_pt2	i;

	//printf("draw\n");
	ft_memset(f->e.draw.image, 0, f->e.h * f->e.draw.size_line);
	//printf("check1\n");
	i.y = 0;
	i.x = 0;
	while (i.y < f->e.h)
	{
		int color;

		color = f->colors[i.y][i.x];
		//printf("check2\n");
		/*
		if (f->name == JULIA)
		{
			draw_pixel(&f->e.draw, i.y, i.x, color);
			draw_pixel(&f->e.draw, f->e.h - i.y, f->e.w - i.x, color);
			if (i.y == f->e.h / 2 + 1)
				break;
		}
		else
		*/
		draw_pixel(&f->e.draw, i.y, i.x, color);
		ft_increment_index(&i.y, &i.x, f->e.w);
	}
	//printf("check3\n");
	mlx_put_image_to_window(f->e.mlx, f->e.win_mlx, f->e.img_mlx, 0, 0);
	return (1);
}

/*
** Draws a pixel to the image in draw_tools at coordinates (y, x) of color
** color.
*/

// Maybe will be used in other functions (gradient color change)
// Will need to store point colors to save on speed.

static void	draw_pixel(t_draw_tools *t, int y, int x, int color)
{
	unsigned int	*tmp;

	tmp = (unsigned int *)(t->image + y * t->size_line +
		x * t->bpp / 8);
	*tmp = color;
}

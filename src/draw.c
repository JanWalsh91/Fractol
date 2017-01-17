/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:24:32 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/17 15:28:15 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	draw_pixel(t_draw_tools *t, int x, int y, int color);

/*
** Draws fractal of index y to the image.
*/

int			draw(t_data *d, t_fractals y) //y is the fractal index
{
	t_pt2	i;
	int color;

	printf("win: (w, h) (%i, %i)\n", d->f[y].e.win.w, d->f[y].e.win.h);
	d->f[y].e.win.img_mlx = mlx_new_image(d->mlx, d->f[y].e.win.w, d->f[y].e.win.h);
	d->f[y].e.draw.image = mlx_get_data_addr(d->f[y].e.win.img_mlx,
			&(d->f[y].e.draw.bpp),&(d->f[y].e.draw.size_line),
			&(d->f[y].e.draw.endian));

	i.y = 0;
	i.x = 0;
	while (i.y < d->f[y].e.win.h)
	{
		color = d->f[y].f(i);
		draw_pixel(&d->f[y].e.draw, i.y, i.x, d->f[y].f(i));
		ft_increment_index(&i.y, &i.x, d->f[y].e.win.w);
		printf("(y: %i x: %i color: %x) ", i.y, i.x, color);
	}
	printf("done with draw\n");
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

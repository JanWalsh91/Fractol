/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:24:32 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/23 11:07:03 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	draw_pixel(t_draw_tools *t, int x, int y, int color);

/*
** Draws fractal of index y to the image.
*/

int			draw(t_fractal *f) //y is the fractal index
{
	pthread_t	threads[THREAD_COUNT];
	int			i;
	t_th		*th;
	void		**ret;

	i = -1;
	ret = NULL;
	th = (t_th *)malloc(sizeof(t_th) * 8);
	//printf("draw\n");
	ft_memset(f->e.draw.image, 0, f->e.h * f->e.draw.size_line);
	//printf("check1\n");
	while (++i < THREAD_COUNT)
	{
		printf("new thread\n");
		th[i].f = f;
		th[i].i = i;
		pthread_create(&threads[i], NULL, draw_section, &th[i]);
	}
	//printf("check3\n");
	i = -1;
	while (++i < THREAD_COUNT)
		pthread_join(threads[i], ret);
	//pthread_exit(NULL);
	mlx_put_image_to_window(f->e.mlx, f->e.win_mlx, f->e.img_mlx, 0, 0);
	return (1);
}

void		*draw_section(void *v)
{
	t_pt2	i;
	int		max_x;
	t_th	*th;
	int		color;

	th = (t_th *)v;
	max_x = (th->f->e.w / THREAD_COUNT) * (th->i + 1);
	//printf("thread %d\n", th->i);
	i.y = -1;
	while (++i.y < th->f->e.h)
	{
		i.x = (th->f->e.w / THREAD_COUNT) * th->i - 1;
		while (++i.x < max_x)
		{
			//printf("draw pixel at : (y, x) (%i, %i) thread: %i\n", i.y, i.x, th->i);
			color = th->f->colors[i.y][i.x];
			draw_pixel(&th->f->e.draw, i.y, i.x, color);
		}
	}
	//pthread_exit(NULL);
	return (NULL);
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

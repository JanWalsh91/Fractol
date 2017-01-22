/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:44:40 by tgros             #+#    #+#             */
/*   Updated: 2017/01/22 14:29:50 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Draws fractal of index y to the image.
*/

int			calc_colors(t_fractal *f) //y is the fractal index
{
	pthread_t	threads[THREAD_COUNT];
	int		i;
	t_th	*th;
	void	**ret;

	printf("calc_colors\n");
	i = -1;
	ret = NULL;
	th = (t_th *)malloc(sizeof(t_th) * 8);
	while (++i < THREAD_COUNT)
	{
		printf("new thread\n");
		th[i].f = f;
		th[i].i = i;
		pthread_create(&threads[i], NULL, calc_colors_sections, &th[i]);
	}
	i = -1;
	while (++i < THREAD_COUNT)
	{
		pthread_join(threads[i], ret);
		printf("join thread\n");
	}
	printf("end calc_colors\n");
	return (1);
}

void		*calc_colors_sections(void *v)
{
	t_pt2	i;
	int		max_x;
	t_th	*th;

	printf("calc_colors_section\n");
	th = (t_th *)v;
	max_x = (th->f->e.w / THREAD_COUNT) * (th->i + 1);
	i.y = -1;
	while (++i.y < th->f->e.h)
	{
		i.x = (th->f->e.w / THREAD_COUNT) * th->i - 1;
		while (++i.x < max_x)
			th->f->colors[i.y][i.x] = th->f->f(i, th->f);
	}
	printf("end calc_colors_section\n");
	//display_colors(f->colors, f->e.w, f->e.h);
	return (NULL);
}

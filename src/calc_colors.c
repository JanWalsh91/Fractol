/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:44:40 by tgros             #+#    #+#             */
/*   Updated: 2017/01/27 12:05:17 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Determines the colors of the pixels of a fractal.
*/

static void	*calc_colors_sections(void *v);

int			calc_colors(t_fractal *f)
{
	pthread_t	threads[THREAD_COUNT];
	int			i;
	t_th		*th;
	void		**ret;

	i = -1;
	ret = NULL;
	if (!(th = (t_th *)malloc(sizeof(t_th) * THREAD_COUNT)))
		ft_error_exit("Malloc error");
	while (++i < THREAD_COUNT)
	{
		th[i].f = f;
		th[i].i = i;
		pthread_create(&threads[i], NULL, calc_colors_sections, &th[i]);
	}
	i = -1;
	while (++i < THREAD_COUNT)
		pthread_join(threads[i], ret);
	return (1);
}

/*
** Determines the colors of the pixels of a slice of the image.
*/

static void	*calc_colors_sections(void *v)
{
	t_pt2	i;
	int		max_x;
	t_th	*th;

	th = (t_th *)v;
	max_x = (th->f->e.w * (th->i + 1) / THREAD_COUNT);
	i.y = -1;
	while (++i.y < th->f->e.h)
	{
		i.x = (th->f->e.w * (th->i - 1) / THREAD_COUNT);
		while (++i.x < max_x)
			th->f->colors[i.y][i.x] = th->f->f(i, th->f);
	}
	return (NULL);
}

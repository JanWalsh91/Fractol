/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgros <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:44:40 by tgros             #+#    #+#             */
/*   Updated: 2017/01/28 13:16:34 by tgros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Determines the colors of the pixels of a fractal.
*/

static void	*calc_colors_sections(void *v);

int			calc_colors(t_fractal *f)
{
	pthread_t	threads[f->e.h];
	int			i;
	t_th		*th;
	void		**ret;

	i = -1;
	ret = NULL;
	if (!(th = (t_th *)malloc(sizeof(t_th) * f->e.h)))
		ft_error_exit("Malloc error");
	while (++i < f->e.h)
	{
		th[i].f = f;
		th[i].i = i;
		pthread_create(&threads[i], NULL, calc_colors_sections, &th[i]);
	}
	i = -1;
	while (++i < f->e.h)
		pthread_join(threads[i], ret);
	return (1);
}

/*
** Determines the colors of the pixels of a slice of the image.
*/

static void	*calc_colors_sections(void *v)
{
	t_pt2	i;
	t_th	*th;

	th = (t_th *)v;
	i.y = th->i;
	i.x = -1;
	while (++i.x < th->f->e.w)
		th->f->colors[th->i][i.x] = th->f->f(i, th->f);
	return (NULL);
}

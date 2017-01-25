/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cuda.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:03:06 by jwalsh            #+#    #+#             */
/*   Updated: 2017/01/25 14:39:22 by jwalsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUDA_H
# define CUDA_H
# ifdef __cplusplus
extern "C"
# endif
void cuda_mandelbrot(unsigned int* a_h, unsigned int constw,
		unsigned int consth, float middlex, float middley, float scale,
		unsigned int max, unsigned int reset);
# define CUDA_THREAD_COUNT
# define CUDA_BLOCK_COUNT
# define THREADS_PER_BLOCK 512
# define N (2048 * 2048)
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:18:01 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/06 20:59:19 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot(t_complex c)
{
	t_complex	z;
	int			iter;
	double		temp;

	z.re = 0;
	z.im = 0;
	iter = 0;
	while (iter < MAX_ITER)
	{
		if ((z.re * z.re + z.im * z.im) > 4.0)
			break ;
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		iter++;
	}
	return (iter);
}

int	julia(t_complex z, t_complex c)
{
	int		iter;
	double	temp;

	iter = 0;
	while (iter < MAX_ITER)
	{
		if ((z.re * z.re + z.im * z.im) > 4.0)
			break ;
		temp = z.re * z.re - z.im * z.im + c.re;
		z.im = 2 * z.re * z.im + c.im;
		z.re = temp;
		iter++;
	}
	return (iter);
}
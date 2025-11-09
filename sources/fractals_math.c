/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:18:01 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/09 18:03:40 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_complex c)
{
	t_complex	z;
	double		temp;
	int			i;

	z.re = 0;
	z.im = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		if ((z.re * z.re + z.im * z.im) > 4.0)
			return (i);
		temp = 2 * z.re * z.im + c.im;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = temp;
		i++;
	}
	return (i);
}

int	julia(t_complex z, t_complex c)
{
	double	temp;
	int		i;

	i = 0;
	while (i < MAX_ITER)
	{
		if ((z.re * z.re + z.im * z.im) > 4.0)
			return (i);
		temp = 2 * z.re * z.im + c.im;
		z.re = z.re * z.re - z.im * z.im + c.re;
		z.im = temp;
		i++;
	}
	return (i);
}

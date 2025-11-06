/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:18:01 by wilisson          #+#    #+#             */
/*   Updated: 2025/10/10 23:24:22 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int mandelbrot(double start_r, double start_i, int max_iter)
{
	double	zr;
	double	zi;
	double	temp;
	int		i;
	double	modulus_squared;

	zr = 0;
	zi = 0;
	i = 0;
	while ((zr * zr + zi * zi <= 4.0) && i < max_iter)
	{
		temp = zr * zr - zi * zi + start_r;
		zi = 2 * zr * zi + start_i;
		zr = temp;
		i++;
	}
	if (i == max_iter)
		return (i);
	modulus_squared = zr * zr + zi * zi;
	if (modulus_squared > 0.0)
		return (i + 1 - log(log(modulus_squared)) / log(2.0));
	else
		return (i);
}

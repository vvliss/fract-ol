/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:35:42 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/09 18:55:57 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	get_color(int iterations)
{
	float	t;
	int		r;
	int		g;
	int		b;

	if (iterations == MAX_ITER)
		return (0x000000FF);
	t = (float)iterations / MAX_ITER;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

void	render_fractal(t_fractal *f)
{
	int		x;
	int		y;
	int		iter;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iter = calculate_pixel(f, x, y);
			put_pixel(f, x, y, get_color(iter));
			x++;
		}
		y++;
	}
}

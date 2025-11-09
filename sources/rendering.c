/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:35:42 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/09 18:49:46 by wilisson         ###   ########.fr       */
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
	// Smooth HSV-like gradient: Hue cycles through colors
	float hue = t * 360.0f; // Full color wheel
	float sat = 1.0f;       // Full saturation
	float val = 1.0f;       // Full brightness
	// Convert HSV to RGB
	int hi = (int)(hue / 60.0f) % 6;
	float f = (hue / 60.0f) - hi;
	float p = val * (1.0f - sat);
	float q = val * (1.0f - f * sat);
	float v = val;
	switch (hi)
	{
		case 0: r = (int)(v * 255); g = (int)(q * 255); b = (int)(p * 255); break;
		case 1: r = (int)(q * 255); g = (int)(v * 255); b = (int)(p * 255); break;
		case 2: r = (int)(p * 255); g = (int)(v * 255); b = (int)(q * 255); break;
		case 3: r = (int)(p * 255); g = (int)(q * 255); b = (int)(v * 255); break;
		case 4: r = (int)(q * 255); g = (int)(p * 255); b = (int)(v * 255); break;
		case 5: r = (int)(v * 255); g = (int)(p * 255); b = (int)(q * 255); break;
	}
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

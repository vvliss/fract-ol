/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:53:33 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/09 18:03:58 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	calculate_pixel(t_fractal *f, int x, int y)
{
	t_complex	c;
	int			iter;

	c.re = (x - WIDTH / 2.0) * 4.0 / (WIDTH * f->zoom) + f->offset_x;
	c.im = (y - HEIGHT / 2.0) * 4.0 / (HEIGHT * f->zoom) + f->offset_y;
	if (f->type == 1)
		iter = mandelbrot(c);
	else
		iter = julia(c, (t_complex){f->julia_re, f->julia_im});
	return (iter);
}

void	put_pixel(t_fractal *f, int x, int y, int color)
{
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		mlx_put_pixel(f->img, x, y, color);
	}
}

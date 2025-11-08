/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:35:42 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/08 17:03:57 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractal(t_fractal *f, int type)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		exit(1);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!f->win)
		exit(1);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		exit(1);
	f->addr = mlx_get_data_addr(f->img, &f->bits_per_pixel, &f->line_length,
			&f->endian);
	f->type = type;
	f->zoom = 300.0;
	f->offset_x = -2.0;
	f->offset_y = -1.5;
	f->julia_re = -0.7;
	f->julia_im = 0.27015;
	mlx_key_hook(f->win, key_hook, f);
	mlx_mouse_hook(f->win, mouse_hook, f);
	mlx_hook(f->win, 17, 0, close_window, f);
}

void	put_pixel(t_fractal *f, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = f->addr + (y * f->line_length + x * (f->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	render_fractal(t_fractal *f)
{
	int x;
	int y;
	int iter;
	t_complex c;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			c.re = (x / f->zoom) + f->offset_x;
			c.im = (y / f->zoom) + f->offset_y;

			if (f->type == 1)
				iter = mandelbrot(c);
			else
				iter = julia(c, (t_complex){f->julia_re, f->julia_im});

			if (iter == MAX_ITER)
				put_pixel(f, x, y, 0x000000);
			else
			{
				int r = iter * 5 % 256;
				int g = iter * 3 % 256;
				int b = iter * 10 % 256;
				put_pixel(f, x, y, create_rgb(r, g, b));
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 17:52:25 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/09 18:03:18 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_mlx(t_fractal *f)
{
	f->mlx = mlx_init(WIDTH, HEIGHT, "fract-ol", false);
	if (!f->mlx)
	{
		write(2, "Error initializing MLX\n", 22);
		exit(1);
	}
}

void	init_image(t_fractal *f)
{
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
	{
		mlx_terminate(f->mlx);
		write(2, "Error creating image\n", 20);
		exit(1);
	}
	if (mlx_image_to_window(f->mlx, f->img, 0, 0) < 0)
	{
		mlx_terminate(f->mlx);
		write(2, "Error putting image to window\n", 29);
		exit(1);
	}
}

void	init_hooks(t_fractal *f)
{
	mlx_close_hook(f->mlx, close_window, f);
	mlx_key_hook(f->mlx, key_hook, f);
	mlx_scroll_hook(f->mlx, scroll_hook, f);
}

void	init_fractal(t_fractal *f, int type)
{
	f->type = type;
	f->zoom = 1.0;
	f->offset_x = 0;
	f->offset_y = 0;
	if (f->type == 2 && f->julia_re == 0 && f->julia_im == 0)
	{
		f->julia_re = -0.4;
		f->julia_im = 0.6;
	}
	init_mlx(f);
	init_image(f);
	init_hooks(f);
}

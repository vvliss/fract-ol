/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:37:07 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/07 20:37:13 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_window(t_fractal *f)
{
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_fractal *f)
{
	if (keycode == 65307)
		close_window(f);
	return (0);
}
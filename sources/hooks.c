/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:37:07 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/09 18:53:19 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	close_window(void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	mlx_close_window(f->mlx);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_fractal	*f;

	f = param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(f->mlx);
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fractal	*f;

	f = (t_fractal *)param;
	(void)xdelta;
	if (ydelta > 0)
		f->zoom *= 1.1;
	else if (ydelta < 0)
		f->zoom *= 0.9;
	render_fractal(f);
}

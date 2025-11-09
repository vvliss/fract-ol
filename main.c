/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:25:54 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/09 17:13:51 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_help(void)
{
	write(1, "Usage: ./fractol <fractal_type>\n", 32);
	write(1, "Available fractals:\n", 20);
	write(1, "  1 - Mandelbrot\n", 17);
	write(1, "  2 - Julia\n", 12);
}

static int	parse_fractal_type(t_fractal *f, char *arg)
{
	if (arg[0] == '1' && arg[1] == '\0')
		return (f->type = 1, 1);
	if (arg[0] == '2' && arg[1] == '\0')
		return (f->type = 2, 1);
	return (0);
}

static int	parse_julia_params(t_fractal *f, int argc, char **argv)
{
	if (f->type == 2)
	{
		if (argc == 4)
			return (f->julia_re = ft_atof(argv[2]),
				f->julia_im = ft_atof(argv[3]), 1);
		return (write(1, "give values for julia\n", 22), exit(1), 0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc < 2 || (!parse_fractal_type(&f, argv[1])
			|| !parse_julia_params(&f, argc, argv)))
		return (show_help(), 1);
	init_fractal(&f, f.type);
	render_fractal(&f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}

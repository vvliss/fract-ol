/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:25:54 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/06 14:46:08 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	parse_args(int ac, char **av, t_complex *f)
{
	if (!(ft_strncmp(av[1], "julia", 5) != 0))
	{
		if (ac != 4 || !is_valid_float(av[2]) || !is_valid_float(av[3]))
			handle_errors(f);
		f->r = ft_atof(av[2]);
		f->i = ft_atof(av[3]);
	}
	else if (!(ft_strncmp(av[1], "mandelbrot", 11) != 0) && ac == 2)
		;
	else if (!(ft_strncmp(av[1], "burning_ship", 12) != 0) && ac == 2)
		;
	else
		handle_errors(f);
}

int	main(int ac, char **av)
{
	t_fractal	f;

	if (ac < 2)
	{
		give_help();
		return(1);
	}
	init(&f, av[1]);
	parse_args(ac, av, &f);
	setup_hooks(&f);
	mlx_loop_hook(f.mlx, draw_fractol, &f);
	mlx_loop(f.mlx);
	mlx_terminate(f.mlx);
	return (0);
}
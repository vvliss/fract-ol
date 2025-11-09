/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 20:43:11 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/08 20:46:02 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	show_help(void)
{
	ft_putstr_fd("Usage: ./fractol <fractal_type> [julia_re] [julia_im]\n", 1);
	ft_putstr_fd("Available fractals:\n", 1);
	ft_putstr_fd("  1 - Mandelbrot\n", 1);
	ft_putstr_fd("  2 - Julia\n", 1);
}

static int	handle_julia_args(int argc, char **argv, t_fractal *f)
{
	if (argc == 4)
	{
		f->julia_re = ft_atof(argv[2]);
		f->julia_im = ft_atof(argv[3]);
	}
	else if (argc == 2)
	{
		f->julia_re = -0.4;
		f->julia_im = 0.6;
	}
	else
	{
		ft_putstr_fd("Error: Julia set requires 0 or 2 parameters.\n", 2);
		return (0);
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_fractal *f)
{
	if (argc < 2)
	{
		show_help();
		return (0);
	}
	if (ft_strncmp(argv[1], "1", 2) == 0 && argc == 2)
		f->type = 1;
	else if (ft_strncmp(argv[1], "2", 2) == 0)
	{
		f->type = 2;
		if (!handle_julia_args(argc, argv, f))
			return (0);
	}
	else
	{
		show_help();
		return (0);
	}
	return (1);
}

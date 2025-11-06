/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:25:54 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/06 20:58:04 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

#include "fractol.h"

void	help_message(void)
{
	write(1, "Usage: ./fractol <fractal_type>\n", 32);
	write(1, "Available fractals:\n", 20);
	write(1, "  1 - Mandelbrot\n", 17);
	write(1, "  2 - Julia\n", 12);
}

int	main(int argc, char **argv)
{
	t_fractal	f;

	if (argc < 2)
	{
		help_message();
		return (1);
	}
	if (argv[1][0] == '1')
		f.type = 1;
	else if (argv[1][0] == '2')
		f.type = 2;
	else
	{
		help_message();
		return (1);
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:44:50 by wilisson          #+#    #+#             */
/*   Updated: 2025/10/10 21:10:06 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

//escape time calc
int	julia(double start_r, double start_i, t_complex *f)
{
	double	zr; //to track the point's current position
	double	zi; //to track the point's current position
	int		i; //to count how many steps we've taken
	double	new_zr; //temporary storage for the next 

	zr = start_r;
	zi = start_i;
	i = 0;
	while ((zr * zr + zi * zi <= 4.0) && i < f->max_iter)
	{
		new_zr = zr * zr - zi * zi + f->r;
		zi = 2 * zr * zi + f->i;
		zr = new_zr;
		i++;
	}
	return (i);
}

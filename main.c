/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:25:54 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/08 20:48:29 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
    t_fractal	f;

    ft_bzero(&f, sizeof(t_fractal));
    if (!parse_args(argc, argv, &f))
        return (1);
    init_fractal(&f);
    render_fractal(&f);
    mlx_loop(f.mlx);
    mlx_terminate(f.mlx);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 23:25:54 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/09 18:24:32 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	show_help(void)
{
    write(1, "Usage: ./fractol <fractal_type> [julia_re julia_im]\n", 51);
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
        {
            f->julia_re = ft_atof(argv[2]);
            f->julia_im = ft_atof(argv[3]);
            return (1);
        }
        write(2, "Error: Julia needs 2 params (re im) or none.\n", 45);
        return (0);
    }
    return (1);
}

int	main(int argc, char **argv)
{
    t_fractal	f;

    ft_bzero(&f, sizeof(t_fractal));
    if (argc < 2 || !parse_fractal_type(&f, argv[1])
        || !parse_julia_params(&f, argc, argv))
        return (show_help(), 1);
    init_fractal(&f, f.type);
    render_fractal(&f);
    mlx_loop(f.mlx);
    if (f.img)
        mlx_delete_image(f.mlx, f.img);
    if (f.mlx)
        mlx_terminate(f.mlx);
    return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 20:35:42 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/08 20:52:18 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int	get_color(int i)
{
    int	r;
    int	g;
    int	b;

    if (i == MAX_ITER)
        return (0x000000FF);
    r = (int)(sin(0.1 * i) * 127 + 128);
    g = (int)(sin(0.1 * i + 2) * 127 + 128);
    b = (int)(sin(0.1 * i + 4) * 127 + 128);
    return ((r << 24) | (g << 16) | (b << 8) | 0xFF);
}

static int	calculate_pixel(t_fractal *f, int x, int y)
{
    t_complex	c;
    t_complex	z;
    int			i;

    c.re = (x - WIDTH / 2.0) * 4.0 / WIDTH / f->zoom + f->offset_x;
    c.im = (y - HEIGHT / 2.0) * 4.0 / HEIGHT / f->zoom + f->offset_y;
    if (f->type == 1)
    {
        i = mandelbrot(c);
    }
    else
    {
        z.re = c.re;
        z.im = c.im;
        c.re = f->julia_re;
        c.im = f->julia_im;
        i = julia(z, c);
    }
    return (get_color(i));
}

void	render_fractal(t_fractal *f)
{
    int	x;
    int	y;
    int	color;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            color = calculate_pixel(f, x, y);
            mlx_put_pixel(f->img, x, y, color);
            x++;
        }
        y++;
    }
}

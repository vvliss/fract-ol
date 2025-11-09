/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:45:17 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/08 20:55:41 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "MLX42/MLX42.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_fractal
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			type;
	double		zoom;
	double		offset_x;
	double		offset_y;
	double		julia_re;
	double		julia_im;
}				t_fractal;

/* Parsing */
int			parse_args(int argc, char **argv, t_fractal *f);
double		ft_atof(const char *str);

/* Initialization */
void		init_fractal(t_fractal *f);

/* Rendering */
void		render_fractal(t_fractal *f);
void		put_pixel(t_fractal *f, int x, int y, int color);
int			calculate_pixel(t_fractal *f, int x, int y);

/* Math */
int			mandelbrot(t_complex c);
int			julia(t_complex z, t_complex c);

/* Hooks */
void		close_window(void *param);
void		key_hook(mlx_key_data_t keydata, void *param);
void		scroll_hook(double xdelta, double ydelta, void *param);

#endif
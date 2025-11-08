/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:45:17 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/08 17:04:32 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL
# define FRACT_OL

# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600
# define MAX_ITER 100

typedef struct s_complex {
    double	re;
	double	im;
}               t_complex;

typedef struct s_fractal {
    void *mlx;           
    void *win;          
    void *img;           
    char *addr;          
    int bits_per_pixel;  
    int line_length;     
    int endian;         
    int type;            
    double zoom;        
    double offset_x;
    double offset_y;
    double julia_re;
    double julia_im;
} t_fractal;

//math
int	mandelbrot(t_complex c);
int	julia(t_complex z, t_complex c);

//rendering
void	init_fractal(t_fractal *f, int type);
void	put_pixel(t_fractal *f, int x, int y, int color);

//main
void	show_help(void);

//hooks
int	close_window(t_fractal *f);
int	key_hook(int keycode, t_fractal *f);
int	mouse_hook(int button, int x, int y, t_fractal *f);


#endif
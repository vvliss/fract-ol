/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilisson <wilisson@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:45:17 by wilisson          #+#    #+#             */
/*   Updated: 2025/11/05 15:51:03 by wilisson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL
# define FRACT_OL


typedef struct s_complex {
    double      r;
    double      i;
    int  max_iter;
}               t_complex;

typedef struct s_fractal {
    void *mlx;           // MiniLibX connection
    void *win;           // Window object
    void *img;           // Image buffer
    char *addr;          // Raw pixel data
    int bits_per_pixel;  // Color depth
    int line_length;     // Bytes per image row
    int endian;          // Byte order
    int type;            // 1=Mandelbrot, 2=Julia
    double zoom;         // Zoom level
    double offset_x;     // Pan left/right
    double offset_y;     // Pan up/down
    double julia_re;     // Julia parameter (real)
    double julia_im;     // Julia parameter (imaginary)
} t_fractal;

//math


//julia

//colors

//graphics

#endif
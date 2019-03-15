/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:05:36 by clfoltra          #+#    #+#             */
/*   Updated: 2019/03/15 16:13:21 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
# include "libft.h"
////////////////////////////

#include <stdio.h>

////////////////////////////
# define WINDOW_W	800
# define WINDOW_H	800
# define THREADS	4
# define USG		1
# define MEM		2
# define ARG		3
# define MLX		4

typedef struct		s_fractal
{
	int				id;
	char			*name;
}					t_fractal;

typedef struct		s_img {
	void			*image;
	int				*datas;
	int				bpp;
	int				s_line;
	int				endian;
}					t_img;

typedef struct		s_env {
	void			*mlx;
	void			*window;
	int				pannel;
	int				win_w;
	int				win_h;
	int				thr_w;
	int				thr_h;
	int				color;
	int				x;
	int				y;
	int				y_max;
	int				zr;
	int				zi;
	int				cr;
	int				ci;
	int				it_max;
	int				zoom;
	float			x1;
	float			y1;
	int				it;
	int				tmp;
	int				th_color;
	int				th_test;
	t_img			*img;
}					t_env;

static t_fractal	g_fractals[] =
{
	{1, "Mandelbrot"},
	{2, "Julia"},
};

void	display_usage(t_env *env);
int		keylogger(int code, t_env *env);
int		refresh(t_env *env);
int     draw(t_env *env);
int		errors(int code);
int		print_iterations(t_env *env);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:05:36 by clfoltra          #+#    #+#             */
/*   Updated: 2019/03/07 17:40:36 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
# include "libft.h"
# define WINDOW_W	1500
# define WINDOW_H	900
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
	int				threads[THREADS];
	int				pannel;
	int				win_w;
	int				win_h;
	int				arg;
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

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:53:47 by clfoltra          #+#    #+#             */
/*   Updated: 2019/03/11 13:23:26 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"

int		errors(int code)
{
	if (code == MEM)
		ft_putendl_fd("Error : failed to allocate memory", 2);
	if (code == ARG)
		ft_putendl_fd("Error : invalid map", 2);
	if (code == MLX)
		ft_putendl_fd("Error : mlx", 2);
	return (1);
}

int		refresh(t_env *env)
{
	t_img img;

	if (!(img.image = mlx_new_image(env->mlx, env->win_w, env->win_h)))
		return (errors(MLX));
	if (!(img.datas = (int *)mlx_get_data_addr(img.image, &img.bpp,
		&img.s_line, &img.endian)))
		return (errors(MLX));
	env->img = &img;
	draw(env);
	display_usage(env);
	mlx_destroy_image(env->mlx, env->img->image);
	return (0);
}

int		init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		return (errors(MLX));
	if (!(env->window = mlx_new_window(env->mlx, env->win_w, env->win_h,
		"Fractol")))
		return (errors(MLX));
	if (refresh(env))
		return (1);
	if (!(mlx_hook(env->window, 2, 5, keylogger, env)))
		return (errors(MLX));
	if (!(mlx_loop(env->mlx)))
		return (errors(MLX));
	return (0);
}

int		fractol(int arg)
{
	t_env	env;

	env.pannel = 1;
	env.win_h = WINDOW_H;
	env.win_w = WINDOW_W;
	env.thr_w = WINDOW_W / THREADS;
	env.arg = arg;
	if (!init_mlx(&env))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		ft_putendl_fd("Usage : ./fractol <fractal id> <help>", 2);
		return (1);
	}
	else if (ft_strcmp("help", argv[1]) == 0)
		ft_putstr("1 : Suite de Mandelbrot\n2 : Suite de Julia\n");
	else if (fractol(ft_atoi(argv[1])))
		return (1);
	return (0);
}

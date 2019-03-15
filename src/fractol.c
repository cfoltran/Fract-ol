/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 16:53:47 by clfoltra          #+#    #+#             */
/*   Updated: 2019/03/15 15:27:05 by clfoltra         ###   ########.fr       */
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
	// if (env->x < env->win_w && env->y < env->win_w && env->x > 0 && env->y > 0)
	// {
	// 	printf("i : %d", env->x + (env->y - 1) * env->win_w);
	// 	env->img->datas[env->x + (env->y - 1) * env->win_w] = 0xFFFFFF;
	// }
	// printf(" x : %d y : %d\n", env->x, env->y);
	// if (!(mlx_put_image_to_window(env->mlx, env->window, env->img->image, 0, 0)))
	// 	return (errors(MLX));
	if (env->pannel)
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

void	mandelbrot_init(t_env *env)
{
	env->it_max = 50;
	env->zoom = 100;
	env->x1 = -2.05;
	env->y1 = -1.3;
	env->color = 9999999;
	env->x = 0;
}

int		fractol(char *arg)
{
	t_env	env;

	if (ft_strcmp(arg, "mandelbrot") == 0)
		mandelbrot_init(&env);
	env.pannel = 1;
	env.win_h = WINDOW_H;
	env.win_w = WINDOW_W;
	env.thr_w = WINDOW_W / THREADS;
	env.th_test = 0;
	if (!init_mlx(&env))
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		ft_putendl_fd("Usage : ./fractol <fractal name> <help>", 2);
		return (1);
	}
	else if (ft_strcmp(argv[1], "help") == 0)
		ft_putstr("./fractol [ mandelbrot | julia | burning ship ]\n");
	else if (fractol(argv[1]))
		return (1);
	return (0);
}

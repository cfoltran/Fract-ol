/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:12:36 by clfoltra          #+#    #+#             */
/*   Updated: 2019/03/15 16:15:20 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <pthread.h>

int		mandelbrot(t_env *env)
{
	env->cr = env->x / env->zoom + env->x1;
	env->ci = env->y / env->zoom + env->y1;
	env->zr = 0;
	env->zi = 0;
	env->it = 0;
	while ((env->zr * env->zr + env->zi * env->zi < 4) && (env->it < env->it_max))
	{
		env->tmp = env->zr;
		env->zr = env->zr * env->zr - env->zi * env->zi + env->cr;
		env->zi = 2 * env->zi * env->tmp + env->ci;
		env->it++;
	}
	if (env->it == env->it_max)
		;// todo
	else
		if (env->x < env->win_w && env->y < env->win_w && env->x > 0 && env->y > 0)
		{
			env->img->datas[env->x + (env->y - 1) * env->win_w] = mlx_get_color_value(
				env->mlx, env->color * env->it
			);
			// if (!print_iterations(env))
			// 	return (0);
		}
	return (1);
}

void	*thread_task(void *arg)
{
	t_env	*env;
	int		tmp;

	env = (t_env *) arg;
	tmp = env->y;
	while (env->x < WINDOW_W)
	{
		env->y = tmp;
		while (env->y < env->y_max)
		{
			if (env->x < env->win_w && env->y < env->win_w && env->x > 0
				&& env->y > 0 && env->th_test)
				env->img->datas[env->x + (env->y - 1) * env->win_w] = env->th_color;
			else
				if (!mandelbrot(env))
					return (NULL);
			env->y++;
		}
		env->x++;
	}
	return (arg);
}

int		draw(t_env *env)
{
	pthread_t	threads[THREADS];
	t_env		tab[THREADS];
	int			i;

	i = 0;
	while (i < THREADS)
	{
		ft_memcpy((void*)&tab[i], (void*)env, sizeof(t_env));
		tab[i].y = (tab[i].win_w / THREADS) * i;
		tab[i].y_max = (tab[i].win_w / THREADS) * (i + 1);
		tab[i].th_color = (env->th_test) ? rand() % (((0xFFFF00 + 1)
							- 0x0000010) + 0xFFFFFF) : 0;
		pthread_create(&threads[i], NULL, thread_task, &tab[i]);
		i++;
	}
	while (i--)
		pthread_join(threads[i], NULL);
	if (!(mlx_put_image_to_window(env->mlx, env->window, env->img->image, 0, 0)))
		return (errors(MLX));
	return (0);
}
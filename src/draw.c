/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clfoltra <clfoltra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:12:36 by clfoltra          #+#    #+#             */
/*   Updated: 2019/03/13 18:20:08 by clfoltra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <pthread.h>

void	*thread_task(void *arg)
{
	t_env	*data;
	int		tmp;

	data = (t_env *) arg;
	printf("Color : %d\n", data->color);
	printf("y     : %d\n", data->y);
	printf("y_max : %d\n\n", data->y_max);
	
	data->x = 0;
	tmp = data->y;
	while (data->x < WINDOW_W)
	{
		data->y = tmp;
		while (data->y < data->y_max)
		{
			data->img->datas[data->x + data->y * WINDOW_H] = data->color;
			data->y++;
		}
		data->x++;
	}
	return (arg);
}

int		draw(t_env *env)
{
	pthread_t	threads[THREADS];
	t_env		tab[THREADS];
	int			i;

	i = -1;
	while (++i < THREADS)
	{
		ft_memcpy((void*)&tab[i], (void*)env, sizeof(t_env));
		tab[i].y = (tab[i].win_w / THREADS) * i;
		tab[i].y_max = (tab[i].win_w / THREADS) * (i + 1);
		tab[i].color = rand() % (((0xFFFF00 + 1) - 0x0000010) + 0xFFFFFF);
		pthread_create(&threads[i], NULL, thread_task, &tab[i]);
	}
	while (i--)
		pthread_join(threads[i], NULL);
	if (!(mlx_put_image_to_window(env->mlx, env->window, env->img->image, 0, 0)))
		return (errors(MLX));
	return (0);
}